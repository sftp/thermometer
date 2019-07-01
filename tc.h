#define TC_GAIN_1   AD770X::GAIN_1
#define TC_GAIN_2   AD770X::GAIN_2
#define TC_GAIN_4   AD770X::GAIN_4
#define TC_GAIN_8   AD770X::GAIN_8
#define TC_GAIN_16  AD770X::GAIN_16
#define TC_GAIN_32  AD770X::GAIN_32
#define TC_GAIN_64  AD770X::GAIN_64
#define TC_GAIN_128 AD770X::GAIN_128

#if TYPE == 0
  #include "tc_n.h"
#elif TYPE == 1
  #include "tc_s.h"
#endif

#define AD7705_GAIN TC_GAIN
