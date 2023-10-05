/* 
 * File:   hal_i2c.c
 * Author: minas
 *
 * Created on September 26, 2023, 8:24 AM
 */

#include "hal_i2c.h"
/**
 * 
 * @param i2c_obj
 * @return 
 */

#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        static void (*MSSP_I2C_InterruptHandler)(void) = NULL; 
        static void (*I2C_Reported_Write_Collision)(void) = NULL;
        static void (*I2C_Reported_Receive_Overflow)(void) = NULL;
#endif
static inline void I2C_Master_Mode_Clock_configuration(const mssp_i2c_t *i2c_obj);

Std_ReturnType MSSP_I2C_Init(const mssp_i2c_t *i2c_obj){
    Std_ReturnType ret =E_OK;
    if(NULL == i2c_obj){
        ret=E_NOT_OK;
    }
    else{
        MSSP_MODULE_DISABLE_CFG();
        
        if(MSSP_I2C_MASTER_MODE == i2c_obj->i2c_cfg.i2c_mode){
            I2C_Master_Mode_Clock_configuration(i2c_obj);
        }
        else if(MSSP_I2C_SLAVE_MODE == i2c_obj->i2c_cfg.i2c_mode){
            if(I2C_GENERAL_CALL_ENABLE == i2c_obj->i2c_cfg.i2c_general_call){
                I2C_GENERAL_CALL_ENABLE_CFG();
            }
            else if(I2C_GENERAL_CALL_DISABLE == i2c_obj->i2c_cfg.i2c_general_call){
                I2C_GENERAL_CALL_DISABLE_CFG();
            }
            else{ /* Noting */ }
            SSPCON1bits.WCOL = 0;
            SSPCON1bits.SSPOV = 0;
            SSPCON1bits.CKP = 1;
            SSPADD = i2c_obj->i2c_cfg.i2c_slave_address;
            SSPCON1bits.SSPM = i2c_obj->i2c_cfg.i2c_mode_cfg; 
        }
        else{/* Nothing */}
        /* Set scl and sda as input */
        TRISCbits.TRISC3 = 1;
        TRISCbits.TRISC4 = 1;
        
        if(I2C_SLEW_RATE_ENABLE == i2c_obj->i2c_cfg.i2c_slew_rate){
                I2C_SLEW_RATE_ENABLE_CFG();
            }
            else if(I2C_SLEW_RATE_DISABLE == i2c_obj->i2c_cfg.i2c_slew_rate){
                I2C_SLEW_RATE_DISABLE_CFG();
            }
            else{ /* Noting */ }
        
        
        if(I2C_SLEW_RATE_ENABLE == i2c_obj->i2c_cfg.i2c_SMBus_control){
                I2C_SMbus_ENABLE_CFG();
            }
            else if(I2C_SMBus_DISABLE == i2c_obj->i2c_cfg.i2c_SMBus_control){
                I2C_SMbus_DISABLE_CFG();
            }
            else{ /* Noting */ }
        
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        MSSP_I2C_INTERRUPT_ENABLE();
        MSSP_I2C_BUS_COL_INTERRUPT_ENABLE();
        MSSP_I2C_INTERRUPT_FLAG_CLEAR();
        MSSP_I2C_BUS_COL_INTERRUPT_FLAG_CLEAR();
        MSSP_I2C_InterruptHandler = i2c_obj->I2C_DefaultInterruptHandler;
        I2C_Reported_Write_Collision = i2c_obj->I2C_Reported_Write_Collision;
        I2C_Reported_Receive_Overflow = i2c_obj->I2C_Reported_Receive_Overflow;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_LEVEL_ENABLE();
        
        if(INTERRUPT_HIGH_PRIORITY == i2c_obj->i2c_cfg.mssp_i2c_priority){
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            MSSP_I2C_HIGH_PRIORITY_SET();
        }
        else if(INTERRUPT_LOW_PRIORITY == i2c_obj->i2c_cfg.mssp_i2c_priority){
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            MSSP_I2C_LOW_PRIORITY_SET();
        }
        else{/*Nothing*/}
        
        if(INTERRUPT_HIGH_PRIORITY == i2c_obj->i2c_cfg.mssp_i2c_priority){
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            MSSP_I2C_BUS_COL_HIGH_PRIORITY_SET();
        }
        else if(INTERRUPT_LOW_PRIORITY == i2c_obj->i2c_cfg.mssp_i2c_priority){
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            MSSP_I2C_BUS_COL_LOW_PRIORITY_SET();
        }
        else{/*Nothing*/}
#else      
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif
#endif
        
        MSSP_MODULE_ENABLE_CFG();
    }
    return ret;
}
/**
 * 
 * @param i2c_obj
 * @return 
 */
Std_ReturnType MSSP_I2C_DeInit(const mssp_i2c_t *i2c_obj){
    Std_ReturnType ret =E_OK;
    if(NULL == i2c_obj){
        ret=E_NOT_OK;
    }
    else{
        MSSP_MODULE_DISABLE_CFG();
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        MSSP_I2C_INTERRUPT_DISABLE();
        MSSP_I2C_BUS_COL_INTERRUPT_DISABLE() ;
#endif        
    }
    return ret;
}
/**
 * 
 * @param i2c_obj
 * @return 
 */
Std_ReturnType MSSP_I2C_Master_Send_Start(const mssp_i2c_t *i2c_obj){
    Std_ReturnType ret =E_OK;
    if(NULL == i2c_obj){
        ret=E_NOT_OK;
    }
    else{
        SSPCON2bits.SEN = 1;
        while(SSPCON2bits.SEN);
        PIR1bits.SSPIF = 0;
        if(START_BIT_DETECTED == SSPSTATbits.S){
            ret =E_OK;
        }
        else{
            ret =E_NOT_OK;
        }
    }
    return ret;
}
/**
 * 
 * @param i2c_obj
 * @return 
 */
Std_ReturnType MSSP_I2C_Master_Send_Repeated_Start(const mssp_i2c_t *i2c_obj){
    Std_ReturnType ret =E_OK;
    if(NULL == i2c_obj){
        ret=E_NOT_OK;
    }
    else{
        SSPCON2bits.RSEN = 1;
        while(SSPCON2bits.RSEN);
        PIR1bits.SSPIF = 0;
    }
    return ret;
}
/**
 * 
 * @param i2c_obj
 * @return 
 */
Std_ReturnType MSSP_I2C_Master_Send_Stop(const mssp_i2c_t *i2c_obj){
    Std_ReturnType ret =E_OK;
    if(NULL == i2c_obj){
        ret=E_NOT_OK;
    }
    else{
        SSPCON2bits.PEN = 1;
        while(SSPCON2bits.PEN);
        PIR1bits.SSPIF = 0;
        if(STOP_BIT_DETECTED == SSPSTATbits.P){
            ret =E_OK;
        }
        else{
            ret =E_NOT_OK;
        }
    }
    return ret;
}
/**
 * 
 * @param i2c_obj
 * @param i2c_data
 * @return 
 */
Std_ReturnType MSSP_I2C_Master_Write_Blocking(const mssp_i2c_t *i2c_obj, uint8 i2c_data, uint8 *_ack){
    Std_ReturnType ret =E_OK;
    if((NULL == i2c_obj) || (NULL == _ack)){
        ret=E_NOT_OK;
    }
    else{
        I2C_MASTER_RECEIVE_ENABLE_CFG();
        SSPBUF = i2c_data;
        while(!PIR1bits.SSPIF);
        PIR1bits.SSPIF = 0;
        if(I2C_ACK_RECEIVED_FROM_SLAVE == SSPCON2bits.ACKSTAT){
            *_ack = I2C_ACK_RECEIVED_FROM_SLAVE;
        }
        else{
            *_ack = I2C_ACK_NOT_RECEIVED_FROM_SLAVE;
        }
    }
    return ret;
}
/**
 * 
 * @param i2c_obj
 * @param ack
 * @param i2c_data
 * @return 
 */
Std_ReturnType MSSP_I2C_Master_Read_Blocking(const mssp_i2c_t *i2c_obj, uint8 ack, uint8 *i2c_data){
    Std_ReturnType ret =E_OK;
    if((NULL == i2c_data) || (NULL == i2c_obj)){
        ret=E_NOT_OK;
    }
    else{
        *i2c_data = SSPBUF;
        if(I2C_MASTER_SEND_ACK == ack){
            SSPCON2bits.ACKDT = 0;
            SSPCON2bits.ACKEN = 1; 
        }
        else if(I2C_MASTER_SEND_NACK == ack){
            SSPCON2bits.ACKDT = 1;
            SSPCON2bits.ACKEN = 1; 
        }
        else{/* Nothing */}
    }
    return ret;
}

static inline void I2C_Master_Mode_Clock_configuration(const mssp_i2c_t *i2c_obj){
    SSPCON1bits.SSPM = I2C_MASTER_MODE_DEFINED_CLOCK;
    SSPADD = (uint8)(((_XTAL_FREQ / 4.0)/ i2c_obj->i2c_clock) - 1);
}

void MSSP_I2C_ISR (void){
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE    
/* clear flag bit */
    MSSP_I2C_INTERRUPT_FLAG_CLEAR();
    /* code */
    /* callback function gets called */
    if(MSSP_I2C_InterruptHandler){ MSSP_I2C_InterruptHandler(); }
#endif    
}

void MSSP_I2C_BCL_ISR (void){
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE    
/* clear flag bit */
    MSSP_I2C_BUS_COL_INTERRUPT_FLAG_CLEAR();
    /* code */
    /* callback function gets called */
    if(I2C_Reported_Write_Collision){ I2C_Reported_Write_Collision(); }
#endif    
}