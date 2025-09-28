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

uint16_t Keypad_Rows[] = {R0, R1, R2, R3};
uint16_t Keypad_Colomn[] = {C0, C1, C2, C3};

static void delay_ms(uint32_t time)
{
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}

void HAL_Keypad_Init(void)
{
	GPIO_PinConfig_t PinConfig;

	PinConfig.GPIO_PinNumber = R0;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Keypad_Port, &PinConfig);

	PinConfig.GPIO_PinNumber = R1;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Keypad_Port, &PinConfig);

	PinConfig.GPIO_PinNumber = R2;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Keypad_Port, &PinConfig);

	PinConfig.GPIO_PinNumber = R3;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Keypad_Port, &PinConfig);

	PinConfig.GPIO_PinNumber = C0;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(Keypad_Port, &PinConfig);

	PinConfig.GPIO_PinNumber = C1;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(Keypad_Port, &PinConfig);

	PinConfig.GPIO_PinNumber = C2;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(Keypad_Port, &PinConfig);

	PinConfig.GPIO_PinNumber = C3;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(Keypad_Port, &PinConfig);

}


char HAL_Keypad_Getkey(void)
{
	int i,j;
	for (i = 0; i < 4; i++)
	{
		MCAL_GPIO_WritePin(Keypad_Port, Keypad_Rows[0], GPIO_PIN_Set);
		MCAL_GPIO_WritePin(Keypad_Port, Keypad_Rows[1], GPIO_PIN_Set);
		MCAL_GPIO_WritePin(Keypad_Port, Keypad_Rows[2], GPIO_PIN_Set);
		MCAL_GPIO_WritePin(Keypad_Port, Keypad_Rows[3], GPIO_PIN_Set);

		MCAL_GPIO_WritePin(Keypad_Port, Keypad_Rows[i], GPIO_PIN_Reset);

		for (j = 0; j < 4; j++)
		{
			if (MCAL_GPIO_ReadPin(Keypad_Port, Keypad_Colomn[j]) == 0)
			{
				while(MCAL_GPIO_ReadPin(Keypad_Port, Keypad_Colomn[j]) == 0);
				return Keypad_Keys[i][j];
			}
			delay_ms(1);
		}
		delay_ms(1);
	}
	return 'A';
}
