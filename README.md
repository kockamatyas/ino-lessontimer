# ino-lessontimer

Arduino program that counts down school lesson time

## Assembly

The following is required in order to assemble the device:

- Arduino Nano
- TM1637 display
- 4 buttons (**MINUS**, **PLUS**, **SET** and **SHOW**)
- An RGB led (+resistors, if required)

Assemble the component as described in the schematic file `kicad/ino-lessontimer/ino-lessontimer.kicad_sch`.
You can also use the PCB file (`kicad/ino-lessontimer/ino-lessontimer.kicad_pcb`) to make a circuit board.
If you want to change the pin bindings in the schematic or in the PCB, don't forget to do so in `Config.hpp`.

## Timetable

Follow the instructions in `sampleTimetable.hpp` to make your custom `Timetable.hpp` file.

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
