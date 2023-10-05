/* 
 * File:   hal_ccp1.h
 * Author: minas
 *
 * Created on September 13, 2023, 5:12 PM
 */

#ifndef HAL_CCP1_H
#define	HAL_CCP1_H

/* Section :  Includes   */
#include "ccp1_cfg.h"
#include "../proc/pic18f4620.h"
#include "../../MCAL_LAYER/mcal_std_types.h"
#include "../../MCAL_LAYER/interrupt/mcal_internal_interrupt.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
/* Section :  Macro declaration   */

/* CCP1 Module Mode select */


#define CCP_MODULE_DISABLE                        ((uint8)0x00)
#define CCP_CAPTURE_MODE_1_FALLING_EDGE           ((uint8)0x04)
#define CCP_CAPTURE_MODE_1_RISING_EDGE            ((uint8)0x05)
#define CCP_CAPTURE_MODE_4_RISING_EDGE            ((uint8)0x06)
#define CCP_CAPTURE_MODE_16_RISING_EDGE           ((uint8)0x07)
#define CCP_COMPARE_MODE_SET_PIN_LOW              ((uint8)0x08)
#define CCP_COMPARE_MODE_SET_PIN_HIGH             ((uint8)0x09)
#define CCP_COMPARE_MODE_TOGGLE_ON_MATCH          ((uint8)0x02)
#define CCP_COMPARE_MODE_GEN_SW_INTERRUPT         ((uint8)0x0A)
#define CCP_COMPARE_MODE__GEN_EVENT               ((uint8)0x0B)
#define CCP_PWM_MODE                              ((uint8)0x0C)

/* CCP Capture Mode State */
#define CCP_CAPTURE_NOT_READY     0x00
#define CCP_CAPTURE_READY         0x01

/* CCP Compare Mode State */
#define CCP_COMPARE_NOT_READY     0x00
#define CCP_COMPARE_READY         0x01

/* post scaler macro definithions */
#define CCP_TIMER2_POSTSCALER_DIV_BY_1     1
#define CCP_TIMER2_POSTSCALER_DIV_BY_2     2
#define CCP_TIMER2_POSTSCALER_DIV_BY_3     3
#define CCP_TIMER2_POSTSCALER_DIV_BY_4     4
#define CCP_TIMER2_POSTSCALER_DIV_BY_5     5
#define CCP_TIMER2_POSTSCALER_DIV_BY_6     6
#define CCP_TIMER2_POSTSCALER_DIV_BY_7     7
#define CCP_TIMER2_POSTSCALER_DIV_BY_8     8
#define CCP_TIMER2_POSTSCALER_DIV_BY_9     9
#define CCP_TIMER2_POSTSCALER_DIV_BY_10    10
#define CCP_TIMER2_POSTSCALER_DIV_BY_11    11
#define CCP_TIMER2_POSTSCALER_DIV_BY_12    12
#define CCP_TIMER2_POSTSCALER_DIV_BY_13    13
#define CCP_TIMER2_POSTSCALER_DIV_BY_14    14
#define CCP_TIMER2_POSTSCALER_DIV_BY_15    15
#define CCP_TIMER2_POSTSCALER_DIV_BY_16    16
 
/* PRE scaler macro definithions */
#define CCP_TIMER2_PRESCALER_DIV_BY_1      1
#define CCP_TIMER2_PRESCALER_DIV_BY_4      4
#define CCP_TIMER2_PRESCALER_DIV_BY_16     16

/* Section :  Macro function   */

#define CCP1_SET_MODE(_CONFIG)       (CCP1CONbits.CCP1M = _CONFIG)
#define CCP2_SET_MODE(_CONFIG)       (CCP2CONbits.CCP2M = _CONFIG)
/* Section :  Data types   */

typedef enum{
    CCP_CAPTURE_MODE_SELECTED = 0,
    CCP_COMPARE_MODE_SELECTED,
    CCP_PWM_MODE_SELECTED        
}ccp_mode_t;

typedef enum{
    CCP1_CCP2_TIMER3 = 0,
    CCP1_TIMER1_CCP2_TIMER3,
    CCP1_CCP2_TIMER1        
}ccp_capture_timer_t;

typedef union {
    struct{
        uint8 ccpr_low;
        uint8 ccpr_high;
    };
    struct{
        uint16 ccpr_16bit;
    };
}CCP_REG_T;

typedef enum {
    CCP1_INST,
    CCP2_INST        
}ccp_inst_t;

typedef struct{
    ccp_inst_t ccp_inst;
    ccp_mode_t  ccp_mode;
    uint8 ccp_mode_variant;
    pin_config_t ccp_pin;
    ccp_capture_timer_t ccp_capture_timer;
#if (CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE)  
    void (* CCP1_InterruptHandler)(void);
    interrupt_priority_cfg CCP1_priority;
#endif
#if (CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE)  
    void (* CCP2_InterruptHandler)(void);
    interrupt_priority_cfg CCP2_priority;
#endif    
#if (CCP_CFG_PWM_MODE_SELECTED == CCP1_CFG_SELECTED_MODE)  ||    (CCP_CFG_PWM_MODE_SELECTED == CCP2_CFG_SELECTED_MODE) 
uint32  PWM_Freqencey; 
uint8 timer2_postscaler_value : 4;
uint8 timer2_prescaler_value : 2;
#endif
}ccp_t;

/* Section :  Function Declaration   */

Std_ReturnType CCP_Init(const ccp_t *_ccp_obj);
Std_ReturnType CCP_DeInit(const ccp_t *_ccp_obj);

#if CCP_CFG_COMPARE_MODE_SELECTED == CCP1_CFG_SELECTED_MODE
Std_ReturnType CCP_IsCompareComplete(const ccp_t *_ccp_obj, uint8 *_compare_status);
Std_ReturnType CCP_Compare_Mode_Set_Value(const ccp_t *_ccp_obj, uint16 compare_value);
#endif 

#if CCP_CFG_CAPTURE_MODE_SELECTED == CCP1_CFG_SELECTED_MODE
Std_ReturnType CCP_IsCaptureDataReady(uint8 *_capture_status);
Std_ReturnType CCP_Capture_Mode_Read_Value(uint16 *capture_value);
#endif 

#if CCP_CFG_PWM_MODE_SELECTED == CCP1_CFG_SELECTED_MODE
Std_ReturnType CCP_PWM_Set_Duty(const ccp_t *_ccp_obj,const uint8 _duty);
Std_ReturnType CCP_PWM_Start(const ccp_t *_ccp_obj);
Std_ReturnType CCP_PWM_Stop(const ccp_t *_ccp_obj);

#endif 

#endif	/* HAL_CCP_H */

