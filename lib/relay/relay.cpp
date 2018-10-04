#include "relay.h"
#include "Arduino.h"

#define SET_RELAY 0x52
#define WR_RELAY 0x53
#define RE_RELAY 0x54

Relay::Relay(uint8_t p){
    pin = p;
    state = false;
    pinMode(pin, OUTPUT);
}

bool Relay::execute(Com& inp, Com& out){
    bool exc = false;
    if(inp.checkCmd(SET_RELAY) != -1){
        pin = inp.getArgs(SET_RELAY);
        pinMode(pin, OUTPUT);
        out.addCmd(SET_RELAY,0x01);
        exc = true;
    }
    if(inp.checkCmd(WR_RELAY) != -1){
        uint8_t value = inp.getArgs(WR_RELAY);
        switch (value) {
            case 0:
                state = 0;
                break;
            case 1:
                state = 1;
                break;
            case 2:
                state = !state;
                break;
        }
        digitalWrite(pin, state);
        out.addCmd(WR_RELAY,state);
        exc = true;
    }
    if(inp.checkCmd(RE_RELAY) != -1){
        out.addCmd(RE_RELAY, state);
        exc = true;
    }

    return exc;
}