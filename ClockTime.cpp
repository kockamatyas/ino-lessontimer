#include "ClockTime.hpp"

ClockTime msToClockTime(unsigned long ms)
{
    ClockTime result;
    result.ms = (uint16_t)(ms % 1000);
    result.secs = (uint8_t)(ms / 1000 % 60);
    result.mins = (uint8_t)(ms / 1000 / 60 % 60);
    result.hours = (uint8_t)(ms / 1000 / 60 / 60);
    return result;
}