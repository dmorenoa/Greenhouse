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
    uint8_t numvec[len/2];
        for(float i=0;i<len; i++){
            if(i%2==0){
                numvec[i/2]=len[i];
            }
            else{
                taskvec[i/2-0.5] = len[i];
        }
    }
    return taskvec,numvec;
}

uint8_t Com::taskexec(uint8_t vect, uint8_t numv){
    for(int i=0;i<len/2;i++){
        uint8_t tarea = vect[i];
        if(tarea == 0x50 ){
            try{
                LM35::LM35(numv[i]);
            }
            catch{
                numv[i]= 0x00;
            }
            numv[i]= 0x01;
        }
        else if(tarea == 0x51 ){
            try{
                uint8_t temp = LM35::gettemp();
            }
            catch{
                numv[i]= 0x00;
            }
            numv[i]= temp;
        }
        else if(tarea == 0x52 ){
            try{
                Relay::Relay(numv[i]);
            }
            catch{
                numv[i]= 0x00;
            }
            numv[i]= 0x01;
        }
        else if(tarea == 0x53 ){
            try{
                Relay::on() ;
            }
            catch{
                numv[i]= 0x00;
            }
            numv[i]= 0x01;
        }
        else if(tarea == 0x54 ){
            try{
                Relay::off() ;
            }
            catch{
                numv[i]= 0x00;
            }
            numv[i]= 0x01;
        }
        else if(tarea == 0x55 ){
            try{
                Relay::swap() ;
            }
            catch{
                numv[i]= 0x00;
            }
            numv[i]= 0x01;
        }
        else{

        }
    }
    return numv;
}

int8_t Com::calCheckSum(){
    byte sum = 0;
    for(int i=0;i<cursor; i++){
        sum+=buffer[i];
    }
    return byte(0xFF-sum);
}

bool Com::send(uint8_t vect, uint8_t numv, uint8_t dest){
    inp.write(0x01);
    inp.write(0x03);  //origen= 0x003 -> Arduino
    inp.write(dest);
    inp.write(len);
    for(int i=0;i<len/2;i++){
        inp.write(vect[i]);
        inp.write(numv[i]);
        buffer[2*i] = vect[i];
        buffer[2*i+1] = numv[i];
    }
    inp.write(calCheckSum());
    clear();
}

bool Com::checkOrigin(uint8_t ori){
    return (origen == ori);
}

bool Com::checkDestination(uint8_t des){
    return (destino == des);
}