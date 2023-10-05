/* 
 * File:   mcal_external_interrupt.c
 * Author: minas
 *
 * Created on September 5, 2023, 8:35 AM
 */

#include "mcal_external_interrupt.h"

static InterruptHandler INT0_InterruptHandler = NULL;
static InterruptHandler INT1_InterruptHandler = NULL; 
static InterruptHandler INT2_InterruptHandler = NULL; 

static InterruptHandler RB4_InterruptHandler_LOW = NULL;
static InterruptHandler RB4_InterruptHandler_HIGH = NULL;
static InterruptHandler RB5_InterruptHandler_LOW = NULL;
static InterruptHandler RB5_InterruptHandler_HIGH = NULL;
static InterruptHandler RB6_InterruptHandler_LOW = NULL;
static InterruptHandler RB6_InterruptHandler_HIGH = NULL;
static InterruptHandler RB7_InterruptHandler_LOW = NULL;
static InterruptHandler RB7_InterruptHandler_HIGH = NULL;

static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj);

#if EXTERNAL_INTERRUPT_INTX_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
void INT0_ISR (void){
/* clear flag bit */
    EXT_INT0_INTERRUPT_FLAG_CLEAR();
    /* code */
    /* callback function gets called */
    if(INT0_InterruptHandler){ INT0_InterruptHandler(); }
}
void INT1_ISR (void){
/* clear flag bit */
    EXT_INT1_INTERRUPT_FLAG_CLEAR();
    /* code */
    /* callback function gets called */
    if(INT1_InterruptHandler){ INT1_InterruptHandler(); }
}
void INT2_ISR (void){
/* clear flag bit */
    EXT_INT2_INTERRUPT_FLAG_CLEAR();
    /* code */
    /* callback function gets called */
    if(INT2_InterruptHandler){ INT2_InterruptHandler(); }
}
void RB4_ISR (uint8 pin4_source){
/* clear flag bit */
    EXT_RBx_FLAG_CLEAR();
    /* code */
    /* callback function gets called */
    if(pin4_source==0){
    if(RB4_InterruptHandler_LOW){ RB4_InterruptHandler_LOW(); }
    }
    else{
    if(RB4_InterruptHandler_HIGH){ RB4_InterruptHandler_HIGH(); }
    }
}
void RB5_ISR (uint8 pin5_source){
/* clear flag bit */
    EXT_RBx_FLAG_CLEAR();
    /* code */
    /* callback function gets called */
    if(pin5_source==0){
    if(RB5_InterruptHandler_LOW){ RB5_InterruptHandler_LOW(); }
    }
    else{
    if(RB5_InterruptHandler_HIGH){ RB5_InterruptHandler_HIGH(); }
    }
}
void RB6_ISR (uint8 pin6_source){
/* clear flag bit */
    EXT_RBx_FLAG_CLEAR();
    /* code */
    /* callback function gets called */
    if(pin6_source==0){
    if(RB6_InterruptHandler_LOW){ RB6_InterruptHandler_LOW(); }
    }
    else{
    if(RB6_InterruptHandler_HIGH){ RB6_InterruptHandler_HIGH(); }
    }
}
void RB7_ISR (uint8 pin7_source){
/* clear flag bit */
    EXT_RBx_FLAG_CLEAR();
    /* code */
    /* callback function gets called */
    if(pin7_source==0){
    if(RB7_InterruptHandler_LOW){ RB7_InterruptHandler_LOW(); }
    }
    else{
    if(RB7_InterruptHandler_HIGH){ RB7_InterruptHandler_HIGH(); }
    }
}
#endif
/**
 * @brief 
 * @param int_obj
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_obj){
Std_ReturnType ret =E_OK;
    if( NULL == int_obj){
        ret=E_NOT_OK;
    }
    else{
    /* disable the externa; interrupt */
        ret = Interrupt_INTx_Disable(int_obj);
        /* clear interrupt flag : external did not occur */
        Interrupt_INTx_Clear_Flag(int_obj);
        /* configure external interrupt edge */
        ret &= Interrupt_INTx_Edge_Init(int_obj);
        /* configure external interrupt priority */
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
        ret &= Interrupt_INTx_Priority_Init(int_obj);
#endif
        /* configure external interrupt I/O pin */
        ret &= Interrupt_INTx_Pin_Init(int_obj);
        /* configure external interrupt callback */
        ret &= Interrupt_INTx_SetInterruptHandler(int_obj);
        /* enable the external interrupt */
        ret &= Interrupt_INTx_Enable(int_obj);

    }
    return ret;
}
/**
 * @brief 
 * @param int_obj
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret =E_OK;
    if( NULL == int_obj){
        ret=E_NOT_OK;
    }
    else{
        ret = Interrupt_INTx_Disable(int_obj);
    }
    return ret;
}
/**
 * @brief 
 * @param int_obj
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
Std_ReturnType Interrupt_RBx_Init(const interrupt_RBx_t *int_obj){
    Std_ReturnType ret =E_OK;
    if( NULL == int_obj){
        ret=E_NOT_OK;
    }
    else{
    EXT_RBx_INTERRUPT_DISABLE();
    EXT_RBx_FLAG_CLEAR();
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PRIORITY_LEVEL_ENABLE();
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){
                    INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
                    EXT_RBx_INTERRUPT_PRIORITY_LOW();
                }
                else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority){
                    INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
                    EXT_RBx_INTERRUPT_PRIORITY_HIGH();
                }
                else{/*nothing*/}
#else
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
                INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif
                /*initialize the pin of the interrupt*/
                ret = gpio_pin_direction_initialize(&(int_obj->mcu_pin));
                /*initialize of the call back function*/
                switch(int_obj->mcu_pin.pin){
                    case PIN4:
                        RB4_InterruptHandler_HIGH=int_obj->EXT_interruptHandler_HIGH;
                        RB4_InterruptHandler_LOW=int_obj->EXT_interruptHandler_LOW;
                        break;
                    case PIN5:
                        RB5_InterruptHandler_HIGH=int_obj->EXT_interruptHandler_HIGH;
                        RB5_InterruptHandler_LOW=int_obj->EXT_interruptHandler_LOW;
                        break;
                    case PIN6:
                        RB6_InterruptHandler_HIGH=int_obj->EXT_interruptHandler_HIGH;
                        RB6_InterruptHandler_LOW=int_obj->EXT_interruptHandler_LOW;
                        break;
                    case PIN7:
                        RB7_InterruptHandler_HIGH=int_obj->EXT_interruptHandler_HIGH;
                        RB7_InterruptHandler_LOW=int_obj->EXT_interruptHandler_LOW;
                        break;
                    default:
                        ret=E_NOT_OK;
                }
    EXT_RBx_INTERRUPT_ENABLE();
    }
    return ret;
}
/**
 * @brief 
 * @param int_obj
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
Std_ReturnType Interrupt_RBx_DeInit(const interrupt_RBx_t *int_obj){
    Std_ReturnType ret =E_OK;
    if( NULL == int_obj){
        ret=E_NOT_OK;
    }
    else{
    
    }
    return ret;
}
/**
 * @brief 
 * @param int_obj
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
#if EXTERNAL_INTERRUPT_INTX_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj){
Std_ReturnType ret =E_OK;
    if( NULL == int_obj){
        ret=E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0: 
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
                INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
#else
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
                INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif
                EXT_INT0_INTERRUPT_ENABLE(); 
                break;
            case INTERRUPT_EXTERNAL_INT1:
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PRIORITY_LEVEL_ENABLE();
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();}
                else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority){INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();}
                else{/*nothing*/}
#else
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
                INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif                
                EXT_INT1_INTERRUPT_ENABLE(); 
                break;
            case INTERRUPT_EXTERNAL_INT2: 
#if   INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PRIORITY_LEVEL_ENABLE();
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();}
                else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority){INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();}
                else{/*nothing*/}
#else
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
                INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif
                EXT_INT2_INTERRUPT_ENABLE(); 
                break;
            default : ret=E_NOT_OK;

        }
    }
    return ret;
}
#endif
/**
 * @brief 
 * @param int_obj
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
#if EXTERNAL_INTERRUPT_INTX_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj){
Std_ReturnType ret =E_OK;
    if( NULL == int_obj){
        ret=E_NOT_OK;
    }
    else{
    switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0: EXT_INT0_INTERRUPT_DISABLE(); break;
            case INTERRUPT_EXTERNAL_INT1: EXT_INT1_INTERRUPT_DISABLE(); break;
            case INTERRUPT_EXTERNAL_INT2: EXT_INT2_INTERRUPT_DISABLE (); break;
            default : ret=E_NOT_OK;

        }
    }
    return ret;
}
#endif
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/**
 * @brief 
 * @param int_obj
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj){
Std_ReturnType ret =E_OK;
    if( NULL == int_obj){
        ret=E_NOT_OK;
    }
    else{
    switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT1: 
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){EXT_INT1_LOW_PRIORITY_SET();}
                else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority){EXT_INT1_HIGH_PRIORITY_SET();}
                else{/*nothing*/}
            break;
            case INTERRUPT_EXTERNAL_INT2: 
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){EXT_INT2_LOW_PRIORITY_SET();}
                else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority){EXT_INT2_HIGH_PRIORITY_SET();}
                else{/*nothing*/}
            break;
            default : ret=E_NOT_OK;
        }
    }
    return ret;
}
#endif
/**
 * @brief 
 * @param int_obj
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
#if EXTERNAL_INTERRUPT_INTX_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj){
Std_ReturnType ret =E_OK;
    if( NULL == int_obj){
        ret=E_NOT_OK;
    }
    else{
    switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0: 
                if(INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT0_INTERRUPT_FALLING_EDGE();}
                else if (INTERRUPT_RISING_EDGE == int_obj->edge){EXT_INT0_INTERRUPT_RISING_EDGE();}
                else{/*nothing*/}
            break;
            case INTERRUPT_EXTERNAL_INT1: 
                if(INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT1_INTERRUPT_FALLING_EDGE();}
                else if (INTERRUPT_RISING_EDGE == int_obj->edge){EXT_INT1_INTERRUPT_RISING_EDGE();}
                else{/*nothing*/}
            break;
            case INTERRUPT_EXTERNAL_INT2: 
                if(INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT2_INTERRUPT_FALLING_EDGE();}
                else if (INTERRUPT_RISING_EDGE == int_obj->edge){EXT_INT2_INTERRUPT_RISING_EDGE();}
                else{/*nothing*/}
            break;
            default : ret=E_NOT_OK;
        }
    }
    return ret;
}
#endif
/**
 * @brief 
 * @param int_obj
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj){
Std_ReturnType ret =E_OK;
    if( NULL == int_obj){
        ret=E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_initialize(&(int_obj->mcu_pin));
    }
    return ret; 
}

/**
 * @brief 
 * @param int_obj
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
#if EXTERNAL_INTERRUPT_INTX_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj){
Std_ReturnType ret =E_OK;
    if( NULL == int_obj){
        ret=E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0: 
                EXT_INT0_INTERRUPT_FLAG_CLEAR(); break;
            case INTERRUPT_EXTERNAL_INT1: 
                EXT_INT1_INTERRUPT_FLAG_CLEAR(); break;
            case INTERRUPT_EXTERNAL_INT2: 
                EXT_INT2_INTERRUPT_FLAG_CLEAR(); break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif
static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void)){
Std_ReturnType ret =E_OK;
if(NULL == InterruptHandler){
    ret = E_NOT_OK;
}
else{
    INT0_InterruptHandler = InterruptHandler;
}
return ret;
}

static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void)){
Std_ReturnType ret =E_OK;
if(NULL == InterruptHandler){
    ret = E_NOT_OK;
}
else{
    INT1_InterruptHandler = InterruptHandler;
}
return ret;
}
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void)){
    Std_ReturnType ret =E_OK;
    if(NULL == InterruptHandler){
    ret = E_NOT_OK;
    }
    else{
    INT2_InterruptHandler = InterruptHandler;
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj){
Std_ReturnType ret =E_OK;
    if( NULL == int_obj){
        ret=E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0: 
                INT0_SetInterruptHandler(int_obj->EXT_interruptHandler); break;
            case INTERRUPT_EXTERNAL_INT1: 
                INT1_SetInterruptHandler(int_obj->EXT_interruptHandler); break;
            case INTERRUPT_EXTERNAL_INT2: 
                INT2_SetInterruptHandler(int_obj->EXT_interruptHandler); break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}