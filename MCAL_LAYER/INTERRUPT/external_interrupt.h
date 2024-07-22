/* 
 * File:   external_interrupt.h
 * Author: Mohamed Tarek
 *
 * Created on July 17, 2024, 9:16 PM
 */

#ifndef EXTERNAL_INTERRUPT_H
#define	EXTERNAL_INTERRUPT_H
/*Section : Include Section*/
#include "interrupt_config.h"
/*Section : Macro Declaration Section*/
#define INTX_INTERRUPT          INTERRUPT_ENABLED
#define RBX_INTERRUPT           INTERRUPT_ENABLED
/*Section : Macro Functions Declaration Section*/
#if INTERRUPT_ENABLED
#if INTX_INTERRUPT
#define ENABLE_INTX_INTERRUPT() (INTCONbits.INTE = 1)
#define DISABLE_INTX_INTERRUPT() (INTCONbits.INTE = 0)
#define CLEAR_INTX_FLAG()         (INTCONbits.INTF = 0)
#define SET_RISING_EDGE()          (OPTION_REGbits.INTEDG = 1)
#define SET_FALLING_EDGE()          (OPTION_REGbits.INTEDG = 0)
#endif
#if RBX_INTERRUPT
#define ENABLE_RBX_INTERRUPT (INTCONbits.RBIE = 1)
#define DISABLE_RBX_INTERRUPT (INTCONbits.RBIE = 0)
#define CLEAR_RBX_FLAG()         (INTCONbits.RBIF = 0)
#endif
#endif
/*Section : Data Type Declaration Section*/
typedef enum{
    RISING_EDGE,
    FALLING_EDGE
}src_t;

typedef struct{
    void (*EXT_HANDLER)(void);
    src_t source;
}INTX_T;


/*Section : Functions Declaration Section*/
Std_ReturnType Enable_INTX(const INTX_T *intx);
Std_ReturnType Disable_INTX(const INTX_T *intx);

#endif	/* EXTERNAL_INTERRUPT_H */

