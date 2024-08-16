/* 
 * File:   Temperature_Controlled_Fan_System.h
 * Author: Mohamed Tarek
 *
 * Created on July 7, 2024, 11:08 PM
 */

#ifndef TEMPERATURE_CONTROLLED_FAN_SYSTEM_H
#define	TEMPERATURE_CONTROLLED_FAN_SYSTEM_H
/*Section : Include Section*/
#include "ECU_LAYER/ECU_LAYER.h"
#include "MCAL_LAYER/MCAL_LAYER.h"
/*Section : Macro Declaration Section*/
/*Section : Macro Functions Declaration Section*/
/*Section : Data Type Declaration Section*/
extern motor_t motor1;
extern motor_t motor2;
extern adc_t adc;
extern lcd_4bits_t lcd;
extern keypad_t keypad;
extern pin_config_t pin1;
extern pin_config_t pin2;
extern pin_config_t pin3;
extern pin_config_t pin4;
extern pin_config_t pin5;
extern pin_config_t pin6;
extern pin_config_t pin7;
extern pin_config_t pin8;
/*Section : Functions Declaration Section*/
void apllication_initilaize(void);
#endif	/* TEMPERATURE_CONTROLLED_FAN_SYSTEM_H */

