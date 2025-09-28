/*
 * Stm32_F103C6_EXTI_Driver.h
 *
 *  Created on: Sep 13, 2025
 *      Author: Mina
 */

#ifndef STM32_F103C6_EXTI_DRIVER_H_
#define STM32_F103C6_EXTI_DRIVER_H_

/*** Includes ****/
#include "Stm32_F103C6_GPIO_Driver.h"
#include "stm32f103x6.h"


//----------------------------------
//User type definitions (structures)
//----------------------------------
typedef struct
{
	uint16_t 			GPIO_Pin;
	GPIO_TypeDef*	 	GPIO_Port;
	uint16_t			EXTI_InputPinNumber;
	uint16_t			IVT_IRQ_Number;

}EXTI_GPIO_Mapping_t;

typedef struct
{
	EXTI_GPIO_Mapping_t		EXTI_PIN;		// this Specifies External interrupt GPIO Map
											// this parameter must be set based on @ref EXTI_Define
	uint8_t 				Trigger_Case;	// This Parameter Specifies Trigger edge if is Falling,Rising or both
											// This parameter must be set based on @ref EXTI_Trigger_Define
	uint8_t					IRQ_EN;			// This Parameter used to Enable/Disable Interrupt Request
											// This parameter must be set based on @ ref EXTI_IRQ_Define
	void (* P_IRQ_Callback)(void);			// Pointer to function, Set the function that will run once the interrupt happens.

}EXTI_PinConfig_t;

/**********************/
// Macros Config. Ref.
/**********************/
#define EXTI0       0
#define EXTI1       1
#define EXTI2       2
#define EXTI3       3
#define EXTI4       4
#define EXTI5       5
#define EXTI6       6
#define EXTI7       7
#define EXTI8       8
#define EXTI9       9
#define EXTI10      10
#define EXTI11      11
#define EXTI12      12
#define EXTI13      13
#define EXTI14      14
#define EXTI15      15


// @ref EXTI_Define
//EXTI0
#define EXTI0PA0      (EXTI_GPIO_Mapping_t){GPIO_PIN_0, GPIOA, EXTI0, EXTI0_IRQ}
#define EXTI0PB0      (EXTI_GPIO_Mapping_t){GPIO_PIN_0, GPIOB, EXTI0, EXTI0_IRQ}
#define EXTI0PC0      (EXTI_GPIO_Mapping_t){GPIO_PIN_0, GPIOC, EXTI0, EXTI0_IRQ}
#define EXTI0PD0      (EXTI_GPIO_Mapping_t){GPIO_PIN_0, GPIOD, EXTI0, EXTI0_IRQ}

//EXTI1
#define EXTI1PA1      (EXTI_GPIO_Mapping_t){GPIO_PIN_1, GPIOA, EXTI1, EXTI1_IRQ}
#define EXTI1PB1      (EXTI_GPIO_Mapping_t){GPIO_PIN_1, GPIOB, EXTI1, EXTI1_IRQ}
#define EXTI1PC1      (EXTI_GPIO_Mapping_t){GPIO_PIN_1, GPIOC, EXTI1, EXTI1_IRQ}
#define EXTI1PD1      (EXTI_GPIO_Mapping_t){GPIO_PIN_1, GPIOD, EXTI1, EXTI1_IRQ}

//EXTI2
#define EXTI2PA2      (EXTI_GPIO_Mapping_t){GPIO_PIN_2, GPIOA, EXTI2, EXTI2_IRQ}
#define EXTI2PB2      (EXTI_GPIO_Mapping_t){GPIO_PIN_2, GPIOB, EXTI2, EXTI2_IRQ}
#define EXTI2PC2      (EXTI_GPIO_Mapping_t){GPIO_PIN_2, GPIOC, EXTI2, EXTI2_IRQ}
#define EXTI2PD2      (EXTI_GPIO_Mapping_t){GPIO_PIN_2, GPIOD, EXTI2, EXTI2_IRQ}

//EXTI3
#define EXTI3PA3      (EXTI_GPIO_Mapping_t){GPIO_PIN_3, GPIOA, EXTI3, EXTI3_IRQ}
#define EXTI3PB3      (EXTI_GPIO_Mapping_t){GPIO_PIN_3, GPIOB, EXTI3, EXTI3_IRQ}
#define EXTI3PC3      (EXTI_GPIO_Mapping_t){GPIO_PIN_3, GPIOC, EXTI3, EXTI3_IRQ}
#define EXTI3PD3      (EXTI_GPIO_Mapping_t){GPIO_PIN_3, GPIOD, EXTI3, EXTI3_IRQ}

//EXTI4
#define EXTI4PA4      (EXTI_GPIO_Mapping_t){GPIO_PIN_4, GPIOA, EXTI4, EXTI4_IRQ}
#define EXTI4PB4      (EXTI_GPIO_Mapping_t){GPIO_PIN_4, GPIOB, EXTI4, EXTI4_IRQ}
#define EXTI4PC4      (EXTI_GPIO_Mapping_t){GPIO_PIN_4, GPIOC, EXTI4, EXTI4_IRQ}
#define EXTI4PD4      (EXTI_GPIO_Mapping_t){GPIO_PIN_4, GPIOD, EXTI4, EXTI4_IRQ}

//EXTI5
#define EXTI5PA5      (EXTI_GPIO_Mapping_t){GPIO_PIN_5, GPIOA, EXTI5, EXTI5_IRQ}
#define EXTI5PB5      (EXTI_GPIO_Mapping_t){GPIO_PIN_5, GPIOB, EXTI5, EXTI5_IRQ}
#define EXTI5PC5      (EXTI_GPIO_Mapping_t){GPIO_PIN_5, GPIOC, EXTI5, EXTI5_IRQ}
#define EXTI5PD5      (EXTI_GPIO_Mapping_t){GPIO_PIN_5, GPIOD, EXTI5, EXTI5_IRQ}

//EXTI6
#define EXTI6PA6      (EXTI_GPIO_Mapping_t){GPIO_PIN_6, GPIOA, EXTI6, EXTI6_IRQ}
#define EXTI6PB6      (EXTI_GPIO_Mapping_t){GPIO_PIN_6, GPIOB, EXTI6, EXTI6_IRQ}
#define EXTI6PC6      (EXTI_GPIO_Mapping_t){GPIO_PIN_6, GPIOC, EXTI6, EXTI6_IRQ}
#define EXTI6PD6      (EXTI_GPIO_Mapping_t){GPIO_PIN_6, GPIOD, EXTI6, EXTI6_IRQ}

//EXTI7
#define EXTI7PA7      (EXTI_GPIO_Mapping_t){GPIO_PIN_7, GPIOA, EXTI7, EXTI7_IRQ}
#define EXTI7PB7      (EXTI_GPIO_Mapping_t){GPIO_PIN_7, GPIOB, EXTI7, EXTI7_IRQ}
#define EXTI7PC7      (EXTI_GPIO_Mapping_t){GPIO_PIN_7, GPIOC, EXTI7, EXTI7_IRQ}
#define EXTI7PD7      (EXTI_GPIO_Mapping_t){GPIO_PIN_7, GPIOD, EXTI7, EXTI7_IRQ}

//EXTI8
#define EXTI8PA8      (EXTI_GPIO_Mapping_t){GPIO_PIN_8, GPIOA, EXTI8, EXTI8_IRQ}
#define EXTI8PB8      (EXTI_GPIO_Mapping_t){GPIO_PIN_8, GPIOB, EXTI8, EXTI8_IRQ}
#define EXTI8PC8      (EXTI_GPIO_Mapping_t){GPIO_PIN_8, GPIOC, EXTI8, EXTI8_IRQ}
#define EXTI8PD8      (EXTI_GPIO_Mapping_t){GPIO_PIN_8, GPIOD, EXTI8, EXTI8_IRQ}

//EXTI9
#define EXTI9PA9      (EXTI_GPIO_Mapping_t){GPIO_PIN_9, GPIOA, EXTI9, EXTI9_IRQ}
#define EXTI9PB9      (EXTI_GPIO_Mapping_t){GPIO_PIN_9, GPIOB, EXTI9, EXTI9_IRQ}
#define EXTI9PC9      (EXTI_GPIO_Mapping_t){GPIO_PIN_9, GPIOC, EXTI9, EXTI9_IRQ}
#define EXTI9PD9      (EXTI_GPIO_Mapping_t){GPIO_PIN_9, GPIOD, EXTI9, EXTI9_IRQ}

//EXTI10
#define EXTI10PA10      (EXTI_GPIO_Mapping_t){GPIO_PIN_10, GPIOA, EXTI10, EXTI10_IRQ}
#define EXTI10PB10      (EXTI_GPIO_Mapping_t){GPIO_PIN_10, GPIOB, EXTI10, EXTI10_IRQ}
#define EXTI10PC10      (EXTI_GPIO_Mapping_t){GPIO_PIN_10, GPIOC, EXTI10, EXTI10_IRQ}
#define EXTI10PD10      (EXTI_GPIO_Mapping_t){GPIO_PIN_10, GPIOD, EXTI10, EXTI10_IRQ}

//EXTI11
#define EXTI11PA11      (EXTI_GPIO_Mapping_t){GPIO_PIN_11, GPIOA, EXTI11, EXTI11_IRQ}
#define EXTI11PB11      (EXTI_GPIO_Mapping_t){GPIO_PIN_11, GPIOB, EXTI11, EXTI11_IRQ}
#define EXTI11PC11      (EXTI_GPIO_Mapping_t){GPIO_PIN_11, GPIOC, EXTI11, EXTI11_IRQ}
#define EXTI11PD11      (EXTI_GPIO_Mapping_t){GPIO_PIN_11, GPIOD, EXTI11, EXTI11_IRQ}

//EXTI12
#define EXTI12PA12      (EXTI_GPIO_Mapping_t){GPIO_PIN_12, GPIOA, EXTI12, EXTI12_IRQ}
#define EXTI12PB12      (EXTI_GPIO_Mapping_t){GPIO_PIN_12, GPIOB, EXTI12, EXTI12_IRQ}
#define EXTI12PC12      (EXTI_GPIO_Mapping_t){GPIO_PIN_12, GPIOC, EXTI12, EXTI12_IRQ}
#define EXTI12PD12      (EXTI_GPIO_Mapping_t){GPIO_PIN_12, GPIOD, EXTI12, EXTI12_IRQ}

//EXTI13
#define EXTI13PA13      (EXTI_GPIO_Mapping_t){GPIO_PIN_13, GPIOA, EXTI13, EXTI13_IRQ}
#define EXTI13PB13      (EXTI_GPIO_Mapping_t){GPIO_PIN_13, GPIOB, EXTI13, EXTI13_IRQ}
#define EXTI13PC13      (EXTI_GPIO_Mapping_t){GPIO_PIN_13, GPIOC, EXTI13, EXTI13_IRQ}
#define EXTI13PD13      (EXTI_GPIO_Mapping_t){GPIO_PIN_13, GPIOD, EXTI13, EXTI13_IRQ}

//EXTI14
#define EXTI14PA14      (EXTI_GPIO_Mapping_t){GPIO_PIN_14, GPIOA, EXTI14, EXTI14_IRQ}
#define EXTI14PB14      (EXTI_GPIO_Mapping_t){GPIO_PIN_14, GPIOB, EXTI14, EXTI14_IRQ}
#define EXTI14PC14      (EXTI_GPIO_Mapping_t){GPIO_PIN_14, GPIOC, EXTI14, EXTI14_IRQ}
#define EXTI14PD14      (EXTI_GPIO_Mapping_t){GPIO_PIN_14, GPIOD, EXTI14, EXTI14_IRQ}

//EXTI15
#define EXTI15PA15      (EXTI_GPIO_Mapping_t){GPIO_PIN_15, GPIOA, EXTI15, EXTI15_IRQ}
#define EXTI15PB15      (EXTI_GPIO_Mapping_t){GPIO_PIN_15, GPIOB, EXTI15, EXTI15_IRQ}
#define EXTI15PC15      (EXTI_GPIO_Mapping_t){GPIO_PIN_15, GPIOC, EXTI15, EXTI15_IRQ}
#define EXTI15PD15      (EXTI_GPIO_Mapping_t){GPIO_PIN_15, GPIOD, EXTI15, EXTI15_IRQ}

// @ref EXTI_Trigger_Define
#define EXTI_Trigger_Rising				0
#define EXTI_Trigger_Falling			1
#define EXTI_Trigger_Rising_Falling		2

// @ ref EXTI_IRQ_Define
#define EXTI_IRQ_Enable		1
#define EXTI_IRQ_Disable	0


/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config);
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config);
void MCAL_EXTI_GPIO_DeInit(void);



#endif /* STM32_F103C6_EXTI_DRIVER_H_ */
