#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button
{
public:
    Button(uint8_t pin);
    void begin();
    bool isPressed();
    void awaitPress(bool release = true);
private:
    uint8_t pin;
};

#endif