#include <Arduino.h>
#include <LM35.h>
#include <relay.h>

#define serialrate 115200
int pinlm35 = 0;
int relaypin = 50;

void setup() {
    Serial.begin(serialrate);
    LM35.pinsetup(pinlm35);
    //analogReference(INTERNAL);
    relay.pinsetup(relaypin);
}

void loop(){

}