#include <avr/pgmspace.h>
#include "tnn.h"

#include <TM1637Display.h>
#include <AD770X.h>

#include <OneWire.h>
#include <DallasTemperature.h>

#define DS18B20_PIN 4
#define DISPLAY_CLK_PIN 2
#define DISPLAY_DIO_PIN 3
#define DISPLAY_BRTHNSS 0xC
#define DISPLAY_DOT_SYMB (1<<7)
#define DISPLAY_MINUS_SYMB (1<<6)

uint8_t display_nodata[] =
  {DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB,
   DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB,
   DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB,
   DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB};

uint8_t display_data[] = {0, 0, 0, 0};

AD770X ad7705(2.5);
TM1637Display display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);
OneWire ds18b20_1w(DS18B20_PIN);
DallasTemperature ds18b20(&ds18b20_1w);

uint16_t v;
uint16_t t;

uint16_t find_t(uint16_t x, uint16_t a, uint16_t b)
{
  uint16_t ret;
  uint16_t left;
  uint16_t right;
  uint8_t found = 0;

  if (x >= pgm_read_word_near(TNN + b)) {
    return b;
  }

  while (!found) {
    ret = (a + b) / 2;
    left = pgm_read_word_near(TNN + ret);
    right = pgm_read_word_near(TNN + ret + 1);

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
  display.setSegments(display_nodata);

  ad7705.reset();
  ad7705.init(AD770X::CHN_AIN1,
              AD770X::CLK_DIV_1,
              AD770X::BIPOLAR,
              AD770X::GAIN_64,
              AD770X::UPDATE_RATE_20);

  ds18b20.begin();
}

void loop() {
  ds18b20.requestTemperatures();
  v = ad7705.readADResultRaw(AD770X::CHN_AIN1);
  t = find_t(v, 0, TNN_TABLE_SIZE - 1) +
        (uint16_t) (ds18b20.getTempCByIndex(0) * 10);

  if (t < 10000) {
    display_data[3] = display.encodeDigit(t % 10);
    display_data[2] = t >=    1 ? display.encodeDigit((t /   10) % 10) ^ DISPLAY_DOT_SYMB : 0;
    display_data[1] = t >=  100 ? display.encodeDigit((t /  100) % 10) : 0;
    display_data[0] = t >= 1000 ? display.encodeDigit((t / 1000) % 10) : 0;
  } else {
    display_data[3] = display.encodeDigit((t /    10) % 10);
    display_data[2] = display.encodeDigit((t /   100) % 10);
    display_data[1] = display.encodeDigit((t /  1000) % 10);
    display_data[0] = display.encodeDigit((t / 10000) % 10);
  }

  display.setSegments(display_data);

  delay(100);
}
