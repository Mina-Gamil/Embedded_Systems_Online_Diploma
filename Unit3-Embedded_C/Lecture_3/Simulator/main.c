/**
 ****************************************************
 * @file           : main.c
 * @author         : Mina Gamil
 * @date           : 24 Dec. 2024
 * @brief          : Toggle Led On GPIO A13
 ****************************************************
 */

/******* INCLUDE PLATFORM TYPES ********/
#include "Platform_Types.h"

/********* DIFINED USED ADDRESSES *********/
#define RCC_BASE              0x40021000
#define GPIO_BASE             0x40010800
#define RCC_APB2ENR_REG       (RCC_BASE  + 0x18)
#define GPIO_PORTA_CRH_REG    (GPIO_BASE + 0x04)
#define GPIO_PORTA_ODR_REG    (GPIO_BASE + 0x0C)

/******** APB2ENR REG DECLARATION **********/
typedef union {
	vuint32 All_Pins;
	struct {
		vuint32 reserved:2;
		vuint32 IOPAEN:1;
	}Pin;
}R_APB2ENR_t;

/******** CRH REG DECLARATION **********/
typedef union {
	vuint32 All_Pins;
	struct {
		vuint32 reversed:20;
		vuint32 MODE_PIN13:4;
	}Pin;
}R_CRH_t;

/******** ODR REG DECLARATION **********/
typedef union {
	vuint32 All_Pins;
	struct {
		vuint32 reserved:13;
		vuint32 GPIOA_13:1;
	}Pin;
}R_GPIOA_ODR_t;

/****************** ALL REG INITIALIZATION *******************/
volatile R_APB2ENR_t* APB2ENR = (volatile R_APB2ENR_t*)(RCC_APB2ENR_REG);
volatile R_CRH_t* R_CRH = (volatile R_CRH_t*) GPIO_PORTA_CRH_REG;
volatile R_GPIOA_ODR_t* GPIOA_ODR = (volatile R_GPIOA_ODR_t*) GPIO_PORTA_ODR_REG;

/***** Declare Some Variables *****/
uint8 g_variables[3] = {1, 2, 3};
uint8 const const_Var[3] = {1, 2, 3};
uint32 i;

/********** MAIN PROGRAM **********/
int main(void)
{
	APB2ENR->Pin.IOPAEN = 1;
	R_CRH->Pin.MODE_PIN13 = 2;
	
	while(1)
	{
		GPIOA_ODR->Pin.GPIOA_13 = 1;
		for(i = 0; i < 5000; i++);
		GPIOA_ODR->Pin.GPIOA_13 = 0;
		for(i = 0; i < 5000; i++);
	}

	return 0;
}
