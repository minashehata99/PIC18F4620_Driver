/* 
 * File:   mcal_external_interrupt.h
 * Author: minas
 *
 * Created on September 5, 2023, 8:35 AM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* Section :  Includes   */
#include "mcal_interrupt_cfg.h"
/* Section :  Macro declaration   */
#if EXTERNAL_INTERRUPT_INTX_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/*THIS MACRO ENABLE/DISABLE INTERRUPT FOR EXTERNAL INTERUPT INT0 */
#define EXT_INT0_INTERRUPT_DISABLE()          (INTCONbits.INT0IE = 0)
#define EXT_INT0_INTERRUPT_ENABLE()           (INTCONbits.INT0IE = 1)
/*THIS MACRO CLEAR FLAG  OF EXTERNAL INTERUPT INT0 */
#define EXT_INT0_INTERRUPT_FLAG_CLEAR()       (INTCONbits.INT0IF = 0)
/*THIS MACRO ENABLE FALLING/RISING EDGE EXTERNAL INTERUPT INT0 */
#define EXT_INT0_INTERRUPT_RISING_EDGE()          (INTCON2bits.INTEDG0 = 1)
#define EXT_INT0_INTERRUPT_FALLING_EDGE()         (INTCON2bits.INTEDG0 = 0)

/*THIS MACRO ENABLE/DISABLE INTERRUPT FOR EXTERNAL INTERUPT INT0 */
#define EXT_INT1_INTERRUPT_DISABLE()          (INTCON3bits.INT1IE = 0)
#define EXT_INT1_INTERRUPT_ENABLE()           (INTCON3bits.INT1IE = 1)
/*THIS MACRO CLEAR FLAG  OF EXTERNAL INTERUPT INT0 */
#define EXT_INT1_INTERRUPT_FLAG_CLEAR()       (INTCON3bits.INT1IF = 0)
/*THIS MACRO ENABLE FALLING/RISING EDGE EXTERNAL INTERUPT INT0 */
#define EXT_INT1_INTERRUPT_RISING_EDGE()          (INTCON2bits.INTEDG1 = 1)
#define EXT_INT1_INTERRUPT_FALLING_EDGE()         (INTCON2bits.INTEDG1 = 0)

/*THIS MACRO ENABLE/DISABLE INTERRUPT FOR EXTERNAL INTERUPT INT0 */
#define EXT_INT2_INTERRUPT_DISABLE()          (INTCON3bits.INT2IE = 0)
#define EXT_INT2_INTERRUPT_ENABLE()           (INTCON3bits.INT2IE = 1)
/*THIS MACRO CLEAR FLAG  OF EXTERNAL INTERUPT INT0 */
#define EXT_INT2_INTERRUPT_FLAG_CLEAR()       (INTCON3bits.INT2IF = 0)
/*THIS MACRO ENABLE FALLING/RISING EDGE EXTERNAL INTERUPT INT0 */
#define EXT_INT2_INTERRUPT_RISING_EDGE()          (INTCON2bits.INTEDG2 = 1)
#define EXT_INT2_INTERRUPT_FALLING_EDGE()         (INTCON2bits.INTEDG2 = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE

#define EXT_INT1_HIGH_PRIORITY_SET()        (INTCON3bits.INT1IP = 1)
#define EXT_INT1_LOW_PRIORITY_SET()         (INTCON3bits.INT1IP = 0)
#define EXT_INT2_HIGH_PRIORITY_SET()        (INTCON3bits.INT2IP = 1)
#define EXT_INT2_LOW_PRIORITY_SET()         (INTCON3bits.INT2IP = 0)
#endif

#endif

#if EXTERNAL_INTERRUPT_ONCHANGE_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
#define EXT_RBx_INTERRUPT_DISABLE()              (INTCONbits.RBIE = 0)
#define EXT_RBx_INTERRUPT_ENABLE()               (INTCONbits.RBIE = 1)
#define EXT_RBx_FLAG_CLEAR()                     (INTCONbits.RBIF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
#define EXT_RBx_INTERRUPT_PRIORITY_HIGH()          (INTCON2bits.RBIP = 1)
#define EXT_RBx_INTERRUPT_PRIORITY_LOW()           (INTCON2bits.RBIP = 0)

#endif

#endif
/* Section :  Macro function   */

/* Section :  Data types   */
typedef enum{
    INTERRUPT_FALLING_EDGE = 0,
    INTERRUPT_RISING_EDGE
}INTERRUPT_INTx_edge;
typedef enum{
    INTERRUPT_EXTERNAL_INT0 = 0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2
}INTERRUPT_INTx_src;
typedef struct{
    InterruptHandler EXT_interruptHandler;
    pin_config_t mcu_pin;
    INTERRUPT_INTx_edge edge;
    INTERRUPT_INTx_src source;
    interrupt_priority_cfg priority;
}interrupt_INTx_t;
typedef struct{
    InterruptHandler EXT_interruptHandler_HIGH;
    InterruptHandler EXT_interruptHandler_LOW;
    pin_config_t mcu_pin;
    interrupt_priority_cfg priority;
}interrupt_RBx_t;
/* Section :  Function Declaration   */
#if EXTERNAL_INTERRUPT_INTX_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_obj);
Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj);
#endif
Std_ReturnType Interrupt_RBx_Init(const interrupt_RBx_t *int_obj);
Std_ReturnType Interrupt_RBx_DeInit(const interrupt_RBx_t *int_obj);
#if EXTERNAL_INTERRUPT_INTX_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
void INT0_ISR (void);
void INT1_ISR (void);
void INT2_ISR (void);
#endif
void RB4_ISR (uint8 pin4_source);
void RB5_ISR (uint8 pin5_source);
void RB6_ISR (uint8 pin6_source);
void RB7_ISR (uint8 pin7_source);
#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

