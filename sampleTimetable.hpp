#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "ScheduleSegment.hpp"

#define SEG mkScheduleSegment
#define LESSON_MS 2700000
#define BREAK_MS 600000
#define LONG_BREAK_MS 3600000

const int schedules = 5;
const int segments = 10;

ScheduleSegment timetable[schedules][segments] = {
    {SEG(Lesson, LESSON_MS), SEG(Break, BREAK_MS), SEG(Lesson, LESSON_MS), SEG(LongBreak, LONG_BREAK_MS), SEG(Lesson, LESSON_MS)},
    {SEG(Lesson, LESSON_MS), SEG(Break, BREAK_MS), SEG(Lesson, LESSON_MS), SEG(LongBreak, LONG_BREAK_MS), SEG(Lesson, LESSON_MS)},
    {SEG(Lesson, LESSON_MS), SEG(Break, BREAK_MS), SEG(Lesson, LESSON_MS), SEG(LongBreak, LONG_BREAK_MS), SEG(Lesson, LESSON_MS)},
    {SEG(Lesson, LESSON_MS), SEG(Break, BREAK_MS), SEG(Lesson, LESSON_MS), SEG(LongBreak, LONG_BREAK_MS), SEG(Lesson, LESSON_MS)},
    {SEG(Lesson, LESSON_MS), SEG(Break, BREAK_MS), SEG(Lesson, LESSON_MS), SEG(LongBreak, LONG_BREAK_MS), SEG(Lesson, LESSON_MS)}};

#endif