#define MENU_SCREEN_MAIN     0
#define MENU_SCREEN_SETPOINT 1

uint8_t curr_screen = MENU_SCREEN_MAIN;
uint32_t enc_sw_start_ms = 0;
uint8_t enc_sw_prev = 1;
uint8_t sw_long = 0;
uint8_t sw_short = 0;
