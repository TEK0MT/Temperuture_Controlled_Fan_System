/* 
 * File:   external_interrupt.c
 * Author: Mohamed Tarek
 *
 * Created on July 17, 2024, 9:16 PM
 */
#include "external_interrupt.h"


static Std_ReturnType set_src_intx(const INTX_T *intx);
static Std_ReturnType EXT_Rbx_Fun(const RBX_t *rbx);
static void(*EXT_INTX_HANDLER)(void);
static void(*EXT_RB0_HIGH_HANDLER)(void);
static void(*EXT_RB0_LOW_HANDLER)(void);

static void(*EXT_RB1_HIGH_HANDLER)(void);
static void(*EXT_RB1_LOW_HANDLER)(void);

static void(*EXT_RB2_HIGH_HANDLER)(void);
static void(*EXT_RB2_LOW_HANDLER)(void);

static void(*EXT_RB3_HIGH_HANDLER)(void);
static void(*EXT_RB3_LOW_HANDLER)(void);

static void(*EXT_RB4_HIGH_HANDLER)(void);
static void(*EXT_RB4_LOW_HANDLER)(void);

static void(*EXT_RB5_HIGH_HANDLER)(void);
static void(*EXT_RB5_LOW_HANDLER)(void);

static void(*EXT_RB6_HIGH_HANDLER)(void);
static void(*EXT_RB6_LOW_HANDLER)(void);

static void(*EXT_RB7_HIGH_HANDLER)(void);
static void(*EXT_RB7_LOW_HANDLER)(void);



void ISR_INTX(void){
    CLEAR_INTX_FLAG();
    if(EXT_RB0_HIGH_HANDLER){
        EXT_RB0_HIGH_HANDLER();
    }
    else{/*nothing*/}
}

void ISR_RB0(uint8 n){
    CLEAR_INTX_FLAG();
    if(!n){
    if(EXT_RB0_HIGH_HANDLER){
        EXT_RB0_HIGH_HANDLER();
    }
    else{/*nothing*/}
    }
    else{
        if(EXT_RB0_LOW_HANDLER){
        EXT_RB0_LOW_HANDLER();
    }
    else{/*nothing*/}
    }
    
}



void ISR_RB1(uint8 n){
    CLEAR_INTX_FLAG();
    if(!n){
    if(EXT_RB1_HIGH_HANDLER){
        EXT_RB1_HIGH_HANDLER();
    }
    else{/*nothing*/}
    }
    else{
        if(EXT_RB1_LOW_HANDLER){
        EXT_RB1_LOW_HANDLER();
    }
    else{/*nothing*/}
    }
}

void ISR_RB2(uint8 n){
    CLEAR_INTX_FLAG();
    if(!n){
    if(EXT_RB2_HIGH_HANDLER){
        EXT_RB2_HIGH_HANDLER();
    }
    else{/*nothing*/}
    }
    else{
        if(EXT_RB2_LOW_HANDLER){
        EXT_RB2_LOW_HANDLER();
    }
    else{/*nothing*/}
    }
}
void ISR_RB3(uint8 n){
    CLEAR_INTX_FLAG();
    if(!n){
    if(EXT_RB3_HIGH_HANDLER){
        EXT_RB3_HIGH_HANDLER();
    }
    else{/*nothing*/}
    }
    else{
        if(EXT_RB3_LOW_HANDLER){
        EXT_RB3_LOW_HANDLER();
    }
    else{/*nothing*/}
    }
}
void ISR_RB4(uint8 n){
    CLEAR_INTX_FLAG();
    if(!n){
    if(EXT_RB4_HIGH_HANDLER){
        EXT_RB4_HIGH_HANDLER();
    }
    else{/*nothing*/}
    }
    else{
        if(EXT_RB4_LOW_HANDLER){
        EXT_RB4_LOW_HANDLER();
    }
    else{/*nothing*/}
    }
}
void ISR_RB5(uint8 n){
    CLEAR_INTX_FLAG();
    if(!n){
    if(EXT_RB5_HIGH_HANDLER){
        EXT_RB5_HIGH_HANDLER();
    }
    else{/*nothing*/}
    }
    else{
        if(EXT_RB5_LOW_HANDLER){
        EXT_RB5_LOW_HANDLER();
    }
    else{/*nothing*/}
    }
}

void ISR_RB6(uint8 n){
    CLEAR_INTX_FLAG();
    if(!n){
    if(EXT_RB6_HIGH_HANDLER){
        EXT_RB6_HIGH_HANDLER();
    }
    else{/*nothing*/}
    }
    else{
        if(EXT_RB6_LOW_HANDLER){
        EXT_RB6_LOW_HANDLER();
    }
    else{/*nothing*/}
    }
}

void ISR_RB7(uint8 n){
    CLEAR_INTX_FLAG();
    if(!n){
    if(EXT_RB7_HIGH_HANDLER){
        EXT_RB7_HIGH_HANDLER();
    }
    else{/*nothing*/}
    }
    else{
        if(EXT_RB7_LOW_HANDLER){
        EXT_RB7_LOW_HANDLER();
    }
    else{/*nothing*/}
    }
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
        EXT_INTX_HANDLER = intx->EXT_HANDLER;
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





Std_ReturnType Enable_RBX(const RBX_t *rbx){
    Std_ReturnType ret = E_OK;
    if(rbx == NULL){
        ret = E_NOT_OK;
    }
    else{
        DISABLE_RBX_INTERRUPT();
        CLEAR_RBX_FLAG();
        ret = gpio_pin_direction_initialize(&rbx->pin);
        EXT_Rbx_Fun(rbx);
        ENABLE_RBX_INTERRUPT();
    }
    return ret;
}
Std_ReturnType Disable_RBX(const RBX_t *rbx){
    Std_ReturnType ret = E_OK;
    if(rbx == NULL){
        ret = E_NOT_OK;
    }
    else{
        DISABLE_RBX_INTERRUPT();
    }
    return ret;
}


static Std_ReturnType EXT_Rbx_Fun(const RBX_t *rbx){
    switch(rbx->pin.pin){
        case PIN0:
            rbx->EXT_HIGH_INTERRUPT = EXT_RB0_HIGH_HANDLER;
            rbx->EXT_LOW_INTERRUPT = EXT_RB0_LOW_HANDLER;
            break;
        case PIN1:
            rbx->EXT_HIGH_INTERRUPT = EXT_RB1_HIGH_HANDLER;
            rbx->EXT_LOW_INTERRUPT = EXT_RB1_LOW_HANDLER;
            break;
        case PIN2:
            rbx->EXT_HIGH_INTERRUPT = EXT_RB2_HIGH_HANDLER;
            rbx->EXT_LOW_INTERRUPT = EXT_RB2_LOW_HANDLER;
            break;
        case PIN3:
            rbx->EXT_HIGH_INTERRUPT = EXT_RB3_HIGH_HANDLER;
            rbx->EXT_LOW_INTERRUPT = EXT_RB3_LOW_HANDLER;
            break;
        case PIN4:
            rbx->EXT_HIGH_INTERRUPT = EXT_RB4_HIGH_HANDLER;
            rbx->EXT_LOW_INTERRUPT = EXT_RB4_LOW_HANDLER;
            break;
        case PIN5:
            rbx->EXT_HIGH_INTERRUPT = EXT_RB5_HIGH_HANDLER;
            rbx->EXT_LOW_INTERRUPT = EXT_RB5_LOW_HANDLER;
            break;
        case PIN6:
            rbx->EXT_HIGH_INTERRUPT = EXT_RB6_HIGH_HANDLER;
            rbx->EXT_LOW_INTERRUPT = EXT_RB6_LOW_HANDLER;
            break;
        case PIN7:
            rbx->EXT_HIGH_INTERRUPT = EXT_RB7_HIGH_HANDLER;
            rbx->EXT_LOW_INTERRUPT = EXT_RB7_LOW_HANDLER;
            break;
    }
}