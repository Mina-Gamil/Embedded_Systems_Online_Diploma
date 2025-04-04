/*
 * LCD_Keypad.c
 *
 * Created: 3/30/2025 1:45:34 PM
 * Author : Mina
 */ 

#include "LCD/LCD.h"
#include "Keypad/Keypad.h"


int main(void)
{
	char Pressed_Key;
    LCD_Init();
	Keypad_Init();
	
    while (1) 
    {
		Pressed_Key = Keypad_Getkey();
		
		switch(Pressed_Key)
		{
			case 'A':
				break;
				
			case 'C':
				LCD_Clear_Display();
				break;
				
			default:
				LCD_Send_Character(Pressed_Key);
				break;
		}
    }
}

