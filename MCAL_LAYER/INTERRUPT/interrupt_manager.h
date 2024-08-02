/* 
 * File:   interrupt_manager.h
 * Author: Mohamed Tarek
 *
 * Created on July 18, 2024, 12:41 AM
 */

#ifndef INTERRUPT_MANAGER_H
#define	INTERRUPT_MANAGER_H
/*Section : Include Section*/
#include "external_interrupt.h"
/*Section : Macro Declaration Section*/

/*Section : Macro Functions Declaration Section*/
/*Section : Data Type Declaration Section*/
/*Section : Functions Declaration Section*/
void ISR_INTX(void);
void ISR_RB0(uint8 n);
void ISR_RB1(uint8 n);
void ISR_RB2(uint8 n);
void ISR_RB3(uint8 n);
void ISR_RB4(uint8 n);
void ISR_RB5(uint8 n);
void ISR_RB6(uint8 n);
void ISR_RB7(uint8 n);
#endif	/* INTERRUPT_MANAGER_H */

