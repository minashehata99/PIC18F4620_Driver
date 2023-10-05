
/* 
 * File:   hal_timer2.c
 * Author: minas
 *
 * Created on September 12, 2023, 12:14 AM
 */

#include "hal_timer2.h"

#if TIMER2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
static InterruptHandler Timer2_InterruptHandler = NULL;
#endif
static uint8 timer2_preload = ZERO_INIT;

/**
 * @brief timer2_Initializaition
 * @param _timer
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
    Std_ReturnType Timer2_Init(const timer2_t *_timer ){
    Std_ReturnType ret =E_OK;
    if(NULL == _timer){
        ret=E_NOT_OK;
    }
    else{
        TIMER2_MODULE_DISABLE();
        TIMER2_PRESCALER_SELECT(_timer->timer2_prescaler_value);
        TIMER2_POSTSCALER_SELECT(_timer->timer2_postscaler_value);
        TMR2 = _timer->timer2_preloaded_value; 
        timer2_preload = _timer->timer2_preloaded_value; 
#if TIMER2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER2_INTERRUPT_ENABLE();
        TIMER2_INTERRUPT_FLAG_CLEAR();
        Timer2_InterruptHandler = _timer->Timer2_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_LEVEL_ENABLE();
        
        if(INTERRUPT_HIGH_PRIORITY == _timer->priority){
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            TIMER2_HIGH_PRIORITY_SET();
        }
        else if(INTERRUPT_LOW_PRIORITY == _timer->priority){
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            TIMER2_LOW_PRIORITY_SET();
        }
        else{/*Nothing*/}
#else      
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif
#endif
        TIMER2_MODULE_ENABLE();
    }
    return ret;      
    }
    
 /**
 * @brief timer2_DeInitializaition
 * @param _timer
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
    Std_ReturnType Timer2_DeInit(const timer2_t *_timer ){
    Std_ReturnType ret =E_OK;
    if(NULL == _timer){
        ret=E_NOT_OK;
    }
    else{
             TIMER2_MODULE_DISABLE();
#if TIMER2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER2_INTERRUPT_DISABLE();
#endif
    }
    return ret;      
    }
/**
 * @brief write value to the timer2 register
 * @param _timer
 * @param _value
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */    
    Std_ReturnType Timer2_Write_value(const timer2_t *_timer ,uint8 _value){
    Std_ReturnType ret =E_OK;
    if(NULL == _timer){
        ret=E_NOT_OK;
    }
    else{
     TMR2 = _value;
    }
    return ret;    
    }
/**
 * @brief read value from the timer2 register
 * @param _timer
 * @param _value
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */    
    Std_ReturnType Timer2_Read_value(const timer2_t *_timer ,uint8 *_value){
    Std_ReturnType ret =E_OK;
    if((NULL == _timer) && (NULL == _value)){
        ret=E_NOT_OK;
    }
    else{
     *_value = TMR2;
    }
    return ret;
    }
    
    
void Timer2_ISR (void){
/* clear flag bit */
    TIMER2_INTERRUPT_FLAG_CLEAR();
    TMR2 = timer2_preload;
    /* code */
    /* callback function gets called */
    if(Timer2_InterruptHandler){ Timer2_InterruptHandler(); }
}