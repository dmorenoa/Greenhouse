#ifndef relay_h
#define relay_h

#include <Arduino.h>

class relay{
    public:
        int pinsetup(int relaypin);
        bool onrelay(uint8_t relay_pin);
        bool offrelay(uint8_t relay_pin);
    private:
        uint8_t relaypin();
};

#endif