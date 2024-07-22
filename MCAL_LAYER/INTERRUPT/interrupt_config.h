/* 
 * File:   interrupt_config.h
 * Author: Mohamed Tarek
 *
 * Created on July 17, 2024, 9:16 PM
 */

#ifndef INTERRUPT_CONFIG_H
#define	INTERRUPT_CONFIG_H
/*Section : Include Section*/
#include "pic16f877a.h"
#include "../std_type.h"
#include "../GPIO/mcal_gpio.h"
/*Section : Macro Declaration Section*/
#define INTERRUPT_ENABLED       1
#define INTERRUPT_OCCURED       1
#define ENABLE_ALL_INTERRUPT()  (INTCONbits.GIE = 1)
#define DISABLE_ALL_INTERRUPT() (INTCONbits.GIE = 0)
#define ENABLE_PERIPHERAL_INTERRUPT() (INTCONbits.PEIE = 1)
#define DISABLE_PERIPHERAL_INTERRUPT() (INTCONbits.PEIE = 0)
/*Section : Macro Functions Declaration Section*/
/*Section : Data Type Declaration Section*/

/*Section : Functions Declaration Section*/

#endif	/* INTERRUPT_CONFIG_H */

