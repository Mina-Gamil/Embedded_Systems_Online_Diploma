/*
 * Stm32_F103C6_GPIO_Driver.c
 *
 *  Created on: Apr 18, 2025
 *      Author: Mina Gamil
 */

/** Includes **/
#include "Stm32_F103C6_GPIO_Driver.h"


/*
 *****************************************************************************************
 * @Fn			- Get_Pin_Location
 * @brief 		- Get Pin bits start Location in Selected GPIOx Register
 * @param[in] 	- PinNumber : Number of selected pin
 * @retval		- Location of selected pin in which configuration bits start
 * Note			- None
 *****************************************************************************************
 */
uint8_t Get_Pin_Location(uint16_t PinNumber)
{

	switch (PinNumber) {
		case GPIO_PIN_0:
			return 0;
			break;
		case GPIO_PIN_1:
			return 4;
			break;
		case GPIO_PIN_2:
			return 8;
			break;
		case GPIO_PIN_3:
			return 12;
			break;
		case GPIO_PIN_4:
			return 16;
			break;
		case GPIO_PIN_5:
			return 20;
			break;
		case GPIO_PIN_6:
			return 24;
			break;
		case GPIO_PIN_7:
			return 28;
			break;
		case GPIO_PIN_8:
			return 0;
			break;
		case GPIO_PIN_9:
			return 4;
			break;
		case GPIO_PIN_10:
			return 8;
			break;
		case GPIO_PIN_11:
			return 12;
			break;
		case GPIO_PIN_12:
			return 16;
			break;
		case GPIO_PIN_13:
			return 20;
			break;
		case GPIO_PIN_14:
			return 24;
			break;
		case GPIO_PIN_15:
			return 28;
			break;
	}
	return 1;
}



/*
 *****************************************************************************************
 * @Fn			- MCAL_GPIO_Init
 * @brief 		- Initializes GPIOx PINy According to specified parameters on PinConfig
 * @param[in]	- GPIOx : Pointer to GPIO Instant
 * 				  Where x can be (A..E Depend on used device) to Select GPIO Peripherals
 * @param[in] 	- PinConfig : Pointer To GPIO_PinConfig_t Structure that Contains
 * 				  Configuration Information For Selected GPIO Pin.
 * @retval		- None
 * Note			- STM32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 				  But LQFP48 Package Has Only A,B, Part Of C,D Exported As External Pins
 *****************************************************************************************
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	/*First we should select Port Configuration Register to be configured
	  GPIOx->CRL for Pins from 0 To 7 *** GPIOx_CRH for pins From 8 to 15 */
	volatile uint32_t *ConfigRegister = NULL;													// Pointer to hold register address
	uint8_t Pin_Configuration = 0;																// Variable to hold pin 4 bit configuration

	ConfigRegister = ((PinConfig->GPIO_PinNumber) < GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH;		// Assign Register Address Based on Pin Number

	/*Clear Selected Pin Bits CNFx[1:0]  MODEx[1:0]*/
	*ConfigRegister &= ~(0xF << Get_Pin_Location(PinConfig->GPIO_PinNumber));

	/*Now we select configuration register and Clear it, then we need to check required mode to set configuration register*/
	/* First Check if GPIO is Output Mode */
	if ((PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_PP) || (PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_OD) ||
			(PinConfig->GPIO_Mode == GPIO_MODE_AF_OUTPUT_PP) || (PinConfig->GPIO_Mode == GPIO_MODE_AF_OUTPUT_OD))
	{
		/*if the Mode is output we need to configure   CNFx[1:0]  MODEx[1:0]
		  CNFx = GPIO_MODE_Define  ***  MODEx = GPIO_SPEED_Define */
		Pin_Configuration = ((((PinConfig->GPIO_Mode - 4) << 2) | PinConfig->GPIO_Output_Speed) & 0x0F);
	}
	/*if Mode is not Output Then Mode will be Input so we need to check which Input mode was selected */
	else
	{
		if ((PinConfig->GPIO_Mode == GPIO_MODE_Analog) || (PinConfig->GPIO_Mode == GPIO_MODE_INPUT_FLO))
		{
			// Set CNFx[1:0] MODEx[1:0]00
			Pin_Configuration = ((((PinConfig->GPIO_Mode) << 2) | 0x0) & 0x0F);
		}
		else
		{
			if (PinConfig->GPIO_Mode == GPIO_MODE_INPUT_FLO)
			{
				// Set CNFx[1:0]01 MODEx[1:0]00
				Pin_Configuration = ((((GPIO_MODE_INPUT_FLO) << 2) | 0x0) & 0x0F);
			}
			else
			{
				// Set CNFx[1:0]10 MODEx[1:0]00
				Pin_Configuration = ((((GPIO_MODE_INPUT_PU) << 2) | 0x0) & 0x0F);

				if (PinConfig->GPIO_Mode == GPIO_MODE_INPUT_PU)
				{
					// PxODR Pin Bit = 1 for Input Pull-Up, Refer to Table 20: Port bit configuration table.
					GPIOx->ODR |= PinConfig->GPIO_PinNumber;
				}
				else
				{
					// PxODR Pin Bit = 0 for Input Pull-Down, Refer to Table 20: Port bit configuration table.
					GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
				}
			}
		}
	}
	// Set Pin configuration into Selected Configuration Register at Selected Pin Location
	*ConfigRegister |= Pin_Configuration << Get_Pin_Location(PinConfig->GPIO_PinNumber);
}



/*
 *****************************************************************************************
 * @Fn			- MCAL_GPIO_DeInit
 * @brief 		- Reset All GPIOx Registers
 * @param[in]	- GPIOx : Pointer to GPIO Instant
 * 				  Where x can be (A..E Depend on used device) to Select GPIO Peripherals
 * @retval		- None
 * Note			- None
 *****************************************************************************************
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx)
{
	/*To DeInit Specific Port we have two ways, First way Clear each Register manually,
	  Second way reset it using reset Register if Our MCU support this option */
	/*Our MCU Support Reset register option At APB2RSTR Register, all we need to do
	  is to Set and Clear Portx Bit in the register */
	if (GPIOx == GPIOA)
	{	//Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR |= (1 << 2);
		RCC->APB2RSTR &= ~(1 << 2);
	}
	else if (GPIOx == GPIOB)
	{	//Bit 3 IOPBRST: IO port B reset
		RCC->APB2RSTR |= (1 << 3);
		RCC->APB2RSTR &= ~(1 << 3);
	}
	else if (GPIOx == GPIOC)
	{	//Bit 4 IOPCRST: IO port C reset
		RCC->APB2RSTR |= (1 << 4);
		RCC->APB2RSTR &= ~(1 << 4);
	}
	else if (GPIOx == GPIOD)
	{	//Bit 5 IOPDRST: IO port D reset
		RCC->APB2RSTR |= (1 << 5);
		RCC->APB2RSTR &= ~(1 << 5);
	}
	else if (GPIOx == GPIOE)
	{	//Bit 6 IOPERST: IO port E reset
		RCC->APB2RSTR |= (1 << 6);
		RCC->APB2RSTR &= ~(1 << 6);
	}
}



/*
 *****************************************************************************************
 * @Fn			- MCAL_GPIO_ReadPin
 * @brief 		- Read Specific Pin
 * @param[in]	- GPIOx : Pointer to GPIO Instant
 * 				  Where x can be (A..E Depend on used device) to Select GPIO Peripherals
 * @param[in]	- PinNumber : Specify Pin To Read, Set it According to @ref GPIO_PIN_Define
 * @retval		- Input Pin Value (Two Values Based On @ref GPIO_PIN_State)
 * Note			- None
 *****************************************************************************************
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	uint8_t bitStatus;
	if (GPIOx->IDR & PinNumber)
	{
		bitStatus = GPIO_PIN_Set;
	} else
	{
		bitStatus = GPIO_PIN_Reset;
	}
	return bitStatus;
}



/*
 *****************************************************************************************
 * @Fn			- MCAL_GPIO_ReadPort
 * @brief 		- Read GPIOx Port Value
 * @param[in]	- GPIOx : Pointer to GPIO Instant
 * 				  Where x can be (A..E Depend on used device) to Select GPIO Peripherals
 * @retval		- Input Port Value
 * Note			- None
 *****************************************************************************************
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
	uint16_t PortStatus;
	PortStatus = (uint16_t) GPIOx->IDR;
	return PortStatus;
}



/*
 *****************************************************************************************
 * @Fn			- MCAL_GPIO_WritePin
 * @brief 		- Write On Specific Pin
 * @param[in]	- GPIOx : Pointer to GPIO Instant
 * 				  Where x can be (A..E Depend on used device) to Select GPIO Peripherals
 * @param[in]	- PinNumber : Specify Pin To Write On, Set it According to @ref GPIO_PIN_Define
 * @param[in]	- Value : Value to be written on Selected Pin
 * @retval		- None
 * Note			- None
 *****************************************************************************************
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t Value)
{
	if (Value)
	{
	//  Port Bit Set/Reset Register "BSRR"
	//	Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
	//	These bits are write-only and can be accessed in Word mode only.
	//	0: No action on the corresponding ODRx bit
	//	1: Set the corresponding ODRx bit
		GPIOx->BSRR = (uint32_t)PinNumber;

	} else {
	//  Port Bit Reset Register "BRR"
	//	Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
	//	These bits are write-only and can be accessed in Word mode only.
	//	0: No action on the corresponding ODRx bit
	//	1: Reset the corresponding ODRx bit
		GPIOx->BRR = (uint32_t)PinNumber;
	}
}



/*
 *****************************************************************************************
 * @Fn			- MCAL_GPIO_WritePort
 * @brief 		- Write On Selected GPIOx Port
 * @param[in]	- GPIOx : Pointer to GPIO Instant
 * 				  Where x can be (A..E Depend on used device) to Select GPIO Peripherals
 * @param[in]	- Value : Value to be written on Selected Port
 * @retval		- None
 * Note			- None
 *****************************************************************************************
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value)
{
	GPIOx->ODR = (uint32_t) Value;
}




/*
 *****************************************************************************************
 * @Fn			- MCAL_GPIO_TogglePin
 * @brief 		- toggle Selected GPIOx Pin
 * @param[in]	- GPIOx : Pointer to GPIO Instant
 * 				  Where x can be (A..E Depend on used device) to Select GPIO Peripherals
 * @param[in]	- PinNumber : Specify Pin To Toggle, Set it According to @ref GPIO_PIN_Define
 * @retval		- None
 * Note			- None
 *****************************************************************************************
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}



/*
 *****************************************************************************************
 * @Fn			- MCAL_GPIO_LockPin
 * @brief 		- Lock Selected GPIOx Pin (Locking Mechanism allow IO Configuration to be frozen)
 * @param[in]	- GPIOx : Pointer to GPIO Instant
 * 				  Where x can be (A..E Depend on used device) to Select GPIO Peripherals
 * @param[in]	- PinNumber : Specify Pin To Be Locked, Set it According to @ref GPIO_PIN_Define
 * @retval		- Ok If Pin Config Is locked Or Error If Pin Not Locked
 * 				  (Ok And Error Are Defined @ref GPIO_RETURN_LOCK
 * Note			- None
 *****************************************************************************************
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	//	Bit 16 LCKK[16]: Lock key
	//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)
	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//	Any error in the lock sequence will abort the lock.
	//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked.

	// Set LCKK To Pin 16
	volatile uint32_t tmp = 1<<16;
	// Set LCKy
	tmp |= PinNumber;

	// Start the sequence
	GPIOx->LCKR = tmp;				// Set both LCKK And LCKy "Write 1 to LCKK"
	GPIOx->LCKR = PinNumber;		// Reset LCKK and keep LCKy "Write 0 to LCKK"
	GPIOx->LCKR = tmp;				// Set LCKK and keep LCKy "Write 1 to LCKK"
	tmp = GPIOx->LCKR;				// Read 0 From LCKK and lets check
	if (!(tmp & 1<<16)) {
		tmp = GPIOx->LCKR;			// Read 1 From LCKK and lets check
		if ((tmp & 1<<16)) {
			return GPIO_LOCK_Enable;
		} else {
			return GPIO_LOCK_ERROR;
		}
	} else {
		return GPIO_LOCK_ERROR;
	}
}
