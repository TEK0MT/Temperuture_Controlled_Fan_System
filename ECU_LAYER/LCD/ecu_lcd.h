/* 
 * File:   ecu_lcd.h
 * Author: Mohamed Tarek
 *
 * Created on July 9, 2024, 7:39 AM
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H
/*Section : Include Section*/
#include "ecu_lcd_cfg.h"
#include "../../MCAL_LAYER/GPIO/mcal_gpio.h"
/*Section : Macro Declaration Section*/
#define CLEAR_DISPLAY   0x01
#define RETURN_HOME     0x02
#define ENTRY_MODE_INCREAMENT_SIFT_OFF 0x06
#define ENTRY_MODE_INCREAMENT_SIFT_ON 0x07
#define ENTRY_MODE_DECREAMENT_SIFT_OFF 0x04
#define ENTRY_MODE_DECREAMENT_SIFT_ON 0x05
#define DISPLAY_ON_CURSOR_OFF_BLINKING_OFF 0x0C
#define DISPLAY_ON_CURSOR_ON_BLINKING_OFF 0x0E
#define DISPLAY_ON_CURSOR_ON_BLINKING_ON 0x0F
#define DISPLAY_OFF 0x08
#define CURSOR_MOVE 0x10
#define DISPLAY_SHIFT_TO_THE_RIGHT 0x1C
#define DISPLAY_SHIFT_TO_THE_LEFT 0x18
#define LCD_8BITS_1LINE 0x30
#define LCD_8BITS_2LINE 0x38
#define LCD_4BITS_1LINE 0x20
#define LCD_4BITS_2LINE 0x28


#define ROW1 1
#define ROW2 2
/*Section : Macro Functions Declaration Section*/
/*Section : Data Type Declaration Section*/
typedef struct{
    pin_config_t rs;
    pin_config_t en;
    pin_config_t pins[4];
}lcd_4bits_t;
/*Section : Functions Declaration Section*/
Std_ReturnType lcd_4bits_initialize(const lcd_4bits_t *lcd);
Std_ReturnType lcd_4bits_send_command(const lcd_4bits_t *lcd,uint8 command);
Std_ReturnType lcd_4bits_send_char(const lcd_4bits_t *lcd,uint8 data);
Std_ReturnType lcd_4bits_send_char_pos(const lcd_4bits_t *lcd,uint8 Row,uint8 coloumn,uint8 data);
Std_ReturnType lcd_4bits_send_string(const lcd_4bits_t *lcd,uint8 *data);
Std_ReturnType lcd_4bits_send_string_pos(const lcd_4bits_t *lcd,uint8 Row,uint8 coloumn,uint8 *data);
#endif	/* ECU_LCD_H */

