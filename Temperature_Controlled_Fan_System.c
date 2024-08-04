/* 
 * File:   Temperature_Controlled_Fan_System.c
 * Author: Mohamed Tarek
 *
 * Created on July 7, 2024, 11:07 PM
 */
#include "Temperature_Controlled_Fan_System.h"
uint8 counter = 0;
void isr(void){
    gpio_pin_toggle_logic(&pin1);
    counter++;
}

void rb_isr(void){
    gpio_pin_toggle_logic(&pin2);
}

INTX_T int1 = {.source = RISING_EDGE,.EXT_HANDLER = isr};
RBX_t rb2 = {.pin.port = PORTB_INDEX,.pin.pin = PIN4,.pin.logic = GPIO_LOW,.pin.direction = GPIO_DIRECTION_INPUT,.EXT_HIGH_INTERRUPT = rb_isr,.EXT_LOW_INTERRUPT = rb_isr};

int main() {
    apllication_initilaize();
   Enable_INTX(&int1);
   Enable_RBX(&rb2);
    READ_DATA_EEPROM(0x00,&counter);
while(1){
    
    WRITE_DATA_EEPROM(0x00,counter);
}
    return (EXIT_SUCCESS);
}
void apllication_initilaize(void){
    ecu_initialzie();
}

