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
Toggle_LED_WithStatibLib.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Toggle_LED_WithStatibLib.list \

OBJCOPY_HEX += \
Toggle_LED_WithStatibLib.hex \

OBJCOPY_BIN += \
Toggle_LED_WithStatibLib.bin \


# All Target
all: Toggle_LED_WithStatibLib.elf secondary-outputs

dependents:
	-cd D:/Mastering_embedded_systems/Projects/Embedded_C_1/Toggle_LED_WithStatibLib/Release && $(MAKE) all

# Tool invocations
Toggle_LED_WithStatibLib.elf: $(OBJS) $(USER_OBJS) D:/Mastering_embedded_systems/Projects/Embedded_C_1/Toggle_LED_WithStatibLib/Release/Toggle_LED_WithStatibLib.elf D:\Mastering_embedded_systems\Projects\Embedded_C_1\Toggle_LED_WithStatibLib\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "Toggle_LED_WithStatibLib.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Mastering_embedded_systems\Projects\Embedded_C_1\Toggle_LED_WithStatibLib\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Toggle_LED_WithStatibLib.map" -Wl,--gc-sections -static -L"D:\Mastering_embedded_systems\Projects\Embedded_C_1\Toggle_LED_WithStatibLib\Inc" --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Toggle_LED_WithStatibLib.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Toggle_LED_WithStatibLib.list"
	@echo 'Finished building: $@'
	@echo ' '

Toggle_LED_WithStatibLib.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Toggle_LED_WithStatibLib.hex"
	@echo 'Finished building: $@'
	@echo ' '

Toggle_LED_WithStatibLib.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Toggle_LED_WithStatibLib.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:
D:/Mastering_embedded_systems/Projects/Embedded_C_1/Toggle_LED_WithStatibLib/Release/Toggle_LED_WithStatibLib.elf:

-include ../makefile.targets
