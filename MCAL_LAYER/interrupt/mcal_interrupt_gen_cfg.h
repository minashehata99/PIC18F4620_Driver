/* 
 * File:   mcal_interrupt_gen_cfg.h
 * Author: minas
 *
 * Created on September 5, 2023, 9:33 AM
 */

#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define	MCAL_INTERRUPT_GEN_CFG_H

/* Section :  Includes   */
 
/* Section :  Macro declaration   */
#define INTERRUPT_FEATURE_ENABLE  1U
#define INTERRUPT_FEATURE_DISABLE 0U
#define INTERRUPT_PRIORITY_LEVELS_ENABLE             INTERRUPT_FEATURE_DISABLE        
#define EXTERNAL_INTERRUPT_INTX_FEATURE_ENABLE       INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_ONCHANGE_FEATURE_ENABLE   INTERRUPT_FEATURE_ENABLE
#define ADC_INTERRUPT_FEATURE_ENABLE                 INTERRUPT_FEATURE_ENABLE
#define TIMER0_INTERRUPT_FEATURE_ENABLE              INTERRUPT_FEATURE_ENABLE
#define TIMER1_INTERRUPT_FEATURE_ENABLE              INTERRUPT_FEATURE_ENABLE
#define TIMER2_INTERRUPT_FEATURE_ENABLE              INTERRUPT_FEATURE_ENABLE
#define TIMER3_INTERRUPT_FEATURE_ENABLE              INTERRUPT_FEATURE_ENABLE
#define CCP1_INTERRUPT_FEATURE_ENABLE                INTERRUPT_FEATURE_ENABLE
#define CCP2_INTERRUPT_FEATURE_ENABLE                INTERRUPT_FEATURE_ENABLE
#define ESUART_TX_INTERRUPT_FEATURE_ENABLE           INTERRUPT_FEATURE_ENABLE
#define ESUART_RX_INTERRUPT_FEATURE_ENABLE           INTERRUPT_FEATURE_ENABLE
#define MSSP_I2C_INTERRUPT_FEATURE_ENABLE            INTERRUPT_FEATURE_DISABLE
/* Section :  Macro function   */

/* Section :  Data types   */
typedef void (*InterruptHandler)(void);
/* Section :  Function Declaration   */

#endif	/* MCAL_INTERRUPT_GEN_CFG_H */

