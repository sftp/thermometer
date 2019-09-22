#include <avr/pgmspace.h>

#include "config.h"
#include "tc.h"

#include <TM1637Display.h>
#include <AD770X.h>

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Encoder.h>
#include <PID_v1.h>

int32_t disp_val;
uint8_t display_data[] =
  {DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB,
   DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB,
   DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB,
   DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB};

AD770X ad7705(AD7705_VREF);
TM1637Display display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);

Encoder enc(ENC_CLK_PIN, ENC_DT_PIN);
int32_t enc_off = 0;
int32_t enc_pos = 0;
int32_t enc_pos_new = 0;
double setpoint = 0;

double Kp;
double Ki;
double Kd;
double pid_in;
double pid_out;
PID pid(&pid_in, &pid_out, &setpoint, Kp, Ki, Kd, DIRECT);

DeviceAddress ds18b20_addr;

OneWire ds18b20_1w(DS18B20_PIN);
DallasTemperature ds18b20(&ds18b20_1w);

#if DS18B20_EXT_PIN
OneWire ds18b20_ext_1w(DS18B20_EXT_PIN);
DallasTemperature ds18b20_ext(&ds18b20_ext_1w);
#endif

int32_t ms = 0;
uint32_t adc_ms = 0;
uint32_t ds18b20_ms = 0;
uint32_t display_ms = 0;
uint32_t enc_ms_act = 0;
uint32_t pid_compute_ms = 0;

uint16_t adc;
int16_t t;
int32_t ds18b20_t;

uint16_t find_t(uint16_t x)
{
  uint16_t a;
  uint16_t b;
  uint16_t left;
  uint16_t right;
  uint16_t pos;
  uint16_t ret;

  pos = x / TABLE_STEP;

  if (pos >= TABLE_SIZE) {
    return pgm_read_word_near(TABLE + TABLE_SIZE);
  }

  a = pgm_read_word_near(TABLE + pos);
  b = pgm_read_word_near(TABLE + pos + 1);
  left = pos * TABLE_STEP;
  right = (pos + 1) * TABLE_STEP;

  ret = a + ((x - left) * (b - a)) / (right - left);

#if DEBUG == 1
  Serial.print("adc = ");
  Serial.print(x);
  Serial.print("\ta = ");
  Serial.print(a);
  Serial.print("\tb = ");
  Serial.print(b);
  Serial.print("\tleft = ");
  Serial.print(left);
  Serial.print("\tright = ");
  Serial.print(right);
  Serial.print("\tt = ");
  Serial.println(ret / 10.0);
#endif

  return ret;
}

void setup() {

#if DEBUG == 1
  Serial.begin(115200);
#endif

  display.setBrightness(DISPLAY_BRTHNSS);
  display.setSegments(display_data);

  ad7705.reset();
  ad7705.init(AD7705_CHN,
              AD7705_CLK_DIV,
              AD7705_MODE,
              AD7705_GAIN,
              AD7705_UPDATE_RATE);

  ds18b20.begin();
  ds18b20.setResolution(DS18B20_RESOLUTION);
  ds18b20.requestTemperatures();
  ds18b20.setWaitForConversion(false);

#if DS18B20_EXT_PIN
  ds18b20_ext.begin();
  ds18b20_ext.setResolution(DS18B20_RESOLUTION);
  ds18b20_ext.requestTemperatures();
  ds18b20_ext.setWaitForConversion(false);
#endif

  pid.SetOutputLimits(0, PID_COMPUTE_DELAY_MS);
  pid.SetMode(AUTOMATIC);
}

void loop() {
  ms = millis();

#if DEBUG == 1
  Serial.print("loop start at ");
  Serial.println(ms);
#endif

  if (ms > ds18b20_ms + DS18B20_DELAY_MS || ms < ds18b20_ms || !ds18b20_ms) {
    ds18b20_ms = millis();

#if DEBUG == 1
    Serial.print("ds18b20 task start at ");
    Serial.println(ds18b20_ms);
#endif

#if DS18B20_EXT_PIN
    if (ds18b20_ext.getAddress(ds18b20_addr, 0)) {
      ds18b20_t = (int32_t) ds18b20_ext.getTemp(ds18b20_addr) * 10 / 128;
      ds18b20_ext.requestTemperatures();
    } else {
      ds18b20.getAddress(ds18b20_addr, 0);
      ds18b20_t = (int32_t) ds18b20.getTemp(ds18b20_addr) * 10 / 128;
      ds18b20.requestTemperatures();
    }
#else
    ds18b20.getAddress(ds18b20_addr, 0);
    ds18b20_t = (int32_t) ds18b20.getTemp(ds18b20_addr) * 10 / 128;
    ds18b20.requestTemperatures();
#endif

    ms = millis();
  }

  if (ms > adc_ms + ADC_DELAY_MS || ms < adc_ms || !adc_ms) {
    adc_ms = millis();

#if DEBUG == 1
    Serial.print("adc task start at ");
    Serial.println(adc_ms);
#endif

    adc = ad7705.readADResultRaw(AD7705_CHN);

    ms = millis();
  }

  if (ms > pid_compute_ms + PID_COMPUTE_DELAY_MS || ms < pid_compute_ms || !pid_compute_ms) {
    pid_compute_ms = millis();

    if (setpoint - t > PID_CONS_GAP) {
      pid.SetTunings(PID_K_P, PID_K_I, PID_K_D);
    } else {
      pid.SetTunings(PID_K_CONS_P, PID_K_CONS_P, PID_K_CONS_P);
    }

    pid_in = t;
    pid.Compute();

    ms = millis();
  }

  if (ms < pid_compute_ms + pid_out) {
    digitalWrite(PID_PIN, HIGH);
  } else {
    digitalWrite(PID_PIN, LOW);
  }

  enc_pos_new = enc.read();
  enc_off = enc_pos_new - enc_pos;

  if (enc_off && enc_off % ENC_TRANS_PER_CLICK == 0) {
    enc_pos = enc_pos_new;
    enc_ms_act = millis();

    if (enc_off > ENC_TRANS_TO_FF) {
      setpoint += ENC_FF_STEP;
    } else if (enc_off < -ENC_TRANS_TO_FF){
      setpoint += -ENC_FF_STEP;
    } else {
      setpoint += enc_off / ENC_TRANS_PER_CLICK;
    }
  }

  if (ms > display_ms + DISPLAY_DELAY_MS || ms < display_ms || !display_ms) {
    display_ms = millis();

#if DEBUG == 1
    Serial.print("display task start at ");
    Serial.println(display_ms);
#endif

    t = find_t(adc) + ds18b20_t;

    if (enc_ms_act && ms < enc_ms_act + MENU_DELAY_MS) {
      disp_val = setpoint;
    } else {
      disp_val = t;
    }

    uint8_t neg[2] = {0, 0};
    if (disp_val < 0) {
      neg[0] = DISPLAY_MINUS_SYMB;
      neg[1] = DISPLAY_MINUS_SYMB;
      disp_val = -disp_val;
    }

    if ((disp_val < 10000 && !neg[0]) || disp_val < 1000) {
      display_data[3] = display.encodeDigit(disp_val % 10);
      display_data[2] = disp_val >=    1 ? display.encodeDigit((disp_val /   10) % 10) ^ DISPLAY_DOT_SYMB : 0;
      display_data[1] = disp_val >=  100 ? display.encodeDigit((disp_val /  100) % 10) : 0 ^ (neg[0] = 0, neg[1]);
      display_data[0] = disp_val >= 1000 ? display.encodeDigit((disp_val / 1000) % 10) : 0 ^ neg[0];
    } else {
      display_data[3] = display.encodeDigit((disp_val /    10) % 10);
      display_data[2] = display.encodeDigit((disp_val /   100) % 10);
      display_data[1] = disp_val >=  1000 ? display.encodeDigit((disp_val /  1000) % 10) : 0 ^ (neg[0] = 0, neg[1]);
      display_data[0] = disp_val >= 10000 ? display.encodeDigit((disp_val / 10000) % 10) : 0 ^ neg[0];
    }

    display.setSegments(display_data);

    ms = millis();
  }
}
