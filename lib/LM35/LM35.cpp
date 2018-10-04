#include "LM35.h"
#include "Arduino.h"

#define SET_LM_35 0x50
#define GET_TEMP 0x51

LM35::LM35(int p){
    pin = p;
    pinMode(pin, INPUT);
}

bool LM35::execute(Com& inp, Com& out){
    bool exc = false;
    if(inp.checkCmd(SET_LM_35) != -1){
        pin = inp.getArgs(SET_LM_35);
        pinMode(pin, INPUT);
        out.addCmd(SET_LM_35,0x01);
        exc = true;
    }
    if(inp.checkCmd(GET_TEMP) != -1){
        uint8_t temp = analogRead(pin);
        out.addCmd(GET_TEMP,temp);
        exc = true;
    }
    return exc;
}