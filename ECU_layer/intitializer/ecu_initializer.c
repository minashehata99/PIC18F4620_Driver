/* 
 * File:   ecu_initializer.c
 * Author: minas
 *
 * Created on August 18, 2023, 5:16 PM
 */
#include "ecu_initializer.h"


chr_lcd_4bit_t lcd1 ={

.lcd_rs.direction=GPIO_DIRECTION_OUTPUT,
.lcd_rs.logic=GPIO_LOW,
.lcd_rs.port=PORTC_INDEX,
.lcd_rs.pin=PIN0,
.lcd_en.direction=GPIO_DIRECTION_OUTPUT,
.lcd_en.logic=GPIO_LOW,
.lcd_en.port=PORTC_INDEX,
.lcd_en.pin=PIN1,
.lcd_data[0].direction=GPIO_DIRECTION_OUTPUT,
.lcd_data[0].logic=GPIO_LOW,
.lcd_data[0].port=PORTC_INDEX,
.lcd_data[0].pin=PIN2,

.lcd_data[1].direction=GPIO_DIRECTION_OUTPUT,
.lcd_data[1].logic=GPIO_LOW,
.lcd_data[1].port=PORTC_INDEX,
.lcd_data[1].pin=PIN3,

.lcd_data[2].direction=GPIO_DIRECTION_OUTPUT,
.lcd_data[2].logic=GPIO_LOW,
.lcd_data[2].port=PORTC_INDEX,
.lcd_data[2].pin=PIN4,

.lcd_data[3].direction=GPIO_DIRECTION_OUTPUT,
.lcd_data[3].logic=GPIO_LOW,
.lcd_data[3].port=PORTC_INDEX,
.lcd_data[3].pin=PIN5,
};

void ecu_initialization(void){

    lcd_4bit_initialize(&lcd1);

}