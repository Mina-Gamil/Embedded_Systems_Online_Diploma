/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*Clock Register */
#define RCC_Base          0x40021000
#define RCC_APB2ENR       *(volatile unsigned int *)(RCC_Base + 0x18)

/* GPIOA Registers */
#define GPIOA_BASE        0x40010800
#define GPIOA_CRH         *(volatile unsigned int *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL         *(volatile unsigned int *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR         *(volatile unsigned int *)(GPIOA_BASE + 0x0C)

/* External interrupt registers */
#define EXTI_BASE         0x40010400
#define EXTI_IMR          *(volatile unsigned int *)(EXTI_BASE + 0x00)
#define EXTI_RTSR         *(volatile unsigned int *)(EXTI_BASE + 0x08)
#define EXTI_PR           *(volatile unsigned int *)(EXTI_BASE + 0x14)

/*Arm NVIC Registers */
#define NVIC_BASE         0xE000E100
#define NVIC_ISR0         *(volatile unsigned int *)(NVIC_BASE + 0x00)

/*Choose PA0 To Be An EXTI0 */
#define AFIO_BASE         0x40010000
#define AFIO_EXTICR1      *(volatile unsigned int *)(AFIO_BASE + 0x08)

/* Clock Init Function */
void Clock_init(void)
{
	/* Enable AFIO Colck */
	RCC_APB2ENR |= (1 << 0);

	/* Enable GPIOA Colck */
	RCC_APB2ENR |= (1 << 2);
}

/* GPIO Init Function */
void GPIO_init(void)
{
	//Init GPIOA PIN13 as output with 2 Mhz freq
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	//Init GPIOA Pin0 as floating input
	GPIOA_CRL |= (1 << 2);
}

/* main Function */
int main(void)
{
	Clock_init();
	GPIO_init();

	/* Set PA0 to be connected to EXTI0*/
	AFIO_EXTICR1 |= 0x000;

	/*Enable PortA Pin0 Interrupt mask*/
	EXTI_IMR |= (1 << 0);

	/*Enable PortA Pin0 Rising trigger*/
	EXTI_RTSR |= (1 << 0);

	/*Enable NVIC Interrupt 6*/
	NVIC_ISR0 |= (1 << 6);

	/*Infinite loop*/
	while(1);
}

/* External Interrupt 0 Handler */
void EXTI0_IRQHandler (void)
{
	/* toggle PortA Pin13 */
	GPIOA_ODR ^= (1 << 13);

	/* Clear Pending status */
	EXTI_PR |= (1 << 0);
}
