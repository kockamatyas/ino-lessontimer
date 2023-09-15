# ino-lessontimer

Arduino program that counts down school lesson time

## Usage

Lessontimer has two phases.

### Selection

Use the **PLUS** and **MINUS** buttons to select a day in the timetable. Then confirm the selection by  
pressing the **SET** button. Press the **SET** button one more time exactly at the beginning of the schedule.

### Countdown

After starting the countdown, you can select three modes, which you can switch between with the **SET** button. In each mode, the display can be turned on or off with the **SHOW** button. Leaving the display on even when not in active use may result in the device turning off prematurely due to low battery.

#### Lesson/break mode

After switching to this mode, you will see the time remaining until the end of the lesson/break, if the current segment is not a lesson/break, the display is blank.

#### Long break mode

When there is no longbreak currently in progress, you will see the time remaining until the longbreak starts. You will then see the time remaining until the end of the longbreak. After this time, the display will be blank.

#### Schedule end mode

Countdown to the end of the schedule.

## Library notice

This project uses the TM1637, a third-party library, which is distributed under the terms of the GNU Lesser General Public License (LGPL) version 3.  
You can find more information about the library and its licensing terms at <https://github.com/avishorp/TM1637>.
