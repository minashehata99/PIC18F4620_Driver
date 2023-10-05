/* 
 * File:   hal_adc.h
 * Author: minas
 *
 * Created on September 8, 2023, 6:48 PM
 */

#ifndef HAL_ADC_H
#define	HAL_ADC_H

/* Section :  Includes   */
#include "hal_adc_cfg.h"
#include "../proc/pic18f4620.h"
#include "../../MCAL_LAYER/mcal_std_types.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
#include "../../MCAL_LAYER/interrupt/mcal_internal_interrupt.h" 
/* Section :  Macro declaration   */

/**
 * @brief Analog-To-Digital Port Configuration Control
 * @note When ADC_AN4_ANALOG_FUNCTIONALITY is configured ,this means
 *          AN4,AN3,AN2,AN1,AN0 are Analog functionality.
 */
#define ADC_AN0_ANALOG_FUNCTIONALITY   0x0E
#define ADC_AN1_ANALOG_FUNCTIONALITY   0x0D
#define ADC_AN2_ANALOG_FUNCTIONALITY   0x0C
#define ADC_AN3_ANALOG_FUNCTIONALITY   0x0B
#define ADC_AN4_ANALOG_FUNCTIONALITY   0x0A
#define ADC_AN5_ANALOG_FUNCTIONALITY   0x09
#define ADC_AN6_ANALOG_FUNCTIONALITY   0x08
#define ADC_AN7_ANALOG_FUNCTIONALITY   0x07
#define ADC_AN8_ANALOG_FUNCTIONALITY   0x06
#define ADC_AN9_ANALOG_FUNCTIONALITY   0x05
#define ADC_AN10_ANALOG_FUNCTIONALITY  0x04
#define ADC_AN11_ANALOG_FUNCTIONALITY  0x03
#define ADC_AN12_ANALOG_FUNCTIONALITY  0x02
#define ADC_ALL_ANALOG_FUNCTIONALITY   0x00
#define ADC_ALL_DIGITAL_FUNCTIONALITY  0x0F

#define ADC_RESULT_RIGHT 0x01U
#define ADC_RESULT_LEFT  0x00U

#define ADC_VOLTAGE_REFRENCE_ENABLED   0x01U
#define ADC_VOLTAGE_REFRENCE_DISABLED  0x00U

#define ADC_CONVERSION_COMPLETED  1
#define ADC_CONVERSION_INPROGRESS 0
/* Section :  Macro function   */


/* A/D Conversion status A/D Conversion in progress/ A/D is idle*/
#define ADC_CONVERSION_STATUS()  (ADCON0bits.GO_nDONE)
/* A/D Conversion Start Conversion */
#define ADC_START_CONVERSION()  (ADCON0bits.GO_nDONE = 1)
/**
 * @brief Analog-To-Digital control
 * @note ADC_CONVERTER_ENABLE()  : enable the ADC converter
 *       ADC_CONVERTER_DISABLE() : disable the ADC converter
 */
#define ADC_CONVERTER_ENABLE()     (ADCON0bits.ADON = 1)
#define ADC_CONVERTER_DISABLE()    (ADCON0bits.ADON = 0)

/**
 * @brief Analog-To-Digital Port Configuration Control
 * @note When ADC_AN4_ANALOG_FUNCTIONALITY is configured ,this means
 *          AN4,AN3,AN2,AN1,AN0 are Analog functionality.
 * @ref  Analog-To-Digital Port Configuration Control
 */
#define ADC_ANALOG_DIGITAL_PORT_CONFIG(_CONFIG) (ADCON1bits.PCFG = _CONFIG)
/**
 * @brief A/D Result Format Select
 */
#define ADC_RESULT_RIGHT_FORMAT()   (ADCON2bits.ADFM = 1)
#define ADC_RESULT_LEFT_FORMAT()    (ADCON2bits.ADFM = 0)

/* Section :  Data types   */
/**
 * @brief Analog channel select
 */
typedef enum {
    ADC_CHANNEL_AN0 = 0,
    ADC_CHANNEL_AN1,
    ADC_CHANNEL_AN2,
    ADC_CHANNEL_AN3,
    ADC_CHANNEL_AN4,
    ADC_CHANNEL_AN5,
    ADC_CHANNEL_AN6,
    ADC_CHANNEL_AN7,
    ADC_CHANNEL_AN8,
    ADC_CHANNEL_AN9,
    ADC_CHANNEL_AN10,
    ADC_CHANNEL_AN11, 
    ADC_CHANNEL_AN12             
}adc_channel_select_t;

typedef enum{
    ADC_0_TAD = 0,
    ADC_2_TAD,
    ADC_4_TAD,
    ADC_6_TAD,
    ADC_8_TAD,
    ADC_12_TAD, 
    ADC_16_TAD, 
    ADC_20_TAD
}adc_acquisition_time_t;

typedef enum{
    ADC_CONVERTION_CLOCK_FOSC_DIV_2 = 0,
    ADC_CONVERTION_CLOCK_FOSC_DIV_8,
    ADC_CONVERTION_CLOCK_FOSC_DIV_32,
    ADC_CONVERTION_CLOCK_FOSC_DIV_FRC,
    ADC_CONVERTION_CLOCK_FOSC_DIV_4,
    ADC_CONVERTION_CLOCK_FOSC_DIV_16,
    ADC_CONVERTION_CLOCK_FOSC_DIV_64
}adc_conversion_clock_t;
typedef struct{
#if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (* ADC_InterruptHandler)(void);
    interrupt_priority_cfg priority;
#endif
    adc_acquisition_time_t acqusition_time;    /* @ref adc_acquisition_time_t */
    adc_conversion_clock_t conversion_clock;   /* @ref adc_conversion_clock_t */
    adc_channel_select_t adc_channel;          /* @ref adc_channel_select_t */
    uint8 voltage_refrence :4;
    uint8 result_format :1;
    uint8 ADC_Reseeved :6;
}adc_config_t;

typedef uint16 adc_result_t;

/* Section :  Function Declaration   */

Std_ReturnType ADC_Init(const adc_config_t *_adc );
Std_ReturnType ADC_DeInit(const adc_config_t *_adc );
Std_ReturnType ADC_SelectChannel(const adc_config_t *_adc , adc_channel_select_t channel );
Std_ReturnType ADC_StartConversion(const adc_config_t *_adc );
Std_ReturnType ADC_IsConversionDone(const adc_config_t *_adc , uint8 *conversion_status);
Std_ReturnType ADC_GetConversionResult(const adc_config_t *_adc , adc_result_t *conversion_result);
Std_ReturnType ADC_GetConversion_by_polling(const adc_config_t *_adc , adc_channel_select_t channel, adc_result_t *conversion_result);
Std_ReturnType ADC_StartConversion_by_Interrupt(const adc_config_t *_adc , adc_channel_select_t channel);
#endif	/* HAL_ADC_H */

