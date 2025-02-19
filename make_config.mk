# Copyright (C) 2024 Subhajit Roy
# This file is part of openAUTOSAR/BSW
#
# openAUTOSAR free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# RTOS Basic Software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.






#-----------------------------------------------
#  Artifacts configutation Based on build inputs
#-----------------------------------------------
RM							:= rm -rf
RMDIR						:= rmdir --ignore-fail-on-non-empty
MKDIR						:= mkdir -p
COPY 						:= cp

CC 							:= arm-none-eabi-gcc
CPP							:= arm-none-eabi-g++
CC_OBJDUMP					:= arm-none-eabi-objdump
CC_OBJCPY					:= arm-none-eabi-objcopy
CC_OPTIMIZATION				:= -O0 -g3 -c
CC_EXTRA_FLAGS				:= --specs=nano.specs
CC_INPUT_STD				:= -std=gnu99
CC_WARNINGS					:= -Wall
CC_TARGET_PROP				:= -mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard 
CC_LINKER_INPUT				:= -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
CC_ASSEMBLER_FLAGS			:= -x assembler-with-cpp
CC_INCLUDE_DIR				:= ../

#General Include
INC_SRC_DIR += \
-I../ \
-I../kernel/FreeRTOS-Kernel/Include/ \
-I../../FreeRTOS-KERNEL-conf/

#Target Specific include
ifeq ($(TARGET), STM32F401)
INC_SRC_DIR += \
-I../kernel/FreeRTOS-Kernel/portable/GCC/ARM_CM4F
endif


C++M_SRCS := 
CPP_SRCS := 
S_UPPER_SRCS := 
O_SRCS := 
ELF_SRCS := 
C_UPPER_SRCS := 
CXX_SRCS := 
CCM_SRCS := 
C++_SRCS := 
OBJ_SRCS := 
S_SRCS := 
CC_SRCS := 
C_SRCS := 
CXXM_SRCS := 
CYCLO_FILES := 
OBJDUMP_LIST := 
CCM_DEPS := 
C_UPPER_DEPS := 
S_DEPS := 
CXXM_DEPS := 
C_DEPS := 
CC_DEPS := 
OBJCOPY_HEX := 
SIZE_OUTPUT := 
C++_DEPS := 
SU_FILES := 
EXECUTABLES := 
OBJS := 
CXX_DEPS := 
MAP_FILES := 
S_UPPER_DEPS := 
C++M_DEPS := 
CPP_DEPS := 




