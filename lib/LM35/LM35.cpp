#include "LM35.h"
#include "Arduino.h"

LM35::LM35(int p){
    pin = p;
    pinMode(pin, INPUT);
}

float LM35::gettemp(){
    float temp = ((float(analogRead(pin))/(1023))*5)/0.01;
    Serial.println(analogRead(pin));
    return temp;
}
