################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Unit7_Lecture1_Lab.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Unit7_Lecture1_Lab.list \

OBJCOPY_HEX += \
Unit7_Lecture1_Lab.hex \

OBJCOPY_BIN += \
Unit7_Lecture1_Lab.bin \


# All Target
all: Unit7_Lecture1_Lab.elf secondary-outputs

# Tool invocations
Unit7_Lecture1_Lab.elf: $(OBJS) $(USER_OBJS) D:\Mastering_embedded_systems\Projects\Unit7_Lecture1\Unit7_Lecture1_Lab\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "Unit7_Lecture1_Lab.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Mastering_embedded_systems\Projects\Unit7_Lecture1\Unit7_Lecture1_Lab\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Unit7_Lecture1_Lab.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Unit7_Lecture1_Lab.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Unit7_Lecture1_Lab.list"
	@echo 'Finished building: $@'
	@echo ' '

Unit7_Lecture1_Lab.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Unit7_Lecture1_Lab.hex"
	@echo 'Finished building: $@'
	@echo ' '

Unit7_Lecture1_Lab.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Unit7_Lecture1_Lab.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
