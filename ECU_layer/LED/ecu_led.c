/* 
 * File:   ecu_led.c
 * Author: minas
 *
 * Created on August 6, 2023, 2:28 PM
 */

#include "ecu_led.h"
/**
 * @brief this function used to initialize led
 * @param led
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType led_initialize(const led_t *led){
    uint8 ret =E_OK;
    if( NULL == led){
        ret=E_NOT_OK;
    }
    else{
        
    pin_config_t pin_obj={
    .port=led->port_name,
    .direction=GPIO_DIRECTION_OUTPUT,
    .pin=led->pin,
    .logic=led->led_status
    };
    
        ret=gpio_pin_initialize(&pin_obj);
    
    }
    return ret;
}
/**
 * @brief this function used to turn on led
 * @param led
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
Std_ReturnType led_turn_on(const led_t *led){
    uint8 ret =E_OK;
    if( NULL == led){
        ret=E_NOT_OK;
    }
    else{
    
        pin_config_t pin_obj={
    .port=led->port_name,
    .direction=GPIO_DIRECTION_OUTPUT,
    .pin=led->pin,
    .logic=led->led_status
    };
    
        ret=gpio_pin_write_logic(&pin_obj,GPIO_HIGH);
    
    }
    return ret;
}
/**
 * @brief this function used to turn off led
 * @param led
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType led_turn_off(const led_t *led){
    uint8 ret =E_OK;
    if( NULL == led){
        ret=E_NOT_OK;
    }
    else{
    
         pin_config_t pin_obj={
    .port=led->port_name,
    .direction=GPIO_DIRECTION_OUTPUT,
    .pin=led->pin,
    .logic=led->led_status
    };
    
        ret=gpio_pin_write_logic(&pin_obj,GPIO_LOW);   
    
    }
    return ret;
}
/**
 * @brief this function used to toggle led
 * @param led
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
Std_ReturnType led_turn_toggle(const led_t *led){
    uint8 ret =E_OK;
    if( NULL == led){
        ret=E_NOT_OK;
    }
    else{
    
    pin_config_t pin_obj={
        .port=led->port_name,
        .direction=GPIO_DIRECTION_OUTPUT,
        .pin=led->pin,
        .logic=led->led_status
    };
    
        ret=gpio_pin_toggle_logic(&pin_obj);
    
    }
    return ret;
}