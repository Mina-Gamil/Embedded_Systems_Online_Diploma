/*
 * LCD.c
 *
 * Created: 3/30/2025 1:48:01 PM
 *  Author: Mina
 */ 


#include "LCD.h"

volatile unsigned char Display_Feature = 0;

void LCD_Init(void)
{
	_delay_ms(20);
	LCD_Ctrl_Dir |= (1 << RS_Switch | 1 << RW_Switch | 1 << EN_Switch);
	LCD_Ctrl &= ~(1 << RS_Switch | 1 << RW_Switch | 1 << EN_Switch);
	LCD_Port_Dir = 0xFF;
	_delay_ms(20);
	
	#ifdef Eight_Bit_Mode
		LCD_Send_Command(LCD_FunctionSet | LCD_8bit_Mode | LCD_2Line);
	#endif
	
	#ifdef Four_Bit_Mode
		LCD_Send_Command(LCD_ReturnHome);
		LCD_Send_Command(LCD_FunctionSet | LCD_4bit_Mode | LCD_2Line);
	#endif
	
	LCD_Clear_Display();
	LCD_Send_Command(LCD_EntryModeSet | LCD_Left_Dec);
	LCD_Display_On();
	LCD_Blink_On();
	LCD_Cursor_On();
}


void LCD_Kick(void)
{
	LCD_Ctrl |= (1 << EN_Switch);
	_delay_ms(50);
	LCD_Ctrl &= ~(1 << EN_Switch);
}


void LCD_Is_Busy(void)
{
	LCD_Port_Dir &= ~(0xFF << Data_Shift);
	LCD_Ctrl |= 1 << RW_Switch;
	LCD_Ctrl &= ~(1 << RS_Switch);
	LCD_Kick();
	LCD_Port_Dir |= (0xFF << Data_Shift);
	LCD_Ctrl &= ~(1 << RW_Switch);
}

void LCD_GoTo_XY(int Line, int Position)
{
	if (Line == 1 && Position >= 0 && Position < 16)
	{
		LCD_Send_Command((LCD_DDRAM_Address | LCD_1st_Line) + Position);
	}
	if (Line == 2 && Position >= 0 && Position < 16)
	{
		LCD_Send_Command((LCD_DDRAM_Address | LCD_2nd_Line) + Position);
	}
}

void LCD_Clear_Display(void)
{
	LCD_Send_Command(LCD_ClearDisplay);
}

void LCD_Send_Command(unsigned char Command)
{	
	#ifdef Eight_Bit_Mode
		LCD_Is_Busy();
		LCD_Ctrl &= ~((1 << RS_Switch) | (1 << RW_Switch));
		LCD_Port = Command;
		LCD_Kick();
	#endif
	
	#ifdef Four_Bit_Mode
		LCD_Ctrl &= ~((1 << RS_Switch) | (1 << RW_Switch));
		LCD_Port = (LCD_Port & 0x0F) | (Command & 0xF0);
		LCD_Kick();
		_delay_ms(20);
		LCD_Port = (LCD_Port & 0x0F) | (Command << 4);
		LCD_Kick();
	#endif
}

void LCD_Send_Character(unsigned char Character)
{
	
	#ifdef Eight_Bit_Mode
		LCD_Is_Busy();
		LCD_Ctrl |= 1 << RS_Switch;
		LCD_Ctrl &= ~(1 << RW_Switch);
		LCD_Port = Character;
		LCD_Kick();
	#endif
	
	#ifdef Four_Bit_Mode
		LCD_Port = (LCD_Port & 0x0F) | (Character & 0xF0);
		LCD_Ctrl |= 1 << RS_Switch;
		LCD_Ctrl &= ~(1 << RW_Switch);
		LCD_Kick();
		LCD_Port = (LCD_Port & 0x0F) | (Character << 4);
		LCD_Ctrl |= 1 << RS_Switch;
		LCD_Ctrl &= ~(1 << RW_Switch);
		LCD_Kick();
	#endif
}

void LCD_Send_String(char *String)
{
	int Count = 0;
	while(*String != 0)
	{
		Count++;
		LCD_Send_Character(*String++);
		
		if (Count == 16)
		{
			LCD_GoTo_XY(2, 0);
		}
		else if (Count == 32)
		{
			LCD_Clear_Display();
			LCD_GoTo_XY(1, 0);
			Count = 0;
		}
	}
}

void LCD_Blink_On(void)
{
	LCD_Send_Command(LCD_DisplayControl | LCD_Blink | Display_Feature);
	Display_Feature |= LCD_Blink;
}

void LCD_Blink_Off(void)
{
	Display_Feature &= ~(LCD_Blink);
	LCD_Send_Command(LCD_DisplayControl | Display_Feature);
	
}

void LCD_Cursor_On(void)
{
	LCD_Send_Command(LCD_DisplayControl | LCD_Cursor | Display_Feature);
	Display_Feature |= LCD_Cursor;
}

void LCD_Cursor_Off(void)
{
	Display_Feature &= ~(LCD_Cursor);
	LCD_Send_Command(LCD_DisplayControl | Display_Feature);
}

void LCD_Display_On(void)
{
	LCD_Send_Command(LCD_DisplayControl | LCD_Display | Display_Feature);
	Display_Feature |= LCD_Display;
}

void LCD_Display_Off(void)
{
	Display_Feature &= ~(LCD_Display);
	LCD_Send_Command(LCD_DisplayControl | Display_Feature);
}