#ifndef RGBLED_H
#define RGBLED_H

#include <Arduino.h>

#define RED 0b00000100
#define GREEN 0b00000010
#define BLUE 0b00000001

class RGBLed
{
public:
    RGBLed(uint8_t red, uint8_t green, uint8_t blue);
    void begin();
    void set(uint8_t rgb);
private:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

#endif
