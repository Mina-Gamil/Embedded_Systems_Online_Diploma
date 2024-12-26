/**
 ******************************************************************************
 * @file           : Toggle_Static_Lib.c
 * @author         : Mina Gamil
 * @date           : 26 Dec. 2024
 * @brief          : Static library to toggle led A13
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "Toggle_Static_Lib.h"

/** Functions ----------------------------------------------------------------*/
void vToggle_Led(void* GPIO)
{
	/***** ASSIGN ADDRESS *****/
	volatile R_GPIOA_ODR_t* GPIOA_ODR = (volatile R_GPIOA_ODR_t*) GPIO;

	while(1)
	{
		GPIOA_ODR->Pin.GPIOA_13 = 1;               // Toggle LED TO 1, We Can also Use TRUE
		for(int i = 0; i < 5000; i++);             // using for loop for make delay
		GPIOA_ODR->Pin.GPIOA_13 = 0;               // Toggle LED TO 0, We Can also Use FALSE
		for(int i = 0; i < 5000; i++);             // using for loop for make delay
	}
}
