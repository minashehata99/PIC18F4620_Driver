/* 
 * File:   hal_eeprom.h
 * Author: minas
 *
 * Created on September 7, 2023, 6:44 AM
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H

/* Section :  Includes   */
#include "../interrupt/mcal_internal_interrupt.h"
#include "../proc/pic18f4620.h"
#include  "../mcal_std_types.h"

/* Section :  Macro declaration   */

#define ACCESS_EEPROM_MEMORY  0
#define ACCESS_FLASH_MEMORY   1

#define ACCESS_CONFIGURATION_BITS    1
#define ACCESS_FLASH_EEPROM_MEMORY   0

#define ALLOW_WRITE_TO_EEPROM_FLASH_MEMORY     1
#define INHIBIT_WRITE_TO_EEPROM_FLASH_MEMORY   0
#define EEPROM_START_WRITING_ERASE             1
#define EEPROM_WRITING_ERASE_COMPLETER         0
#define EEPROM_START_READING             1
#define EEPROM_READING_COMPLETER         0
/* Section :  Macro function   */

/* Section :  Data types   */


/* Section :  Function Declaration   */
Std_ReturnType Data_EEPROM_WriteByte(uint16  bAdd, uint8 bData);
Std_ReturnType Data_EEPROM_ReadByte(uint16  bAdd, uint8 *bData);
#endif	/* HAL_EEPROM_H */

