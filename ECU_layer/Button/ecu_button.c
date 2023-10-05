/* 
 * File:   ecu_button.c
 * Author: minas
 *
 * Created on August 11, 2023, 7:34 PM
 */
#include "ecu_button.h"
/**
 * @brief this function used to initialize button
 * @param btn
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType button_initialization(const button_t *btn){
    uint8 ret =E_OK;
    if(NULL == btn){
        ret=E_NOT_OK;
    }
    else{
    
        gpio_pin_direction_initialize(&(btn->button_pin));
    
    
    }
}
/**
 * @brief this function used to read state of button
 * @param btn
 * @param btn_state
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state ){
    uint8 ret =E_OK;
    logic_t btn_logic=GPIO_LOW;
    if( (NULL == btn) || (NULL == btn_state) ){
        ret=E_NOT_OK;
    }
    else{
        ret=gpio_pin_read_logic(&(btn->button_pin),&btn_logic);
        if(btn->button_connection == BUTTON_ACTIVE_HIGH ){
            if(btn_logic == GPIO_HIGH){
                *btn_state=BUTTON_PRESSED;
            }
            else{
                *btn_state=BUTTON_RELEASED;
            }
        }
        else if(btn->button_connection == BUTTON_ACTIVE_LOW ){
            if(btn_logic == GPIO_HIGH){
                *btn_state=BUTTON_PRESSED;
            }
            else{
                *btn_state=BUTTON_RELEASED;
            }
        }
        else{/* NOTHING */}
        
    }
    return ret;
}