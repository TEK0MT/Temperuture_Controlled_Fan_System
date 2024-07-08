/* 
 * File:   mcal_gpio.h
 * Author: Mohamed Tarek
 *
 * Created on July 7, 2024, 11:19 PM
 */

#ifndef MCAL_GPIO_H
#define	MCAL_GPIO_H
/*Section : Include Section*/
#include "gpio_cfg.h"
#include "../std_libraries.h"
#include "../device_config.h"
#include "../../../xc8/pic/include/proc/pic16f877a.h"
#include "../std_type.h"
/*Section : Macro Declaration Section*/
#define MAX_PORTA_PINS 6
#define MAX_PORTB_PINS 8
#define MAX_PORTC_PINS 8
#define MAX_PORTD_PINS 8
#define MAX_PORTE_PINS 3
#define MAX_PORTS      5
#define BIT_MASK       0x01
#define PORT_MASK      0xFF
#define Std_ReturnType uint8
/*Section : Macro Functions Declaration Section*/
#define SET_BIT(Reg,Pos)        (Reg |= (BIT_MASK << Pos))
#define CLEAR_BIT(Reg,Pos)      (Reg &= ~(BIT_MASK << Pos))
#define TOGGLE_BIT(Reg,Pos)     (Reg ^= (BIT_MASK << Pos))
#define READ_BIT(Reg,Pos)       ((Reg >> Pos) & BIT_MASK)
/*Section : Data Type Declaration Section*/
typedef enum{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
}pin_t;

typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_t;

typedef enum {
    GPIO_LOW = 0,
    GPIO_HIGH
}logic_t;

typedef enum{
    GPIO_DIRECTION_OUTPUT = 0,
    GPIO_DIRECTION_INPUT
}direction_t;

typedef struct{
    uint8 port             :3 ;
    uint8 pin               :3;
    uint8 logic           :1;
    uint8 direction   :1;
}pin_config_t;
/*Section : Functions Declaration Section*/
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *pin);
Std_ReturnType gpio_get_pin_direction(const pin_config_t *pin,direction_t *direction);
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin,logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin,logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin);
Std_ReturnType gpio_pin_initialize(const pin_config_t *pin);



Std_ReturnType gpio_port_direction_initialize(const port_t port,direction_t direction);
Std_ReturnType gpio_get_port_direction(const port_t port,direction_t *direction);
Std_ReturnType gpio_port_write_logic(const port_t port,logic_t logic);
Std_ReturnType gpio_port_read_logic(const port_t port,logic_t *logic);
Std_ReturnType gpio_port_toggle_logic(const port_t port);


#endif	/* MCAL_GPIO_H */

