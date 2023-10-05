/* 
 * File:   hal_timer3.h
 * Author: minas
 *
 * Created on September 12, 2023, 12:17 AM
 */

#ifndef HAL_TIMER3_H
#define	HAL_TIMER3_H

/* Section :  Includes   */

#include "../proc/pic18f4620.h"
#include "../GPIO/hal_gpio.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include "../mcal_std_types.h"

/* Section :  Macro declaration   */

#define TIMER3_COUNTER_MODE   1
#define TIMER3_TIMER_MODE     0 

#define TIMER3_ASYNC_COUNTER_MODE   1
#define TIMER3_SYNC_COUNTER_MODE    0 

#define TIMER3_PRESCALER_DIV_BY_1  0
#define TIMER3_PRESCALER_DIV_BY_2  1
#define TIMER3_PRESCALER_DIV_BY_4  2
#define TIMER3_PRESCALER_DIV_BY_8  3

#define TIMER3_RW_REG_16BIT_MODE   1
#define TIMER3_RW_REG_8BIT_MODE    0 

/* Section :  Macro function   */

/* TIMER 3 Enable/Disable functions*/
#define TIMER3_MODULE_ENABLE()        (T3CONbits.TMR3ON = 1)
#define TIMER3_MODULE_DISABLE()       (T3CONbits.TMR3ON = 0)
/* TIMER 3 TIMER/COUNTER Mode functions */
#define TIMER3_COUNTER_MODE_ENABLE()         (T3CONbits.TMR3CS = 1)
#define TIMER3_TIMER_MODE_ENABLE()           (T3CONbits.TMR3CS = 0)
/* TIMER 3 External clock sync Enable/Disable */
#define TIMER3_ASYNC_COUNTER_MODE_ENABLE()   (T3CONbits.T3SYNC = 1)
#define TIMER3_SYNC_COUNTER_MODE_ENABLE()    (T3CONbits.T3SYNC = 0)
/* Timer3 input clock PRE-scaler */
#define TIMER3_PRESCALER_SELECT(_PRESCALER_)        ( T3CONbits.T3CKPS = _PRESCALER_)
/*8/16-Bit Read/Write Mode Enable*/
#define TIMER3_RW_REG_16BIT_MODE_ENABLE()          (T3CONbits.RD16 = 1)
#define TIMER3_RW_REG_8BIT_MODE_ENABLE()           (T3CONbits.RD16 = 0)
/* Section :  Data types   */

    typedef struct{
#if TIMER3_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (* Timer3_InterruptHandler)(void);
    interrupt_priority_cfg priority;
#endif
    uint16 timer3_preloaded_value;
    uint8 timer3_prescaler_value : 2;
    uint8 timer3_mode  : 1;
    uint8 timer3_counter_mode : 1;
    uint8 timer3_reg_wr_mode : 1;
    uint8 timer3_reserved : 3;
    }timer3_t;

/* Section :  Function Declaration   */
    Std_ReturnType Timer3_Init(const timer3_t *_timer );
    Std_ReturnType Timer3_DeInit(const timer3_t *_timer );
    Std_ReturnType Timer3_Write_value(const timer3_t *_timer ,uint16 _value);
    Std_ReturnType Timer3_Read_value(const timer3_t *_timer ,uint16 *_value);
    
#endif	/* HAL_TIMER3_H */

