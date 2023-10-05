 /* 
 * File:   hal_timer0.c
 * Author: minas
 *
 * Created on September 10, 2023, 11:36 PM
 */


#include "hal_timer0.h"

static inline void Timer0_Mode_Select(const timer0_t *_timer);
static inline void Timer0_Prescaler_Config(const timer0_t *_timer);
static inline void Timer0_Register_Size_Config(const timer0_t *_timer);

#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
static InterruptHandler Timer0_InterruptHandler = NULL;
#endif

static uint16 timer0_preload = ZERO_INIT;

/**
 * @brief timer0_Initializaition
 * @param _timer
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
Std_ReturnType Timer0_Init(const timer0_t *_timer ){
Std_ReturnType ret =E_OK;
    if(NULL == _timer){
        ret=E_NOT_OK;
    }
    else{
        TIMER0_MODULE_DISABLE();
        Timer0_Prescaler_Config(_timer);
        Timer0_Mode_Select(_timer);
        Timer0_Register_Size_Config(_timer);
        TMR0H = (_timer->timer0_preloaded_value) >>8;
        TMR0L = (uint8)(_timer->timer0_preloaded_value);
        timer0_preload = _timer->timer0_preloaded_value;
#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER0_INTERRUPT_ENABLE();
        TIMER0_INTERRUPT_FLAG_CLEAR();
        Timer0_InterruptHandler = _timer->Timer0_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_LEVEL_ENABLE();
        
        if(INTERRUPT_HIGH_PRIORITY == _timer->priority){
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            TIMER0_HIGH_PRIORITY_SET();
        }
        else if(INTERRUPT_LOW_PRIORITY == _timer->priority){
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            TIMER0_LOW_PRIORITY_SET();
        }
        else{/*Nothing*/}
#else      
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif
#endif
        TIMER0_MODULE_ENABLE();
    }
    return ret;
}


/**
 * @brief timer0_DeInitializaition
 * @param _timer
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
Std_ReturnType Timer0_DeInit(const timer0_t *_timer ){
Std_ReturnType ret =E_OK;
    if(NULL == _timer){
        ret=E_NOT_OK;
    }
    else{
        TIMER0_MODULE_DISABLE();
        #if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER0_INTERRUPT_DISABLE();
        #endif
    }
    return ret;
}

/**
 * @brief write value to the timer0 register
 * @param _timer
 * @param _value
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
Std_ReturnType Timer0_Write_value(const timer0_t *_timer ,uint16 _value){
Std_ReturnType ret =E_OK;
    if(NULL == _timer){
        ret=E_NOT_OK;
    }
    else{
        TMR0H = (_value) >>8;
        TMR0L = (uint8)(_value);
    }
    return ret;
}

/**
 * @brief read value from the timer0 register
 * @param _timer
 * @param _value
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
Std_ReturnType Timer0_Read_value(const timer0_t *_timer ,uint16 *_value){
Std_ReturnType ret =E_OK;
uint8 l_tmr0l = ZERO_INIT , ltmr0h = ZERO_INIT;
    if((NULL == _timer) && (NULL == _value)){
        ret=E_NOT_OK;
    }
    else{
    l_tmr0l = TMR0L;
    ltmr0h = TMR0H;
    *_value = (uint16)((ltmr0h << 8) + l_tmr0l);
    }
    return ret;
}

void Timer0_ISR (void){
/* clear flag bit */
    TIMER0_INTERRUPT_FLAG_CLEAR();
    TMR0H = (timer0_preload) >>8;
    TMR0L = (uint8)(timer0_preload);
    /* code */
    /* callback function gets called */
    if(Timer0_InterruptHandler){ Timer0_InterruptHandler(); }
}

static inline void Timer0_Prescaler_Config(const timer0_t *_timer){
    if(TIMER0_PRESCALER_ENABLE_CFG == _timer->prescaler_enable){
        TIMER0_PRESCALLER_ENABLE();
        T0CONbits.T0PS = _timer->prescaler_value;
    }
    else if(TIMER0_PRESCALER_DISABLE_CFG == _timer->prescaler_enable){
        TIMER0_PRESCALLER_DISABLE();
    }
    else{/*Nothing*/}
}

static inline void Timer0_Mode_Select(const timer0_t *_timer){
    if(TIMER0_TIMER_MODE == _timer->timer0_mode){
        TIMER0_TIMER_MODE_ENABLE();
    }
    else if(TIMER0_COUNTER_MODE == _timer->timer0_mode){
        TIMER0_COUNTER_MODE_ENABLE();
        if(TIMER0_RISING_EDGE_CFG == _timer->timer0_couter_edge_type){TIMER0_RISING_EDGE_ENABLE(); }
        else if(TIMER0_FALLING_EDGE_CFG == _timer->timer0_couter_edge_type){TIMER0_FALLING_EDGE_ENABLE(); }
        else{/*Nothing*/}
    }
    else{/*Nothing*/}
}

static inline void Timer0_Register_Size_Config(const timer0_t *_timer){
    if(TIMER0_8BIT_REGISTER_MODE == _timer->timer0_register_size){
        TIMER0_8BIT_REGISTER_MODE_ENABLE();
    }
    else if(TIMER0_16BIT_REGISTER_MODE == _timer->timer0_register_size){
        TIMER0_16BIT_REGISTER_MODE_ENABLE();
    }
    else{/*Nothing*/}
}