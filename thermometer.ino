#include <avr/pgmspace.h>

#include "config.h"
#include "tc.h"

#include <TM1637Display.h>
#include <AD770X.h>

#include <OneWire.h>
#include <DallasTemperature.h>

uint8_t display_data[] =
  {DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB,
   DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB,
   DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB,
   DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB};

AD770X ad7705(2.5);
TM1637Display display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);

OneWire ds18b20_1w(DS18B20_PIN);
DallasTemperature ds18b20(&ds18b20_1w);

#if DS18B20_EXT_PIN
OneWire ds18b20_ext_1w(DS18B20_EXT_PIN);
DallasTemperature ds18b20_ext(&ds18b20_ext_1w);
#endif

uint16_t adc;
int16_t t;
int16_t ds18b20_t;

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
  Serial.begin(9600);
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

#if DS18B20_EXT_PIN
    ds18b20_ext.begin();
#endif
}

void loop() {
  uint8_t neg[2] = {0, 0};

  ds18b20.requestTemperatures();
#if DS18B20_EXT_PIN
  ds18b20_ext.requestTemperatures();
  if ((ds18b20_t = ds18b20_ext.getTempCByIndex(0) * 10) == DEVICE_DISCONNECTED_C * 10) {
    ds18b20_t = ds18b20.getTempCByIndex(0) * 10;
  }
#else
  ds18b20_t = ds18b20.getTempCByIndex(0) * 10;
#endif

  adc = ad7705.readADResultRaw(AD7705_CHN);
  t = find_t(adc) + ds18b20_t;

  if (t < 0) {
    neg[0] = DISPLAY_MINUS_SYMB;
    neg[1] = DISPLAY_MINUS_SYMB;
    t = -t;
  }

  if ((t < 10000 && !neg[0]) || t < 1000) {
    display_data[3] = display.encodeDigit(t % 10);
    display_data[2] = t >=    1 ? display.encodeDigit((t /   10) % 10) ^ DISPLAY_DOT_SYMB : 0;
    display_data[1] = t >=  100 ? display.encodeDigit((t /  100) % 10) : 0 ^ (neg[0] = 0, neg[1]);
    display_data[0] = t >= 1000 ? display.encodeDigit((t / 1000) % 10) : 0 ^ neg[0];
  } else {
    display_data[3] = display.encodeDigit((t /    10) % 10);
    display_data[2] = display.encodeDigit((t /   100) % 10);
    display_data[1] = t >=  1000 ? display.encodeDigit((t /  1000) % 10) : 0 ^ (neg[0] = 0, neg[1]);
    display_data[0] = t >= 10000 ? display.encodeDigit((t / 10000) % 10) : 0 ^ neg[0];
  }

  display.setSegments(display_data);

  delay(CYCLE_DELAY_MS);
}
