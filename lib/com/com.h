#ifndef com_h
#define com_h

#include <Arduino.h>

class Com{
    public:
        Com();
        bool read();
        bool checkOrigin(uint8_t ori);
        bool checkDestination(uint8_t des);
        uint8_t task(uint8_t vec);
    private:
        int8_t calCheckSum();
        bool relaystate;
        float temp;
        uint8_t cursor;
        uint8_t buffer[90];
        uint8_t origen;
        uint8_t destino;
        uint8_t len;
        uint8_t inp_buffer[90];
        uint8_t inp_data;
};

#endif