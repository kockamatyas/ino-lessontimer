#ifndef CLOCKTIME_H
#define CLOCKTIME_H

struct ClockTime
{
    unsigned long hours;
    unsigned long mins;
    unsigned long secs;
    unsigned long ms;
};

ClockTime msToClockTime(unsigned long ms);

#endif