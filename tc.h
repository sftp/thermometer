#define TC_GAIN_1   AD770X::GAIN_1
#define TC_GAIN_2   AD770X::GAIN_2
#define TC_GAIN_4   AD770X::GAIN_4
#define TC_GAIN_8   AD770X::GAIN_8
#define TC_GAIN_16  AD770X::GAIN_16
#define TC_GAIN_32  AD770X::GAIN_32
#define TC_GAIN_64  AD770X::GAIN_64
#define TC_GAIN_128 AD770X::GAIN_128

#if TYPE == 0
  #include "tc_k.h"
#elif TYPE == 1
  #include "tc_n.h"
#elif TYPE == 2
  #include "tc_s.h"
#endif

#define AD7705_GAIN TC_GAIN

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
