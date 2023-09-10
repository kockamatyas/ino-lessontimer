#ifndef SCHEDULE_SEGMENT_H
#define SCHEDULE_SEGMENT_H

enum ScheduleSegmentType : unsigned char
{
    Lesson,
    Break,
    LongBreak
};

struct ScheduleSegment
{
    enum ScheduleSegmentType type;
    unsigned long length;
};

#endif