/* 
 * File:   external_interrupt.c
 * Author: Mohamed Tarek
 *
 * Created on July 17, 2024, 9:16 PM
 */
#include "external_interrupt.h"


static Std_ReturnType set_src_intx(const INTX_T *intx);

static void(*EXT__HANDLER)(void);

void ISR_INTX(void){
    CLEAR_INTX_FLAG();
    if(EXT__HANDLER){
        EXT__HANDLER();
    }
    else{/*nothing*/}
}

Std_ReturnType Enable_INTX(const INTX_T *intx){
    Std_ReturnType ret = E_OK;
        pin_config_t pin_obj = {.port = PORTB_INDEX,.pin=PIN0,.logic = GPIO_LOW,.direction = GPIO_DIRECTION_INPUT};
    if(intx == NULL){
        ret = E_NOT_OK;
    }
    else{
        ENABLE_ALL_INTERRUPT();
        ENABLE_PERIPHERAL_INTERRUPT();
        DISABLE_INTX_INTERRUPT();
        CLEAR_INTX_FLAG();
        ret = gpio_pin_direction_initialize(&pin_obj);
        ret = set_src_intx(intx);
        EXT__HANDLER = intx->EXT_HANDLER;
        ENABLE_INTX_INTERRUPT();
    }
    return ret;
}



Std_ReturnType Disable_INTX(const INTX_T *intx){
    Std_ReturnType ret = E_OK;
    if(intx == NULL){
        ret = E_NOT_OK;
    }
    else{
        DISABLE_INTX_INTERRUPT();
    }
    return ret;
}


static Std_ReturnType set_src_intx(const INTX_T *intx){
    Std_ReturnType ret = E_OK;
    if(intx == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(intx->source){
            case RISING_EDGE:
                SET_RISING_EDGE();
                break;
            case FALLING_EDGE :
                SET_FALLING_EDGE();
                break;
            default :
                ret = E_NOT_OK;
        }
    }
    return ret;
}





Std_ReturnType Enable_RBX(const INTX_T *intx){
    Std_ReturnType ret = E_OK;
    if(intx == NULL){
        ret = E_NOT_OK;
    }
    else{
        
    }
    return ret;
}
Std_ReturnType Disable_RBX(const INTX_T *intx);