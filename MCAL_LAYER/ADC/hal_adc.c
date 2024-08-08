/* 
 * File:   hal_adc.c
 * Author: Mohamed Tarek
 *
 * Created on August 8, 2024, 10:22 AM
 */
#include "hal_adc.h"

static Std_ReturnType Result_Format(const adc_t *adc);


Std_ReturnType ADC_INIT(const adc_t *adc){
    Std_ReturnType ret = E_OK;
    if(adc == NULL){
        ret = E_NOT_OK;
    }
    else{
        ADC_DISABLE();
        ADC_CLEAR_FLAG();
        ADC_CHANNEL_SELECT(adc->channel);
        Result_Format(adc);
        ADC_ANALOG_SELECT(0x04);
        ADC_ENABLE();
    }
    return ret;
}
Std_ReturnType ADC_DEINIT(const adc_t *adc){
    Std_ReturnType ret = E_OK;
    if(adc == NULL){
        ret = E_NOT_OK;
    }
    else{
        ADC_DISABLE();
    }
    return ret;
}
Std_ReturnType ADC_Start_Conversion(const adc_t *adc){
    Std_ReturnType ret = E_OK;
    if(adc == NULL){
        ret = E_NOT_OK;
    }
    else{
        ADCON0bits.GO_nDONE = 1;
        while(ADCON0bits.GO_nDONE);
    }
    return ret;
}
Std_ReturnType ADC_Conversion_Is_Done(const adc_t *adc,uint8 *status){
    Std_ReturnType ret = E_OK;
    if(adc == NULL){
        ret = E_NOT_OK;
    }
    else{
        *status = ADCON0bits.GO_nDONE;
        
    }
    return ret;
}

Std_ReturnType ADC_Get_Conversion_Result(const adc_t *adc,uint16 *result){
    Std_ReturnType ret = E_OK;
    if(adc == NULL){
        ret = E_NOT_OK;
    }
    else{
        if(adc->format == RIGHT_JUSTIFIED){
            *result = (uint16)(ADRESL + (ADRESH << 8));
        }
        else if(adc->format == LEFT_JUSTIFIED){
            *result = (uint16)((ADRESL + (ADRESH << 8)) >> 6);
        }
        
    }
    return ret;
}


Std_ReturnType ADC_Start_Conversion_Blocking(const adc_t *adc,channel_t channel,uint16 result){
    Std_ReturnType ret = E_OK;
    if(adc == NULL){
        ret = E_NOT_OK;
    }
    else{
        ADC_CLEAR_FLAG();
        ADC_CHANNEL_SELECT(adc->channel);
        ADC_Start_Conversion(adc);
        ADC_Get_Conversion_Result(adc,result);
    }
    return ret;
}

static Std_ReturnType Result_Format(const adc_t *adc){
    Std_ReturnType ret = E_OK;
    if(adc == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(adc->format){
            case RIGHT_JUSTIFIED :
                ADCON1bits.ADFM = 1;
            break;
            case LEFT_JUSTIFIED :
                ADCON1bits.ADFM = 0;
            break;
        }
    }
    return ret;
}