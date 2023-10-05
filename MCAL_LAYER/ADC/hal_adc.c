/* 
 * File:   hal_adc.c
 * Author: minas
 *
 * Created on September 8, 2023, 6:48 PM
 */

#include "hal_adc.h"
static inline void adc_input_channel_port_configure(const adc_channel_select_t channel);
#if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
static InterruptHandler ADC_InterruptHandler = NULL;
#endif
/**
 * @brief ADC_Initializaition
 * @param _adc 
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType ADC_Init(const adc_config_t *_adc ){
    uint8 ret =E_OK;
    if( NULL == _adc){
        ret=E_NOT_OK;
    }
    else{
        /* Disable the ADC */
        ADC_CONVERTER_DISABLE();
        /* configure the acquisition time  */
         ADCON2bits.ACQT = _adc->acqusition_time;
        /* configure the conversion clock */
         ADCON2bits.ADCS = _adc->conversion_clock;
        /* configure the default channel */
         ADCON0bits.CHS = _adc->adc_channel;
         adc_input_channel_port_configure(_adc->adc_channel);
        /* configure the interrupt  */
        #if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        ADC_INTERRUPT_ENABLE();
#if  INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_LEVEL_ENABLE();
        if(_adc->priority == INTERRUPT_HIGH_PRIORITY){INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();}
        else if(_adc->priority == INTERRUPT_LOW_PRIORITY){INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();}
        else {/*Nothing*/}
#else
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif
        ADC_INTERRUPT_FLAG_CLEAR();
        #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        if(INTERRUPT_HIGH_PRIORITY == _adc->priority){
        ADC_HIGH_PRIORITY_SET();
        }
        else if(INTERRUPT_LOW_PRIORITY == _adc->priority){
        ADC_LOW_PRIORITY_SET();
        }
        else {/*Nothing*/}
        #endif
        ADC_InterruptHandler = _adc->ADC_InterruptHandler;
        #endif
        /* configure the result format */
        if(_adc->result_format == ADC_RESULT_RIGHT){
            ADC_RESULT_RIGHT_FORMAT();
        }
        else if(_adc->result_format == ADC_RESULT_LEFT){
            ADC_RESULT_LEFT_FORMAT();
        }
        else{
            ADC_RESULT_RIGHT_FORMAT();
        }
        /* configure the voltage reference */
         
        if(_adc->voltage_refrence == ADC_VOLTAGE_REFRENCE_ENABLED){
            ADCON1bits.VCFG1 = 1;
            ADCON1bits.VCFG0 = 1;
        }
        else if(_adc->voltage_refrence == ADC_VOLTAGE_REFRENCE_DISABLED){
            ADCON1bits.VCFG1 = 0;
            ADCON1bits.VCFG0 = 0;
        }
        else{
            ADCON1bits.VCFG1 = 0;
            ADCON1bits.VCFG0 = 0;
        }
        /* Enable the ADC */
        ADC_CONVERTER_ENABLE();
    }
    return ret;
}
/**
 * @brief ADC_DeInitializaition
 * @param _adc
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType ADC_DeInit(const adc_config_t *_adc ){
    uint8 ret =E_OK;
    if( NULL == _adc){
        ret=E_NOT_OK;
    }
    else{
        /* Disable the ADC */
        ADC_CONVERTER_DISABLE();
        /* configure the interrupt  */
        #if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        ADC_INTERRUPT_DISABLE();
        #endif
#if  INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
        if(_adc->priority == INTERRUPT_HIGH_PRIORITY){INTERRUPT_GLOBAL_INTERRUPT_HIGH_DISABLE();}
        else if(_adc->priority == INTERRUPT_LOW_PRIORITY){INTERRUPT_GLOBAL_INTERRUPT_LOW_DISABLE();}
        else {/*Nothing*/}
#else
        INTERRUPT_GLOBAL_INTERRUPT_DISABLE();
        INTERRUPT_PEREPHRAL_INTERRUPT_disable();
#endif
    }
    return ret;
}
/**
 * @brief ADC_channel selection
 * @param _adc
 * @param channel
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType ADC_SelectChannel(const adc_config_t *_adc , adc_channel_select_t channel ){
    uint8 ret =E_OK;
    if( NULL == _adc){
        ret=E_NOT_OK;
    }
    else{
        /* configure the default channel */
         ADCON0bits.CHS = channel;
         adc_input_channel_port_configure(channel);
    }
    return ret;
}
/**
 * @brief ADC function to start conversion
 * @param _adc
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType ADC_StartConversion(const adc_config_t *_adc ){
    uint8 ret =E_OK;
    if( NULL == _adc){
        ret=E_NOT_OK;
    }
    else{
        ADC_START_CONVERSION();
        }
    return ret;
}
/**
 * @brief ADC function to get conversion status
 * @param _adc
 * @param conversion_status
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType ADC_IsConversionDone(const adc_config_t *_adc , uint8 *conversion_status){
    uint8 ret =E_OK;
    if((NULL == _adc) || (NULL == conversion_status)){
        ret=E_NOT_OK;
    }
    else{
        *conversion_status = (uint8)(!(ADCON0bits.GO_nDONE));
    }
    return ret;
}
/**
 * @brief function to get conversion result
 * @param _adc
 * @param conversion_result
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType ADC_GetConversionResult(const adc_config_t *_adc , adc_result_t *conversion_result){
    uint8 ret =E_OK;
    if( (NULL == _adc) || (NULL == conversion_result)){
        ret=E_NOT_OK;
    }
    else{
        if(_adc->result_format == ADC_RESULT_RIGHT){
            *conversion_result = (adc_result_t)((ADRESH << 8) +ADRESL);
        }
        else if(_adc->result_format == ADC_RESULT_LEFT){
            *conversion_result = (adc_result_t)(((ADRESH << 8) + ADRESL) >> 6);
        }
        else{
            *conversion_result = (adc_result_t)((ADRESH << 8) +ADRESL);
        }
    }
    return ret;
}
/**
 * @brief function to get conversion result
 * @param _adc
 * @param channel
 * @param conversion_status
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType ADC_GetConversion_by_polling(const adc_config_t *_adc , adc_channel_select_t channel, adc_result_t *conversion_result){
    uint8 ret =E_OK;
    uint8 l_conversion_status = ZERO_INIT;
    if((NULL == _adc) || (NULL == conversion_result)){
        ret=E_NOT_OK;
    }
    else{
        ret  = ADC_SelectChannel( _adc, channel );
        ret &= ADC_StartConversion(_adc);
        while(ADCON0bits.GO_nDONE);
        ret &= ADC_GetConversionResult(_adc,conversion_result);
    }
    return ret;
}

/**
 * @brief function to get conversion result
 * @param _adc
 * @param channel
 * @param conversion_status
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType ADC_StartConversion_by_Interrupt(const adc_config_t *_adc , adc_channel_select_t channel){
    uint8 ret =E_OK;
    uint8 l_conversion_status = ZERO_INIT;
    if(NULL == _adc){
        ret=E_NOT_OK;
    }
    else{
        ret  = ADC_SelectChannel( _adc, channel );
        ret &= ADC_StartConversion(_adc);
    }
    return ret;
}
static inline void adc_input_channel_port_configure(const adc_channel_select_t channel){
    switch(channel){
        case ADC_CHANNEL_AN0: SET_BIT(TRISA,_TRISA_RA0_POSN);  break;
        case ADC_CHANNEL_AN1: SET_BIT(TRISA,_TRISA_RA1_POSN);  break;
        case ADC_CHANNEL_AN2: SET_BIT(TRISA,_TRISA_RA2_POSN);  break;
        case ADC_CHANNEL_AN3: SET_BIT(TRISA,_TRISA_RA3_POSN);  break;
        case ADC_CHANNEL_AN4: SET_BIT(TRISA,_TRISA_RA5_POSN);  break;
        case ADC_CHANNEL_AN5: SET_BIT(TRISA,_TRISE_RE0_POSN);  break;
        case ADC_CHANNEL_AN6: SET_BIT(TRISA,_TRISE_RE1_POSN);  break;
        case ADC_CHANNEL_AN7: SET_BIT(TRISA,_TRISE_RE2_POSN);  break;
        case ADC_CHANNEL_AN8: SET_BIT(TRISA,_TRISB_RB2_POSN);  break;
        case ADC_CHANNEL_AN9: SET_BIT(TRISA,_TRISB_RB3_POSN);  break;
        case ADC_CHANNEL_AN10: SET_BIT(TRISA,_TRISB_RB1_POSN); break;
        case ADC_CHANNEL_AN11: SET_BIT(TRISA,_TRISB_RB4_POSN); break;
        case ADC_CHANNEL_AN12: SET_BIT(TRISA,_TRISB_RB0_POSN); break;
        default : {/* Nothing */}
        
    }
}

void ADC_ISR (void){
/* clear flag bit */
    ADC_INTERRUPT_FLAG_CLEAR();
    /* code */
    /* callback function gets called */
    if(ADC_InterruptHandler){ ADC_InterruptHandler(); }
}