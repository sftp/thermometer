/*
 * 0 - N
 * 1 - S
 */
#define TYPE 0

#if TYPE == 0
  #include "tnn.h"
  #define AD7705_GAIN        AD770X::GAIN_64
#elif TYPE == 1
  #include "ts.h"
  #define AD7705_GAIN        AD770X::GAIN_128
#endif

#define AD7705_CHN         AD770X::CHN_AIN1
#define AD7705_CLK_DIV     AD770X::CLK_DIV_1
#define AD7705_MODE        AD770X::BIPOLAR
#define AD7705_UPDATE_RATE AD770X::UPDATE_RATE_20

#define DS18B20_PIN 2

#define DISPLAY_CLK_PIN A5
#define DISPLAY_DIO_PIN A4
#define DISPLAY_BRTHNSS 0xC
#define DISPLAY_DOT_SYMB (1<<7)
#define DISPLAY_MINUS_SYMB (1<<6)

