#include "ScheduleSegment.hpp"

ScheduleSegment mkScheduleSegment(enum ScheduleSegmentType type, unsigned long duration_ms)
{
    ScheduleSegment result;
    result.type = type;
    result.duration_ms = duration_ms;
    return result;
}