#ifndef lm35_h
#define lm35_h

#include <Arduino.h>

class LM35{
    public:
        LM35(int pin);
        float gettemp();
    private:
        int pin;
};

#endif