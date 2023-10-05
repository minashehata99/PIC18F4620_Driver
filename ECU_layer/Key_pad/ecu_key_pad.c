/* 
 * File:   ecu_key_pad.c
 * Author: minas
 *
 * Created on August 15, 2023, 2:48 PM
 */

#include "ecu_key_pad.h"


static const uint8 btn_values[ECU_KEYPAD_ROW_NUMBER][ECU_KEYPAD_COLUMN_NUMBER]={

                        {'7','8','9','/'},                                       
                        {'4','5','6','*'},
                        {'1','2','3','-'},
                        {'#','0','=','+'}
                     };

/**
 * @brief this function used to initialize keypad
 * @param _keypad
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType keypad_initialization(const key_pad_t *_keypad){
    uint8 coloumn_counter=ZERO_INIT;
    uint8 row_counter=ZERO_INIT;
    uint8 ret =E_OK;
    if( NULL == _keypad){
        ret=E_NOT_OK;
    }
    else{
        for(row_counter=ZERO_INIT;row_counter<ECU_KEYPAD_ROW_NUMBER;row_counter++){
            ret=gpio_pin_initialize(&(_keypad->keypad_row_pin[row_counter]));
        }
        
        for(coloumn_counter=ZERO_INIT;coloumn_counter<ECU_KEYPAD_COLUMN_NUMBER;coloumn_counter++){
            ret=gpio_pin_direction_initialize(&(_keypad->keypad_coloum_pin[coloumn_counter]));
        }
    
    }
    return ret;

}

/**
 * @brief this function used to get the value on the keypad
 * @param _keypad
 * @param value
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType keypad_get_value(const key_pad_t *_keypad, uint8 *value){
    uint8 coloumn_counter=ZERO_INIT;
    uint8 row_counter=ZERO_INIT;
    uint8 counter=ZERO_INIT;
    logic_t coloumn_logic=ZERO_INIT;
    uint8 ret =E_OK;
    if( (NULL == _keypad)  || (NULL == value)){
        ret=E_NOT_OK;
    }
    else{
        
        for(row_counter=ZERO_INIT;row_counter<ECU_KEYPAD_ROW_NUMBER;row_counter++){
            for(counter=ZERO_INIT;counter<ECU_KEYPAD_ROW_NUMBER;counter++){
                ret=gpio_pin_write_logic(&(_keypad->keypad_row_pin[counter]),GPIO_LOW);
            }
            
            ret=gpio_pin_write_logic(&(_keypad->keypad_row_pin[row_counter]),GPIO_HIGH);
            for(coloumn_counter=ZERO_INIT;coloumn_counter<ECU_KEYPAD_COLUMN_NUMBER;coloumn_counter++){
            ret=gpio_pin_read_logic(&(_keypad->keypad_coloum_pin[coloumn_counter]),&coloumn_logic);
            if(GPIO_HIGH == coloumn_logic){
            *value=btn_values[row_counter][coloumn_counter];
            }
        }
        }
    
    }
    return ret;


}