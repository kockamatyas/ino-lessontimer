#include "TM1637Display.h"
#include "ClockTime/ClockTime.hpp"

#define DISPLAY_CLK 2
#define DISPLAY_DIO 3
#define DISPLAY_BRIGHTNESS 7

TM1637Display display(DISPLAY_CLK, DISPLAY_DIO);

void displayClockTime(ClockTime ct, bool colon) {
    uint8_t segments[4];
    if (ct.hours > 0)
    {
        segments[0] = (uint8_t)ct.hours / 10;
        segments[1] = (uint8_t)ct.hours % 10;
        segments[2] = (uint8_t)ct.mins / 10;
        segments[3] = (uint8_t)ct.mins % 10;
    }
    else if (ct.mins > 0)
    {
        segments[0] = (uint8_t)ct.mins / 10;
        segments[1] = (uint8_t)ct.mins % 10;
        segments[2] = (uint8_t)ct.secs / 10;
        segments[3] = (uint8_t)ct.secs % 10;
    }
    else
    {
        segments[0] = (uint8_t)ct.secs / 10;
        segments[1] = (uint8_t)ct.secs % 10;
        segments[2] = (uint8_t)ct.ms / 10;
        segments[3] = (uint8_t)ct.ms % 10;
    }
    if (colon) segments[1] += 128;
    display.setSegments(segments);
}

void setup() {
    display.setBrightness(DISPLAY_BRIGHTNESS);
}
void loop() {}