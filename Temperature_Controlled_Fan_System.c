/* 
 * File:   Temperature_Controlled_Fan_System.c
 * Author: Mohamed Tarek
 *
 * Created on July 7, 2024, 11:07 PM
 */
#include "Temperature_Controlled_Fan_System.h"

int main() {
    apllication_initilaize();

while(1){
    lcd_4bits_send_char(&lcd,'f');
    /*motor_turn_right(&motor1);
    motor_turn_left(&motor2);
    __delay_ms(2000);
    motor_turn_right(&motor2);
    motor_turn_left(&motor1);
    __delay_ms(2000);
    motor_turn_off(&motor1);
    motor_turn_off(&motor2);
    __delay_ms(2000);*/
}
    return (EXIT_SUCCESS);
}
void apllication_initilaize(void){
    ecu_initialzie();
}

