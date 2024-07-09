/* 
 * File:   ecu_motor_driver.c
 * Author: Mohamed Tarek
 *
 * Created on July 8, 2024, 8:29 PM
 */
#include "ecu_motor_driver.h"
Std_ReturnType motor_initialize(const motor_t *motor){
    Std_ReturnType ret = E_OK;
    if(motor == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_initialize(&(motor->pins[0]));
        ret = gpio_pin_initialize(&(motor->pins[1]));
    }
    return ret;
}
Std_ReturnType motor_turn_right(const motor_t *motor){
    Std_ReturnType ret = E_OK;
    if(motor == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(motor->pins[0]),GPIO_HIGH);
        ret = gpio_pin_write_logic(&(motor->pins[1]),GPIO_LOW);
    }
    return ret;
}
Std_ReturnType motor_turn_left(const motor_t *motor){
    Std_ReturnType ret = E_OK;
    if(motor == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(motor->pins[0]),GPIO_LOW);
        ret = gpio_pin_write_logic(&(motor->pins[1]),GPIO_HIGH);
    }
    return ret;
}
Std_ReturnType motor_turn_off(const motor_t *motor){
    Std_ReturnType ret = E_OK;
    if(motor == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(motor->pins[0]),GPIO_LOW);
        ret = gpio_pin_write_logic(&(motor->pins[1]),GPIO_LOW);
    }
    return ret;
}