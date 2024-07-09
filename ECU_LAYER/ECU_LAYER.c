/* 
 * File:   ECU_LAYER.c
 * Author: Mohamed Tarek
 *
 * Created on July 8, 2024, 5:27 AM
 */
#include "ECU_LAYER.h"

motor_t motor1 = {.pins[0].port = PORTB_INDEX,.pins[0].pin = PIN0,.pins[0].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
                   .pins[1].port = PORTB_INDEX,.pins[1].pin = PIN1,.pins[1].logic = GPIO_LOW,.pins[1].direction = GPIO_DIRECTION_OUTPUT};

motor_t motor2 = {.pins[0].port = PORTB_INDEX,.pins[0].pin = PIN2,.pins[0].logic = GPIO_LOW,.pins[0].direction = GPIO_DIRECTION_OUTPUT,
                   .pins[1].port = PORTB_INDEX,.pins[1].pin = PIN3,.pins[1].logic = GPIO_LOW,.pins[1].direction = GPIO_DIRECTION_OUTPUT};
void ecu_initialzie(void){
    motor_initialize(&motor1);
    motor_initialize(&motor2);
}
