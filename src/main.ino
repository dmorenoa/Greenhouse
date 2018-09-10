#include <Arduino.h>
#include <lm35.h>
#include <relay.h>
#include <com.h>

Com com();
Relay relay = Relay(50);
LM35 lm35 = LM35(A1);
int tf = 0;

void setup() {
    Serial.begin(9600);
    relay.off();
}

void loop(){
    int tini = millis();
    if((tini - tf)> 2000){
        tf = tini;
        float temp = lm35.gettemp();
        Serial.println(temp);
        if(temp>=30){
            relay.on();
        }
        else if(temp<30){
            relay.off();
        }
    }
}