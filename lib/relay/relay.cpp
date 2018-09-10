#include "relay.h"
#include "Arduino.h"


Relay::Relay(uint8_t p){
    pin = p;
    state = false;
    pinMode(pin, OUTPUT);
}

bool Relay::off(){
    digitalWrite(pin, 0);
    state = 0;
    return state;
}

bool Relay::on(){
    digitalWrite(pin, 1);
    state = 1;
    return state;
}

bool Relay::swap(){
    state = !state;
    digitalWrite(pin, state);
    return state;
}