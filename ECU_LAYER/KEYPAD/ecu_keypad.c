/* 
 * File:   ecu_keypad.c
 * Author: Mohamed Tarek
 *
 * Created on August 15, 2024, 10:37 AM
 */
#include "ecu_keypad.h"


static const uint8 btn_values[KEYPAD_ROWS][KEYPAD_COLOUMNS] = {
                                                                {'1','2','3'},
                                                                {'4','5','6'},
                                                                {'7','8','9'},
                                                                {'*','0','#'}
                                                                };

Std_ReturnType keypad_initialize(const keypad_t *keypad){
    Std_ReturnType ret = E_OK;
    uint8 l_rows = ZERO_INIT;
    uint8 l_coloumns = ZERO_INIT;
    if(keypad == NULL){
        ret = E_NOT_OK;
    }
    else{
        for(l_rows = ZERO_INIT;l_rows < KEYPAD_ROWS;l_rows++){
            ret = gpio_pin_initialize(&(keypad->ROWS_PIN[l_rows]));
        }
        
        for(l_coloumns = ZERO_INIT;l_coloumns < KEYPAD_COLOUMNS;l_coloumns++){
            ret = gpio_pin_initialize(&(keypad->COLOUMNS_PIN[l_coloumns]));
        }
    }
    return ret;
}
Std_ReturnType keypad_read_value(const keypad_t *keypad,uint8 *value){
    Std_ReturnType ret = E_OK;
    uint8 l_rows = ZERO_INIT;
    uint8 l_coloumns = ZERO_INIT;
    uint8 counter = ZERO_INIT;
    uint8 val = ZERO_INIT;
    if(keypad == NULL){
        ret = E_NOT_OK;
    }
    else{
        for(l_rows = ZERO_INIT;l_rows < KEYPAD_ROWS;l_rows++){
            for(counter = ZERO_INIT;counter < KEYPAD_ROWS;counter++){
                ret = gpio_pin_write_logic(&(keypad->ROWS_PIN[counter]),GPIO_LOW);
            }
            ret = gpio_pin_write_logic(&(keypad->ROWS_PIN[l_rows]),GPIO_HIGH);
            __delay_ms(10);
            for(l_coloumns = ZERO_INIT;l_coloumns < KEYPAD_COLOUMNS;l_coloumns++){
                ret = gpio_pin_read_logic(&(keypad->COLOUMNS_PIN[l_coloumns]),&val);
                if(val == GPIO_HIGH){
                    *value = btn_values[l_rows][l_coloumns];
                }
                else{/*NOTHING*/}
            }
        }
        
        
    }
    return ret;
}