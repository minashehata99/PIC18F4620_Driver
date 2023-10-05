/* 
 * File:   ecu_led.h
 * Author: minas
 *
 * Created on August 6, 2023, 2:28 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H
/* Section :  Includes   */
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h" 
/* Section :  Macro declaration   */

/* Section :  Macro function   */

/* Section :  Data types   */
typedef enum {
            LED_OFF,
            LED_ON
}led;
typedef struct{
    uint8 port_name : 3;
    uint8 pin       : 3;
    uint8 led_status: 1;
    uint8 reserved  : 1;
}led_t;
/* Section :  Function Declaration   */
Std_ReturnType led_initialize(const led_t *led);
Std_ReturnType led_turn_on(const led_t *led);
Std_ReturnType led_turn_off(const led_t *led);
Std_ReturnType led_turn_toggle(const led_t *led);
#endif	/* ECU_LED_H */

