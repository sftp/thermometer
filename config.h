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
#define AD7705_VREF        2.5

#define DS18B20_PIN 4
#define DS18B20_EXT_PIN 7
#define DS18B20_RESOLUTION 12

#define DISPLAY_CLK_PIN A5
#define DISPLAY_DIO_PIN A4
#define DISPLAY_BRTHNSS 0xC

#define ENC_CLK_PIN 2
#define ENC_DT_PIN 3
#define ENC_DIRECTION -1
#define ENC_TRANS_PER_CLICK 4
#define ENC_TRANS_TO_FF 8
#define ENC_FF_STEP 100

#define PID_PIN 6
#define PID_K_P 30
#define PID_K_I 0.24
#define PID_K_D 60
#define PID_CONS_GAP 0
#define PID_K_CONS_P 10
#define PID_K_CONS_I 0.25
#define PID_K_CONS_D 1

#define ADC_DELAY_MS 20
#define DS18B20_DELAY_MS 1000
#define DISPLAY_DELAY_MS 100
#define PID_COMPUTE_DELAY_MS 600
#define MENU_DELAY_MS 3000

#define DEBUG 0
