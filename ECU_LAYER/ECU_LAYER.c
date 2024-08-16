/* 
 * File:   ECU_LAYER.c
 * Author: Mohamed Tarek
 *
 * Created on July 8, 2024, 5:27 AM
 */
#include "ECU_LAYER.h"

keypad_t keypad = {.ROWS_PIN[0].port = PORTB_INDEX,.ROWS_PIN[0].pin = PIN0,.ROWS_PIN[0].direction = GPIO_DIRECTION_OUTPUT,.ROWS_PIN[0].logic = GPIO_LOW,
                   .ROWS_PIN[1].port = PORTB_INDEX,.ROWS_PIN[1].pin = PIN1,.ROWS_PIN[1].direction = GPIO_DIRECTION_OUTPUT,.ROWS_PIN[1].logic = GPIO_LOW,
                   .ROWS_PIN[2].port = PORTB_INDEX,.ROWS_PIN[2].pin = PIN2,.ROWS_PIN[2].direction = GPIO_DIRECTION_OUTPUT,.ROWS_PIN[2].logic = GPIO_LOW,
                   .ROWS_PIN[3].port = PORTB_INDEX,.ROWS_PIN[3].pin = PIN3,.ROWS_PIN[3].direction = GPIO_DIRECTION_OUTPUT,.ROWS_PIN[3].logic = GPIO_LOW,
                   .COLOUMNS_PIN[0].port = PORTB_INDEX,.COLOUMNS_PIN[0].pin = PIN4,.COLOUMNS_PIN[0].direction = GPIO_DIRECTION_INPUT,.COLOUMNS_PIN[0].logic = GPIO_LOW,
                   .COLOUMNS_PIN[1].port = PORTB_INDEX,.COLOUMNS_PIN[1].pin = PIN5,.COLOUMNS_PIN[1].direction = GPIO_DIRECTION_INPUT,.COLOUMNS_PIN[1].logic = GPIO_LOW,
                   .COLOUMNS_PIN[2].port = PORTB_INDEX,.COLOUMNS_PIN[2].pin = PIN6,.COLOUMNS_PIN[2].direction = GPIO_DIRECTION_INPUT,.COLOUMNS_PIN[2].logic = GPIO_LOW,};




motor_t motor1 = {.pins[0].port = PORTD_INDEX,.pins[0].pin = PIN0,.pins[0].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
                   .pins[1].port = PORTD_INDEX,.pins[1].pin = PIN1,.pins[1].logic = GPIO_LOW,.pins[1].direction = GPIO_DIRECTION_OUTPUT};

motor_t motor2 = {.pins[0].port = PORTD_INDEX,.pins[0].pin = PIN2,.pins[0].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
                   .pins[1].port = PORTD_INDEX,.pins[1].pin = PIN3,.pins[1].logic = GPIO_LOW,.pins[1].direction = GPIO_DIRECTION_OUTPUT};


lcd_4bits_t lcd = {.rs.port = PORTC_INDEX,.rs.pin = PIN0,.rs.logic = GPIO_LOW,.rs.direction = GPIO_DIRECTION_OUTPUT,
                   .en.port = PORTC_INDEX,.en.pin = PIN1,.en.logic = GPIO_LOW,.en.direction = GPIO_DIRECTION_OUTPUT,
                   .pins[0].port = PORTC_INDEX,.pins[0].pin = PIN2,.pins[0].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
                   .pins[1].port = PORTC_INDEX,.pins[1].pin = PIN3,.pins[1].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
                   .pins[2].port = PORTC_INDEX,.pins[2].pin = PIN4,.pins[2].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
                   .pins[3].port = PORTC_INDEX,.pins[3].pin = PIN5,.pins[3].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT};
void ecu_initialzie(void){
    motor_initialize(&motor1);
    motor_initialize(&motor2);
    keypad_initialize(&keypad);
    lcd_4bits_initialize(&lcd);
}
