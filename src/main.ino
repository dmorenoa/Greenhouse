#include <Arduino.h>
// #include <lm35.h>
// #include <relay.h>
#include <com.h>

Com com = Com(0xAA);

void setup() {
    Serial.begin(9600);
}

// 0x23 0xAA 0x00 0x06 0x50 0x0A 0x51 0x00 0x52 0x01 0x01

void loop(){
    if(com.read(Serial)){
        if(com.checkCmd(SET_LM_35) != -1){
            Serial.print("LM35: ");Serial.println(com.getArgs(SET_LM_35));
        }
        if(com.checkCmd(SET_LM_35) != -1){
            Serial.print("LM35: ");Serial.println(com.getArgs(SET_LM_35));
        }
        if(com.checkCmd(SET_LM_35) != -1){
            Serial.print("LM35: ");Serial.println(com.getArgs(SET_LM_35));
        } 
        else {
            Serial.print("404");
        }
    }

    // com.addCmd(SET_LM_35, 10);
    // com.addCmd(SET_LM_35, 20);
    // com.send(Serial);
    // while(1){
    //     ;
    // }
}