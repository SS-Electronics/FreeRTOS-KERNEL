# File:        Makefile
# Author:      Subhajit Roy  
#              subhajitroy005@gmail.com 
#
# Moudle:      Modeule Device [ Local Build ] 
# Info:        Compile sources based on spefic target 
#                             
# Dependency:  None
#
# This file is part of FreeRTOS-KERNEL Project.
# 
# FreeRTOS-KERNEL is free software: you can redistribute it and/or 
# modify it under the terms of the GNU General Public License 
# as published by the Free Software Foundation, either version 
# 3 of the License, or (at your option) any later version.
#
# FreeRTOS-KERNEL is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License 
# along with FreeRTOS-KERNEL. If not, see <https://www.gnu.org/licenses/>.


-include ../make_config.mk

$(info #################################)
$(info Module: Device -- Source Build --)


NULL_STR :=
FILE_EXT :=
OBJECTS_LOCATION := ./build/objs/
SOURCE_DIR		 := ./

ifeq ( $(TARGET) , $(NULL_STR) )
$(info Device: No Target Nselected.....!)
else
$(info Device: Building Sources........!)
endif

#################  Configurations ##################################
#-----------------------------------------------
#  Devive Vendor:   ST Microelectronics
#  Target       :   STM32F429VIT6
#  Core         :   ARM-CM4
#-----------------------------------------------

ifeq ($(TARGET), STM32F429VIT6)
DEVICE_SRCS += \
DEVICES/stm32_f429xx_irq.c \
IO_Driver/Dio.c
endif

#-----------------------------------------------
#  Devive Vendor:   ST Microelectronics
#  Target       :   STM32F401CDU6
#  Core         :   ARM-CM4
#-----------------------------------------------
ifeq ($(TARGET), STM32F401CDU6)
DEVICE_SRCS += \
stm32_f401cdu6_system.c \

DEVICE_ASM_SRC += \
stm32_f401xx_startup.s
endif


#################  END Configurations #############################




all: sources_build asm_build
	@echo Module: Device
	@echo Sources: $(DEVICE_SRCS) $(DEVICE_ASM_SRC)
	@echo Obj Locaton: $(OBJECTS_LOCATION)
	@echo Device build completed! 
	@echo "#################################"


sources_build:
	@mkdir -p ../$(OBJECTS_LOCATION)

	@for s in  $(DEVICE_SRCS); \
	do \
	echo ; \
	echo Compiling ... $$s ; \
	echo ; \
	$(CC) -D$(TARGET) $(CC_OPTIMIZATION)  $(CC_EXTRA_FLAGS) $(CC_INPUT_STD) $(CC_WARNINGS) $(CC_TARGET_PROP) -o ../$(OBJECTS_LOCATION)$$s.o $(SOURCE_DIR)$$s; \
	echo "$(OBJECTS_LOCATION)$$s.o" >> ../object.list ; \
	done

asm_build:
	@mkdir -p ../$(OBJECTS_LOCATION)

	@for s in  $(DEVICE_ASM_SRC); \
	do \
	echo ; \
	echo Compiling ... $$s ; \
	echo ; \
	$(CC) -D$(TARGET) $(CC_OPTIMIZATION) $(CC_ASSEMBLER_FLAGS) $(CC_EXTRA_FLAGS) $(CC_INPUT_STD) $(CC_WARNINGS) $(CC_TARGET_PROP) -o ../$(OBJECTS_LOCATION)$$s.o $(SOURCE_DIR)$$s ; \
	echo "$(OBJECTS_LOCATION)$$s.o" >> ../object.list ; \
	done




clean:
	rm -rf $(OBJECTS_LOCATION)object.list 
	rm -rf $(OBJECTS_LOCATION)* 

.PHONY: device_build

