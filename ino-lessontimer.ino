#include "TM1637Display.h"
#include "ClockTime.hpp"
#include "Button.hpp"
#include "RGBLed.hpp"
#include "Timetable.hpp"
#include "ScheduleSegment.hpp"
#include <Arduino.h>

#define DISPLAY_CLK 2
#define DISPLAY_DIO 3
#define DISPLAY_BRIGHTNESS 2

#define BTN_MINUS 4
#define BTN_PLUS 5
#define BTN_SET 6
#define BTN_SHOW 7
#define MODE_LED_RED (uint8_t)8
#define MODE_LED_GREEN (uint8_t)9
#define MODE_LED_BLUE (uint8_t)10

#define LESSON_BREAK_COLOR 0b00000100
#define LONG_BREAK_COLOR 0b00000001
#define SCHEDULE_END_COLOR 0b00000010

Button BTNMinus(BTN_MINUS);
Button BTNPlus(BTN_PLUS);
Button BTNSet(BTN_SET);
Button BTNShow(BTN_SHOW);

RGBLed RGBModeLed(MODE_LED_RED, MODE_LED_GREEN, MODE_LED_BLUE);

TM1637Display display(DISPLAY_CLK, DISPLAY_DIO);

enum Mode : uint8_t
{
    LessonBreakEnd,
    LongBreakEnd,
    ScheduleEnd
};

void displayClockTime(ClockTime ct, bool colon)
{
    uint8_t segments[4];
    if (ct.hours > 0)
    {
        segments[0] = TM1637Display::encodeDigit((uint8_t)(ct.hours / 10));
        segments[1] = TM1637Display::encodeDigit((uint8_t)(ct.hours % 10));
        segments[2] = TM1637Display::encodeDigit((uint8_t)(ct.mins / 10));
        segments[3] = TM1637Display::encodeDigit((uint8_t)(ct.mins % 10));
    }
    else if (ct.mins > 0)
    {
        segments[0] = TM1637Display::encodeDigit((uint8_t)(ct.mins / 10));
        segments[1] = TM1637Display::encodeDigit((uint8_t)(ct.mins % 10));
        segments[2] = TM1637Display::encodeDigit((uint8_t)(ct.secs / 10));
        segments[3] = TM1637Display::encodeDigit((uint8_t)(ct.secs % 10));
    }
    else
    {
        segments[0] = TM1637Display::encodeDigit((uint8_t)(ct.secs / 10));
        segments[1] = TM1637Display::encodeDigit((uint8_t)(ct.secs % 10));
        segments[2] = TM1637Display::encodeDigit((uint8_t)(ct.ms / 100));
        segments[3] = TM1637Display::encodeDigit((uint8_t)(ct.ms / 10 % 10));
    }
    if (colon)
        segments[1] += 128;
    display.setSegments(segments);
}

void setup()
{
    BTNMinus.begin();
    BTNPlus.begin();
    BTNSet.begin();
    BTNShow.begin();
    RGBModeLed.begin();
}

void loop()
{
    /*
     *  Choosing the schedule from the timetable
     */
    display.setBrightness(DISPLAY_BRIGHTNESS, true);
    int schedule_index = 0;
    while (!BTNSet.isPressed())
    {
        if (BTNMinus.isPressed())
        {
            schedule_index--;
            while (BTNMinus.isPressed());
        }
        else if (BTNPlus.isPressed())
        {
            schedule_index++;
            while (BTNPlus.isPressed());
        }
        if (schedule_index < 0)
            schedule_index = schedules - 1;
        else if (schedule_index >= schedules)
            schedule_index = 0;
        display.showNumberDec(schedule_index + 1);
    }
    displayClockTime(msToClockTime(0), false);
    while (BTNSet.isPressed());
    while (!BTNSet.isPressed());
    while (BTNSet.isPressed());
    /*
     *  Looping through segments in the selected schedule
     */
    Mode mode = LessonBreakEnd;
    bool display_on = true;
    uint8_t rgb_byte = LESSON_BREAK_COLOR;
    RGBModeLed.set(rgb_byte);
    display.setBrightness(DISPLAY_BRIGHTNESS, display_on);
    for (int i = 0; i < segments; i++)
    {
        if (timetable[schedule_index][i].type == None)
            continue;
        unsigned long scheduleEnd_ms = 0;
        unsigned long nextLongBreak_ms = 0;
        bool isLongBreakQueued = false;
        for (int j = i; j < segments; j++)
        {
            if (timetable[schedule_index][j].type == None)
                break;
            scheduleEnd_ms += timetable[schedule_index][j].duration_ms;
            if (!isLongBreakQueued)
            {
                if (timetable[schedule_index][j].type == LongBreak)
                {
                    isLongBreakQueued = true;
                }
                else
                {
                    nextLongBreak_ms += timetable[schedule_index][j].duration_ms;
                }
            }
        }
        const unsigned long startTime = millis();
        for (;;)
        {
            unsigned long currentTime = millis() - startTime;
            if (currentTime > timetable[schedule_index][i].duration_ms)
                break;
            switch (mode)
            {
            case LessonBreakEnd:
                if (timetable[schedule_index][i].type == LessonBreak)
                    displayClockTime(msToClockTime(timetable[schedule_index][i].duration_ms - currentTime), true);
                else
                    display.clear();
                break;
            case LongBreakEnd:
                if (timetable[schedule_index][i].type == LongBreak)
                    displayClockTime(msToClockTime(timetable[schedule_index][i].duration_ms - currentTime), true);
                else if (isLongBreakQueued)
                    displayClockTime(msToClockTime(nextLongBreak_ms - currentTime), true);
                else
                    display.clear();
                break;
            case ScheduleEnd:
                displayClockTime(msToClockTime(scheduleEnd_ms - currentTime), true);
                break;
            }
            if (BTNMinus.isPressed() && BTNPlus.isPressed())
            {
                display.clear();
                RGBModeLed.set(0b00000000);
                return;
            }
            if (BTNSet.isPressed())
            {
                switch (mode)
                {
                case LessonBreakEnd:
                    mode = LongBreakEnd;
                    RGBModeLed.set(LONG_BREAK_COLOR);
                    break;
                case LongBreakEnd:
                    mode = ScheduleEnd;
                    RGBModeLed.set(SCHEDULE_END_COLOR);
                    break;
                case ScheduleEnd:
                    mode = LessonBreakEnd;
                    RGBModeLed.set(LESSON_BREAK_COLOR);
                    break;
                }
                while (BTNSet.isPressed());
            }
            else if (BTNShow.isPressed())
            {
                display_on = !display_on;
                display.setBrightness(DISPLAY_BRIGHTNESS, display_on);
                if (display_on)
                    RGBModeLed.set(rgb_byte);
                else
                    RGBModeLed.set(0b00000000);
                while (BTNShow.isPressed());
            }
        }
    }
}
