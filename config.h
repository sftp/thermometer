/*
 * 0 - K
 * 1 - N
 * 2 - S
 */
#define TYPE 0

#define AD7705_CHN         AD770X::CHN_AIN1
#define AD7705_CLK_DIV     AD770X::CLK_DIV_1
#define AD7705_MODE        AD770X::BIPOLAR
#define AD7705_UPDATE_RATE AD770X::UPDATE_RATE_20

#define DS18B20_PIN 2
#define DS18B20_EXT_PIN 4

#define DISPLAY_CLK_PIN A5
#define DISPLAY_DIO_PIN A4
#define DISPLAY_BRTHNSS 0xC
#define DISPLAY_DOT_SYMB (1<<7)
#define DISPLAY_MINUS_SYMB (1<<6)

#define CYCLE_DELAY_MS 100
#define DS18B20_DELAY_MS 1000

#define DEBUG 0
