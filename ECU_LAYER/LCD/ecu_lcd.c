/* 
 * File:   ecu_lcd.c
 * Author: Mohamed Tarek
 *
 * Created on July 9, 2024, 7:39 AM
 */
#include "ecu_lcd.h"


static Std_ReturnType send_4bits( lcd_4bits_t *lcd,uint8 command);
static Std_ReturnType send_enable_signal(const lcd_4bits_t *lcd);
static Std_ReturnType set_cursor(const lcd_4bits_t *lcd,uint8 Row,uint8 coloumn);
/*************************4 BITS LCD FUNCTIONS****************************/
Std_ReturnType lcd_4bits_initialize(const lcd_4bits_t *lcd){
    Std_ReturnType ret = E_OK;
    uint8 counter = ZERO_INIT;
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_initialize(&(lcd->rs));
        ret = gpio_pin_initialize(&(lcd->en));
        for(counter = ZERO_INIT;counter < 4;counter++){
        ret = gpio_pin_initialize(&(lcd->pins[counter]));
        }
        __delay_ms(150);
        ret = lcd_4bits_send_command(lcd,LCD_8BITS_2LINE);
        __delay_ms(50);
        ret = lcd_4bits_send_command(lcd,LCD_8BITS_2LINE);
        __delay_us(150);
        ret = lcd_4bits_send_command(lcd,LCD_8BITS_2LINE);
        ret = lcd_4bits_send_command(lcd,CLEAR_DISPLAY);
        ret = lcd_4bits_send_command(lcd,RETURN_HOME);
        ret = lcd_4bits_send_command(lcd,ENTRY_MODE_INCREAMENT_SIFT_OFF);
        ret = lcd_4bits_send_command(lcd,DISPLAY_ON_CURSOR_ON_BLINKING_ON);
        ret = lcd_4bits_send_command(lcd,CURSOR_MOVE);
        ret = lcd_4bits_send_command(lcd,LCD_4BITS_2LINE);
        ret = lcd_4bits_send_command(lcd,0x80);
        
    }
    return ret;
}
Std_ReturnType lcd_4bits_send_command(const lcd_4bits_t *lcd,uint8 command){
    Std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->rs),GPIO_LOW);
        ret = send_4bits(lcd,(command >> 4));
        ret = send_enable_signal(lcd);
        ret = send_4bits(lcd,command);
        ret = send_enable_signal(lcd);
    }
    return ret;
}
Std_ReturnType lcd_4bits_send_char(const lcd_4bits_t *lcd,uint8 data){
    Std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->rs),GPIO_HIGH);
        ret = send_4bits(lcd,(data >> 4));
         ret = send_enable_signal(lcd);
        ret = send_4bits(lcd,data);
        ret = send_enable_signal(lcd);
    }
    return ret;
}
Std_ReturnType lcd_4bits_send_char_pos(const lcd_4bits_t *lcd,uint8 Row,uint8 coloumn,uint8 data){
    Std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = set_cursor(lcd,Row,coloumn);
        ret = lcd_4bits_send_char(lcd,data);
    }
    return ret;
}
Std_ReturnType lcd_4bits_send_string(const lcd_4bits_t *lcd,uint8 *data){
    Std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        while(*data){
            ret = lcd_4bits_send_char(lcd,*data++);
        }
    }
    return ret;
}
Std_ReturnType lcd_4bits_send_string_pos(const lcd_4bits_t *lcd,uint8 Row,uint8 coloumn,uint8 *data){
    Std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = set_cursor(lcd,Row,coloumn);
        ret = lcd_4bits_send_char(lcd,*data++);
    }
    return ret;
}


/**************************HELPER FUNCTIONS*************************************/
static Std_ReturnType send_4bits( lcd_4bits_t *lcd,uint8 command){
    Std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->pins[0]),((command >> 0) & 0x01));
        ret = gpio_pin_write_logic(&(lcd->pins[1]),((command >> 1) & 0x01));
        ret = gpio_pin_write_logic(&(lcd->pins[2]),((command >> 2) & 0x01));
        ret = gpio_pin_write_logic(&(lcd->pins[3]),((command >> 3) & 0x01));
    }
    return ret;
}

static Std_ReturnType send_enable_signal(const lcd_4bits_t *lcd){
    Std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->en),GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->en),GPIO_LOW);
    }
    return ret;
}
static Std_ReturnType set_cursor(const lcd_4bits_t *lcd,uint8 Row,uint8 coloumn){
    Std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(Row){
            case ROW1 :
                ret = lcd_4bits_send_command(lcd,(0x80 + coloumn));
                break;
            case ROW2 :
                ret = lcd_4bits_send_command(lcd,(0xC0 + coloumn));
                break;
            default :
                break;
        }
    }
    return ret;
}