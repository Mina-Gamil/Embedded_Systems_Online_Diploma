/**
 *******************************************************************
 * @file           : main.c
 * @author         : Mina Gamil
 * @date           : 26 Dec. 2024
 * @brief          : Toggle Led On GPIO A13 With Static Library
 *******************************************************************
 */

#include <stdint.h>

/******* INCLUDE PLATFORM TYPES ********/
#include "Platform_Types.h"

/******* INCLUDE To ********/
#include "Toggle_Static_Lib.h"

/********* DIFINED USED ADDRESSES *********/
#define RCC_BASE           0x40021000
#define GPIO_BASE          0x40010800
#define RCC_APB2ENR_REG   (0x40021000 + 0x18)
#define GPIOA_CRH_REG     (0x40010800 + 0x04)
#define GPIOA_ODR_REG     (0x40010800 + 0x0C)

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

/****************** ALL REG INITIALIZATION *******************/
volatile R_APB2ENR_t* APB2ENR = (volatile R_APB2ENR_t*)(RCC_APB2ENR_REG);
volatile R_CRH_t* R_CRH = (volatile R_CRH_t*) GPIOA_CRH_REG;

/********** MAIN PROGRAM **********/
int main(void)
{
	/************* INIT IOPAEN AND MODE PIN************/
	APB2ENR->Pin.IOPAEN = 1;
	R_CRH->Pin.MODE_PIN13 = 2;

	/********* CALL vToggle_Led function which Implemented in Library **********/
	vToggle_Led((void*)GPIOA_ODR_REG);
	return 0;
}
