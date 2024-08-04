/* 
 * File:   ECU_LAYER.c
 * Author: Mohamed Tarek
 *
 * Created on July 8, 2024, 5:27 AM
 */
#include "ECU_LAYER.h"
pin_config_t pin1 = {.port =PORTD_INDEX,.pin = PIN0,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin2 = {.port =PORTD_INDEX,.pin = PIN1,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin3 = {.port =PORTD_INDEX,.pin = PIN2,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin4 = {.port =PORTD_INDEX,.pin = PIN3,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin5 = {.port =PORTD_INDEX,.pin = PIN4,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin6 = {.port =PORTD_INDEX,.pin = PIN5,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin7 = {.port =PORTD_INDEX,.pin = PIN6,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin8 = {.port =PORTD_INDEX,.pin = PIN7,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_OUTPUT};
motor_t motor1 = {.pins[0].port = PORTB_INDEX,.pins[0].pin = PIN0,.pins[0].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
                   .pins[1].port = PORTB_INDEX,.pins[1].pin = PIN1,.pins[1].logic = GPIO_LOW,.pins[1].direction = GPIO_DIRECTION_OUTPUT};

motor_t motor2 = {.pins[0].port = PORTB_INDEX,.pins[0].pin = PIN2,.pins[0].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
                   .pins[1].port = PORTB_INDEX,.pins[1].pin = PIN3,.pins[1].logic = GPIO_LOW,.pins[1].direction = GPIO_DIRECTION_OUTPUT};


lcd_4bits_t lcd = {.rs.port = PORTC_INDEX,.rs.pin = PIN0,.rs.logic = GPIO_LOW,.rs.direction = GPIO_DIRECTION_OUTPUT,
                   .en.port = PORTC_INDEX,.en.pin = PIN1,.en.logic = GPIO_LOW,.en.direction = GPIO_DIRECTION_OUTPUT,
                   .pins[0].port = PORTC_INDEX,.pins[0].pin = PIN2,.pins[0].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
                   .pins[1].port = PORTC_INDEX,.pins[1].pin = PIN3,.pins[1].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
                   .pins[2].port = PORTC_INDEX,.pins[2].pin = PIN4,.pins[2].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
                   .pins[3].port = PORTC_INDEX,.pins[3].pin = PIN5,.pins[3].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT};
void ecu_initialzie(void){
    gpio_pin_initialize(&pin1);
    /*motor_initialize(&motor1);
    motor_initialize(&motor2);*/
    gpio_pin_initialize(&pin2);/*
    gpio_pin_initialize(&pin3);
    gpio_pin_initialize(&pin4);
    gpio_pin_initialize(&pin5);
    gpio_pin_initialize(&pin6);
    gpio_pin_initialize(&pin7);
    gpio_pin_initialize(&pin8);
    
    lcd_4bits_initialize(&lcd);*/
}
