/* 
 * File:   ecu_seven_seg.c
 * Author: minas
 *
 * Created on August 14, 2023, 7:09 PM
 */

#include "ecu_seven_seg.h"

/**
 * @brief this function used to initialize the seven segment by multiplexing
 * @param seg
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType seven_segment_initialization(const segment_t *seg){
uint8 ret =E_OK;
    if( NULL == seg){
        ret=E_NOT_OK;
    }
    else{
        
        ret = gpio_pin_initialize(&(seg->segment_pins[SEGMENT_PIN0]));
        ret = gpio_pin_initialize(&(seg->segment_pins[SEGMENT_PIN1]));
        ret = gpio_pin_initialize(&(seg->segment_pins[SEGMENT_PIN2]));
        ret = gpio_pin_initialize(&(seg->segment_pins[SEGMENT_PIN3]));
                
    }
    return ret;
}

/**
 * @brief this function used to write number on seven segment by multiplexing
 * @param seg
 * @param number
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType seven_segment_write_number(const segment_t *seg, uint8 number){
uint8 ret =E_OK;
    if( (NULL == seg) || (number > 9) ){
        ret=E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(seg->segment_pins[SEGMENT_PIN0]), number & 0x01);
        ret = gpio_pin_write_logic(&(seg->segment_pins[SEGMENT_PIN1]), (number>>1) & 0x01);
        ret = gpio_pin_write_logic(&(seg->segment_pins[SEGMENT_PIN2]), (number>>2) & 0x01);
        ret = gpio_pin_write_logic(&(seg->segment_pins[SEGMENT_PIN3]), (number>>3) & 0x01);
    }
    return ret;
}