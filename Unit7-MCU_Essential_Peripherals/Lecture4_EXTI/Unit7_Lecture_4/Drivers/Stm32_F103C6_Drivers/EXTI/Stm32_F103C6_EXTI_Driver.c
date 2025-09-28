/*
 * Stm32_F103C6_EXTI_Driver.c
 *
 *  Created on: Sep 13, 2025
 *      Author: Mina Gamil
 */

/** Includes **/
#include "Stm32_F103C6_EXTI_Driver.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
									Generic Variables
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void (* GP_IRQ_Callback[15])(void);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
									Generic Macros
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
#define AFIO_EXTI_GPIO_Mapping(x)		(x == GPIOA)? 0:\
										(x == GPIOB)? 1:\
										(x == GPIOC)? 2:\
										(x == GPIOD)? 3:0

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
									Generic Functions
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void Enable_NVIC(uint16_t IRQ)
{
	switch (IRQ) {
		case 6:
			NVIC_IRQ6_EXTI0_Enable;
			break;

		case 7:
			NVIC_IRQ7_EXTI1_Enable;
			break;

		case 8:
			NVIC_IRQ8_EXTI2_Enable;
			break;

		case 9:
			NVIC_IRQ9_EXTI3_Enable;
			break;

		case 10:
			NVIC_IRQ10_EXTI4_Enable;
			break;

		case 23:
			NVIC_IRQ23_EXTI9_5_Enable;
			break;

		case 40:
			NVIC_IRQ40_EXTI15_10_Enable;
			break;
	}
}

void Disable_NVIC(uint16_t IRQ)
{
	switch (IRQ) {
		case 6:
			NVIC_IRQ6_EXTI0_Disable;
			break;

		case 7:
			NVIC_IRQ7_EXTI1_Disable;
			break;

		case 8:
			NVIC_IRQ8_EXTI2_Disable;
			break;

		case 9:
			NVIC_IRQ9_EXTI3_Disable;
			break;

		case 10:
			NVIC_IRQ10_EXTI4_Disable;
			break;

		case 23:
			NVIC_IRQ23_EXTI9_5_Disable;
			break;

		case 40:
			NVIC_IRQ40_EXTI15_10_Disable;
			break;
	}
}

void Update_EXTI(EXTI_PinConfig_t* EXTI_Config)
{
	// 1: Configure Selected EXTI GPIO To be Input Floating and initialize it.
	GPIO_PinConfig_t GPIO_Config;
	GPIO_Config.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_Pin;
	GPIO_Config.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &GPIO_Config);

	// 2: Configure The AFIO to connect Selected GPIOx PIN to the equivalent EXTIx.
	uint8_t AFIO_EXTICR_index 	= EXTI_Config->EXTI_PIN.EXTI_InputPinNumber / 4;						// Calculate Index In Where we will select the EXTIx "EXTICR[x]"
	uint8_t AFIO_EXTICR_EXTIx_Position = (EXTI_Config->EXTI_PIN.EXTI_InputPinNumber % 4) * 4;			// Calculate the first position on Selected EXTIx

	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_EXTIx_Position);																// Reset Selected EXTIx
	AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_EXTI_GPIO_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port) & 0xF) << AFIO_EXTICR_EXTIx_Position);		// Set Selected EXTIx

	// 3: Set Trigger Selection Register
	EXTI->RTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputPinNumber);									// Reset Rising Trigger Selection Register for Selected GPIO
	EXTI->FTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputPinNumber);									// Reset Falling Trigger Selection Register for Selected GPIO

	if (EXTI_Config->Trigger_Case == EXTI_Trigger_Rising)												// If Configured Rising Trigger
	{
		EXTI->RTSR |= 1 << EXTI_Config->EXTI_PIN.EXTI_InputPinNumber;									// Set Rising Trigger Selection Register For Selected GPIO
	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_Falling)											// If Configured Falling Trigger
	{
		EXTI->FTSR |= 1 << EXTI_Config->EXTI_PIN.EXTI_InputPinNumber;									// Set Falling Trigger Selection Register For Selected GPIO
	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_Rising_Falling)									// If Configured Both Triggers
	{
		EXTI->RTSR |= 1 << EXTI_Config->EXTI_PIN.EXTI_InputPinNumber;									// Set Rising Trigger Selection Register For Selected GPIO
		EXTI->FTSR |= 1 << EXTI_Config->EXTI_PIN.EXTI_InputPinNumber;									// Set Falling Trigger Selection Register For Selected GPIO
	}

	// 4: Set IRQ Handler Callback Function
	GP_IRQ_Callback[EXTI_Config->EXTI_PIN.EXTI_InputPinNumber] = EXTI_Config->P_IRQ_Callback;			// Set Callback Function to its location in the Global IRQ Array

	// 5: Enable IMR and NVIC IRQ
	if (EXTI_Config->IRQ_EN == EXTI_IRQ_Enable) 														// Check if Enable is On
	{
		EXTI->IMR |= 1 << EXTI_Config->EXTI_PIN.EXTI_InputPinNumber;									// Enable IMR At Selected EXTIx
		Enable_NVIC(EXTI_Config->EXTI_PIN.IVT_IRQ_Number);												// Enable NVIC IRQ At Selected EXTIx_IRQ
	}
	else if (EXTI_Config->IRQ_EN == EXTI_IRQ_Disable)
	{
		EXTI->IMR &= ~ (1 << EXTI_Config->EXTI_PIN.EXTI_InputPinNumber);								// Disable IMR At Selected EXTIx
		Disable_NVIC(EXTI_Config->EXTI_PIN.IVT_IRQ_Number);												// Disable NVIC IRQ At Selected EXTIx_IRQ
	}
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
									API's Functions
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/



/*
 *****************************************************************************************
 * @Fn			- MCAL_EXTI_GPIO_Init
 * @brief 		- This Function Used To Initialize EXTI, Specifies GPIO Pin, AFIO_EXTICR,
 *	 	 	 	  Trigger Selection, Enable IMR and Enable NVIC IRQ.
 * @param[in]	- EXTI_Config, input set based on @ref EXTI_Define, @ref EXTI_IRQ_Define
 *	 	 	 	  @ref EXTI_Trigger_Define.
 * @retval		- none
 * Note			- stm32_F103C6 MCU Has GPIO A, B, C, D, E Modules
 * 				  But LQFP48 Package has A, B and Part of C,D.
 * 				- We Must Enable RCC Clock for AFIO and corresponding GPIOx
 *****************************************************************************************
 */
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}

/*
 *****************************************************************************************
 * @Fn			- MCAL_EXTI_GPIO_Update
 * @brief 		- This Function Used To Update EXTI, Specifies GPIO Pin, AFIO_EXTICR,
 *	 	 	 	  Trigger Selection, Enable IMR and Enable NVIC IRQ.
 * @param[in]	- EXTI_Config, input set based on @ref EXTI_Define, @ref EXTI_IRQ_Define
 *	 	 	 	  @ref EXTI_Trigger_Define.
 * @retval		- none
 * Note			- stm32_F103C6 MCU Has GPIO A, B, C, D, E Modules
 * 				  But LQFP48 Package has A, B and Part of C,D.
 *****************************************************************************************
 */
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}

/*
 *****************************************************************************************
 * @Fn			- MCAL_EXTI_GPIO_DeInit
 * @brief 		- Reset EXTI Registers and NVIC Corresponding IRQ Mask
 * @retval		- none
 * Note			- None
 *****************************************************************************************
 */
void MCAL_EXTI_GPIO_DeInit(void)
{
	EXTI->IMR   |= 0x00000000;					// Reset Interrupt Mask Register
	EXTI->EMR   |= 0x00000000;					// Reset Event Mask Register
	EXTI->RTSR  |= 0x00000000;					// Reset Rising Trigger Selection Register
	EXTI->RTSR  |= 0x00000000;					// Reset Falling Trigger Selection Register
	EXTI->SWIER |= 0x00000000;					// Reset Software Interrupt Event Register
	EXTI->PR    |= 0xFFFFFFFF;					// Reset Pending Request Register by writing 1 as per TRM

	NVIC_IRQ6_EXTI0_Disable;					// Disable NVIC IRQ No.6 which connected to EXTI No.0
	NVIC_IRQ7_EXTI1_Disable;					// Disable NVIC IRQ No.7 which connected to EXTI No.1
	NVIC_IRQ8_EXTI2_Disable;					// Disable NVIC IRQ No.8 which connected to EXTI No.2
	NVIC_IRQ9_EXTI3_Disable;					// Disable NVIC IRQ No.9 which connected to EXTI No.3
	NVIC_IRQ10_EXTI4_Disable;					// Disable NVIC IRQ No.10 which connected to EXTI No.4
	NVIC_IRQ23_EXTI9_5_Disable;					// Disable NVIC IRQ No.23 which connected to EXTI From No.5 to No.9
	NVIC_IRQ40_EXTI15_10_Disable;				// Disable NVIC IRQ No.40 which connected to EXTI From No.10 to No.15
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
									IRQ CallBack Functions
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void EXTI0_IRQHandler(void)
{
	EXTI->PR |= (1 << 0);				// Clear Pending Register By Writing 1 on Selected Pin
	GP_IRQ_Callback[0]();			// Call IRQ Callback Function
}

void EXTI1_IRQHandler(void)
{
	EXTI->PR |= (1 << 1);				// Clear Pending Register By Writing 1 on Selected Pin
	GP_IRQ_Callback[1]();			// Call IRQ Callback Function
}

void EXTI2_IRQHandler(void)
{
	EXTI->PR |= (1 << 2);				// Clear Pending Register By Writing 1 on Selected Pin
	GP_IRQ_Callback[2]();			// Call IRQ Callback Function
}

void EXTI3_IRQHandler(void)
{
	EXTI->PR |= (1 << 3);				// Clear Pending Register By Writing 1 on Selected Pin
	GP_IRQ_Callback[3]();			// Call IRQ Callback Function
}

void EXTI4_IRQHandler(void)
{
	EXTI->PR |= (1 << 4);				// Clear Pending Register By Writing 1 on Selected Pin
	GP_IRQ_Callback[4]();			// Call IRQ Callback Function
}

void EXTI9_5_IRQHandler(void)
{
	if (EXTI->PR & 1 << 5) { EXTI->PR |= (1 << 5);	GP_IRQ_Callback[5]();}
	if (EXTI->PR & 1 << 6) { EXTI->PR |= (1 << 6);	GP_IRQ_Callback[6]();}
	if (EXTI->PR & 1 << 7) { EXTI->PR |= (1 << 7);	GP_IRQ_Callback[7]();}
	if (EXTI->PR & 1 << 8) { EXTI->PR |= (1 << 8);	GP_IRQ_Callback[8]();}
	if (EXTI->PR & 1 << 9) { EXTI->PR |= (1 << 9);	GP_IRQ_Callback[9]();}
}

void EXTI15_10_IRQHandler(void)
{
	if (EXTI->PR & 1 << 10) { EXTI->PR |= (1 << 10);	GP_IRQ_Callback[10]();}
	if (EXTI->PR & 1 << 11) { EXTI->PR |= (1 << 11);	GP_IRQ_Callback[11]();}
	if (EXTI->PR & 1 << 12) { EXTI->PR |= (1 << 12);	GP_IRQ_Callback[12]();}
	if (EXTI->PR & 1 << 13) { EXTI->PR |= (1 << 13);	GP_IRQ_Callback[13]();}
	if (EXTI->PR & 1 << 14) { EXTI->PR |= (1 << 14);	GP_IRQ_Callback[14]();}
	if (EXTI->PR & 1 << 15) { EXTI->PR |= (1 << 15);	GP_IRQ_Callback[15]();}
}
