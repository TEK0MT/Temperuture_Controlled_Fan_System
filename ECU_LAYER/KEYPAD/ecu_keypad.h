/* 
 * File:   ecu_keypad.h
 * Author: Mohamed Tarek
 *
 * Created on August 15, 2024, 10:37 AM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H
/*Section : Include Section*/
#include "../../MCAL_LAYER/GPIO/mcal_gpio.h"
/*Section : Macro Declaration Section*/
#define KEYPAD_ROWS         4
#define KEYPAD_COLOUMNS     3
/*Section : Macro Functions Declaration Section*/
/*Section : Data Type Declaration Section*/
typedef struct{
    pin_config_t ROWS_PIN[KEYPAD_ROWS];
    pin_config_t COLOUMNS_PIN[KEYPAD_COLOUMNS];
}keypad_t;
/*Section : Functions Declaration Section*/
Std_ReturnType keypad_initialize(const keypad_t *keypad);
Std_ReturnType keypad_read_value(const keypad_t *keypad,uint8 *value);
#endif	/* ECU_KEYPAD_H */

