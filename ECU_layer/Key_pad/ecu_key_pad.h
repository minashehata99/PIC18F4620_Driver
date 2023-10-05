/* 
 * File:   ecu_key_pad.h
 * Author: minas
 *
 * Created on August 15, 2023, 2:48 PM
 */

#ifndef ECU_KEY_PAD_H
#define	ECU_KEY_PAD_H


/* Section :  Includes   */

#include "ecu_key_pad_cfg.h"
#include "../../ECU_layer/Key_pad/../../MCAL_LAYER/GPIO/hal_gpio.h"

/* Section :  Macro declaration   */

#define ECU_KEYPAD_ROW_NUMBER 4
#define ECU_KEYPAD_COLUMN_NUMBER 4

/* Section :  Macro function   */

/* Section :  Data types   */

typedef struct {
    pin_config_t keypad_row_pin[4];
    pin_config_t keypad_coloum_pin[4];
}key_pad_t;

/* Section :  Function Declaration   */

Std_ReturnType keypad_initialization(const key_pad_t *_keypad);
Std_ReturnType keypad_get_value(const key_pad_t *_keypad, uint8 *value);

#endif	/* ECU_KEY_PAD_H */

