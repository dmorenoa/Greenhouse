#include "LM35.h"
#include "Arduino.h"

uint8_t LM35::pinsetup(uint8_t pinnum){
    pinMode(pinnum, OUTPUT);
    uint8_t lm35_pin = pinnum;
}

float LM35::gettemp(){
    float temp = (float(analogRead(lm35_pin))*5/1023/0.001);
    return temp;
}
