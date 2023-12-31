/* 
 * File:   ecu_button.h
 * Author: minas
 *
 * Created on August 11, 2023, 7:34 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/* Section :  Includes   */
#include "ecu_button_cfg.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
/* Section :  Macro declaration   */

typedef enum {
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct{
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connection;
}button_t;
/* Section :  Macro function   */

/* Section :  Data types   */

/* Section :  Function Declaration   */

Std_ReturnType button_initialization(const button_t *btn);
Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state );


#endif	/* ECU_BUTTON_H */

