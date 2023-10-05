/* 
 * File:   ecu_dc_motor.h
 * Author: minas
 *
 * Created on August 13, 2023, 3:57 PM
 */



#include "ecu_dc_motor.h"

static pin_config_t motor_pin_1;
static pin_config_t motor_pin_2;

/**
 * @brief this function used to initialize dc motor
 * @param _dc_motor
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
Std_ReturnType dc_motor_initialization(const dc_motor_t *_dc_motor){
uint8 ret =E_OK;
    if( NULL == _dc_motor){
        ret=E_NOT_OK;
    }
    else{
        
        ret=gpio_pin_initialize(&(_dc_motor->dc_motor_pin[0]));
        ret=gpio_pin_initialize(&(_dc_motor->dc_motor_pin[1]));
    
    }
    return ret;
}
/**
 * @brief this function used to move dc motor left
 * @param _dc_motor
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
Std_ReturnType dc_motor_turn_left(const dc_motor_t *_dc_motor){
uint8 ret =E_OK;
    if( NULL == _dc_motor){
        ret=E_NOT_OK;
    }
    else{
        ret=gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]),GPIO_HIGH);
        ret=gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[1]),GPIO_LOW);

    }
    return ret;
}
/**
 * @brief this function used to move dc motor right
 * @param _dc_motor
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
Std_ReturnType dc_motor_turn_right(const dc_motor_t *_dc_motor){
uint8 ret =E_OK;
    if( NULL == _dc_motor){
        ret=E_NOT_OK;
    }
    else{
        ret=gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]),GPIO_LOW);
        ret=gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[1]),GPIO_HIGH);
    
    }
    return ret;
}
/**
 * @brief this function used to stop dc motor
 * @param _dc_motor
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
Std_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor){
uint8 ret =E_OK;
    if( NULL == _dc_motor){
        ret=E_NOT_OK;
    }
    else{

        ret=gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]),GPIO_LOW);
        ret=gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[1]),GPIO_LOW);
    
    }
    return ret;
}