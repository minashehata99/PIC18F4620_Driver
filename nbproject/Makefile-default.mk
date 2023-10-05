#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_layer/Button/ecu_button.c ECU_layer/Chr_LCD/ecu_chr_lcd.c ECU_layer/DC_Motor/ecu_dc_motor.c ECU_layer/intitializer/ecu_initializer.c ECU_layer/Key_pad/ecu_key_pad.c ECU_layer/LED/ecu_led.c ECU_layer/Relay/ecu_relay.c ECU_layer/Seven_Segment/ecu_seven_seg.c MCAL_LAYER/ADC/hal_adc.c MCAL_LAYER/CCP1/hal_ccp1.c MCAL_LAYER/EEPROM/hal_eeprom.c MCAL_LAYER/GPIO/hal_gpio.c MCAL_LAYER/I2C/hal_i2c.c MCAL_LAYER/interrupt/mcal_internal_interrupt.c MCAL_LAYER/interrupt/mcal_external_interrupt.c MCAL_LAYER/interrupt/mcal_interrupt_manager.c MCAL_LAYER/Timer/hal_timer0.c MCAL_LAYER/Timer1/hal_timer1.c MCAL_LAYER/Timer2/hal_timer2.c MCAL_LAYER/Timer3/hal_timer3.c MCAL_LAYER/USART/hal_usart.c MCAL_LAYER/device_config.c application.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_layer/Button/ecu_button.p1 ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1 ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1 ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1 ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1 ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1 ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1 ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1 ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1 ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1 ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1 ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1 ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1 ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1 ${OBJECTDIR}/MCAL_LAYER/device_config.p1 ${OBJECTDIR}/application.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_layer/Button/ecu_button.p1.d ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1.d ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1.d ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1.d ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1.d ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1.d ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1.d ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1.d ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1.d ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1.d ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d ${OBJECTDIR}/application.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_layer/Button/ecu_button.p1 ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1 ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1 ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1 ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1 ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1 ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1 ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1 ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1 ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1 ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1 ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1 ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1 ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1 ${OBJECTDIR}/MCAL_LAYER/device_config.p1 ${OBJECTDIR}/application.p1

# Source Files
SOURCEFILES=ECU_layer/Button/ecu_button.c ECU_layer/Chr_LCD/ecu_chr_lcd.c ECU_layer/DC_Motor/ecu_dc_motor.c ECU_layer/intitializer/ecu_initializer.c ECU_layer/Key_pad/ecu_key_pad.c ECU_layer/LED/ecu_led.c ECU_layer/Relay/ecu_relay.c ECU_layer/Seven_Segment/ecu_seven_seg.c MCAL_LAYER/ADC/hal_adc.c MCAL_LAYER/CCP1/hal_ccp1.c MCAL_LAYER/EEPROM/hal_eeprom.c MCAL_LAYER/GPIO/hal_gpio.c MCAL_LAYER/I2C/hal_i2c.c MCAL_LAYER/interrupt/mcal_internal_interrupt.c MCAL_LAYER/interrupt/mcal_external_interrupt.c MCAL_LAYER/interrupt/mcal_interrupt_manager.c MCAL_LAYER/Timer/hal_timer0.c MCAL_LAYER/Timer1/hal_timer1.c MCAL_LAYER/Timer2/hal_timer2.c MCAL_LAYER/Timer3/hal_timer3.c MCAL_LAYER/USART/hal_usart.c MCAL_LAYER/device_config.c application.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_layer/Button/ecu_button.p1: ECU_layer/Button/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Button" 
	@${RM} ${OBJECTDIR}/ECU_layer/Button/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Button/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Button/ecu_button.p1 ECU_layer/Button/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Button/ecu_button.d ${OBJECTDIR}/ECU_layer/Button/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Button/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1: ECU_layer/Chr_LCD/ecu_chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Chr_LCD" 
	@${RM} ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1 ECU_layer/Chr_LCD/ecu_chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.d ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1: ECU_layer/DC_Motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1 ECU_layer/DC_Motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.d ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1: ECU_layer/intitializer/ecu_initializer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/intitializer" 
	@${RM} ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1 ECU_layer/intitializer/ecu_initializer.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.d ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1: ECU_layer/Key_pad/ecu_key_pad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Key_pad" 
	@${RM} ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1 ECU_layer/Key_pad/ecu_key_pad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.d ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LED/ecu_led.p1: ECU_layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ECU_layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LED/ecu_led.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1: ECU_layer/Relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Relay" 
	@${RM} ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1 ECU_layer/Relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.d ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1: ECU_layer/Seven_Segment/ecu_seven_seg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Seven_Segment" 
	@${RM} ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1 ECU_layer/Seven_Segment/ecu_seven_seg.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.d ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1: MCAL_LAYER/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 MCAL_LAYER/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.d ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1: MCAL_LAYER/CCP1/hal_ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1 MCAL_LAYER/CCP1/hal_ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.d ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1: MCAL_LAYER/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 MCAL_LAYER/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1: MCAL_LAYER/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 MCAL_LAYER/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1: MCAL_LAYER/I2C/hal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1 MCAL_LAYER/I2C/hal_i2c.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.d ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1: MCAL_LAYER/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1 MCAL_LAYER/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1: MCAL_LAYER/interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1 MCAL_LAYER/interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1: MCAL_LAYER/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1 MCAL_LAYER/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1: MCAL_LAYER/Timer/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Timer" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1 MCAL_LAYER/Timer/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.d ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1: MCAL_LAYER/Timer1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1 MCAL_LAYER/Timer1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.d ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1: MCAL_LAYER/Timer2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1 MCAL_LAYER/Timer2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.d ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1: MCAL_LAYER/Timer3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1 MCAL_LAYER/Timer3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.d ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1: MCAL_LAYER/USART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/USART" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1 MCAL_LAYER/USART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.d ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/device_config.p1: MCAL_LAYER/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/device_config.p1 MCAL_LAYER/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/device_config.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_layer/Button/ecu_button.p1: ECU_layer/Button/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Button" 
	@${RM} ${OBJECTDIR}/ECU_layer/Button/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Button/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Button/ecu_button.p1 ECU_layer/Button/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Button/ecu_button.d ${OBJECTDIR}/ECU_layer/Button/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Button/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1: ECU_layer/Chr_LCD/ecu_chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Chr_LCD" 
	@${RM} ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1 ECU_layer/Chr_LCD/ecu_chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.d ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Chr_LCD/ecu_chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1: ECU_layer/DC_Motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1 ECU_layer/DC_Motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.d ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1: ECU_layer/intitializer/ecu_initializer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/intitializer" 
	@${RM} ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1 ECU_layer/intitializer/ecu_initializer.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.d ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/intitializer/ecu_initializer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1: ECU_layer/Key_pad/ecu_key_pad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Key_pad" 
	@${RM} ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1 ECU_layer/Key_pad/ecu_key_pad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.d ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Key_pad/ecu_key_pad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LED/ecu_led.p1: ECU_layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ECU_layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LED/ecu_led.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1: ECU_layer/Relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Relay" 
	@${RM} ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1 ECU_layer/Relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.d ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1: ECU_layer/Seven_Segment/ecu_seven_seg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Seven_Segment" 
	@${RM} ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1 ECU_layer/Seven_Segment/ecu_seven_seg.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.d ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Seven_Segment/ecu_seven_seg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1: MCAL_LAYER/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 MCAL_LAYER/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.d ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1: MCAL_LAYER/CCP1/hal_ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1 MCAL_LAYER/CCP1/hal_ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.d ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/CCP1/hal_ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1: MCAL_LAYER/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 MCAL_LAYER/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1: MCAL_LAYER/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 MCAL_LAYER/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1: MCAL_LAYER/I2C/hal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1 MCAL_LAYER/I2C/hal_i2c.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.d ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/I2C/hal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1: MCAL_LAYER/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1 MCAL_LAYER/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1: MCAL_LAYER/interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1 MCAL_LAYER/interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1: MCAL_LAYER/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1 MCAL_LAYER/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1: MCAL_LAYER/Timer/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Timer" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1 MCAL_LAYER/Timer/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.d ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Timer/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1: MCAL_LAYER/Timer1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1 MCAL_LAYER/Timer1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.d ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Timer1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1: MCAL_LAYER/Timer2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1 MCAL_LAYER/Timer2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.d ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Timer2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1: MCAL_LAYER/Timer3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1 MCAL_LAYER/Timer3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.d ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Timer3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1: MCAL_LAYER/USART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/USART" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1 MCAL_LAYER/USART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.d ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/device_config.p1: MCAL_LAYER/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/device_config.p1 MCAL_LAYER/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/device_config.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/application.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/application.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/application.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/application.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/application.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
