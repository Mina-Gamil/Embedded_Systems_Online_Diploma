/*
 * Keypad.h
 *
 * Created: 4/1/2025 7:51:43 PM
 *  Author: Mina
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../LCD/MemoryMap.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#define Keypad_Port          PORTD
#define Keypad_Port_Dir      DDRD
#define Keypad_Port_Pin      PIND

void Keypad_Init(void);
char Keypad_Getkey(void);

#endif /* KEYPAD_H_ */