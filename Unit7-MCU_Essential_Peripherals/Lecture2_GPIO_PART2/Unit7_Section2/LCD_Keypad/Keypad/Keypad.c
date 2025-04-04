/*
 * Keypad.c
 *
 * Created: 4/1/2025 7:51:24 PM
 *  Author: Mina
 */ 



#include "Keypad.h"

char Keypad_Keys[4][4] = {{'7', '8', '9', '/'},
						  {'4', '5', '6', '*'},
						  {'1', '2', '3', '-'},
						  {'C', '0', '=', '+'}};

void Keypad_Init(void)
{
	Keypad_Port_Dir = 0x0F;
	Keypad_Port |= (0xFF);
}


char Keypad_Getkey(void)
{
	int i,j;
	for (i = 0; i < 4; i++)
	{
		if (i > 0){ Keypad_Port |= (1 << (i - 1)); }
		Keypad_Port &= ~(1 << i);
		
		for (j = 0; j < 4; j++)
		{
			if (((Keypad_Port_Pin >> 4 >> j) & 1) == 0)
			{
				while(((Keypad_Port_Pin >> 4 >> j) & 1) == 0);
				return Keypad_Keys[i][j];
			}
		}
		if (i == 3){ Keypad_Port |= (1 << i); }
	}
	return 'A';
}