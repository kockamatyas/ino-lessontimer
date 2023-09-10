#ifndef SCHEDULE_H
#define SCHEDULE_H

struct ScheduleSegment
{
    enum type : unsigned char
    {
        Lesson,
        Break,
        LongBreak
    };
    unsigned long length;
};

#endif