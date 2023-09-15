#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "ScheduleSegment.hpp"

#define SEG mkScheduleSegment
#define LessonBreak_MS 2700000
#define BREAK_MS 600000
#define LONG_BREAK_MS 3600000

const int schedules = 5;
const int segments = 10;

ScheduleSegment timetable[schedules][segments] = {
    {SEG(LessonBreak, LessonBreak_MS), SEG(LessonBreak, BREAK_MS), SEG(LessonBreak, LessonBreak_MS), SEG(LongBreak, LONG_BREAK_MS), SEG(LessonBreak, LessonBreak_MS)},
    {SEG(LessonBreak, LessonBreak_MS), SEG(LessonBreak, BREAK_MS), SEG(LessonBreak, LessonBreak_MS), SEG(LongBreak, LONG_BREAK_MS), SEG(LessonBreak, LessonBreak_MS)},
    {SEG(LessonBreak, LessonBreak_MS), SEG(LessonBreak, BREAK_MS), SEG(LessonBreak, LessonBreak_MS), SEG(LongBreak, LONG_BREAK_MS), SEG(LessonBreak, LessonBreak_MS)},
    {SEG(LessonBreak, LessonBreak_MS), SEG(LessonBreak, BREAK_MS), SEG(LessonBreak, LessonBreak_MS), SEG(LongBreak, LONG_BREAK_MS), SEG(LessonBreak, LessonBreak_MS)},
    {SEG(LessonBreak, LessonBreak_MS), SEG(LessonBreak, BREAK_MS), SEG(LessonBreak, LessonBreak_MS), SEG(LongBreak, LONG_BREAK_MS), SEG(LessonBreak, LessonBreak_MS)}};

#endif