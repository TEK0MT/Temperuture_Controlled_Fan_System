/* 
 * File:   hal_adc.h
 * Author: Mohamed Tarek
 *
 * Created on August 8, 2024, 10:22 AM
 */

#ifndef HAL_ADC_H
#define	HAL_ADC_H
/*Section : Include Section*/
#include "../INTERRUPT/interrupt_manager.h"
#include "../GPIO/mcal_gpio.h"
/*Section : Macro Declaration Section*/

/*Section : Macro Functions Declaration Section*/
#define ADC_ENABLE()    (ADCON0bits.ADON = 1)
#define ADC_DISABLE()    (ADCON0bits.ADON = 0)

#define ADC_CLEAR_FLAG()    (ADCON0bits.GO_nDONE = 0)

#define ADC_CHANNEL_SELECT(CHANNEL) (ADCON0bits.CHS = CHANNEL)

#define ADC_ANALOG_SELECT(CHANNEL) (ADCON1bits.PCFG = CHANNEL)

/*Section : Data Type Declaration Section*/
typedef enum{
    CHANNEL0 = 0,
            CHANNEL1,
            CHANNEL2,
            CHANNEL3,
            CHANNEL4,
            CHANNEL5,
            CHANNEL6,
            CHANNEL7
}channel_t;

typedef enum{
    FOSC_DIV2,
            FOSC_DIV8,
            FOSC_DIV32,
            FOSC_DIV4,
            FOSC_DIV16,
            FOSC_DIV64
}clock_time;

typedef enum{
    RIGHT_JUSTIFIED,
            LEFT_JUSTIFIED
}result_format;


typedef struct{
    channel_t channel;
    clock_time clock;
    result_format format;
}adc_t;
/*Section : Functions Declaration Section*/
Std_ReturnType ADC_INIT(const adc_t *adc);
Std_ReturnType ADC_DEINIT(const adc_t *adc);
Std_ReturnType ADC_Start_Conversion(const adc_t *adc);
Std_ReturnType ADC_Conversion_Is_Done(const adc_t *adc,uint8 *status);
Std_ReturnType ADC_Get_Conversion_Result(const adc_t *adc,uint16 *result);
Std_ReturnType ADC_Start_Conversion_Blocking(const adc_t *adc,channel_t channel,uint16 result);

#endif	/* HAL_ADC_H */

