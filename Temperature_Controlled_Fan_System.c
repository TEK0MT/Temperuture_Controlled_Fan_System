/* 
 * File:   Temperature_Controlled_Fan_System.c
 * Author: Mohamed Tarek
 *
 * Created on July 7, 2024, 11:07 PM
 */
#include "Temperature_Controlled_Fan_System.h"


uint16 adc_res;
uint16 Temp;
uint16 Max_Temp = 0;
uint8 lcd_show[6];
uint8 lcd_show_max[6];
uint8 pass[4] = {'5','4','8','9'};
uint8 val;
uint8 flag = 0;


uint8 temp[4] = "....";
int main() {
    apllication_initilaize();
    READ_DATA_EEPROM(0xFF,&Max_Temp);
while(1){
    ADC_Start_Conversion_Blocking(&adc,CHANNEL0,&adc_res);
    Temp =  adc_res * 4.8828125f / 10;

    Convert_uint16_to_string(Temp,lcd_show);
    keypad_read_value(&keypad,&val);
    if(val == '*' && flag == 0){
        __delay_ms(400);
        
        for(uint8 counter = 0;counter < 4;counter++){
        while(temp[counter] == '.'){
        keypad_read_value(&keypad,&(temp[counter]));
        
        }
        __delay_ms(400);
    }
        flag = 1;
        for(uint8 i = 0;i < 4;i++){
            if(temp[i] != pass[i]){
                flag = 0;
                break;
            }
            
            else{}
        }
    }
    
    
    else{}
    Convert_uint16_to_string(Max_Temp,lcd_show_max);
    if(flag == 1){
    lcd_4bits_send_string_pos(&lcd,1,1,"Temp is : ");
    lcd_4bits_send_string_pos(&lcd,1,10,lcd_show);
    lcd_4bits_send_string_pos(&lcd,2,1,"Max Temp is : ");
    lcd_4bits_send_string_pos(&lcd,2,14,lcd_show_max);
    }
    else if(flag == 0){
        lcd_4bits_send_string_pos(&lcd,1,1,"Enter password");
    }
    else{}
    
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
    if(Temp > Max_Temp){
        Max_Temp = Temp;
        WRITE_DATA_EEPROM(0xFF,Max_Temp);
    }
    
}
    return (EXIT_SUCCESS);
}
void apllication_initilaize(void){
    ecu_initialzie();
    mcal_initialize();
}

