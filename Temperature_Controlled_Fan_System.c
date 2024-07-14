/* 
 * File:   Temperature_Controlled_Fan_System.c
 * Author: Mohamed Tarek
 *
 * Created on July 7, 2024, 11:07 PM
 */
#include "Temperature_Controlled_Fan_System.h"
const uint8  customChar[] = {
  0x00,
  0x0E,
  0x11,
  0x11,
  0x0E,
  0x00,
  0x00,
  0x00
};
int main() {
    apllication_initilaize();
    uint32 counter = 0;
    uint8 str[11];
    //lcd_4bits_send_string_pos(&lcd,2,10,"HOLA");
while(1){
    /*motor_turn_right(&motor1);
    motor_turn_left(&motor2);
    __delay_ms(2000);
    motor_turn_right(&motor2);
    motor_turn_left(&motor1);
    __delay_ms(2000);
    motor_turn_off(&motor1);
    motor_turn_off(&motor2);
    __delay_ms(2000);*/
   
   /* gpio_pin_write_logic(&pin1,GPIO_HIGH);
    gpio_pin_write_logic(&pin2,GPIO_HIGH);
    gpio_pin_write_logic(&pin3,GPIO_HIGH);
    gpio_pin_write_logic(&pin4,GPIO_HIGH);
    gpio_pin_write_logic(&pin5,GPIO_HIGH);
    gpio_pin_write_logic(&pin6,GPIO_HIGH);
    gpio_pin_write_logic(&pin7,GPIO_HIGH);
    gpio_pin_write_logic(&pin8,GPIO_HIGH);
    __delay_ms(1000);
    gpio_pin_write_logic(&pin1,GPIO_LOW);
    gpio_pin_write_logic(&pin2,GPIO_LOW);
    gpio_pin_write_logic(&pin3,GPIO_LOW);
    gpio_pin_write_logic(&pin4,GPIO_LOW);
    gpio_pin_write_logic(&pin5,GPIO_LOW);
    gpio_pin_write_logic(&pin6,GPIO_LOW);
    gpio_pin_write_logic(&pin7,GPIO_LOW);
    gpio_pin_write_logic(&pin8,GPIO_LOW);
    __delay_ms(1000);*/
    Convert_uint32_to_string(counter,str);
    lcd_4bits_send_string_pos(&lcd,1,1,str);
    lcd_4bit_custom_character(&lcd,1,10,customChar,0);
    __delay_ms(500);
    counter++;
    
}
    return (EXIT_SUCCESS);
}
void apllication_initilaize(void){
    ecu_initialzie();
}

