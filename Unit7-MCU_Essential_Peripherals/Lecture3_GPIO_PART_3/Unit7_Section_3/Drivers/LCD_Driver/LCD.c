/*
 * LCD.c
 *
 * Created: 3/30/2025 1:48:01 PM
 *  Author: Mina
 */ 

/* Including Required Header */
#include "LCD.h"

#define Output		1
#define Input		0

volatile unsigned char Display_Feature = 0;
GPIO_PinConfig_t PinConfig;							// Declare variable to store Pin Data

static void delay_ms(uint32_t time)
{
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}

void HAL_LCD_Port_GPIO(uint8_t Direction)
{
	if (Direction)
	{
		// Config. & Init Pins from 0 to 7 to output push pull with speed 10Mhz.
#ifdef Eight_Bit_Mode
		//GPIO Pin 0
		PinConfig.GPIO_PinNumber = GPIO_PIN_0;
		PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
		PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
		//GPIO Pin 1
		PinConfig.GPIO_PinNumber = GPIO_PIN_1;
		PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
		PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
		//GPIO Pin 2
		PinConfig.GPIO_PinNumber = GPIO_PIN_2;
		PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
		PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
		//GPIO Pin 3
		PinConfig.GPIO_PinNumber = GPIO_PIN_3;
		PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
		PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
#endif

		//GPIO Pin 4
		PinConfig.GPIO_PinNumber = GPIO_PIN_4;
		PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
		PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
		//GPIO Pin 5
		PinConfig.GPIO_PinNumber = GPIO_PIN_5;
		PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
		PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
		//GPIO Pin 6
		PinConfig.GPIO_PinNumber = GPIO_PIN_6;
		PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
		PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
		//GPIO Pin 7
		PinConfig.GPIO_PinNumber = GPIO_PIN_7;
		PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
		PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);

	}
	else
	{
		// Config. & Init Pins from 0 to 7 to Floating Input.
#ifdef Eight_Bit_Mode
		//GPIO Pin 0
		PinConfig.GPIO_PinNumber = GPIO_PIN_0;
		PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
		//GPIO Pin 1
		PinConfig.GPIO_PinNumber = GPIO_PIN_1;
		PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
		//GPIO Pin 2
		PinConfig.GPIO_PinNumber = GPIO_PIN_2;
		PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
		//GPIO Pin 3
		PinConfig.GPIO_PinNumber = GPIO_PIN_3;
		PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
#endif
		//GPIO Pin 4
		PinConfig.GPIO_PinNumber = GPIO_PIN_4;
		PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
		//GPIO Pin 5
		PinConfig.GPIO_PinNumber = GPIO_PIN_5;
		PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
		//GPIO Pin 6
		PinConfig.GPIO_PinNumber = GPIO_PIN_6;
		PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
		//GPIO Pin 7
		PinConfig.GPIO_PinNumber = GPIO_PIN_7;
		PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(LCD_Port, &PinConfig);
	}
}

void HAL_LCD_Init(void)
{
	delay_ms(20);

	// Register Select Pin Config
	PinConfig.GPIO_PinNumber = RS_Switch;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Ctrl, &PinConfig);

	// Read/Write Pin Config
	PinConfig.GPIO_PinNumber = RW_Switch;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Ctrl, &PinConfig);

	// Enable Pin Config
	PinConfig.GPIO_PinNumber = EN_Switch;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Ctrl, &PinConfig);

	// Reset RS_Switch, RW_Switch & EN_Switch.
	MCAL_GPIO_WritePin(LCD_Ctrl, RS_Switch, GPIO_PIN_Reset);
	MCAL_GPIO_WritePin(LCD_Ctrl, RW_Switch, GPIO_PIN_Reset);
	MCAL_GPIO_WritePin(LCD_Ctrl, EN_Switch, GPIO_PIN_Reset);

	HAL_LCD_Port_GPIO(Output);														//Config. & Init. RS_Switch, RW_Switch & EN_Switch to Output push pull with speed 10Mhz.
	delay_ms(15);

#ifdef Eight_Bit_Mode
	HAL_LCD_Send_Command(LCD_FunctionSet | LCD_8bit_Mode | LCD_2Line);
#endif

#ifdef Four_Bit_Mode
	HAL_LCD_Send_Command(LCD_ReturnHome);
	HAL_LCD_Send_Command(LCD_FunctionSet | LCD_4bit_Mode | LCD_2Line);
#endif

	HAL_LCD_Clear_Display();
	HAL_LCD_Send_Command(LCD_EntryModeSet | LCD_Left_Dec);
	HAL_LCD_Display_On();
	HAL_LCD_Blink_On();
	HAL_LCD_Cursor_On();
}


void HAL_LCD_Kick(void)
{
	MCAL_GPIO_WritePin(LCD_Ctrl, EN_Switch, GPIO_PIN_Set);
	delay_ms(50);
	MCAL_GPIO_WritePin(LCD_Ctrl, EN_Switch, GPIO_PIN_Reset);
}


void HAL_LCD_Is_Busy(void)
{
	HAL_LCD_Port_GPIO(Input);													// Config. & Init Pins from 0 to 7 to Floating Input.
	MCAL_GPIO_WritePin(LCD_Ctrl, RW_Switch, GPIO_PIN_Set);						// Set RW_Switch
	MCAL_GPIO_WritePin(LCD_Ctrl, RS_Switch, GPIO_PIN_Reset);					// Reset RS_Switch
	while(MCAL_GPIO_ReadPin(LCD_Port, GPIO_PIN_7))								// Check Busy Flag
		HAL_LCD_Kick();															// LCD toggle enable
	HAL_LCD_Port_GPIO(Output);													// Config. & Init. RS_Switch, RW_Switch & EN_Switch to Output push pull with speed 10Mhz.
	MCAL_GPIO_WritePin(LCD_Ctrl, RW_Switch, GPIO_PIN_Reset);					// Read/Write Pin Reset
}

void HAL_LCD_GoTo_XY(int Line, int Position)
{
	if (Line == 1 && Position >= 0 && Position < 16)
	{
		HAL_LCD_Send_Command((LCD_DDRAM_Address | LCD_1st_Line) + Position);
	}
	if (Line == 2 && Position >= 0 && Position < 16)
	{
		HAL_LCD_Send_Command((LCD_DDRAM_Address | LCD_2nd_Line) + Position);
	}
}

void HAL_LCD_Clear_Display(void)
{
	HAL_LCD_Send_Command(LCD_ClearDisplay);
}

void HAL_LCD_Send_Command(unsigned char Command)
{	
#ifdef Eight_Bit_Mode

	HAL_LCD_Is_Busy();
	MCAL_GPIO_WritePort(LCD_Port, Command);
	MCAL_GPIO_WritePin(LCD_Ctrl, RW_Switch, GPIO_PIN_Reset);
	MCAL_GPIO_WritePin(LCD_Ctrl, RS_Switch, GPIO_PIN_Reset);
	delay_ms(1);
	HAL_LCD_Kick();

#endif

#ifdef Four_Bit_Mode

	delay_ms(15);
	HAL_LCD_Is_Busy();
	MCAL_GPIO_WritePort(LCD_Port, (uint8_t)(Command & 0xF0));
	MCAL_GPIO_WritePin(LCD_Ctrl, RW_Switch, GPIO_PIN_Reset);
	MCAL_GPIO_WritePin(LCD_Ctrl, RS_Switch, GPIO_PIN_Reset);
	HAL_LCD_Kick();

	MCAL_GPIO_WritePort(LCD_Port, (uint8_t)(Command << 4));
	MCAL_GPIO_WritePin(LCD_Ctrl, RW_Switch, GPIO_PIN_Reset);
	MCAL_GPIO_WritePin(LCD_Ctrl, RS_Switch, GPIO_PIN_Reset);
	HAL_LCD_Kick();

#endif
}

void HAL_LCD_Write_Character(unsigned char Character)
{

#ifdef Eight_Bit_Mode

	HAL_LCD_Is_Busy();
	MCAL_GPIO_WritePort(LCD_Port, Character);
	MCAL_GPIO_WritePin(LCD_Ctrl, RS_Switch, GPIO_PIN_Set);
	MCAL_GPIO_WritePin(LCD_Ctrl, RW_Switch, GPIO_PIN_Reset);

	delay_ms(1);
	HAL_LCD_Kick();

#endif

#ifdef Four_Bit_Mode

	HAL_LCD_Is_Busy();
	MCAL_GPIO_WritePort(LCD_Port, (uint8_t)(Character & 0xF0));
	MCAL_GPIO_WritePin(LCD_Ctrl, RS_Switch, GPIO_PIN_Set);
	MCAL_GPIO_WritePin(LCD_Ctrl, RW_Switch, GPIO_PIN_Reset);
	HAL_LCD_Kick();

	MCAL_GPIO_WritePort(LCD_Port, (uint8_t)(Character << 4));
	MCAL_GPIO_WritePin(LCD_Ctrl, RS_Switch, GPIO_PIN_Set);
	MCAL_GPIO_WritePin(LCD_Ctrl, RW_Switch, GPIO_PIN_Reset);
	HAL_LCD_Kick();

#endif
}

void HAL_LCD_Write_String(char *String)
{
	int Count = 0;
	while(*String != 0)
	{
		Count++;
		HAL_LCD_Write_Character(*String++);

		if (Count == 16)
		{
			HAL_LCD_GoTo_XY(2, 0);
		}
		else if (Count == 32)
		{
			HAL_LCD_Clear_Display();
			HAL_LCD_GoTo_XY(1, 0);
			Count = 0;
		}
	}
}

void HAL_LCD_Blink_On(void)
{
	HAL_LCD_Send_Command(LCD_DisplayControl | LCD_Blink | Display_Feature);
	Display_Feature |= LCD_Blink;
}

void HAL_LCD_Blink_Off(void)
{
	Display_Feature &= ~(LCD_Blink);
	HAL_LCD_Send_Command(LCD_DisplayControl | Display_Feature);

}

void HAL_LCD_Cursor_On(void)
{
	HAL_LCD_Send_Command(LCD_DisplayControl | LCD_Cursor | Display_Feature);
	Display_Feature |= LCD_Cursor;
}

void HAL_LCD_Cursor_Off(void)
{
	Display_Feature &= ~(LCD_Cursor);
	HAL_LCD_Send_Command(LCD_DisplayControl | Display_Feature);
}

void HAL_LCD_Display_On(void)
{
	HAL_LCD_Send_Command(LCD_DisplayControl | LCD_Display | Display_Feature);
	Display_Feature |= LCD_Display;
}

void HAL_LCD_Display_Off(void)
{
	Display_Feature &= ~(LCD_Display);
	HAL_LCD_Send_Command(LCD_DisplayControl | Display_Feature);
}
