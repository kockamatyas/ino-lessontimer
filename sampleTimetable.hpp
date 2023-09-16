#ifndef SCHEDULE_H
#define SCHEDULE_H

/*
 *
 *  This is the timetable sample.
 *
 *  Use this as a sample for creating your own timetable.
 *  First, modify the timetable rows number (const int schedules) and the columns number (const int segments).
 *  Then, add your timetable rows (schedules), consisting of schedule segments (LessonBreak, LongBreak, None).
 *
 *  LessonBreak = Lesson / Break
 *  LongBreak = Most commonly a lunch break, it is possible to have more per schedule
 *  None = See IMPORTANT NOTE below
 *
 *  Remember to write all durations in miliseconds
 *  and as unsigned longs (UL at the end of the number).
 *
 *  Tip: Use #define macros to easily write common durations for your segments.
 * 
 *  DO NOT MODIFY ANYTHING NOT IN THE EDITABLE PART OF THE FILE,
 *  WHICH IS INDICATED BY THE COMMENTS!
 *
 *  After you've done your changes, save this file as Timetable.hpp.
 *
 *  IMPORTANT NOTE:
 *  When one schedule has less segments than
 *  the timetable rows number (const int segments),
 *  fill the rest with SEG(None, 0),
 *  until every schedule is exactly as long
 *  as the timetable rows number (const int segments)!
 *
 */

#include "ScheduleSegment.hpp"

#define SEG mkScheduleSegment

/*
 *  EDITABLE PART START
 */

#define LESSON_MS 2700000UL
#define BREAK_MS 600000UL
#define LONG_BREAK_MS 3600000UL

const int schedules = 1;
const int segments = 13;

ScheduleSegment timetable[schedules][segments] = {
    {SEG(LessonBreak, LESSON_MS), // <- first lesson
     SEG(LessonBreak, BREAK_MS),  // <- break in-between lessons
     SEG(LessonBreak, LESSON_MS),
     SEG(LessonBreak, 1200000UL), // <- specifying a length directly, without a #define macro
     SEG(LessonBreak, LESSON_MS),
     SEG(LessonBreak, BREAK_MS),
     SEG(LessonBreak, LESSON_MS),
     SEG(LessonBreak, BREAK_MS),
     SEG(LessonBreak, LESSON_MS),
     SEG(LessonBreak, BREAK_MS),
     SEG(LessonBreak, LESSON_MS),   // <- sixth lesson
     SEG(LongBreak, LONG_BREAK_MS), // <- lunch break
     SEG(LessonBreak, LESSON_MS) /* <- after-lunchbreak lesson */} /* more schedules */};

/*
 *  EDITABLE PART END
 */

#endif