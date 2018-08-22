#include <Arduino.h>
#include <LM35.h>
#include <relay.h>

#define serialrate 115200
#define pinlm35 0 
#define relaypin 50

void setup() {
    Serial.begin(serialrate);
    LM35.pinsetup(pinlm35);
    //analogReference(INTERNAL);
    relay.pinsetup(uint8_t relaypin);
}

void loop(){

}