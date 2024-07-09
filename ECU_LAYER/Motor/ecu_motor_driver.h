/* 
 * File:   ecu_motor_driver.h
 * Author: Mohamed Tarek
 *
 * Created on July 8, 2024, 8:29 PM
 */

#ifndef ECU_MOTOR_DRIVER_H
#define	ECU_MOTOR_DRIVER_H
/*Section : Include Section*/
#include "../../MCAL_LAYER/GPIO/mcal_gpio.h"
/*Section : Macro Declaration Section*/
/*Section : Macro Functions Declaration Section*/
/*Section : Data Type Declaration Section*/



typedef struct{
    pin_config_t pins[2];
}motor_t;
/*Section : Functions Declaration Section*/
Std_ReturnType motor_initialize(const motor_t *motor);
Std_ReturnType motor_turn_right(const motor_t *motor);
Std_ReturnType motor_turn_left(const motor_t *motor);
Std_ReturnType motor_turn_off(const motor_t *motor);
#endif	/* ECU_MOTOR_DRIVER_H */

