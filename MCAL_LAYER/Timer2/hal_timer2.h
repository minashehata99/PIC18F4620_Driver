/* 
 * File:   hal_timer2.h
 * Author: minas
 *
 * Created on September 12, 2023, 12:14 AM
 */

#ifndef HAL_TIMER2_H
#define	HAL_TIMER2_H

/* Section :  Includes   */

#include "../proc/pic18f4620.h"
#include "../GPIO/hal_gpio.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include "../mcal_std_types.h"

/* Section :  Macro declaration   */

/* post scaler macro definithions */
#define TIMER2_POSTSCALER_DIV_BY_1     0
#define TIMER2_POSTSCALER_DIV_BY_2     1
#define TIMER2_POSTSCALER_DIV_BY_3     2
#define TIMER2_POSTSCALER_DIV_BY_4     3
#define TIMER2_POSTSCALER_DIV_BY_5     4
#define TIMER2_POSTSCALER_DIV_BY_6     5
#define TIMER2_POSTSCALER_DIV_BY_7     6
#define TIMER2_POSTSCALER_DIV_BY_8     7
#define TIMER2_POSTSCALER_DIV_BY_9     8
#define TIMER2_POSTSCALER_DIV_BY_10    9
#define TIMER2_POSTSCALER_DIV_BY_11    10
#define TIMER2_POSTSCALER_DIV_BY_12    11
#define TIMER2_POSTSCALER_DIV_BY_13    12
#define TIMER2_POSTSCALER_DIV_BY_14    13
#define TIMER2_POSTSCALER_DIV_BY_15    14
#define TIMER2_POSTSCALER_DIV_BY_16    15
 
/* PRE scaler macro definithions */
#define TIMER2_PRESCALER_DIV_BY_1      0
#define TIMER2_PRESCALER_DIV_BY_4      1
#define TIMER2_PRESCALER_DIV_BY_16     2

/* Section :  Macro function   */

/* TIMER 2 Enable/Disable functions*/
#define TIMER2_MODULE_ENABLE()        (T2CONbits.TMR2ON = 1)
#define TIMER2_MODULE_DISABLE()       (T2CONbits.TMR2ON = 0)

/* Timer2 input clock PRE-scaler */
#define TIMER2_PRESCALER_SELECT(_PRESCALER_)        ( T2CONbits.T2CKPS = _PRESCALER_)
/* Timer2 input clock post-scaler */
#define TIMER2_POSTSCALER_SELECT(_POSTSCALER_)      ( T2CONbits.TOUTPS = _POSTSCALER_)
/* Section :  Data types   */

    typedef struct{
#if TIMER2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (* Timer2_InterruptHandler)(void);
    interrupt_priority_cfg priority;
#endif
    uint8 timer2_preloaded_value;
    uint8 timer2_postscaler_value : 4;
    uint8 timer2_prescaler_value : 2;
    uint8 timer2_reserved :2;
    }timer2_t;

/* Section :  Function Declaration   */

    Std_ReturnType Timer2_Init(const timer2_t *_timer );
    Std_ReturnType Timer2_DeInit(const timer2_t *_timer );
    Std_ReturnType Timer2_Write_value(const timer2_t *_timer ,uint8 _value);
    Std_ReturnType Timer2_Read_value(const timer2_t *_timer ,uint8 *_value);
    
#endif	/* HAL_TIMER2_H */

