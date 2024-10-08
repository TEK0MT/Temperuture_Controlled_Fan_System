/* 
 * File:   interrupt_manager.
 * Author: Mohamed Tarek
 *
 * Created on July 18, 2024, 12:41 AM
 */
#include "interrupt_manager.h"

static uint8 counter = 0;
#if INTERRUPT_ENABLED
void  __interrupt() InterruptManager(void){
    if((INTCONbits.INTE == INTERRUPT_ENABLED) && (INTCONbits.INTF == INTERRUPT_OCCURED) ){
        ISR_INTX();
    }
    else{/*Nothing*/}
    
    
    if((INTCONbits.RBIE == INTERRUPT_ENABLED) && (INTCONbits.RBIF == INTERRUPT_OCCURED) && (PORTBbits.RB4 == 1) && (counter == 0)){
        counter = 1;
        ISR_RB4(0);
    }
    else{/*Nothing*/}
    
    if((INTCONbits.RBIE == INTERRUPT_ENABLED) && (INTCONbits.RBIF == INTERRUPT_OCCURED) && (PORTBbits.RB4 == 0) && (counter == 1)){
        counter = 0;
        ISR_RB4(1);
    }
    else{/*Nothing*/}
    
    if((INTCONbits.RBIE == INTERRUPT_ENABLED) && (INTCONbits.RBIF == INTERRUPT_OCCURED) && (PORTBbits.RB5 == 1) && (counter == 0)){
        counter = 1;
        ISR_RB5(0);
    }
    else{/*Nothing*/}
    
    if((INTCONbits.RBIE == INTERRUPT_ENABLED) && (INTCONbits.RBIF == INTERRUPT_OCCURED) && (PORTBbits.RB5 == 0) && (counter == 1)){
        counter = 0;
        ISR_RB5(1);
    }
    else{/*Nothing*/}
    
    if((INTCONbits.RBIE == INTERRUPT_ENABLED) && (INTCONbits.RBIF == INTERRUPT_OCCURED) && (PORTBbits.RB6 == 1) && (counter == 0)){
        counter = 1;
        ISR_RB6(0);
    }
    else{/*Nothing*/}
    
    if((INTCONbits.RBIE == INTERRUPT_ENABLED) && (INTCONbits.RBIF == INTERRUPT_OCCURED) && (PORTBbits.RB6 == 0) && (counter == 1)){
        counter = 0;
        ISR_RB6(1);
    }
    else{/*Nothing*/}
    
    if((INTCONbits.RBIE == INTERRUPT_ENABLED) && (INTCONbits.RBIF == INTERRUPT_OCCURED) && (PORTBbits.RB7 == 1) && (counter == 0)){
        counter = 1;
        ISR_RB7(0);
    }
    else{/*Nothing*/}
    
    if((INTCONbits.RBIE == INTERRUPT_ENABLED) && (INTCONbits.RBIF == INTERRUPT_OCCURED) && (PORTBbits.RB7 == 0) && (counter == 1)){
        counter = 0;
        ISR_RB7(1);
    }
    else{/*Nothing*/}
}
#endif