/* 
 * File:   ecu_chr_lcd.c
 * Author: minas
 *
 * Created on August 19, 2023, 11:41 AM
 */

#include "ecu_chr_lcd.h"

static Std_ReturnType send_4bits(const chr_lcd_4bit_t *lcd, uint8 command);
static Std_ReturnType lcd_4bit_send_enable_signal (const chr_lcd_4bit_t *lcd);
static Std_ReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bit_t *lcd);
static Std_ReturnType lcd_8bit_send_set_cursor(const chr_lcd_8bit_t *lcd,uint8 row ,uint8 coloumn );
static Std_ReturnType lcd_4bit_send_set_cursor(const chr_lcd_4bit_t *lcd,uint8 row ,uint8 coloumn );
/**
 * @brief this function used to initialize led
 * @param lcd
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_4bit_initialize(const chr_lcd_4bit_t *lcd){
uint8 ret =E_OK;
uint8 counter = 0;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
        ret = gpio_pin_initialize(&(lcd->lcd_rs));
        ret = gpio_pin_initialize(&(lcd->lcd_en));
        
        for(counter=0;counter<4;counter++){
        ret = gpio_pin_initialize(&(lcd->lcd_data[counter]));
        }
        __delay_ms(20);
        ret = lcd_4bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_4bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_4bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        ret = lcd_4bit_send_command(lcd,_LCD_CLEAR);
        ret = lcd_4bit_send_command(lcd,_LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd,_LCD_ENTRY_MODE);
        ret = lcd_4bit_send_command(lcd,_LCD_CURSOR_OFF_DISPLAY_ON);
        ret = lcd_4bit_send_command(lcd,_LCD_4BIT_MODE_2_LINE);
        ret = lcd_4bit_send_command(lcd,_LCD_DDRAM_START);
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param lcd
 * @param command
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_4bit_send_command(const chr_lcd_4bit_t *lcd, uint8 command){
uint8 ret =E_OK;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
    ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_LOW);
    ret = send_4bits(lcd,command >> 4);
    ret =lcd_4bit_send_enable_signal(lcd);
    ret = send_4bits(lcd,command);
    ret =lcd_4bit_send_enable_signal(lcd);

    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param lcd
 * @param data
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_4bit_char_data(const chr_lcd_4bit_t *lcd, uint8 data){
uint8 ret =E_OK;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
    ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_HIGH);
    ret = send_4bits(lcd,data >> 4);
    ret =lcd_4bit_send_enable_signal(lcd);
    ret = send_4bits(lcd,data);
    ret =lcd_4bit_send_enable_signal(lcd);
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param lcd
 * @param row
 * @param coloumn
 * @param str
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_4bit_char_data_pos(const chr_lcd_4bit_t *lcd,uint8 row,uint8 coloumn, uint8 *data){
uint8 ret =E_OK;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
        ret = lcd_4bit_send_set_cursor(lcd,row,coloumn);
        ret = lcd_4bit_char_data(lcd,*data);
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param lcd
 * @param data
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_4bit_char_string(const chr_lcd_4bit_t *lcd, uint8 *str){
uint8 ret =E_OK;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
    while(*str){
            ret = lcd_4bit_char_data(lcd,*str++);
        }
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param lcd
 * @param row
 * @param coloumn
 * @param str
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_4bit_char_string_pos(const chr_lcd_4bit_t *lcd,uint8 row,uint8 coloumn, uint8 *str){
uint8 ret =E_OK;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
            ret = lcd_4bit_send_set_cursor(lcd,row,coloumn);
            ret = lcd_4bit_char_string(lcd,str);
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param lcd
 * @param row
 * @param coloumn
 * @param _chr
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_4bit_send_custom_char(const chr_lcd_4bit_t *lcd ,uint8 row , uint8 coloumn , const uint8 _chr[],uint8 mem_pos){
uint8 ret =E_OK;
uint8 counter=ZERO_INIT;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
    ret = lcd_4bit_send_command(lcd,(_LCD_CGRAM_START+(mem_pos*8)));
        for(counter = ZERO_INIT;counter<8;counter++){
            ret = lcd_4bit_char_data(lcd,_chr[counter]);
        }
        ret = lcd_4bit_char_data_pos(lcd,row,coloumn,&mem_pos);
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param lcd
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_8bit_initialize(const chr_lcd_8bit_t *lcd){
uint8 ret =E_OK;
uint8 counter=0;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
    ret = gpio_pin_initialize(&(lcd->lcd_rs));
    ret = gpio_pin_initialize(&(lcd->lcd_en));
        
        for(counter=0;counter<8;counter++){
        ret = gpio_pin_initialize(&(lcd->lcd_data[counter]));
        }
        __delay_ms(20);
        ret = lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        ret = lcd_8bit_send_command(lcd,_LCD_CLEAR);
        ret = lcd_8bit_send_command(lcd,_LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(lcd,_LCD_ENTRY_MODE);
        ret = lcd_8bit_send_command(lcd,_LCD_CURSOR_OFF_DISPLAY_ON);
        ret = lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        ret = lcd_8bit_send_command(lcd,_LCD_DDRAM_START);
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param lcd
 * @param command
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_8bit_send_command(const chr_lcd_8bit_t *lcd, uint8 command){
uint8 ret =E_OK;
uint8 pin_counter =ZERO_INIT;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_LOW);
        for(pin_counter= ZERO_INIT;pin_counter<8;++pin_counter){
        ret = gpio_pin_write_logic(&(lcd->lcd_data[pin_counter]),(command >> pin_counter) & (uint8)0x01);
        }
        ret = lcd_8bit_send_enable_signal(lcd);

        
    }
    return ret;
}
/**
 * @@brief this function used to initialize led
 * @param lcd
 * @param data
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_8bit_char_data(const chr_lcd_8bit_t *lcd, uint8 data){
uint8 ret =E_OK;
uint8 pin_counter =ZERO_INIT;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_HIGH);
        for(pin_counter= ZERO_INIT;pin_counter<8;++pin_counter){
            ret = gpio_pin_write_logic(&(lcd->lcd_data[pin_counter]),(data >> pin_counter) & (uint8)0x01);
        }
        ret = lcd_8bit_send_enable_signal(lcd);
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param lcd
 * @param row
 * @param coloumn
 * @param str
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_8bit_char_data_pos(const chr_lcd_8bit_t *lcd,uint8 row,uint8 coloumn, uint8 data){
uint8 ret =E_OK;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
     ret = lcd_8bit_send_set_cursor(lcd,row,coloumn);
     ret = lcd_8bit_char_data(lcd,data);
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param lcd
 * @param data
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_8bit_char_string(const chr_lcd_8bit_t *lcd, uint8 *str){
uint8 ret =E_OK;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
        while(*str){
            ret = lcd_8bit_char_data(lcd,*str++);
        }
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param lcd
 * @param row
 * @param coloumn
 * @param str
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_8bit_char_string_pos(const chr_lcd_8bit_t *lcd,uint8 row,uint8 coloumn, uint8 *str){
uint8 ret =E_OK;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
       ret = lcd_8bit_send_set_cursor(lcd,row,coloumn);
       ret = lcd_8bit_char_string(lcd,str);
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param lcd
 * @param row
 * @param coloumn
 * @param _chr
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType lcd_8bit_send_custom_char(const chr_lcd_8bit_t *lcd ,uint8 row , uint8 coloumn , const uint8 _chr[],uint8 mem_pos){
uint8 ret =E_OK;
uint8 counter=ZERO_INIT;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
        ret = lcd_8bit_send_command(lcd,(_LCD_CGRAM_START+(mem_pos*8)));
        for(counter = ZERO_INIT;counter<8;counter++){
            ret = lcd_8bit_char_data(lcd,_chr[counter]);
        }
        ret = lcd_8bit_char_data_pos(lcd,row,coloumn,mem_pos);
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param value
 * @param str
 */
Std_ReturnType convert_uint8_to_string(uint8 value, uint8 *str){
Std_ReturnType ret =E_OK;
uint8 Temp_String[4]={0};
uint8 DataCounter = 0;
    if( NULL == str){
                ret=E_NOT_OK;

    }
    else{
        memset(str,' ',3);
        str[3] = '\0';
        sprintf((char *)Temp_String,"%i",value);
    while(Temp_String[DataCounter]){
        str[DataCounter] = Temp_String[DataCounter];
        DataCounter++;
        }
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param value
 * @param str
 */
Std_ReturnType convert_uint16_to_string(uint16 value, uint8 *str){
Std_ReturnType ret =E_OK;
uint8 Temp_String[6]={0};
uint8 DataCounter = 0;
    if( NULL == str){
             ret=E_NOT_OK;

    }
    else{
    memset(str,' ',5);
    str[5] = '\0';
    sprintf((char *)Temp_String,"%i",value);
    while(Temp_String[DataCounter]){
        str[DataCounter] = Temp_String[DataCounter];
        DataCounter++;
        }
    }
    return ret;
}
/**
 * @brief this function used to initialize led
 * @param value
 * @param str
 */
Std_ReturnType convert_uint32_to_string(uint32 value, uint8 *str){
    Std_ReturnType ret =E_OK;
    uint8 Temp_String[12]={0};
    uint8 DataCounter = 0;
        if( NULL == str){
                    ret=E_NOT_OK;

        }
        else{
            memset(str,' ',11);
            str[11] = '\0';
            sprintf((char *)Temp_String,"%i",value);
        while(Temp_String[DataCounter]){
            str[DataCounter] = Temp_String[DataCounter];
            DataCounter++;
            }
        }
        return ret;
}

static Std_ReturnType send_4bits(const chr_lcd_4bit_t *lcd, uint8 command){
uint8 ret =E_OK;
    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->lcd_data[0]),(command >> 0) & (uint8)0x01);
        ret = gpio_pin_write_logic(&(lcd->lcd_data[1]),(command >> 1) & (uint8)0x01);
        ret = gpio_pin_write_logic(&(lcd->lcd_data[2]),(command >> 2) & (uint8)0x01);
        ret = gpio_pin_write_logic(&(lcd->lcd_data[3]),(command >> 3) & (uint8)0x01);
    }
    return ret;
}

static Std_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit_t *lcd){

    Std_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);
    return ret;
}
static Std_ReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bit_t *lcd){

    Std_ReturnType ret = E_OK;
    if( NULL == lcd){
    
    }
    ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);
    return ret;
}

static Std_ReturnType lcd_8bit_send_set_cursor(const chr_lcd_8bit_t *lcd,uint8 row ,uint8 coloumn ){
    Std_ReturnType ret = E_OK;

    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
        coloumn--;
        switch(row){
            case ROW1 : ret = lcd_8bit_send_command(lcd,(_LCD_DDRAM_START+coloumn)); break;
            case ROW2 : ret = lcd_8bit_send_command(lcd,(0xc0+coloumn)); break;
            case ROW3 : ret = lcd_8bit_send_command(lcd,(0x94+coloumn)); break;
            case ROW4 : ret = lcd_8bit_send_command(lcd,(0xd4+coloumn)); break;
            default : ;
        }
    }
}
static Std_ReturnType lcd_4bit_send_set_cursor(const chr_lcd_4bit_t *lcd,uint8 row ,uint8 coloumn ){
    Std_ReturnType ret = E_OK;

    if( NULL == lcd){
        ret=E_NOT_OK;
    }
    else{
        coloumn--;
        switch(row){
            case ROW1 : ret = lcd_4bit_send_command(lcd,(_LCD_DDRAM_START+coloumn)); break;
            case ROW2 : ret = lcd_4bit_send_command(lcd,(0xc0+coloumn)); break;
            case ROW3 : ret = lcd_4bit_send_command(lcd,(0x94+coloumn)); break;
            case ROW4 : ret = lcd_4bit_send_command(lcd,(0xd4+coloumn)); break;
            default : ;
        }
    }
}