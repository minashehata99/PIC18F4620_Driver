/* 
 * File:   ecu_initializer.h
 * Author: minas
 *
 * Created on August 18, 2023, 5:16 PM
 */

#ifndef ECU_INITIALIZER_H
#define	ECU_INITIALIZER_H


/* Section :  Includes   */
#include "../Button/ecu_button.h"
#include "../Relay/ecu_relay.h"
#include "../DC_Motor/ecu_dc_motor.h"
#include "../Seven_Segment/ecu_seven_seg.h"
#include "../Key_pad/ecu_key_pad.h"
#include "../Chr_LCD/ecu_chr_lcd.h"
/* Section :  Macro declaration   */

/* Section :  Macro function   */

/* Section :  Data types   */

/* Section :  Function Declaration   */
void ecu_initialization(void);
#endif	/* ECU_INITIALIZER_H */

