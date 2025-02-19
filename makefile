# File:        Makefile
# Author:      Subhajit Roy  
#              subhajitroy005@gmail.com 
#
# Moudle:      Build  
# Info:        Build executables of Kernel              
# Dependency:  Configuration generation
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



-include ../makefile.init
-include ./make_config.mk
-include ./build_config.mk



ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif




-include ../makefile.defs


OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \



SIZE_OUTPUT += \
default.size.stdout \



export TARGET_MCU := 





#-----------------------------------------------
#          All individual file makefile
#-----------------------------------------------

all: main-build

main-build: clean_enviornment $(BUILD_ARTIFACT) secondary-outputs

secondary-outputs: $(SIZE_OUTPUT) $(BUILD_ARTIFACT).list 


$(BUILD_ARTIFACT) $(BUILD_ARTIFACT).map: directory_check devices_build kernel_build init_build
# -mcpu=cortex-m4 -T"/home/subhajitroy005/STM32CubeIDE/workspace_1.15.0/STm32f401_src/STM32F401CDUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STm32f401_src.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	$(CPP) -o $(BUILD_LOCATION)$(BUILD_ARTIFACT) @"object.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"$(LINKER_SCRIPT)" -Wl,-Map="$(BUILD_LOCATION)$(BUILD_ARTIFACT).map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	$(CC_OBJDUMP) -S ./build/${BUILD_ARTIFACT} > ./build/${BUILD_ARTIFACT}.lss
	$(CC_OBJCPY) -O ihex ./build/${BUILD_ARTIFACT} ./build/${BUILD_ARTIFACT}.hex
	@echo '##############################################'
	@echo ''
	@echo '   Artifcact Generated [ $@ ] ${BUILD_ARTIFACT}.hex ${BUILD_ARTIFACT}.lss'
	@echo ''
	@echo '##############################################'
	@echo ' '


$(SIZE_OUTPUT): $(BUILD_ARTIFACT) makefile object.list $(OPTIONAL_TOOL_DEPS)
	@echo '##############################################'
	@arm-none-eabi-size  --format=sysv --radix=16 $(BUILD_LOCATION)$(BUILD_ARTIFACT)
	@echo '##############################################'
	@echo ' '


$(BUILD_ARTIFACT).list: $(BUILD_ARTIFACT) makefile object.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(BUILD_LOCATION)$(BUILD_ARTIFACT) > "$(BUILD_LOCATION)$(BUILD_ARTIFACT).list"
	@echo '##############################################'
	@echo ''
	@echo '   $(BUILD_ARTIFACT).list Generated...'
	@echo ''
	@echo '##############################################'
	@echo ' '




devices_build:
	make -C ./devices all TARGET=$(TARGET)

init_build:
	make -C ./init all TARGET=$(TARGET)

kernel_build:
	make -C ./kernel all TARGET=$(TARGET)




directory_check:
	$(MKDIR)    build

clean:
	$(RM) object.list
	$(RM) $(BUILD_LOCATION)objs/* 
	$(RM) $(BUILD_LOCATION)* 
	$(RMDIR) ./build
	@echo '##############################################'
	@echo ''
	@echo '          Cleaning completed!'
	@echo ''
	@echo '##############################################'

clean_enviornment:


.PHONY: all clean dependents main-build

-include ../makefile.targets