#include "TM1637Display.h"
#include "ClockTime.hpp"
#include "Button.hpp"
#include "RGBLed.hpp"
#include <Arduino.h>

#define DISPLAY_CLK 2
#define DISPLAY_DIO 3
#define DISPLAY_BRIGHTNESS 2

#define BTN_MINUS 4
#define BTN_PLUS 5
#define BTN_SET 6
#define BTN_SHOW 7
#define MODE_LED_RED (uint8_t)8
#define MODE_LED_GREEN (uint8_t)9
#define MODE_LED_BLUE (uint8_t)10

#define LESSON_BREAK_COLOR 0b00000100
#define LONG_BREAK_COLOR 0b00000010
#define SCHEDULE_END_COLOR 0b00000001

Button BTNMinus(BTN_MINUS);
Button BTNPlus(BTN_PLUS);
Button BTNSet(BTN_SET);
Button BTNShow(BTN_SHOW);

RGBLed RGBModeLed(MODE_LED_RED, MODE_LED_GREEN, MODE_LED_BLUE);

TM1637Display display(DISPLAY_CLK, DISPLAY_DIO);

enum Mode : uint8_t
{
    LessonBreak,
    LongBreak,
    ScheduleEnd
};

void displayClockTime(ClockTime ct, bool colon)
{
    uint8_t segments[4];
    if (ct.hours > 0)
    {
        segments[0] = TM1637Display::encodeDigit((uint8_t)(ct.hours / 10));
        segments[1] = TM1637Display::encodeDigit((uint8_t)(ct.hours % 10));
        segments[2] = TM1637Display::encodeDigit((uint8_t)(ct.mins / 10));
        segments[3] = TM1637Display::encodeDigit((uint8_t)(ct.mins % 10));
    }
    else if (ct.mins > 0)
    {
        segments[0] = TM1637Display::encodeDigit((uint8_t)(ct.mins / 10));
        segments[1] = TM1637Display::encodeDigit((uint8_t)(ct.mins % 10));
        segments[2] = TM1637Display::encodeDigit((uint8_t)(ct.secs / 10));
        segments[3] = TM1637Display::encodeDigit((uint8_t)(ct.secs % 10));
    }
    else
    {
        segments[0] = TM1637Display::encodeDigit((uint8_t)(ct.secs / 10));
        segments[1] = TM1637Display::encodeDigit((uint8_t)(ct.secs % 10));
        segments[2] = TM1637Display::encodeDigit((uint8_t)(ct.ms / 100));
        segments[3] = TM1637Display::encodeDigit((uint8_t)(ct.ms / 10 % 10));
    }
    if (colon)
        segments[1] += 128;
    display.setSegments(segments);
}

void setup()
{
    display.setBrightness(DISPLAY_BRIGHTNESS);
    BTNMinus.begin();
    BTNPlus.begin();
    BTNSet.begin();
    BTNShow.begin();
    RGBModeLed.begin();
}
void loop() {}
