/* 
 * File:   Temperature_Controlled_Fan_System.c
 * Author: Mohamed Tarek
 *
 * Created on July 7, 2024, 11:07 PM
 */
#include "Temperature_Controlled_Fan_System.h"
void isr(void){
    gpio_pin_toggle_logic(&pin1);
}
INTX_T int1 = {.source = RISING_EDGE,.EXT_HANDLER = isr};
int main() {
    apllication_initilaize();
   Enable_INTX(&int1);
while(1){
    
    
}
    return (EXIT_SUCCESS);
}
void apllication_initilaize(void){
    ecu_initialzie();
}

