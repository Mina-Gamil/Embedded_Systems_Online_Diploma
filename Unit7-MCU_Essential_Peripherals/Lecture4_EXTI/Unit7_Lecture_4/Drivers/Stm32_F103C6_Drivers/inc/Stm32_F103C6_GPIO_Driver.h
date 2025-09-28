/*
 * Stm32_F103C6_GPIO_Driver.h
 *
 *  Created on: Apr 18, 2025
 *      Author: Mina
 */

#ifndef STM32_F103C6_GPIO_DRIVER_H_
#define STM32_F103C6_GPIO_DRIVER_H_

/*** Includes ****/
#include "stm32f103x6.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------

// Config Structure
typedef struct
{
	uint16_t GPIO_PinNumber;		// Specifies The GPIO Pin To Be configured
									// This Parameter Must Be A Value of @ref GPIO_PIN_Define

	uint8_t	GPIO_Mode;				// Specifies GPIO Pin Mode For Selected Pin
									// This Parameter Must Be A Value Of @ref GPIO_MODE_Define

	uint8_t GPIO_Output_Speed;		// Specifies GPIO Pin Speed For Selected Pin In Output Mode
									// This Parameter Must Be A Value Of @ref GPIO_SPEED_Define

}GPIO_PinConfig_t;


//@ref GPIO_PIN_Define
#define GPIO_PIN_0						((uint16_t)0x0001)
#define GPIO_PIN_1						((uint16_t)0x0002)
#define GPIO_PIN_2						((uint16_t)0x0004)
#define GPIO_PIN_3						((uint16_t)0x0008)
#define GPIO_PIN_4						((uint16_t)0x0010)
#define GPIO_PIN_5						((uint16_t)0x0020)
#define GPIO_PIN_6						((uint16_t)0x0040)
#define GPIO_PIN_7						((uint16_t)0x0080)
#define GPIO_PIN_8						((uint16_t)0x0100)
#define GPIO_PIN_9						((uint16_t)0x0200)
#define GPIO_PIN_10						((uint16_t)0x0400)
#define GPIO_PIN_11						((uint16_t)0x0800)
#define GPIO_PIN_12						((uint16_t)0x1000)
#define GPIO_PIN_13						((uint16_t)0x2000)
#define GPIO_PIN_14						((uint16_t)0x4000)
#define GPIO_PIN_15						((uint16_t)0x8000)

#define GPIO_PIN_All					((uint16_t)0xFFFF)
#define GPIO_PIN_Mask					((uint16_t)0x00FF)


//@ref GPIO_MODE_Define
#define GPIO_MODE_Analog				0x00000000u		// Analog mode
#define GPIO_MODE_INPUT_FLO				0x00000001u		// Floating Input
#define GPIO_MODE_INPUT_PU				0x00000002u		// Input Pull-Up
#define GPIO_MODE_INPUT_PD				0x00000003u		// Input Pull-Down
#define GPIO_MODE_OUTPUT_PP				0x00000004u		// Output Push-Pull
#define GPIO_MODE_OUTPUT_OD				0x00000005u		// Output Open-Drain
#define GPIO_MODE_AF_OUTPUT_PP			0x00000006u		// Alternative Function Output Push-Pull
#define GPIO_MODE_AF_OUTPUT_OD			0x00000007u		// Alternative Function Output Open-Drain
#define GPIO_MODE_AF_INPUT				0x00000008u		// Alternative Function Input


//@ref GPIO_SPEED_Define
#define GPIO_SPEED_10M					0x00000001u		// Output mode, max speed 10 MHz
#define GPIO_SPEED_2M					0x00000002u		// Output mode, max speed 2 MHz
#define GPIO_SPEED_50M					0x00000003u		// Output mode, max speed 50 MHz


//@ref GPIO_PIN_State
#define GPIO_PIN_Reset					0
#define GPIO_PIN_Set					1

//@ref GPIO_RETURN_LOCK
#define GPIO_LOCK_ERROR					0
#define GPIO_LOCK_Enable				1

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);

void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t Value);
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

#endif /* STM32_F103C6_GPIO_DRIVER_H_ */
