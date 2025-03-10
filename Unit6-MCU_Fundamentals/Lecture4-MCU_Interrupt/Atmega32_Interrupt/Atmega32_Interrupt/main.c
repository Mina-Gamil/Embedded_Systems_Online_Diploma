/*
 * main.c
 *
 * Created: 3/9/2025 1:09:05 AM
 * Author : Mina Gamil
 */ 

#define F_CPU 8000000ul
#include <avr/interrupt.h>
#include <util/delay.h>

/* Needed Registers */
#define GPIOD_Dir_Reg     *(volatile unsigned char *)(0x31)             /* GPIO PORTD Data Direction Register*/
#define GPIOD_ODR_Reg     *(volatile unsigned char *)(0x32)             /* GPIO PORTD Data Register*/
#define MCUCSR_Reg        *(volatile unsigned char *)(0x54)             /* MCU Control Register */
#define MCUCR_Reg         *(volatile unsigned char *)(0x55)             /* MCU Control and Status Register */
#define GICR_Reg          *(volatile unsigned char *)(0x5B)             /* General Interrupt Control Register*/
#define SREG_Reg          *(volatile unsigned char *)(0x5F)             /* Status Register */


int main(void)
{	
	/* Config. Ext. Interrupt 0 to any logic change*/
	MCUCR_Reg |= 0x01;
	
	/* Config. Ext. Interrupt 0 to rising edge change*/
	MCUCR_Reg |= 0x0C;
	
	/* Config. Ext. Interrupt 0 to falling edge change*/
	MCUCSR_Reg &= ~(1 << 6);
	
	/* Enable Masking of Ext. Int. 0,1,2 */
	GICR_Reg |= 0xE0;
	
	/* Enable Global Interrupt */
	SREG_Reg |= 0x80;
	
	/* Config. Pin(5,6,7) To OUTPUT */
	GPIOD_Dir_Reg |= 0xE0;
	
    while (1);
}

ISR(INT0_vect)
{
	GPIOD_ODR_Reg |= 1 << 5;              /* Turn On LED connected to portD 5 */
	_delay_ms(1000);                      /* Delay For 1 Second */
	GPIOD_ODR_Reg &= ~(1 << 5);           /* Turn Off LED connected to portD 5 */
}

ISR(INT1_vect)
{
	GPIOD_ODR_Reg |= 1 << 6;             /* Turn On LED connected to portD 6 */
	_delay_ms(1000);                     /* Delay For 1 Second */
	GPIOD_ODR_Reg &= ~(1 << 6);          /* Turn Off LED connected to portD 6 */
}

ISR(INT2_vect)
{
	GPIOD_ODR_Reg |= 1 << 7;            /* Turn On LED connected to portD 7 */
	_delay_ms(1000);                    /* Delay For 1 Second */
	GPIOD_ODR_Reg &= ~(1 << 7);         /* Turn Off LED connected to portD 7 */
}