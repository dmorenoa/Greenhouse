#ifndef lm35_h
#define lm35_h

#include <Arduino.h>
#include <com.h>

class LM35{
    public:
        LM35(int pin);
        bool execute(Com& com, Com& out);
    private:
        int pin;
};

#endif