/* 
 * File:   Temperature_Controlled_Fan_System.c
 * Author: Mohamed Tarek
 *
 * Created on July 7, 2024, 11:07 PM
 */
#include "Temperature_Controlled_Fan_System.h"


uint16 adc_res;
uint16 Temp;
uint16 Max_Temp;
uint8 lcd_show[6];
int main() {
    apllication_initilaize();
    WRITE_DATA_EEPROM(0x00,&Max_Temp);
while(1){
    ADC_Start_Conversion_Blocking(&adc,CHANNEL0,&adc_res);
    
    Temp =  adc_res * 4.8828125f;
    Temp /= 10;
    if(Temp > Max_Temp){
        Max_Temp = Temp;
    }
    Convert_uint16_to_string(Temp,lcd_show);
    lcd_4bits_send_string_pos(&lcd,1,1,"Temp is : ");
    lcd_4bits_send_string_pos(&lcd,1,10,lcd_show);
    if((Temp >= 50) && (Temp < 60)){
        motor_turn_right(&motor1);
    }
    else if(Temp >= 60){
        motor_turn_right(&motor1);
        motor_turn_left(&motor2);
    }
    else{
        motor_turn_off(&motor1);
        motor_turn_off(&motor2);
    }
    
    WRITE_DATA_EEPROM(0x00,Max_Temp);
}
    return (EXIT_SUCCESS);
}
void apllication_initilaize(void){
    ecu_initialzie();
    mcal_initialize();
}

