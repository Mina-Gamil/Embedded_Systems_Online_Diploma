/*
 * 7-Segment.c
 *
 *  Created on: Sep 9, 2025
 *      Author: Mina
 */

#include "Seven_Segment.h"

void HAL_Seven_Segment_Init(void)
{
	GPIO_PinConfig_t PinConfig;

	// Config Pin 9 ===> g
	PinConfig.GPIO_PinNumber = GPIO_PIN_9;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Seven_Segmant_Port, &PinConfig);

	// Config Pin 10 ===> f
	PinConfig.GPIO_PinNumber = GPIO_PIN_10;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Seven_Segmant_Port, &PinConfig);

	// Config Pin 11 ===> e
	PinConfig.GPIO_PinNumber = GPIO_PIN_11;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Seven_Segmant_Port, &PinConfig);

	// Config Pin 12 ===> d
	PinConfig.GPIO_PinNumber = GPIO_PIN_12;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Seven_Segmant_Port, &PinConfig);

	// Config Pin 13 ===> c
	PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Seven_Segmant_Port, &PinConfig);

	// Config Pin 14 ===> b
	PinConfig.GPIO_PinNumber = GPIO_PIN_14;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Seven_Segmant_Port, &PinConfig);

	// Config Pin 15 ===> a
	PinConfig.GPIO_PinNumber = GPIO_PIN_15;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Seven_Segmant_Port, &PinConfig);

	MCAL_GPIO_WritePort(Seven_Segmant_Port, 0x7f << 9);
}

void HAL_Seven_Segment_Send(uint8_t Number)
{
	MCAL_GPIO_WritePort(Seven_Segmant_Port, Number << 9);
}
