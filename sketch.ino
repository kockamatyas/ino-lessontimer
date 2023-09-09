#include "TM1637Display.h"

#define DISPLAY_CLK 2
#define DISPLAY_DIO 3
#define DISPLAY_BRIGHTNESS 7

TM1637Display display(DISPLAY_CLK, DISPLAY_DIO);

void setup() {
    display.setBrightness(DISPLAY_BRIGHTNESS);
}
void loop() {}