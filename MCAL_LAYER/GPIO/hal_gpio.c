/* 
 * File:   hal_gpio.c
 * Author: mina.shehata
 *
 * Created on August 6, 2023, 1:25 PM
 */

#include "hal_gpio.h"
/* REFRENCE TO THE DATA PIN DIRECTION */
volatile uint8 *tris_register[] = {&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
/* REFRENCE TO THE DATA LATCH REGISTER (READ OR WRITE) TO DATA LATCH */
volatile uint8 *lat_register[] = {&LATA,&LATB,&LATC,&LATD,&LATE};
/* REFRENCE TO THE PORT STATUS REGISTER */
volatile uint8 *port_register[] = {&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};

/**
 * @brief this function used for initialization of a pin as input/output @ref direction_t
 * @param _pin_config
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
#if GPIO_PIN_CONFIGURATION_ACTIVE==CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *_pin_config){
    uint8 ret =E_OK;
    if( NULL == _pin_config || _pin_config ->pin >PORT_PIN_MAX_NUMBER-1 ){
        ret=E_NOT_OK;
    }
    else{
        switch(_pin_config -> direction){
            case GPIO_DIRECTION_OUTPUT     :
                CLEAR_BIT(*tris_register[_pin_config -> port] ,_pin_config->pin  );
                break;
            case GPIO_DIRECTION_INPUT  :
                SET_BIT(*tris_register[_pin_config -> port] ,_pin_config->pin  );
                break;
            default : ret=E_NOT_OK;
        }
    }       
    return ret;
}
#endif
/**
 * @brief this function used to return status of pin sa input/output @ref direction_t
 * @param _pin_config
 * @param direction_status
 *  @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
#if GPIO_PIN_CONFIGURATION_ACTIVE==CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status){
    uint8 ret =E_OK;
    if( NULL == _pin_config || _pin_config ->pin >PORT_PIN_MAX_NUMBER-1  || NULL == direction_status){
        ret=E_NOT_OK;
    }
    else{
    
        *direction_status=READ_BIT(*tris_register[_pin_config -> port] , _pin_config->pin);
    
    }
    return ret;
}
#endif
/**
 * @brief this function used to write on a pin a logic @ref logic_t
 * @param _pin_config
 * @param logic
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */ 
#if GPIO_PIN_CONFIGURATION_ACTIVE==CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config , logic_t logic){
    uint8 ret =E_OK;
    if( NULL == _pin_config || _pin_config ->pin >PORT_PIN_MAX_NUMBER-1 ){
        ret=E_NOT_OK;
    }
    else{
    switch(logic){
            case GPIO_LOW     :
                CLEAR_BIT(*lat_register[_pin_config -> port] ,_pin_config->pin  );
                break;
            case GPIO_HIGH  :
                SET_BIT(*lat_register[_pin_config -> port] ,_pin_config->pin  );
                break;
            default : ret=E_NOT_OK;
    
    }
}
        return ret;

}
#endif
/**
 * @brief this function used to read status of a pin  @ref logic_t
 * @param _pin_config
 * @param logic
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
#if GPIO_PIN_CONFIGURATION_ACTIVE==CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config , logic_t *logic){
    uint8 ret =E_OK;
    if( NULL == _pin_config || _pin_config ->pin >PORT_PIN_MAX_NUMBER-1 ){
        ret=E_NOT_OK;
    }
    else{
        
        *logic=READ_BIT(*port_register[_pin_config -> port] , _pin_config->pin);
    }
    return ret;
}
#endif

/**
 * @brief this function used to toggle status of a pin  
 * @param _pin_config
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
#if GPIO_PIN_CONFIGURATION_ACTIVE==CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config){
    uint8 ret =E_OK;
    if( NULL == _pin_config || _pin_config ->pin >PORT_PIN_MAX_NUMBER-1 ){
        ret=E_NOT_OK;
    }
    else{
    
        TOGGLE_BIT(*lat_register[_pin_config -> port] , _pin_config->pin);
    
    }
    return ret;
}
#endif

/**
 * @brief this function used to initialize and write of a pin 
 * @param _pin_config
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
#if GPIO_PIN_CONFIGURATION_ACTIVE==CONFIG_ENABLE
Std_ReturnType gpio_pin_initialize(const pin_config_t *_pin_config){
    uint8 ret =E_OK;
    if( NULL == _pin_config || _pin_config ->pin >PORT_PIN_MAX_NUMBER-1 ){
        ret=E_NOT_OK;
    }
    else{
        ret= gpio_pin_direction_initialize(_pin_config);
        ret= gpio_pin_write_logic(_pin_config,_pin_config->logic);
        }
          
    return ret;
}
#endif
/**
 * @brief this function used to initialize the direction of a port
 * @param port
 * @param direction
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
#if GPIO_PORT_CONFIGURATION_ACTIVE==CONFIG_ENABLE
Std_ReturnType gpio_port_direction_initialize( port_index_t port ,uint8 direction){
    uint8 ret =E_OK;
    if( port >PORT_MAX_NUMBER-1 ){
        ret=E_NOT_OK;
    }
    else{
    
        *tris_register[port]= direction;
    
    }
    return ret;
}
#endif
/**
 * @brief this function used to read the direction of a port
 * @param port
 * @param direction_status
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input  
 */
#if GPIO_PORT_CONFIGURATION_ACTIVE==CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status( port_index_t port , uint8 *direction_status ){
    uint8 ret =E_OK;
    if(( port >PORT_MAX_NUMBER-1) || (NULL == direction_status) ){
        ret=E_NOT_OK;
    }
    else{
    
        *direction_status = *tris_register[port];
    
    }
    return ret;
}
#endif
/**
 * @brief this function used to write on a port
 * @param port
 * @param logic
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
#if GPIO_PORT_CONFIGURATION_ACTIVE==CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic( port_index_t port , uint8 logic ){
    uint8 ret =E_OK;
    if( port >PORT_MAX_NUMBER-1 ){
        ret=E_NOT_OK;
    }
    else{
    
        *lat_register[port]=logic;
    }
    return ret;
}
#endif
/**
 * @brief this function used to read the logic of a port
 * @param port
 * @param logic
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
#if GPIO_PORT_CONFIGURATION_ACTIVE==CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(port_index_t port , uint8 *logic){
    uint8 ret =E_OK;
    if( (port > PORT_MAX_NUMBER-1) || (NULL == logic)){
        ret=E_NOT_OK;
    }
    else{
    
          *logic=*port_register[port];

    }
    return ret;
}
#endif
/**
 * @brief this function used to toggle the logic of a port
 * @param port
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input
 */
#if GPIO_PORT_CONFIGURATION_ACTIVE==CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(port_index_t port){
    uint8 ret =E_OK;
    if( port > PORT_MAX_NUMBER){
        ret=E_NOT_OK;
    }
    else{
    
        *lat_register[port]^=PORT_MASK;
    
    }
    return ret;
}
#endif