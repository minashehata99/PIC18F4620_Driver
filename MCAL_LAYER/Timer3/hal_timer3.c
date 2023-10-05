/* 
 * File:   hal_timer3.c
 * Author: minas
 *
 * Created on September 12, 2023, 12:17 AM
 */


#include "hal_timer3.h"

#if TIMER3_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
static InterruptHandler Timer3_InterruptHandler = NULL;
#endif
static inline void Timer3_Mode_Select(const timer3_t *_timer);
static uint16 timer3_preload = ZERO_INIT;

/**
 * @brief timer3_Initializaition
 * @param _timer
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
    Std_ReturnType Timer3_Init(const timer3_t *_timer ){
    Std_ReturnType ret =E_OK;
    if(NULL == _timer){
        ret=E_NOT_OK;
    }
    else{
        TIMER3_MODULE_DISABLE();
        TIMER3_PRESCALER_SELECT(_timer->timer3_prescaler_value);
        Timer3_Mode_Select(_timer);
        TMR3H = (_timer->timer3_preloaded_value) >>8;
        TMR3L = (uint8)(_timer->timer3_preloaded_value);
        timer3_preload = _timer->timer3_preloaded_value;
#if TIMER3_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER3_INTERRUPT_ENABLE();
        TIMER3_INTERRUPT_FLAG_CLEAR();
        Timer3_InterruptHandler = _timer->Timer3_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_LEVEL_ENABLE();
        
        if(INTERRUPT_HIGH_PRIORITY == _timer->priority){
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            TIMER3_HIGH_PRIORITY_SET();
        }
        else if(INTERRUPT_LOW_PRIORITY == _timer->priority){
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            TIMER3_LOW_PRIORITY_SET();
        }
        else{/*Nothing*/}
#else      
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif
#endif
        TIMER3_MODULE_ENABLE();
    }
    return ret;
    }
    
/**
 * @brief timer3_DeInitializaition
 * @param _timer
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */    
    Std_ReturnType Timer3_DeInit(const timer3_t *_timer ){
    Std_ReturnType ret =E_OK;
    if(NULL == _timer){
        ret=E_NOT_OK;
    }
    else{
        TIMER3_MODULE_DISABLE();
#if TIMER3_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER3_INTERRUPT_DISABLE();
#endif
    }
    return ret;
    }
    
/**
 * @brief write value to the timer3 register
 * @param _timer
 * @param _value
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */    
    Std_ReturnType Timer3_Write_value(const timer3_t *_timer ,uint16 _value){
    Std_ReturnType ret =E_OK;
    if(NULL == _timer){
        ret=E_NOT_OK;
    }
    else{
        TMR3H = (_value) >>8;
        TMR3L = (uint8)(_value);
    }
    return ret;
    }
    
/**
 * @brief read value from the timer3 register
 * @param _timer
 * @param _value
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */    
    Std_ReturnType Timer3_Read_value(const timer3_t *_timer ,uint16 *_value){
    Std_ReturnType ret =E_OK;
    uint8 l_tmr3l = ZERO_INIT , ltmr3h = ZERO_INIT;
    if((NULL == _timer) && (NULL == _value)){
        ret=E_NOT_OK;
    }
    else{
    l_tmr3l = TMR3L;
    ltmr3h = TMR3H;
    *_value = (uint16)((ltmr3h << 8) + l_tmr3l);
    }
    return ret;
    }
    
    
    void Timer3_ISR (void){
/* clear flag bit */
    TIMER3_INTERRUPT_FLAG_CLEAR();
    TMR3H = (timer3_preload) >>8;
    TMR3L = (uint8)(timer3_preload);
    /* code */
    /* callback function gets called */
    if(Timer3_InterruptHandler){ Timer3_InterruptHandler(); }
}

static inline void Timer3_Mode_Select(const timer3_t *_timer){
    if(TIMER3_TIMER_MODE == _timer->timer3_mode){
        TIMER3_TIMER_MODE_ENABLE();
    }
    else if(TIMER3_COUNTER_MODE == _timer->timer3_mode){
        TIMER3_COUNTER_MODE_ENABLE();
        if(TIMER3_ASYNC_COUNTER_MODE == _timer->timer3_counter_mode){
            TIMER3_ASYNC_COUNTER_MODE_ENABLE();
        }
        else if(TIMER3_SYNC_COUNTER_MODE == _timer->timer3_counter_mode){
            TIMER3_SYNC_COUNTER_MODE_ENABLE();
        }
        else{/*Nothing*/}
    }
    else{/*Nothing*/}
}