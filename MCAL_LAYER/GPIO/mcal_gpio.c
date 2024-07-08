/* 
 * File:   mcal_gpio.c
 * Author: Mohamed Tarek
 *
 * Created on July 8, 2024, 6:42 AM
 */
#include "mcal_gpio.h"
volatile uint8 *tris_registers[] = {&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
//volatile uint8 *lat_registers[] = {&LATA,&LATB,&LATC,&LATD,&LATE};
volatile uint8 *port_registers[] = {&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};



Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *pin){
    Std_ReturnType ret = E_OK;
    if(pin == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(pin->direction){
            case GPIO_DIRECTION_OUTPUT:
                CLEAR_BIT(*tris_registers[pin->port],pin->pin);
                break;
            case GPIO_DIRECTION_INPUT:
                SET_BIT(*tris_registers[pin->port],pin->pin);
                break;
        }
    }
    return ret;
}
Std_ReturnType gpio_get_pin_direction(const pin_config_t *pin,direction_t *direction){
    Std_ReturnType ret = E_OK;
    if(pin == NULL || direction == NULL){
        ret = E_NOT_OK;
    }
    else{
        *direction = READ_BIT(*tris_registers[pin->port],pin->pin);
    }
    return ret;
}
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin,logic_t logic){
    Std_ReturnType ret = E_OK;
    if(pin == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(logic){
            case GPIO_HIGH:
                SET_BIT(*port_registers[pin->port],pin->pin);
                break;
            case GPIO_LOW:
                CLEAR_BIT(*port_registers[pin->port],pin->pin);
                break;
        }
    }
    return ret;
}
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin,logic_t *logic){
    Std_ReturnType ret = E_OK;
    if(pin == NULL || logic == NULL){
        ret = E_NOT_OK;
    }
    else{
        *logic = READ_BIT(*port_registers[pin->port],pin->pin);
    }
    return ret;
}
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin){
    Std_ReturnType ret = E_OK;
    if(pin == NULL){
        ret = E_NOT_OK;
    }
    else{
        TOGGLE_BIT(*port_registers[pin->port],pin->pin);
    }
    return ret;
}
Std_ReturnType gpio_pin_initialize(const pin_config_t *pin){
    Std_ReturnType ret = E_OK;
    if(pin == NULL){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_direction_initialize(pin);
        gpio_pin_write_logic(pin,pin->logic);
    }
    return ret;
}






Std_ReturnType gpio_port_direction_initialize(const port_t port,direction_t direction){
    Std_ReturnType ret = E_OK;
    if(port > MAX_PORTS -1){
        ret = E_NOT_OK;
    }
    else{
        switch(direction){
            case GPIO_DIRECTION_INPUT :
                *tris_registers[port] = PORT_MASK;
                break;
            case GPIO_DIRECTION_OUTPUT :
                *tris_registers[port] = ZERO_INIT;
                break;
            default:
                *tris_registers[port] = direction;
        }
        
    }
    return ret;
}
Std_ReturnType gpio_get_port_direction(const port_t port,direction_t *direction){
    Std_ReturnType ret = E_OK;
    if(port > MAX_PORTS -1){
        ret = E_NOT_OK;
    }
    else{
        *direction = *tris_registers[port];
    }
    return ret;
}
Std_ReturnType gpio_port_write_logic(const port_t port,logic_t logic){
    Std_ReturnType ret = E_OK;
    if(port > MAX_PORTS -1){
        ret = E_NOT_OK;
    }
    else{
        switch(logic){
            case GPIO_HIGH :
                *port_registers[port] = PORT_MASK;
                break;
            case GPIO_LOW :
                *port_registers[port] = ZERO_INIT;
                break;
                default:
                *port_registers[port] = logic;
        }
        
    }
    return ret;
}
Std_ReturnType gpio_port_read_logic(const port_t port,logic_t *logic){
    Std_ReturnType ret = E_OK;
    if(port > MAX_PORTS -1){
        ret = E_NOT_OK;
    }
    else{
        *logic = *port_registers[port];
    }
    return ret;
}
Std_ReturnType gpio_port_toggle_logic(const port_t port){
    Std_ReturnType ret = E_OK;
    if(port > MAX_PORTS -1){
        ret = E_NOT_OK;
    }
    else{
        *port_registers[port] ^= PORT_MASK;
    }
    return ret;
}
