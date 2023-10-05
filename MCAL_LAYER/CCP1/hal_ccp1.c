/* 
 * File:   hal_ccp1.h
 * Author: minas
 *
 * Created on September 13, 2023, 5:12 PM
 */

#include "hal_ccp1.h"

#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
static InterruptHandler CCP1_InterruptHandler = NULL;
#endif
#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
static InterruptHandler CCP2_InterruptHandler = NULL;
#endif

static void CCP_Interrupt_Config(const ccp_t *_ccp_obj);
static void CCP_Capture_Mode_Timer_Select(const ccp_t *_ccp_obj);

Std_ReturnType CCP_Init(const ccp_t *_ccp_obj){
    Std_ReturnType ret =E_OK;
    if(NULL == _ccp_obj){
        ret=E_NOT_OK;
    }
    else{
        /* Disable the module */
        if(CCP1_INST == _ccp_obj->ccp_inst){
            CCP1_SET_MODE(CCP_MODULE_DISABLE);
        }
        else if(CCP2_INST == _ccp_obj->ccp_inst){
            CCP2_SET_MODE(CCP_MODULE_DISABLE);
        }
        
        /*sub mode configuration*/
        if(CCP_CAPTURE_MODE_SELECTED == _ccp_obj->ccp_mode){
            if(_ccp_obj->ccp_inst == CCP1_INST){
            switch(_ccp_obj->ccp_mode_variant){
                case CCP_CAPTURE_MODE_1_RISING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_1_RISING_EDGE); break;
                case CCP_CAPTURE_MODE_1_FALLING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE); break;
                case CCP_CAPTURE_MODE_4_RISING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE); break;
                case CCP_CAPTURE_MODE_16_RISING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE); break;
                default :ret = E_NOT_OK;
            }
            CCP_Capture_Mode_Timer_Select(_ccp_obj);
        }
        else if(_ccp_obj->ccp_inst == CCP2_INST){
            switch(_ccp_obj->ccp_mode_variant){
                case CCP_CAPTURE_MODE_1_RISING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_1_RISING_EDGE); break;
                case CCP_CAPTURE_MODE_1_FALLING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE); break;
                case CCP_CAPTURE_MODE_4_RISING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE); break;
                case CCP_CAPTURE_MODE_16_RISING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE); break;
                default :ret = E_NOT_OK;
            }
            CCP_Capture_Mode_Timer_Select(_ccp_obj);
        }
        else{/*Nothing*/}
        }
        else if(CCP_COMPARE_MODE_SELECTED == _ccp_obj->ccp_mode){
                        if(_ccp_obj->ccp_inst == CCP1_INST){
            switch(_ccp_obj->ccp_mode_variant){
                case CCP_COMPARE_MODE_SET_PIN_LOW : CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW); break;
                case CCP_COMPARE_MODE_SET_PIN_HIGH : CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH); break;
                case CCP_COMPARE_MODE_TOGGLE_ON_MATCH : CCP1_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH); break;
                case CCP_COMPARE_MODE_GEN_SW_INTERRUPT : CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT); break;
                case CCP_COMPARE_MODE__GEN_EVENT : CCP1_SET_MODE(CCP_COMPARE_MODE__GEN_EVENT); break;
                default :ret = E_NOT_OK;
            }
        }
        else if(_ccp_obj->ccp_inst == CCP2_INST){
            switch(_ccp_obj->ccp_mode_variant){
                case CCP_COMPARE_MODE_SET_PIN_LOW : CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW); break;
                case CCP_COMPARE_MODE_SET_PIN_HIGH : CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH); break;
                case CCP_COMPARE_MODE_TOGGLE_ON_MATCH : CCP2_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH); break;
                case CCP_COMPARE_MODE_GEN_SW_INTERRUPT : CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT); break;
                case CCP_COMPARE_MODE__GEN_EVENT : CCP2_SET_MODE(CCP_COMPARE_MODE__GEN_EVENT); break;
                default :ret = E_NOT_OK;
            }
        }
        else{/*Nothing*/}
        }
#if (CCP_CFG_PWM_MODE_SELECTED == CCP1_CFG_SELECTED_MODE)  ||    (CCP_CFG_PWM_MODE_SELECTED == CCP2_CFG_SELECTED_MODE)    
        else if(CCP_PWM_MODE_SELECTED == _ccp_obj->ccp_mode){
            if(CCP1_INST == _ccp_obj->ccp_inst){
                if(_ccp_obj->ccp_mode_variant == CCP_PWM_MODE){
                    CCP1_SET_MODE(CCP_PWM_MODE);
                }
                else{/* Nothing */}
            }
            else if(CCP2_INST == _ccp_obj->ccp_inst){
                if(_ccp_obj->ccp_mode_variant == CCP_PWM_MODE){
                    CCP2_SET_MODE(CCP_PWM_MODE);
                }
                else{/* Nothing */}
            }
            else{/* Nothing */}
            /* initialize PWM Frequency */
            PR2 = (uint8)((_XTAL_FREQ/(_ccp_obj->PWM_Freqencey * 4.0 * _ccp_obj->timer2_postscaler_value * _ccp_obj->timer2_prescaler_value))-1);         
        }
        else{/* Nothing */}
 #endif          
        /* pin  initialization */
        ret = gpio_pin_initialize(&(_ccp_obj->ccp_pin));
        CCP_Interrupt_Config(_ccp_obj);
    }
    return ret;
}


Std_ReturnType CCP_DeInit(const ccp_t *_ccp_obj){
    Std_ReturnType ret =E_OK;
    if(NULL == _ccp_obj){
        ret=E_NOT_OK;
    }
    else{
        /* Disable the module */
        if(CCP1_INST == _ccp_obj->ccp_inst){
            CCP1_SET_MODE(CCP_MODULE_DISABLE);
#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        CCP1_INTERRUPT_DISABLE();
#endif            
        }
        else if(CCP2_INST == _ccp_obj->ccp_inst){
            CCP2_SET_MODE(CCP_MODULE_DISABLE);
#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        CCP2_INTERRUPT_DISABLE();
#endif            
        }

    }
    return ret;
}



#if CCP_CFG_COMPARE_MODE_SELECTED == CCP1_CFG_SELECTED_MODE
Std_ReturnType CCP_IsCompareComplete(const ccp_t *_ccp_obj, uint8 *_compare_status){
    Std_ReturnType ret =E_OK;
    if(NULL == _compare_status){
        ret=E_NOT_OK;
    }
    else{
        if(_ccp_obj->ccp_inst == CCP1_INST){
            if(CCP_COMPARE_READY == PIR1bits.CCP1IF){
            *_compare_status = CCP_COMPARE_NOT_READY;
            }
            else{
            *_compare_status = CCP_COMPARE_READY;
            }
        }
        else if(_ccp_obj->ccp_inst == CCP2_INST){
            if(CCP_COMPARE_READY == PIR2bits.CCP2IF){
            *_compare_status = CCP_COMPARE_NOT_READY;
            }
            else{
            *_compare_status = CCP_COMPARE_READY;
            }
        }
        else{/*Nothing*/}
        
        

    }
    return ret;
}


Std_ReturnType CCP_Compare_Mode_Set_Value(const ccp_t *_ccp_obj, uint16 compare_value){
    Std_ReturnType ret =E_OK;
    CCP_REG_T capture_temp_value ={.ccpr_high = 0, .ccpr_low = 0};
    capture_temp_value.ccpr_16bit = compare_value;
    if(NULL == _ccp_obj){
        ret=E_NOT_OK;
    }
    else{
        if(_ccp_obj->ccp_inst == CCP1_INST){
            CCPR2L=capture_temp_value.ccpr_low;
            CCPR2H=capture_temp_value.ccpr_high;
        }
        else if(_ccp_obj->ccp_inst == CCP2_INST){
            CCPR2L=capture_temp_value.ccpr_low;
            CCPR2H=capture_temp_value.ccpr_high;
        }
        else{/*Nothing*/}
    }

    return ret;
}


#endif 

#if CCP_CFG_CAPTURE_MODE_SELECTED == CCP1_CFG_SELECTED_MODE
Std_ReturnType CCP_IsCaptureDataReady(uint8 *_capture_status){
    Std_ReturnType ret =E_OK;
    if(NULL == _capture_status){
        ret=E_NOT_OK;
    }
    else{
        if(CCP_CAPTURE_READY == PIR1bits.CCP1IF){
        *_capture_status = CCP_CAPTURE_NOT_READY;
        }
        else{
        *_capture_status = CCP_CAPTURE_READY;
        }
    }
    return ret;
}


Std_ReturnType CCP_Capture_Mode_Read_Value(uint16 *capture_value){
    Std_ReturnType ret =E_OK;
    CCP_REG_T capture_temp_value ={.ccpr_high = 0, .ccpr_low = 0};
    if(NULL == capture_value){
        ret=E_NOT_OK;
    }
    else{
        capture_temp_value.ccpr_low = CCPR1L;
        capture_temp_value.ccpr_high = CCPR1H;
        *capture_value = capture_temp_value.ccpr_16bit;
    }
    return ret;
}


#endif 

#if CCP_CFG_PWM_MODE_SELECTED == CCP1_CFG_SELECTED_MODE
Std_ReturnType CCP_PWM_Set_Duty(const ccp_t *_ccp_obj,const uint8 _duty){
    Std_ReturnType ret =E_OK;
    uint16 l_duty_temp = 0;
    if(NULL == _ccp_obj){
        ret=E_NOT_OK;
    }
    else{
        l_duty_temp  =(uint16)((PR2+1) * (_duty/100.0) * 4.0);
        if(CCP1_INST == _ccp_obj->ccp_inst){
                CCP1CONbits.DC1B = (uint8)(l_duty_temp & 0x0003);
                CCPR1L = (uint8)(l_duty_temp >> 2);
        }
        else if(CCP2_INST == _ccp_obj->ccp_inst){
            CCP2CONbits.DC2B = (uint8)(l_duty_temp & 0x0003);
            CCPR2L = (uint8)(l_duty_temp >> 2);
        }
    }
    return ret;
}


Std_ReturnType CCP_PWM_Start(const ccp_t *_ccp_obj){
    Std_ReturnType ret =E_OK;
    if(NULL == _ccp_obj){
        ret=E_NOT_OK;
    }
    else{
        if(CCP1_INST == _ccp_obj->ccp_inst){
            CCP1_SET_MODE(CCP_PWM_MODE);
        }
        else if(CCP2_INST == _ccp_obj->ccp_inst){
            CCP2_SET_MODE(CCP_PWM_MODE);
        }
    }
    return ret;
}


Std_ReturnType CCP_PWM_Stop(const ccp_t *_ccp_obj){
    Std_ReturnType ret =E_OK;
    if(NULL == _ccp_obj){
        ret=E_NOT_OK;
    }
    else{
        if(CCP1_INST == _ccp_obj->ccp_inst){
            CCP1_SET_MODE(CCP_MODULE_DISABLE);
        }
        else if(CCP2_INST == _ccp_obj->ccp_inst){
            CCP2_SET_MODE(CCP_MODULE_DISABLE);
        }
    }
    return ret;
}
#endif


void CCP1_ISR (void){
/* clear flag bit */
    CCP1_INTERRUPT_FLAG_CLEAR();
    /* code */
    /* callback function gets called */
    if(CCP1_InterruptHandler){ CCP1_InterruptHandler(); }
}
void CCP2_ISR (void){
/* clear flag bit */
    CCP2_INTERRUPT_FLAG_CLEAR();
    /* code */
    /* callback function gets called */
    if(CCP2_InterruptHandler){ CCP2_InterruptHandler(); }
}

static void CCP_Interrupt_Config(const ccp_t *_ccp_obj){
        /* interrupt  initialization */
#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        CCP1_INTERRUPT_ENABLE();
        CCP1_INTERRUPT_FLAG_CLEAR();
        CCP1_InterruptHandler = _ccp_obj->CCP1_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_LEVEL_ENABLE();
        
        if(INTERRUPT_HIGH_PRIORITY == _ccp_obj->CCP1_priority){
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            CCP1_HIGH_PRIORITY_SET();
        }
        else if(INTERRUPT_LOW_PRIORITY == _ccp_obj->CCP1_priority){
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            CCP1_LOW_PRIORITY_SET();
        }
        else{/*Nothing*/}
#else      
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif
#endif
        
        /* interrupt  initialization */
#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        CCP2_INTERRUPT_ENABLE();
        CCP2_INTERRUPT_FLAG_CLEAR();
        CCP2_InterruptHandler = _ccp_obj->CCP2_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_LEVEL_ENABLE();
        
        if(INTERRUPT_HIGH_PRIORITY == _ccp_obj->CCP2_priority){
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            CCP2_HIGH_PRIORITY_SET();
        }
        else if(INTERRUPT_LOW_PRIORITY == _ccp_obj->CCP2_priority){
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            CCP2_LOW_PRIORITY_SET();
        }
        else{/*Nothing*/}
#else      
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PEREPHRAL_INTERRUPT_ENABLE();
#endif
#endif    
}

static void CCP_Capture_Mode_Timer_Select(const ccp_t *_ccp_obj){
    if(CCP1_CCP2_TIMER3 == _ccp_obj->ccp_capture_timer){
        T3CONbits.T3CCP1 = 0;
        T3CONbits.T3CCP2 = 1;
    }
    else if(CCP1_TIMER1_CCP2_TIMER3 == _ccp_obj->ccp_capture_timer){
        T3CONbits.T3CCP1 = 1;
        T3CONbits.T3CCP2 = 0;
    }
    else if(CCP1_CCP2_TIMER1 == _ccp_obj->ccp_capture_timer){
        T3CONbits.T3CCP1 = 0;
        T3CONbits.T3CCP2 = 0;
    }
    else{/*Nothing*/}
}