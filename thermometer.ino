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

uint16_t v;
int16_t t;

uint16_t find_t(uint16_t x, uint16_t a, uint16_t b)
{
  uint16_t ret;
  uint16_t left;
  uint16_t right;
  uint8_t found = 0;

  if (x >= pgm_read_word_near(TABLE + b)) {
    return b;
  }

  while (!found) {
    ret = (a + b) / 2;
    left = pgm_read_word_near(TABLE + ret);
    right = pgm_read_word_near(TABLE + ret + 1);

    if (x >= left && right > x) {
      found = 1;
      ret = 10 * a + (10 * (x - left) * (b - a)) / (right - left);
      break;
    }

    if (x >= right) {
      a = ret + 1;
    }

    if (x < left) {
      b = ret;
    }
  }

  return ret;
}

void setup() {
  display.setBrightness(DISPLAY_BRTHNSS);
  display.setSegments(display_data);

  ad7705.reset();
  ad7705.init(AD7705_CHN,
              AD7705_CLK_DIV,
              AD7705_MODE,
              AD7705_GAIN,
              AD7705_UPDATE_RATE);

  ds18b20.begin();
}

void loop() {
  uint8_t neg[2] = {0, 0};

  ds18b20.requestTemperatures();
  v = ad7705.readADResultRaw(AD7705_CHN);
  t = find_t(v, 0, TABLE_SIZE - 1) +
	ds18b20.getTempCByIndex(0) * 10;

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
