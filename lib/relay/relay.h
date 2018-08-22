#ifndef relay_h
#define relay_h

#include <Arduino.h>

class relay{
    public:
        int pinsetup(int relaypin);
        bool onrelay();
        bool offrelay();
    private:
        uint8_t relaypin();
};

#endif