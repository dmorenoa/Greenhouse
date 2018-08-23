#include "relay.h"
#include "Arduino.h"

int relay::pinsetup(int r_pinnum){
    pinMode(r_pinnum, OUTPUT);
    //int relay_pin = r_pinnum;
    //return relay_pin;
}

bool relay::onrelay(uint8_t relay_pin){
    digitalWrite(relay_pin, HIGH);
    bool estadorelay = true;
    return estadorelay;
}

bool relay::offrelay(uint8_t relay_pin){
    digitalWrite(relay_pin, LOW);
    bool estadorelay = false;
    return estadorelay;
}