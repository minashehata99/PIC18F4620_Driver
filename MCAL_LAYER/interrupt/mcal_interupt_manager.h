/* 
 * File:   mcal_interupt_manager.h
 * Author: minas
 *
 * Created on September 5, 2023, 8:35 AM
 */

#ifndef MCAL_INTERUPT_MANAGER_H
#define	MCAL_INTERUPT_MANAGER_H

/* Section :  Includes   */
#include "mcal_interrupt_cfg.h"
#include "mcal_internal_interrupt.h"
#include "mcal_external_interrupt.h"

/* Section :  Macro declaration   */



/* Section :  Macro function   */

/* Section :  Data types   */


/* Section :  Function Declaration   */
void __interrupt() InterruptManagerHigh(void);
void __interrupt(low_priority) InterruptManagerLOW(void);
#endif	/* MCAL_INTERUPT_MANAGER_H */

