#ifndef SCHEDULE_SEGMENT_H
#define SCHEDULE_SEGMENT_H

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