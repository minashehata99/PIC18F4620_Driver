/* 
 * File:   ecu_dc_motor.h
 * Author: minas
 *
 * Created on August 13, 2023, 3:57 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Section :  Includes   */

#include "ecu_dc_motor_cfg.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
/* Section :  Macro declaration   */

#define DC_MOTOR_ON_STATE 0x01U
#define DC_MOTOR_OFF_STATE 0x00U

#define DC_MOTOR_PIN_1 0x00U
#define DC_MOTOR_PIN_2 0x01U

/* Section :  Macro function   */

/* Section :  Data types   */


typedef struct {
        pin_config_t dc_motor_pin[2]; 
}dc_motor_t;

/* Section :  Function Declaration   */
Std_ReturnType dc_motor_initialization(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_turn_left(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_turn_right(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor);





#endif	/* ECU_DC_MOTOR_H */

