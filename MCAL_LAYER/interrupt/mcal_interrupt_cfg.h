/* 
 * File:   mcal_interrupt_cfg.h
 * Author: minas
 *
 * Created on September 5, 2023, 8:33 AM
 */

#ifndef MCAL_INTERRUPT_CFG_H
#define	MCAL_INTERRUPT_CFG_H

/* Section :  Includes   */
#include "../mcal_std_types.h"
#include "../proc/pic18f4620.h"  
#include "mcal_interrupt_gen_cfg.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
/* Section :  Macro declaration   */
#define INTERRUPT_ENABLE           1
#define INTERRUPT_DISABLE          0
#define INTERRUPT_OCCUR            1
#define INTERRUPT_NOT_OCCUR        0
#define INTERRUPT_PRIORITY_ENABLE  1
#define INTERRUPT_PRIORITY_DISABLE 0


/* Section :  Macro function   */
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/* THIS MACRO ENABLE/DISABLE PRIORITY LEVEL */
#define INTERRUPT_PRIORITY_LEVEL_ENABLE()           (RCONbits.IPEN = 1)
#define INTERRUPT_PRIORITY_LEVEL_DISABLE()          (RCONbits.IPEN = 0)
/*THIS MACRO ENABLE/DISABLE ALL HIGH PRIO INTERRUPT*/
#define INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE()    (INTCONbits.GIEH = 1)
#define INTERRUPT_GLOBAL_INTERRUPT_HIGH_DISABLE()   (INTCONbits.GIEH = 0)
/*THIS MACRO ENABLE/DISABLE ALL LOW PRIO INTERRUPT*/
#define INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE()     (INTCONbits.GIEL = 1)
#define INTERRUPT_GLOBAL_INTERRUPT_LOW_DISABLE()    (INTCONbits.GIEL = 0)
#else
/* THIS MACRO ENABLE/DISABLE GLOBAK INTERRUPT */
#define INTERRUPT_GLOBAL_INTERRUPT_ENABLE()         (INTCONbits.GIE = 1)
#define INTERRUPT_GLOBAL_INTERRUPT_DISABLE()        (INTCONbits.GIE = 0)
/*THIS MACRO ENABLE/DISABLE ALL PREPHRAL INTERRUPT*/
#define INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE()      (INTCONbits.PEIE = 1)
#define INTERRUPT_PEREPHRAL_INTERRUPT_disable()     (INTCONbits.PEIE = 0)
#endif

/* Section :  Data types   */
typedef enum{
    INTERRUPT_LOW_PRIORITY = 0,
    INTERRUPT_HIGH_PRIORITY
}interrupt_priority_cfg;

/* Section :  Function Declaration   */

#endif	/* MCAL_INTERRUPT_CFG_H */

