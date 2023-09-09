#include "ClockTime.hpp"

ClockTime msToClockTime(unsigned long ms)
{
    ClockTime result;
    result.ms = ms;
    result.secs = result.ms / 1000;
    result.ms = result.ms % 1000;
    result.mins = result.secs / 60;
    result.secs = result.secs % 60;
    result.hours = result.mins / 60;
    result.mins = result.mins % 60;
    return result;
}