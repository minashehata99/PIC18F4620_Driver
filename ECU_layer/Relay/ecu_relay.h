/* 
 * File:   ecu_relay.h
 * Author: minas
 *
 * Created on August 12, 2023, 2:56 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* Section :  Includes   */

#include "ecu_relay_cfg.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"

/* Section :  Macro declaration   */
#define RELAY_ON_STATE 0x01U
#define RELAY_OFF_STATE 0x00U
/* Section :  Macro function   */

/* Section :  Data types   */

typedef struct {
uint8    relay_port  :4;
uint8    relay_pin  :3;
uint8    relay_status  :1;
}relay_t;

/* Section :  Function Declaration   */
Std_ReturnType relay_initialization(const relay_t *_relay);
Std_ReturnType relay_turn_on(const relay_t *_relay);
Std_ReturnType relay_turn_off(const relay_t *_relay);

#endif	/* ECU_RELAY_H */

