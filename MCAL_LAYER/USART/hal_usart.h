/* 
 * File:   hal_usart.h
 * Author: minas
 *
 * Created on September 19, 2023, 7:55 PM
 */

#ifndef HAL_USART_H
#define	HAL_USART_H

/* Section :  Includes   */

#include "hal_usart_cfg.h"
#include "../GPIO/hal_gpio.h"
#include "../../MCAL_LAYER/interrupt/mcal_internal_interrupt.h"
#include "../proc/pic18f4620.h"
#include "../../MCAL_LAYER/mcal_std_types.h"

/* Section :  Macro declaration   */

#define _XTAL_FREQ 8000000UL

#define EUSART_MODULE_ENABLE     1
#define EUSART_MODULE_DISABLE    0

#define EUSART_SYNCHRONOUS_MODE    1
#define EUSART_ASYNCHRONOUS_MODE   0

#define EUSART_ASYNCHRONOUS_HIGH_SPEED   1
#define EUSART_ASYNCHRONOUS_LOW_SPEED    0

#define EUSART_16BIT_BAUDRATE_GEN         1
#define EUSART_08BIT_BAUDRATE_GEN         0

#define EUSART_ASYNCHRONOUS_TX_ENABLE    1
#define EUSART_ASYNCHRONOUS_TX_DISABLE   0

#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE    1
#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE   0

#define EUSART_ASYNCHRONOUS_9BIT_TX_ENABLE    1
#define EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE   0

#define EUSART_ASYNCHRONOUS_RX_ENABLE    1
#define EUSART_ASYNCHRONOUS_RX_DISABLE   0

#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE    1
#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE   0

#define EUSART_ASYNCHRONOUS_9BIT_RX_ENABLE    1
#define EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE   0

#define EUSART_FRAMING_ERROR_DETECTED    1
#define EUSART_FRAMING_ERROR_CLEARED     0

#define EUSART_OVERRUN_ERROR_DETECTED    1
#define EUSART_OVERRUN_ERROR_CLEARED     0

/* Section :  Macro function   */



/* Section :  Data types   */

typedef enum{
    BAUDRATE_ASYN_8BIT_LOW_SPEED,
    BAUDRATE_ASYN_8BIT_HIGH_SPEED,
    BAUDRATE_ASYN_16BIT_LOW_SPEED,
    BAUDRATE_ASYN_16BIT_HIGH_SPEED,
    BAUDRATE_ASYN_8BIT,
    BAUDRATE_ASYN_16BIT                  
}baudrate_gen_t;

typedef struct{
    uint8 usart_rx_reserved : 4;
    interrupt_priority_cfg rx_int_priority;
    uint8 usart_rx_enable   : 1;
    uint8 usart_rx_interrupt_enable  : 1;
    uint8 usart_rx_9bit_enable : 1;
}usart_rx_cfg_t;

typedef struct{
    uint8 usart_tx_reserved : 4;
    interrupt_priority_cfg tx_int_priority;
    uint8 usart_tx_enable   : 1;
    uint8 usart_tx_interrupt_enable  : 1;
    uint8 usart_tx_9bit_enable : 1;
}usart_tx_cfg_t;

typedef union{
    struct{
        uint8 uart_tx_reserved :6;
        uint8 usart_ferr       :1;
        uint8 usart_oerr       :1;
    };
    uint8 status;
}usart_error_status_t;

typedef struct{
    uint32 baudrate;
    baudrate_gen_t baudrate_gen_gonfig;
    usart_tx_cfg_t usart_tx_cfg;
    usart_rx_cfg_t usart_rx_cfg;
    usart_error_status_t error_status;
    void(*EUSART_TxDefaultInterruptHandler)(void);
    void(*EUSART_RxDefaultInterruptHandler)(void);
    void(*EUSART_FramingErrorHandler)(void);
    void(*EUSART_OverrunErrorHandle)(void);
}usart_t;



/* Section :  Function Declaration   */

Std_ReturnType EUSART_ASYNC_Init(const usart_t *eusart);
Std_ReturnType EUSART_ASYNC_DeInit(const usart_t *eusart);
Std_ReturnType EUSART_ASYNC_ReadByteBlocking(uint8 *_data);
Std_ReturnType EUSART_ASYNC_ReadByteNonBlocking(uint8 *_data);
Std_ReturnType EUSART_ASYNC_WriteByteBlocking(uint8 _data);
Std_ReturnType EUSART_ASYNC_RX_Restart(void);
Std_ReturnType EUSART_ASYNC_WriteStringBlocking(uint8 *_data, uint16 str_len);

#endif	/* HAL_USART_H */

