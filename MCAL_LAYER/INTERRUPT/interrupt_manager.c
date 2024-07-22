/* 
 * File:   interrupt_manager.
 * Author: Mohamed Tarek
 *
 * Created on July 18, 2024, 12:41 AM
 */
#include "interrupt_manager.h"
void  __interrupt() InterruptManager(void){
    if((INTCONbits.INTE == INTERRUPT_ENABLED) && (INTCONbits.INTF == INTERRUPT_OCCURED) ){
        ISR_INTX();
    }
}