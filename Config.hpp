#ifndef CONFIG_H
#define CONFIG_H

// TM1637 display config

#define DISPLAY_CLK 2
#define DISPLAY_DIO 3
#define DISPLAY_BRIGHTNESS 2

// Buttons config

#define BTN_MINUS 4
#define BTN_PLUS 5
#define BTN_SET 6
#define BTN_SHOW 7

// RGB Mode led config

#define MODE_LED_RED (uint8_t)8
#define MODE_LED_GREEN (uint8_t)9
#define MODE_LED_BLUE (uint8_t)10

// Countdown modes' colors

#define LESSON_BREAK_END_COLOR 0b00000100
#define LONG_BREAK_END_COLOR 0b00000001
#define SCHEDULE_END_COLOR 0b00000010

#endif