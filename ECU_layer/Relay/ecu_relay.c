/* 
 * File:   ecu_relay.c
 * Author: minas
 *
 * Created on August 12, 2023, 2:56 PM
 */

#include "ecu_relay.h"


/**
 * @brief this function used to initialize the relay an turn relay on or off
 * @param _relay
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType relay_initialization(const relay_t *_relay){
uint8 ret =E_OK;
    if( NULL == _relay){
        ret=E_NOT_OK;
    }
    else{
            pin_config_t pin_obj={
        .port=_relay->relay_port,
        .direction=GPIO_DIRECTION_OUTPUT,
        .pin=_relay->relay_pin,
        .logic=_relay->relay_status
    };
    
        ret=gpio_pin_initialize(&pin_obj);
    
    }
    return ret;
}

/**
 * @brief this function used to turn relay on
 * @param _relay
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType relay_turn_on(const relay_t *_relay){
uint8 ret =E_OK;
    if( NULL == _relay){
        ret=E_NOT_OK;
    }
    else{
            pin_config_t pin_obj={
        .port=_relay->relay_port,
        .direction=GPIO_DIRECTION_OUTPUT,
        .pin=_relay->relay_pin,
        .logic=_relay->relay_status
    };
    
        ret=gpio_pin_write_logic(&pin_obj,GPIO_HIGH); 
    
    }
    return ret;
}

/**
 * @brief this function used to turn relay off
 * @param _relay
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType relay_turn_off(const relay_t *_relay){
uint8 ret =E_OK;
    if( NULL == _relay){
        ret=E_NOT_OK;
    }
    else{
            pin_config_t pin_obj={
        .port=_relay->relay_port,
        .direction=GPIO_DIRECTION_OUTPUT,
        .pin=_relay->relay_pin,
        .logic=_relay->relay_status
    };
    
        ret=gpio_pin_write_logic(&pin_obj,GPIO_LOW); 
    
    }
    return ret;
}