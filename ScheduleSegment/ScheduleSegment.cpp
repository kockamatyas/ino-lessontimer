#include "ScheduleSegment.hpp"

ScheduleSegment mkScheduleSegment(enum ScheduleSegmentType type, unsigned long length)
{
    ScheduleSegment result;
    result.type = type;
    result.length = length;
    return result;
}