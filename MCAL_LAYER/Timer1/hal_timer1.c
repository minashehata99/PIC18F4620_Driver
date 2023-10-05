/* 
 * File:   hal_timer1.c
 * Author: minas
 *
 * Created on September 11, 2023, 6:43 AM
 */

#include "hal_timer1.h"

#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
static InterruptHandler Timer1_InterruptHandler = NULL;
#endif
static inline void Timer1_Mode_Select(const timer1_t *_timer);
static uint16 timer1_preload = ZERO_INIT;

/**
 * @brief timer1_Initializaition
 * @param _timer
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
Std_ReturnType Timer1_Init(const timer1_t *_timer ){
Std_ReturnType ret =E_OK;
    if(NULL == _timer){
        ret=E_NOT_OK;
    }
    else{
        TIMER1_MODULE_DISABLE();
        T1CONbits.T1CKPS = _timer->prescaler_value;
        Timer1_Mode_Select(_timer);
        TMR1H = (_timer->timer1_preloaded_value) >>8;
        TMR1L = (uint8)(_timer->timer1_preloaded_value);
        timer1_preload = _timer->timer1_preloaded_value;
        #if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER1_INTERRUPT_ENABLE();
        TIMER1_INTERRUPT_FLAG_CLEAR();
        Timer1_InterruptHandler = _timer->Timer1_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_LEVEL_ENABLE();
        
        if(INTERRUPT_HIGH_PRIORITY == _timer->priority){
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            TIMER1_HIGH_PRIORITY_SET();
        }
        else if(INTERRUPT_LOW_PRIORITY == _timer->priority){
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            TIMER1_LOW_PRIORITY_SET();
        }
        else{/*Nothing*/}
#else      
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif
#endif
        TIMER1_MODULE_ENABLE();
    }
    return ret;
}



/**
 * @brief timer1_DeInitializaition
 * @param _timer
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
Std_ReturnType Timer1_DeInit(const timer1_t *_timer ){
Std_ReturnType ret =E_OK;
    if(NULL == _timer){
        ret=E_NOT_OK;
    }
    else{
         TIMER1_MODULE_DISABLE();
#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER1_INTERRUPT_DISABLE();
#endif
    }
    return ret;
}

/**
 * @brief write value to the timer1 register
 * @param _timer
 * @param _value
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
Std_ReturnType Timer1_Write_value(const timer1_t *_timer ,uint16 _value){
Std_ReturnType ret =E_OK;
    if(NULL == _timer){
        ret=E_NOT_OK;
    }
    else{
        TMR1H = (_value) >>8;
        TMR1L = (uint8)(_value);
    }
    return ret;
}

/**
 * @brief read value from the timer1 register
 * @param _timer
 * @param _value
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
Std_ReturnType Timer1_Read_value(const timer1_t *_timer ,uint16 *_value){
Std_ReturnType ret =E_OK;
uint8 l_tmr1l = ZERO_INIT , ltmr1h = ZERO_INIT;
    if((NULL == _timer) && (NULL == _value)){
        ret=E_NOT_OK;
    }
    else{
      l_tmr1l = TMR1L;
    ltmr1h = TMR1H;
    *_value = (uint16)((ltmr1h << 8) + l_tmr1l);
    }
    return ret;
}
   
void Timer1_ISR (void){
/* clear flag bit */
    TIMER1_INTERRUPT_FLAG_CLEAR();
    TMR1H = (timer1_preload) >>8;
    TMR1L = (uint8)(timer1_preload);
    /* code */
    /* callback function gets called */
    if(Timer1_InterruptHandler){ Timer1_InterruptHandler(); }
}

static inline void Timer1_Mode_Select(const timer1_t *_timer){
    if(TIMER1_TIMER_MODE == _timer->timer1_mode){
        TIMER1_TIMER_MODE_ENABLE();
    }
    else if(TIMER1_COUNTER_MODE == _timer->timer1_mode){
        TIMER1_COUNTER_MODE_ENABLE();
        if(TIMER1_ASYNC_COUNTER_MODE == _timer->timer1_counter_mode){
            TIMER1_ASYNC_COUNTER_MODE_ENABLE();
        }
        else if(TIMER1_SYNC_COUNTER_MODE == _timer->timer1_counter_mode){
            TIMER1_SYNC_COUNTER_MODE_ENABLE();
        }
        else{/*Nothing*/}
    }
    else{/*Nothing*/}
}