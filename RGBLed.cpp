#include <Arduino.h>
#include "RGBLed.hpp"

RGBLed::RGBLed(uint8_t red, uint8_t green, uint8_t blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void RGBLed::begin()
{
    pinMode(this->red, OUTPUT);
    pinMode(this->green, OUTPUT);
    pinMode(this->blue, OUTPUT);
}

void RGBLed::set(uint8_t rgb)
{
    if (rgb & (1 << 3))
        digitalWrite(this->red, HIGH);
    else
        digitalWrite(this->red, LOW);
    if (rgb & (1 << 2))
        digitalWrite(this->green, HIGH);
    else
        digitalWrite(this->green, LOW);
    if (rgb & (1 << 1))
        digitalWrite(this->blue, HIGH);
    else
        digitalWrite(this->blue, LOW);
}
