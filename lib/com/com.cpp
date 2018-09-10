#include "relay.h"
#include "lm35.h"
#include "Arduino.h"
#include "com.h"

Com::Com(){
    cursor = 0;
}

bool Com::read(){
    if(inp.available()){
        uint8_t header = inp.read();
        if (header == 0x01){
            uint8_t head[3];
            inp.read(head, 3);
            uint8_t temp_origen = head[0];
            uint8_t temp_destino = head[1];
            uint8_t len = head[2];
            uint8_t temp_buffer[len+1];
            inp.readBytes(temp_buffer, len+1);
            uint8_t checksum = temp_buffer[len];
            uint16_t sum = 0;
            for(int i=0;i<len; i++){
                sum += temp_buffer[i];
            }
            sum = 0xFF - byte(sum);
            if(checksum == sum){
                origen = temp_origen;
                destino = temp_destino;
                for(int i=0; i<len; i++){
                    inp_buffer[i] = temp_buffer[i];
                }
                inp_data = len/3;
                return true;
            }
        }
    }
    return false;
}

uint8_t Com::task(uint8_t vec){
    uint8_t taskvec[len/2];
        for(int i=0;i<len; i++){
            if(i%2==0){
                continue;
            }
        else{
            taskvec[i/2-0.5] = len[i];
        }
    }
    return taskvec;
}

int8_t Com::calCheckSum(){
    byte sum = 0;
    for(int i=0;i<cursor; i++){
        sum+=buffer[i];
    }
    return byte(0xFF-sum);
}

bool Com::checkOrigin(uint8_t ori){
    return (origen == ori);
}

bool Com::checkDestination(uint8_t des){
    return (destino == des);
}