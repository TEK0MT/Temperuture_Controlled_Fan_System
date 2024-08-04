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
FINAL_IMAGE=${DISTDIR}/Temperature-Controlled_Fan_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Temperature-Controlled_Fan_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=ECU_LAYER/LCD/ecu_lcd.c ECU_LAYER/Motor/ecu_motor_driver.c ECU_LAYER/ECU_LAYER.c MCAL_LAYER/GPIO/mcal_gpio.c MCAL_LAYER/INTERRUPT/external_interrupt.c MCAL_LAYER/INTERRUPT/interrupt_manager.c MCAL_LAYER/device_config.c Temperature_Controlled_Fan_System.c MCAL_LAYER/EEPROM/eeprom.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1 ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1 ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1 ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1 ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1 ${OBJECTDIR}/MCAL_LAYER/device_config.p1 ${OBJECTDIR}/Temperature_Controlled_Fan_System.p1 ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1.d ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1.d ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1.d ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1.d ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d ${OBJECTDIR}/Temperature_Controlled_Fan_System.p1.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1 ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1 ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1 ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1 ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1 ${OBJECTDIR}/MCAL_LAYER/device_config.p1 ${OBJECTDIR}/Temperature_Controlled_Fan_System.p1 ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1

# Source Files
SOURCEFILES=ECU_LAYER/LCD/ecu_lcd.c ECU_LAYER/Motor/ecu_motor_driver.c ECU_LAYER/ECU_LAYER.c MCAL_LAYER/GPIO/mcal_gpio.c MCAL_LAYER/INTERRUPT/external_interrupt.c MCAL_LAYER/INTERRUPT/interrupt_manager.c MCAL_LAYER/device_config.c Temperature_Controlled_Fan_System.c MCAL_LAYER/EEPROM/eeprom.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Temperature-Controlled_Fan_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F877A
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1: ECU_LAYER/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/LCD" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1 ECU_LAYER/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.d ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1: ECU_LAYER/Motor/ecu_motor_driver.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/Motor" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1 ECU_LAYER/Motor/ecu_motor_driver.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.d ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1: ECU_LAYER/ECU_LAYER.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1 ECU_LAYER/ECU_LAYER.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.d ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1: MCAL_LAYER/GPIO/mcal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1 MCAL_LAYER/GPIO/mcal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.d ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1: MCAL_LAYER/INTERRUPT/external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1 MCAL_LAYER/INTERRUPT/external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.d ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1: MCAL_LAYER/INTERRUPT/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1 MCAL_LAYER/INTERRUPT/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.d ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/device_config.p1: MCAL_LAYER/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/device_config.p1 MCAL_LAYER/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/device_config.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Temperature_Controlled_Fan_System.p1: Temperature_Controlled_Fan_System.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Temperature_Controlled_Fan_System.p1.d 
	@${RM} ${OBJECTDIR}/Temperature_Controlled_Fan_System.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Temperature_Controlled_Fan_System.p1 Temperature_Controlled_Fan_System.c 
	@-${MV} ${OBJECTDIR}/Temperature_Controlled_Fan_System.d ${OBJECTDIR}/Temperature_Controlled_Fan_System.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Temperature_Controlled_Fan_System.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1: MCAL_LAYER/EEPROM/eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1 MCAL_LAYER/EEPROM/eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1: ECU_LAYER/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/LCD" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1 ECU_LAYER/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.d ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1: ECU_LAYER/Motor/ecu_motor_driver.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/Motor" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1 ECU_LAYER/Motor/ecu_motor_driver.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.d ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/Motor/ecu_motor_driver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1: ECU_LAYER/ECU_LAYER.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1 ECU_LAYER/ECU_LAYER.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.d ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/ECU_LAYER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1: MCAL_LAYER/GPIO/mcal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1 MCAL_LAYER/GPIO/mcal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.d ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/GPIO/mcal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1: MCAL_LAYER/INTERRUPT/external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1 MCAL_LAYER/INTERRUPT/external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.d ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1: MCAL_LAYER/INTERRUPT/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1 MCAL_LAYER/INTERRUPT/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.d ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/INTERRUPT/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/device_config.p1: MCAL_LAYER/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/device_config.p1 MCAL_LAYER/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/device_config.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Temperature_Controlled_Fan_System.p1: Temperature_Controlled_Fan_System.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Temperature_Controlled_Fan_System.p1.d 
	@${RM} ${OBJECTDIR}/Temperature_Controlled_Fan_System.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Temperature_Controlled_Fan_System.p1 Temperature_Controlled_Fan_System.c 
	@-${MV} ${OBJECTDIR}/Temperature_Controlled_Fan_System.d ${OBJECTDIR}/Temperature_Controlled_Fan_System.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Temperature_Controlled_Fan_System.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1: MCAL_LAYER/EEPROM/eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1 MCAL_LAYER/EEPROM/eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/EEPROM/eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
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
${DISTDIR}/Temperature-Controlled_Fan_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Temperature-Controlled_Fan_System.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Temperature-Controlled_Fan_System.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Temperature-Controlled_Fan_System.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/Temperature-Controlled_Fan_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Temperature-Controlled_Fan_System.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Temperature-Controlled_Fan_System.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
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
