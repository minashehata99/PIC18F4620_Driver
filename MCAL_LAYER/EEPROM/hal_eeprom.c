/* 
 * File:   hal_eeprom.c
 * Author: minas
 *
 * Created on September 7, 2023, 6:44 AM
 */


#include "hal_eeprom.h"


/**
 * @brief this function used to write data to EEPROM
 * @param bAdd
 * @param bData
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType Data_EEPROM_WriteByte(uint16  bAdd, uint8 bData){
    uint8 ret =E_OK;
    /*read the interrupt status enabled/disabled*/
    uint8 Global_Interrupt_status = INTCONbits.GIE;
    /*update the address registers*/
    EEADRH = (uint8)((bAdd >>8) & 0x03);
    EEADR = (uint8)(bAdd & 0xFF);
    /*update the data register*/
    EEDATA = bData;
    /*select access data EEPROM*/
    EECON1bits.EEPGD = ACCESS_EEPROM_MEMORY;
    EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY;
    /*Allows write cycle to flash program/data EEPROM */
    EECON1bits.WREN = ALLOW_WRITE_TO_EEPROM_FLASH_MEMORY;
    /*Disable all interrupts */
    INTERRUPT_GLOBAL_INTERRUPT_disable();
    /*Write the required sequence :0x55 - 0xAA */
    EECON2=0x55;
    EECON2=0xAA;
    /*Initiates a data EEPROM erase/write cycle*/
    EECON1bits.WR = EEPROM_START_WRITING_ERASE;
    /*Wait for write to complete*/
    while(EECON1bits.WR);
    /*Inhibits write cycle to flash program / data EEPROM*/
    EECON1bits.WREN = INHIBIT_WRITE_TO_EEPROM_FLASH_MEMORY;
    /*Restore the interrupt status enabled/disabled*/
    INTCONbits.GIE = Global_Interrupt_status;
    return ret;
}
/**
 * @brief this function used to read data to EEPROM
 * @param bAdd
 * @param bData
 * @return status  of the function
 *         (E_OK)    :function done successfully
 *         (E_NOT_OK):function fail to do its action due to invalid input 
 */
Std_ReturnType Data_EEPROM_ReadByte(uint16  bAdd, uint8 *bData){
uint8 ret =E_OK;
    if( NULL == bData){
        ret=E_NOT_OK;
    }
    else{
        /*update the address registers*/
        EEADRH = (uint8)((bAdd >>8) & 0x03);
        EEADR = (uint8)(bAdd & 0xFF);
        /*select access data EEPROM*/
        EECON1bits.EEPGD = ACCESS_EEPROM_MEMORY;
        EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY;
        /*initiate EEPROM read cycle*/
        EECON1bits.RD =EEPROM_START_READING;
        NOP();
        NOP();
        /*READ DATA*/
        *bData=EEDATA;
    }
    return ret;
}