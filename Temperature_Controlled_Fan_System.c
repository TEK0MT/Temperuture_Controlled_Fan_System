/* 
 * File:   Temperature_Controlled_Fan_System.c
 * Author: Mohamed Tarek
 *
 * Created on July 7, 2024, 11:07 PM
 */
#include "Temperature_Controlled_Fan_System.h"
pin_config_t pin = {.port = PORTC_INDEX,.pin = PIN0,.logic = GPIO_HIGH,.direction = GPIO_DIRECTION_OUTPUT};
pin_config_t pin2 = {.port = PORTC_INDEX,.pin = PIN1,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_INPUT};
logic_t logic;
direction_t direction;
int main() {
gpio_port_direction_initialize(PORTC_INDEX,0xed);
gpio_port_direction_initialize(PORTD_INDEX,GPIO_DIRECTION_INPUT);
while(1){
    __delay_ms(1000);
gpio_port_write_logic(PORTC_INDEX,0xed);
gpio_port_read_logic(PORTC_INDEX,&logic);
gpio_get_port_direction(PORTC_INDEX,&direction);
   __delay_ms(1000);
gpio_port_write_logic(PORTC_INDEX,GPIO_LOW);
gpio_port_read_logic(PORTC_INDEX,&logic);
gpio_get_port_direction(PORTC_INDEX,&direction);
}
    return (EXIT_SUCCESS);
}

