#ifndef CLOCKTIME_H
#define CLOCKTIME_H

#include <Arduino.h>

struct ClockTime
{
    uint8_t hours;
    uint8_t mins;
    uint8_t secs;
    uint16_t ms;
};

ClockTime msToClockTime(unsigned long ms);

#endif