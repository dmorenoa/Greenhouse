#ifndef relay_h
#define relay_h

#include <Arduino.h>
#include <com.h>

class Relay{
    public:
        Relay(uint8_t pin);
        bool execute(Com& com, Com& out);
    private:
        bool state;
        uint8_t pin;
};

#endif