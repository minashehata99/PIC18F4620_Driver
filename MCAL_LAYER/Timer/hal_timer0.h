/* 
 * File:   hal_timer0.h
 * Author: minas
 *
 * Created on September 10, 2023, 11:36 PM
 */

#ifndef HAL_TIMER0_H
#define	HAL_TIMER0_H

/* Section :  Includes   */

#include "../proc/pic18f4620.h"
#include "../GPIO/hal_gpio.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include "../../MCAL_LAYER/mcal_std_types.h"

/* Section :  Macro declaration   */

#define TIMER0_PRESCALER_ENABLE_CFG   1
#define TIMER0_PRESCALER_DISABLE_CFG  0

#define TIMER0_RISING_EDGE_CFG   1
#define TIMER0_FALLING_EDGE_CFG  0

#define TIMER0_COUNTER_MODE   0
#define TIMER0_TIMER_MODE     1

#define TIMER0_8BIT_REGISTER_MODE   1
#define TIMER0_16BIT_REGISTER_MODE  0

/* Section :  Macro function   */

#define TIMER0_MODULE_ENABLE()        (T0CONbits.TMR0ON = 1)
#define TIMER0_MODULE_DISABLE()       (T0CONbits.TMR0ON = 0)

#define TIMER0_PRESCALLER_ENABLE()        (T0CONbits.PSA = 0)
#define TIMER0_PRESCALLER_DISABLE()       (T0CONbits.PSA = 1)


#define TIMER0_RISING_EDGE_ENABLE()         (T0CONbits.T0SE = 0)
#define TIMER0_FALLING_EDGE_ENABLE()       (T0CONbits.T0SE  = 1)

#define TIMER0_COUNTER_MODE_ENABLE()         (T0CONbits.T0CS = 1)
#define TIMER0_TIMER_MODE_ENABLE()           (T0CONbits.T0CS = 0)

#define TIMER0_8BIT_REGISTER_MODE_ENABLE()        (T0CONbits.T08BIT = 1)
#define TIMER0_16BIT_REGISTER_MODE_ENABLE()       (T0CONbits.T08BIT = 0)

/* Section :  Data types   */

    typedef enum {
        TIMER0_PRESCALER_DIV_BY_2 = 0,
        TIMER0_PRESCALER_DIV_BY_4,
        TIMER0_PRESCALER_DIV_BY_8,
        TIMER0_PRESCALER_DIV_BY_16,
        TIMER0_PRESCALER_DIV_BY_32,
        TIMER0_PRESCALER_DIV_BY_64,        
        TIMER0_PRESCALER_DIV_BY_128,
        TIMER0_PRESCALER_DIV_BY_256        
    }timer0_prescaler_select_t;
            
    typedef struct {
#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (* Timer0_InterruptHandler)(void);
    interrupt_priority_cfg priority;
#endif
    timer0_prescaler_select_t prescaler_value;
    uint16 timer0_preloaded_value;
    uint8 prescaler_enable : 1;
    uint8 timer0_couter_edge_type  : 1;
    uint8 timer0_mode  : 1;
    uint8 timer0_register_size  : 1;
    uint8 timer0_reserved : 4;
    }timer0_t;

/* Section :  Function Declaration   */

Std_ReturnType Timer0_Init(const timer0_t *_timer );
Std_ReturnType Timer0_DeInit(const timer0_t *_timer );
Std_ReturnType Timer0_Write_value(const timer0_t *_timer ,uint16 _value);
Std_ReturnType Timer0_Read_value(const timer0_t *_timer ,uint16 *_value);
    
#endif	/* HAL_TIMER0_H */

