/*
 * Keypad.h
 *
 * Created: 4/1/2025 7:51:43 PM
 *  Author: Mina
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO_Driver.h"

#define Keypad_Port         GPIOB

#define R0		GPIO_PIN_0
#define R1		GPIO_PIN_1
#define R2		GPIO_PIN_3
#define R3		GPIO_PIN_4
#define C0		GPIO_PIN_5
#define C1		GPIO_PIN_6
#define C2		GPIO_PIN_7
#define C3		GPIO_PIN_8


void HAL_Keypad_Init(void);
char HAL_Keypad_Getkey(void);

#endif /* KEYPAD_H_ */
