#ifndef relay_h
#define relay_h

#include <Arduino.h>

class Relay{
    public:
        Relay(uint8_t pin);
        bool on();
        bool off();
        bool swap();
    private:
        bool state;
        uint8_t pin;
};

#endif