#include <Arduino.h>
#include <com.h>
#include <relay.h>
#include <LM35.h>

#define SET_LM_35 0x50
#define GET_TEMP 0x51
#define SET_RELAY 0x52
#define WR_RELAY 0x56
#define RE_RELAY 0x57

Com com = Com(0xAA);
Relay rl = Relay(22);
LM35 sen = LM35(1);

void setup() {
    Serial.begin(9600);
}

// 0x23 0xAA 0x00 0x06 0x50 0x0A 0x51 0x00 0x52 0x01 0x01

void loop(){
    if(com.read(Serial)){
        Com output = Com(0xAA);
        rl.execute(com, output);
        sen.execute(com, output);
        output.send(Serial);
    }
}