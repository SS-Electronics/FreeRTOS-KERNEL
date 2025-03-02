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


$(info ################################# <<<<)
$(info Module:   Kernel)

ifeq ( $(TARGET) , $(NULL_STR) )
$(error No Target Selected.....!)
else
$(info Target:  $(TARGET))
endif


#################  START Configurations #############################

DRV_SRCS += \
drv_cpu.c 


# Target wise configurations

#-----------------------------------------------
#  Core         :   ARM-CM4
#-----------------------------------------------
ifeq ($(TARGET), STM32F401)


endif


#################  END Configurations #############################




all: sources_build
	@echo Sources: $(DRV_SRCS)
	@echo Obj Locaton: $(OBJECTS_LOCATION)
	@echo Init build completed! 
	@echo "################################# <<<<"


sources_build:
	@mkdir -p ../$(OBJECTS_LOCATION)

	@for s in  $(DRV_SRCS); \
	do \
	echo ; \
	echo Compiling ... $$s ; \
	echo ; \
	$(CC) -D$(TARGET) $(FREERTOS_INC_SRC_DIR) $(CC_OPTIMIZATION)  $(CC_EXTRA_FLAGS) $(CC_INPUT_STD) $(CC_WARNINGS) $(CC_TARGET_PROP) -o ../$(OBJECTS_LOCATION)$$s.o $(SOURCE_DIR)$$s; \
	echo "$(OBJECTS_LOCATION)$$s.o" >> ../object.list ; \
	done




clean:
	rm -rf $(OBJECTS_LOCATION)object.list 
	rm -rf $(OBJECTS_LOCATION)* 

.PHONY: device_build

