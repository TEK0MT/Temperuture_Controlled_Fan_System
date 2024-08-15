/* 
 * File:   MCAL_LAYER.c
 * Author: Mohamed Tarek
 *
 * Created on August 15, 2024, 4:50 AM
 */

#include "MCAL_LAYER.h"

adc_t adc = {.channel = CHANNEL0,.clock = FOSC_DIV16,.format = RIGHT_JUSTIFIED};

Std_ReturnType mcal_initialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ret = ADC_INIT(&adc);
}