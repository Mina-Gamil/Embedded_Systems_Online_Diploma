################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD_Driver/LCD.c 

OBJS += \
./LCD_Driver/LCD.o 

C_DEPS += \
./LCD_Driver/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
LCD_Driver/LCD.o: ../LCD_Driver/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Mastering_embedded_systems/Projects/Unit7_Lecture3/Drivers/Seven_Segment/Inc" -I"D:/Mastering_embedded_systems/Projects/Unit7_Lecture3/Drivers/LCD_Driver/inc" -I"D:/Mastering_embedded_systems/Projects/Unit7_Lecture3/Drivers/Stm32_F103C6_Drivers/inc" -I"D:/Mastering_embedded_systems/Projects/Unit7_Lecture3/Drivers/Keypad_Driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD_Driver/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

