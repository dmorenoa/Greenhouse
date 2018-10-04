#include "Arduino.h"
#include "com.h"

Com::Com(uint8_t self_dir)
{
    dir = self_dir;
    cursor = 0;
}

bool Com::read(Stream &inp, uint8_t check = 0)
{
    if (inp.available())
    {
        uint8_t header = inp.read();
        if (header == INIT)
        {
            uint8_t head[3];
            inp.readBytes(head, 3);
            uint8_t temp_origen = head[0];  // Read Origin
            uint8_t temp_destino = head[1]; // Read Destination
            uint8_t temp_len = head[2];          // Lenght of the Payload

            uint8_t temp_buffer[temp_len + 1]; // Temporal Buffer

            inp.readBytes(temp_buffer, temp_len + 1);
            uint8_t checksum = temp_buffer[temp_len];
            uint16_t sum = 0;
            for (int i = 0; i < temp_len; i++)
            {
                sum += temp_buffer[i];
            }
            sum = 0xFF - byte(sum);

            bool check_destination = (temp_destino == dir || !temp_destino);
            bool check_origin = (check == temp_origen || !check);
            bool check_sum = (checksum == sum);
            if (check_sum && check_destination && check_origin)
            {
                for (int i = 0; i < temp_len; i++)
                {
                    inp_buffer[i] = temp_buffer[i];
                }
                len = temp_len;
                return true;
            }
        }
    }
    return false;
}

int8_t Com::checkCmd(uint8_t cmd){
    for(int i=0; i<len; i+=2)
    {
        if(inp_buffer[i] == cmd){
            return i;
        }
    }
    return -1;
}

uint8_t Com::getArgs(uint8_t cmd){
    uint8_t index = checkCmd(cmd);
    if(index != -1){
        uint8_t temp_buffer[len];
        for(int i=0; i<len; i++){
            temp_buffer[i] = inp_buffer[i];
        }
        for(int i = 0; i<len-2; i++){
            if(i < index){
                inp_buffer[i] = temp_buffer[i];
            } else {
                inp_buffer[i] = temp_buffer[i+2];
            }
        }
        len-=2;
        return temp_buffer[index+1];
    }
    return 0;
}

int8_t Com::calCheckSum()
{
    byte sum = 0;
    for (int i = 0; i < cursor; i++)
    {
        sum += buffer[i];
    }
    return byte(0xFF - sum);
}

uint8_t Com::addCmd(uint8_t cmd, uint8_t data){
    buffer[cursor] = cmd;
    buffer[cursor + 1] = data;
    cursor+=2;
    return cursor;
}

void Com::send(Stream &inp, uint8_t dest = 0)
{
    inp.write(INIT);
    inp.write(dir);
    inp.write(dest);
    inp.write(cursor);
    for(int i = 0; i<cursor; i++){
        inp.write(buffer[i]);
    }
    inp.write(calCheckSum());
    cursor = 0;
}