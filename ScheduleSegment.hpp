#ifndef SCHEDULE_SEGMENT_H
#define SCHEDULE_SEGMENT_H

enum ScheduleSegmentType : unsigned char
{
    LessonBreak,
    LongBreak,
    None
};

struct ScheduleSegment
{
    enum ScheduleSegmentType type;
    unsigned long duration_ms;
};

ScheduleSegment mkScheduleSegment(enum ScheduleSegmentType type, unsigned long duration_ms);

#endif