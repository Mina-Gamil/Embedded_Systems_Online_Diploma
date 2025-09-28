################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Keypad_Driver/Keypad.c 

OBJS += \
./Keypad_Driver/Keypad.o 

C_DEPS += \
./Keypad_Driver/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Keypad_Driver/Keypad.o: ../Keypad_Driver/Keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Mastering_embedded_systems/Projects/Unit7_Lecture3/Drivers/Seven_Segment/Inc" -I"D:/Mastering_embedded_systems/Projects/Unit7_Lecture3/Drivers/LCD_Driver/inc" -I"D:/Mastering_embedded_systems/Projects/Unit7_Lecture3/Drivers/Stm32_F103C6_Drivers/inc" -I"D:/Mastering_embedded_systems/Projects/Unit7_Lecture3/Drivers/Keypad_Driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Keypad_Driver/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

