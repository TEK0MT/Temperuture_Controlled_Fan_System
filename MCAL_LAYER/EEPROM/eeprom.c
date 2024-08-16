/* 
 * File:   eeprom.c
 * Author: Mohamed Tarek
 *
 * Created on August 4, 2024, 11:52 AM
 */

#include "eeprom.h"

Std_ReturnType WRITE_DATA_EEPROM(uint16 add,uint8 data){
    uint8 status = INTCONbits.GIE;
    ACCESS_MEMORY();
    EEADR = (add & 0xFF);
    EEDATA = data;
    ENABLE_WRITE();
    DISABLE_ALL_INTERRUPT();
    
    EECON2 = 0x55;
    EECON2 = 0xAA;
    
    START_STORING();
    while(EECON1bits.WR);
    INHIBIT_WRITE();
    INTCONbits.GIE = status;
}
Std_ReturnType READ_DATA_EEPROM(uint16 add,uint8 *data){
    EEADR = (add & 0xFF);
    ACCESS_MEMORY();
    ENABLE_READ();
    NOP();
    NOP();
    *data = EEDATA;
}
