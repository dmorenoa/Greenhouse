#ifndef LM35_h
#define LM35_h

#include <Arduino.h>

class LM35{
    public:
        uint8_t pinsetup(uint8_t pinnum);
        float gettemp();
        bool lm35refsetup();
    private:
        uint8_t lm35_pin;
};

#endif