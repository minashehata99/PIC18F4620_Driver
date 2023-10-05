/* 
 * File:   application.c
 * Author: mina.shehata
 *
 * Created on August 6, 2023, 1:25 PM
 */
#include "application.h"
#include "ECU_layer/DC_Motor/ecu_dc_motor.h"
#include "../application.X/MCAL_LAYER/../ECU_layer/Chr_LCD/ecu_chr_lcd.h"
#include "ECU_layer/../MCAL_LAYER/ADC/hal_adc.h"
uint16 adcres1,adcres2;
uint8 adcflag = 0;
uint8 adcres1txt[6];
uint8 adcres2txt[6];

chr_lcd_4bit_t lcd1={
.lcd_data[0].direction=GPIO_DIRECTION_OUTPUT,
.lcd_data[0].logic = GPIO_LOW,
.lcd_data[0].pin = PIN2,
.lcd_data[0].port = PORTC_INDEX,
.lcd_data[1].direction=GPIO_DIRECTION_OUTPUT,
.lcd_data[1].logic = GPIO_LOW,
.lcd_data[1].pin = PIN3,
.lcd_data[1].port = PORTC_INDEX,
.lcd_data[2].direction=GPIO_DIRECTION_OUTPUT,
.lcd_data[2].logic = GPIO_LOW,
.lcd_data[2].pin = PIN4,
.lcd_data[2].port = PORTC_INDEX,
.lcd_data[3].direction=GPIO_DIRECTION_OUTPUT,
.lcd_data[3].logic = GPIO_LOW,
.lcd_data[3].pin = PIN5,
.lcd_data[3].port = PORTC_INDEX,
.lcd_en.direction = GPIO_DIRECTION_OUTPUT,
.lcd_en.logic = GPIO_LOW,
.lcd_en.pin = PIN1,
.lcd_en.port= PORTC_INDEX,
.lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
.lcd_rs.logic=GPIO_DIRECTION_OUTPUT,
.lcd_rs.pin = PIN0,
.lcd_rs.port=PORTC_INDEX
};

void ADC_handler (void);

adc_config_t adc_1 = {
.ADC_InterruptHandler =ADC_handler,
.acqusition_time =ADC_12_TAD,
.adc_channel=ADC_CHANNEL_AN0,
.conversion_clock=ADC_CONVERTION_CLOCK_FOSC_DIV_16,
.result_format=ADC_RESULT_RIGHT,
.voltage_refrence =ADC_VOLTAGE_REFRENCE_DISABLED
};

dc_motor_t motor1 ={
.dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
.dc_motor_pin[0].logic = GPIO_LOW,
.dc_motor_pin[0].pin = PIN0,
.dc_motor_pin[0].port = PORTD_INDEX,
.dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT,
.dc_motor_pin[1].logic = GPIO_LOW,
.dc_motor_pin[1].pin = PIN1,
.dc_motor_pin[1].port = PORTD_INDEX,
};
dc_motor_t motor2 ={
.dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
.dc_motor_pin[0].logic = GPIO_LOW,
.dc_motor_pin[0].pin = PIN2,
.dc_motor_pin[0].port = PORTD_INDEX,
.dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT,
.dc_motor_pin[1].logic = GPIO_LOW,
.dc_motor_pin[1].pin = PIN3,
.dc_motor_pin[1].port = PORTD_INDEX,
};
int main() { 
    application_initialization();
    lcd_4bit_char_string_pos(&lcd1,1,5,"LM35 Project");
    __delay_ms(2000);
    lcd_4bit_send_command(&lcd1,_LCD_CLEAR);
    lcd_4bit_char_string_pos(&lcd1,1,4,"LM35 Readings");
    lcd_4bit_char_string_pos(&lcd1,2,1,"sensor0 =");
    lcd_4bit_char_string_pos(&lcd1,3,1,"sensor1 =");


    while(1){
        
        if(adcflag == 0){
            ADC_StartConversion_by_Interrupt(&adc_1,ADC_CHANNEL_AN0);
        }
            
        else if (adcflag == 1){
            ADC_StartConversion_by_Interrupt(&adc_1,ADC_CHANNEL_AN1);
        }

            
            
            convert_uint16_to_string(adcres1,&adcres1txt);
            lcd_4bit_char_string_pos(&lcd1,2,10,adcres1txt);
            
            convert_uint16_to_string(adcres2,&adcres2txt);
            lcd_4bit_char_string_pos(&lcd1,3,10,adcres2txt);
            
            if(adcres1 > 50){
                dc_motor_turn_left(&motor1);
            }
            else if(adcres1 <= 50){
                dc_motor_stop(&motor1);
            }
            if(adcres2 > 50){
                dc_motor_turn_left(&motor2);
            }
            else if(adcres2 <= 50){
                dc_motor_stop(&motor2);
            }

    }
        return (EXIT_SUCCESS);

}

void ADC_handler (void){
    if(adcflag == 0){
    ADC_GetConversionResult(&adc_1,&adcres1);
    adcres1=adcres1*0.488f;
    adcflag = 1;
    }
    else if(adcflag == 1){
    ADC_GetConversionResult(&adc_1,&adcres2);
    adcres2=adcres2*0.488f;
    adcflag = 0;
    }

}
void application_initialization(void){
    lcd_4bit_initialize(&lcd1);
    ADC_Init(&adc_1);
    dc_motor_initialization(&motor1);
    dc_motor_initialization(&motor2);
}