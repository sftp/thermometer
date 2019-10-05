#include <TM1637Display.h>

#define DISPLAY_DOT_SYMB (1<<7)
#define DISPLAY_MINUS_SYMB (1<<6)

TM1637Display display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);
uint8_t display_buf[] =
  {DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB,
   DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB,
   DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB,
   DISPLAY_MINUS_SYMB ^ DISPLAY_DOT_SYMB};

void display_tenth_signed (int16_t val)
{
  uint8_t neg[2] = {0, 0};

  if (val < 0) {
    neg[0] = DISPLAY_MINUS_SYMB;
    neg[1] = DISPLAY_MINUS_SYMB;
    val = -val;
  }

  if ((val < 10000 && !neg[0]) || val < 1000) {
    display_buf[3] = display.encodeDigit(val % 10);
    display_buf[2] = val >=    1 ? display.encodeDigit((val /   10) % 10) ^ DISPLAY_DOT_SYMB : 0;
    display_buf[1] = val >=  100 ? display.encodeDigit((val /  100) % 10) : 0 ^ (neg[0] = 0, neg[1]);
    display_buf[0] = val >= 1000 ? display.encodeDigit((val / 1000) % 10) : 0 ^ neg[0];
  } else {
    display_buf[3] = display.encodeDigit((val /    10) % 10);
    display_buf[2] = display.encodeDigit((val /   100) % 10);
    display_buf[1] = val >=  1000 ? display.encodeDigit((val /  1000) % 10) : 0 ^ (neg[0] = 0, neg[1]);
    display_buf[0] = val >= 10000 ? display.encodeDigit((val / 10000) % 10) : 0 ^ neg[0];
  }

  display.setSegments(display_buf);
}
