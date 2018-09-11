#ifndef com_h
#define com_h

#include <Arduino.h>

#define INIT 0x23
#define SET_LM_35 0x50
#define GET_TEMP 0x51
#define SET_RELAY 0x52

class Com{
    public:
        Com(uint8_t dir);
        bool read(Stream& inp, uint8_t check = 0);
        void send(Stream& inp, uint8_t dest= 0);
        int8_t checkCmd(uint8_t cmd);
        uint8_t getArgs(uint8_t cmd);
        uint8_t addCmd(uint8_t cmd, uint8_t data);
    private:
        uint8_t len;
        uint8_t inp_buffer[90];
        uint8_t dir;
        int8_t calCheckSum();
        bool relaystate;
        float temp;
        uint8_t cursor;
        uint8_t buffer[90];
};

#endif