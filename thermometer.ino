#include <avr/pgmspace.h>
#include <EEPROM.h>

#include "config.h"
#include "display.h"
#include "menu.h"
#include "tc.h"

#include <AD770X.h>

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Encoder.h>
#include <PID_v1.h>

AD770X ad7705(AD7705_VREF);

Encoder enc(ENC_CLK_PIN, ENC_DT_PIN);
int32_t enc_off = 0;
int32_t enc_pos = 0;
int32_t enc_pos_new = 0;
double setpoint;

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

uint8_t eeprom_need_write = 0;

uint32_t ms = 0;
uint32_t adc_ms = 0;
uint32_t ds18b20_ms = 0;
uint32_t display_ms = 0;
uint32_t enc_ms_act = 0;
uint32_t pid_compute_ms = 0;

uint16_t adc;
int16_t t;
int32_t ds18b20_t;

void setup() {

#if DEBUG == 1
  Serial.begin(115200);
#endif

  display_init();

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

  setpoint = ((uint16_t)EEPROM.read(0)<<8) + (uint16_t)EEPROM.read(1);

  pid.SetOutputLimits(0, PID_COMPUTE_DELAY_MS);
  pid.SetTunings(PID_K_P, PID_K_I, PID_K_D);
  pid.SetMode(AUTOMATIC);
}

void loop() {
  ms = millis();

#if DEBUG == 1
  Serial.print("loop start at ");
  Serial.println(ms);
#endif

  if (ms > ds18b20_ms + DS18B20_DELAY_MS || ms < ds18b20_ms || !ds18b20_ms) {
    ds18b20_ms = ms;

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
  }

  ms = millis();
  if (ms > adc_ms + ADC_DELAY_MS || ms < adc_ms || !adc_ms) {
    adc_ms = ms;

#if DEBUG == 1
    Serial.print("adc task start at ");
    Serial.println(adc_ms);
#endif

    adc = ad7705.readADResultRaw(AD7705_CHN);
    t = find_t(adc) + ds18b20_t;
  }

  ms = millis();
  if (ms > pid_compute_ms + PID_COMPUTE_DELAY_MS || ms < pid_compute_ms || !pid_compute_ms) {
    pid_compute_ms = ms;

    if (PID_CONS_GAP) {
      if (setpoint - t > PID_CONS_GAP) {
        pid.SetTunings(PID_K_P, PID_K_I, PID_K_D);
      } else {
        pid.SetTunings(PID_K_CONS_P, PID_K_CONS_I, PID_K_CONS_D);
      }
    }

    pid_in = t;
    pid.Compute();
  }

  ms = millis();
  if (ms < pid_compute_ms + pid_out) {
    digitalWrite(PID_PIN, HIGH);
  } else {
    digitalWrite(PID_PIN, LOW);
  }

  /* switch pressed */
  if (enc_sw_prev == 1 && digitalRead(ENC_SW_PIN) == 0) {
    enc_sw_start_ms = millis();
    enc_sw_prev = 0;
  }

  /* switch released */
  if (enc_sw_prev == 0 && digitalRead(ENC_SW_PIN) == 1) {
    enc_sw_prev = 1;
    if (millis() > enc_sw_start_ms + ENC_SW_PRESS_LONG) {
      Serial.println("long");
      sw_long = 1;
    } else if (millis() > enc_sw_start_ms + ENC_SW_PRESS_SHORT) {
      Serial.println("short");
      sw_short = 1;
    }
  }

  if (curr_screen == MENU_SCREEN_MAIN) {
    if (sw_short) {
      sw_short = 0;
      curr_screen = MENU_SCREEN_SETPOINT;
      enc_pos = enc.read();
      enc_ms_act = millis();
    }
  } else if (curr_screen == MENU_SCREEN_SETPOINT) {
    enc_pos_new = enc.read();
    enc_off = enc_pos_new - enc_pos;

    if (enc_off && enc_off % ENC_TRANS_PER_CLICK == 0) {
      enc_pos = enc_pos_new;
      enc_ms_act = millis();

      if (enc_off > ENC_TRANS_TO_FF) {
        setpoint += ENC_FF_STEP * ENC_DIRECTION * 10;
      } else if (enc_off < -ENC_TRANS_TO_FF){
        setpoint -= ENC_FF_STEP * ENC_DIRECTION * 10;
      } else {
        setpoint += enc_off * ENC_DIRECTION * 10 / ENC_TRANS_PER_CLICK;
      }

      eeprom_need_write = 1;
    }

    display_int_signed(setpoint / 10);

    if (sw_short) {
      sw_short = 0;
      curr_screen = MENU_SCREEN_MAIN;
    }

    if (enc_ms_act && millis() > enc_ms_act + MENU_DELAY_MS) {
      curr_screen = MENU_SCREEN_MAIN;
    }
  }

  ms = millis();
  if (ms > display_ms + DISPLAY_DELAY_MS || ms < display_ms || !display_ms) {
    display_ms = ms;

#if DEBUG == 1
    Serial.print("display task start at ");
    Serial.println(display_ms);
#endif

    if (curr_screen == MENU_SCREEN_MAIN) {
      display_tenth_signed(t);

      if (eeprom_need_write) {
        EEPROM.write(0, (uint16_t)setpoint>>8);
        EEPROM.write(1, (uint8_t)setpoint);

        eeprom_need_write = 0;
      }
    }
  }
}
