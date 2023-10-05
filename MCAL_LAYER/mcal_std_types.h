/* 
 * File:   mcal_std_types.h
 * Author: minas
 *
 * Created on August 6, 2023, 2:20 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* Section :  Includes   */

#include "std_libiraries.h"
#include "compiler.h"



/* Section :  Data types   */

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;

typedef uint8 Std_ReturnType;

/* Section :  Macro declaration   */

#define STD_HIGH       0x01
#define STD_LOW        0x00

#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_IDLE       0x00

#define E_OK          (Std_ReturnType)0x01
#define E_NOT_OK      (Std_ReturnType)0x00


#define CONFIG_ENABLE 1
#define CONFIG_DISABLE 0

#define ZERO_INIT 0

/* Section :  Macro function   */




/* Section :  Function Declaration   */

#endif	/* MCAL_STD_TYPES_H */

