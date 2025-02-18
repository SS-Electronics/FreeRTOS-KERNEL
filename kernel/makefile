# File:        Makefile
# Author:      Subhajit Roy  
#              subhajitroy005@gmail.com 
#
# Moudle:      Modeule Kernel [ Local Build ] 
# Info:        Compile sources based on spefic target 
#                             
# Dependency:  Configuration
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
$(info Module: kernel -- Source Build --)


NULL_STR 			:=
FILE_EXT 			:=
OBJECTS_LOCATION 	:= ./build/objs/
SOURCE_DIR		 	:= ./

ifeq ( $(TARGET) , $(NULL_STR) )
$(info Kernel: No Target Nselected.....!)
else
$(info Kernel: Building Sources........!)
endif



KERN_SRCS += \
kernel.c \
irq.c


# FreeRTOS related header include directories
FREERTOS_INC_SRC_DIR += \
-IFreeRTOS-Kernel/include/ \
-I../../FreeRTOS-KERNEL-conf/


FREERTOS_SRCS += \
FreeRTOS-Kernel/croutine.c \
FreeRTOS-Kernel/event_groups.c \
FreeRTOS-Kernel/list.c \
FreeRTOS-Kernel/queue.c \
FreeRTOS-Kernel/stream_buffer.c \
FreeRTOS-Kernel/task.c \
FreeRTOS-Kernel/timers.c \
FreeRTOS-Kernel/portable/MemMang/heap_4.c



#-----------------------------------------------
#  Core         :   ARM-CM4
#-----------------------------------------------
ifeq ($(TARGET), STM32F401CDU6)
FREERTOS_INC_SRC_DIR += \
-IFreeRTOS-Kernel/portable/GCC/ARM_CM4F


FREERTOS_SRCS += \
FreeRTOS-Kernel/portable/GCC/ARM_CM4F/port.c
endif


# Target wise configurations













#################  END Configurations #############################




all: sources_build free_rtos_kernel_build
	@echo Module: Kernel
	@echo Sources: $(KERN_SRCS)
	@echo Obj Locaton: $(OBJECTS_LOCATION)
	@echo Init build completed! 
	@echo "#################################"


sources_build:
	@mkdir -p ../$(OBJECTS_LOCATION)

	@for s in  $(KERN_SRCS); \
	do \
	echo ; \
	echo Compiling ... $$s ; \
	echo ; \
	$(CC) -D$(TARGET) $(CC_OPTIMIZATION)  $(CC_EXTRA_FLAGS) $(CC_INPUT_STD) $(CC_WARNINGS) $(CC_TARGET_PROP) -o ../$(OBJECTS_LOCATION)$$s.o $(SOURCE_DIR)$$s; \
	echo "$(OBJECTS_LOCATION)$$s.o" >> ../object.list ; \
	done






free_rtos_kernel_build: $(FREERTOS_SRCS)
	$(CC) -D$(TARGET) $(FREERTOS_INC_SRC_DIR) $(CC_OPTIMIZATION)  $(CC_EXTRA_FLAGS) $(CC_INPUT_STD) $(CC_WARNINGS) $(CC_TARGET_PROP) -o ../$(OBJECTS_LOCATION)$<.o $<; \









clean:
	rm -rf $(OBJECTS_LOCATION)object.list 
	rm -rf $(OBJECTS_LOCATION)* 

.PHONY: device_build

