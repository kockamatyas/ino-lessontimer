#include "Button.hpp"
#include <Arduino.h>

Button::Button(uint8_t pin)
{
    this->pin = pin;
}

void Button::begin()
{
    pinMode(this->pin, INPUT_PULLUP);
}

bool Button::isPressed()
{
    return digitalRead(this->pin);
}

void Button::awaitPress(bool release = true)
{
    if (release)
        while (isPressed());
    while (!isPressed());
}