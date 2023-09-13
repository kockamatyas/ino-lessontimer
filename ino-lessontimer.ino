#include "TM1637Display.h"
#include "ClockTime.hpp"
#include <Arduino.h>

#define DISPLAY_CLK 2
#define DISPLAY_DIO 3
#define DISPLAY_BRIGHTNESS 2

TM1637Display display(DISPLAY_CLK, DISPLAY_DIO);

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
}
void loop() {}
