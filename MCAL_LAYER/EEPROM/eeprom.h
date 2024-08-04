/* 
 * File:   eeprom.h
 * Author: Mohamed Tarek
 *
 * Created on August 4, 2024, 11:52 AM
 */

#ifndef EEPROM_H
#define	EEPROM_H
#define	TEMPERATURE_CONTROLLED_FAN_SYSTEM_H
/*Section : Include Section*/
#include "../../../../../../Program Files (x86)/Microchip/mplabcomm/../../../Microchip/PIC16Fxxx_DFP/1.6.156/xc8/pic/include/proc/pic16f877a.h"
#include "../GPIO/mcal_gpio.h"
/*Section : Macro Declaration Section*/
/*Section : Macro Functions Declaration Section*/
#define ACCESS_MEMORY() (EECON1bits.EEPGD = 0)
#define ACCESS_PROGRAM  (EECON1bits.EEPGD = 1)

#define ENABLE_WRITE()  (EECON1bits.WREN = 1)
#define INHIBIT_WRITE()  (EECON1bits.WREN = 0)

#define START_STORING()     (EECON1bits.WR = 1)

#define ENABLE_READ()       (EECON1bits.RD = 1)
#define DISABLE_READ()       (EECON1bits.RD = 0)
/*Section : Data Type Declaration Section*/

/*Section : Functions Declaration Section*/
#endif	/* EEPROM_H */

