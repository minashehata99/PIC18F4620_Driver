/* 
 * File:   hal_usart.c
 * Author: minas
 *
 * Created on September 19, 2023, 7:55 PM
 */

#include "hal_usart.h"

static void EUSART_Baud_Rate_Calculations(const usart_t *eusart);
static void EUSART_ASYNC_TX_Init(const usart_t *eusart);
static void EUSART_ASYNC_RX_Init(const usart_t *eusart);

#if ESUART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
static InterruptHandler ESUART_TX_InterruptHandler = NULL;
#endif

#if ESUART_RX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
static InterruptHandler ESUART_RX_InterruptHandler = NULL;
static InterruptHandler ESUART_Framing_Error_InterruptHandler = NULL;
static InterruptHandler ESUART_Overrun_Error_InterruptHandler = NULL;
#endif

Std_ReturnType EUSART_ASYNC_Init(const usart_t *eusart){
    Std_ReturnType ret =E_OK;
    if( NULL == eusart){
        ret=E_NOT_OK;
    }
    else{
    RCSTAbits.SPEN = EUSART_MODULE_DISABLE; 
    TRISCbits.RC7 = 1;
    TRISCbits.RC6 = 1;
    EUSART_Baud_Rate_Calculations(eusart);
    EUSART_ASYNC_TX_Init(eusart);
    EUSART_ASYNC_RX_Init(eusart);
    RCSTAbits.SPEN = EUSART_MODULE_ENABLE;
    }
    return ret;
}

Std_ReturnType EUSART_ASYNC_DeInit(const usart_t *eusart){
    Std_ReturnType ret =E_OK;
    if( NULL == eusart){
        ret=E_NOT_OK;
    }
    else{
    RCSTAbits.SPEN = EUSART_MODULE_ENABLE;
    
    }
    return ret;
}

Std_ReturnType EUSART_ASYNC_ReadByteBlocking(uint8 *_data){
    Std_ReturnType ret =E_OK;
    if( NULL == _data){
        ret=E_NOT_OK;
    }
    else{
        while(!PIR1bits.RCIF);
        *_data = RCREG;
    }
    return ret;
}

Std_ReturnType EUSART_ASYNC_WriteByteBlocking(uint8 _data){
    Std_ReturnType ret =E_OK;
        while(!TXSTAbits.TRMT);
#if ESUART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE        
        ESUART_TX_INTERRUPT_ENABLE();
#endif        
        TXREG = _data;
    return ret;
}

Std_ReturnType EUSART_ASYNC_ReadByteNonBlocking(uint8 *_data){
    Std_ReturnType ret =E_OK;
    if( NULL == _data){
        ret=E_NOT_OK;
    }
    else{
        if(1 == PIR1bits.RCIF){
        *_data = RCREG;
        }
        else{
            ret=E_NOT_OK;
        }
        }
    return ret;
}

Std_ReturnType EUSART_ASYNC_WriteStringBlocking(uint8 *_data, uint16 str_len){
    Std_ReturnType ret =E_OK;
    uint16 char_counter = ZERO_INIT;
    if( NULL == _data){
        ret=E_NOT_OK;
    }
    else{
        for(char_counter=ZERO_INIT; char_counter < str_len; char_counter++ ){
            ret = EUSART_ASYNC_WriteByteBlocking(_data[char_counter]);
        }
    }
    return ret;
}

Std_ReturnType EUSART_ASYNC_RX_Restart(void){
    Std_ReturnType ret = E_OK;
    RCSTAbits.CREN = 0; /*disable receiver*/
    RCSTAbits.CREN = 1; /*enable receiver*/
    return ret;
}



static void EUSART_Baud_Rate_Calculations(const usart_t *eusart){
    float Baud_Rate_Temp = 0;
    switch(eusart->baudrate_gen_gonfig){
        case BAUDRATE_ASYN_8BIT_LOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ( (_XTAL_FREQ / (float)eusart->baudrate) / 64.0 ) - 1;
            break;
        case BAUDRATE_ASYN_8BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ( (_XTAL_FREQ / (float)eusart->baudrate) / 16.0 ) - 1;
            break;    
        case BAUDRATE_ASYN_16BIT_LOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ( (_XTAL_FREQ / (float)eusart->baudrate) / 16.0 ) - 1;
            break;
        case BAUDRATE_ASYN_16BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ( (_XTAL_FREQ / (float)eusart->baudrate) / 4.0 ) - 1;
            break;
        case BAUDRATE_ASYN_8BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ( (_XTAL_FREQ / (float)eusart->baudrate) / 4.0 ) - 1;
            break;
        case BAUDRATE_ASYN_16BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ( (_XTAL_FREQ / (float)eusart->baudrate) / 4.0 ) - 1;
            break;            
        default: /* Nothing */ ;    
    }
    SPBRG = (uint8)((uint32)Baud_Rate_Temp);
    SPBRGH = (uint8)(((uint32)Baud_Rate_Temp) >> 8);
}

static void EUSART_ASYNC_TX_Init(const usart_t *eusart){
    if(EUSART_ASYNCHRONOUS_TX_ENABLE == eusart->usart_tx_cfg.usart_tx_enable){
        TXSTAbits.TXEN = EUSART_ASYNCHRONOUS_TX_ENABLE;
        if(EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE == eusart->usart_tx_cfg.usart_tx_interrupt_enable){
            PIE1bits.TXIE = EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE;
            /* INTERRUPT CONFIGURATION*/
#if ESUART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        ESUART_TX_INTERRUPT_ENABLE();
        ESUART_TX_InterruptHandler = eusart->EUSART_TxDefaultInterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_LEVEL_ENABLE();
        
        if(INTERRUPT_HIGH_PRIORITY == eusart->usart_tx_cfg.tx_int_priority){
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            ESUART_TX_HIGH_PRIORITY_SET();
        }
        else if(INTERRUPT_LOW_PRIORITY == eusart->usart_tx_cfg.tx_int_priority){
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            ESUART_TX_LOW_PRIORITY_SET();
        }
        else{/*Nothing*/}
#else      
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif
#endif            
        }
        else if(EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE == eusart->usart_tx_cfg.usart_tx_interrupt_enable){
            PIE1bits.TXIE = EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE;
        }
        else{/* Nothing */}
        if(EUSART_ASYNCHRONOUS_9BIT_TX_ENABLE == eusart->usart_tx_cfg.usart_tx_9bit_enable){
            TXSTAbits.TX9 = EUSART_ASYNCHRONOUS_9BIT_TX_ENABLE;
        }
        else if(EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE == eusart->usart_tx_cfg.usart_tx_9bit_enable){
            TXSTAbits.TX9 = EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE;
        }
        else{/* Nothing */}
    }
    else{/* Nothing */}
}

static void EUSART_ASYNC_RX_Init(const usart_t *eusart){
    if(EUSART_ASYNCHRONOUS_RX_ENABLE == eusart->usart_rx_cfg.usart_rx_enable){
        RCSTAbits.CREN = EUSART_ASYNCHRONOUS_RX_ENABLE;
        if(EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE == eusart->usart_rx_cfg.usart_rx_interrupt_enable){
            PIE1bits.RCIE = EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE;
            /* INTERRUPT CONFIGURATION*/
#if ESUART_RX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        ESUART_RX_INTERRUPT_ENABLE();
        ESUART_RX_InterruptHandler = eusart->EUSART_RxDefaultInterruptHandler;
        ESUART_Framing_Error_InterruptHandler = eusart->EUSART_FramingErrorHandler;
        ESUART_Overrun_Error_InterruptHandler = eusart->EUSART_OverrunErrorHandle;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_LEVEL_ENABLE();
        
        if(INTERRUPT_HIGH_PRIORITY == eusart->usart_rx_cfg.rx_int_priority){
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            ESUART_RX_HIGH_PRIORITY_SET();
        }
        else if(INTERRUPT_LOW_PRIORITY == eusart->usart_rx_cfg.rx_int_priority){
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            ESUART_RX_LOW_PRIORITY_SET();
        }
        else{/*Nothing*/}
#else      
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif
#endif            
        }
        else if(EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE == eusart->usart_rx_cfg.usart_rx_interrupt_enable){
            PIE1bits.RCIE = EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE;
        }
        else{/* Nothing */}
        if(EUSART_ASYNCHRONOUS_9BIT_RX_ENABLE == eusart->usart_rx_cfg.usart_rx_9bit_enable){
            RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9BIT_RX_ENABLE;
        }
        else if(EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE == eusart->usart_rx_cfg.usart_rx_9bit_enable){
            RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE;
        }
        else{/* Nothing */}
    }
    else{/* Nothing */}
}

void EUSART_TX_ISR (void){
    /* code */
    PIE1bits.TXIE = 0;
    /* callback function gets called */
    if(ESUART_TX_InterruptHandler){ ESUART_TX_InterruptHandler(); }
}

void EUSART_RX_ISR (void){
    /* code */
    /* callback function gets called */
    if(ESUART_RX_InterruptHandler){ ESUART_RX_InterruptHandler(); }
    if(ESUART_Framing_Error_InterruptHandler){ ESUART_Framing_Error_InterruptHandler(); }
    if(ESUART_Overrun_Error_InterruptHandler){ ESUART_Overrun_Error_InterruptHandler(); }
}