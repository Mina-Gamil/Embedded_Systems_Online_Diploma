#include "driver.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void Delay(int nCount)
{
	for(; nCount != 0; nCount--);
}

int getPressureVal(){
	//return (GPIOA_IDR & 0xFF);
	return generate_random_Num(15, 25, 1);
}

void Set_Buzzer_Alarm(int i){
	if (i == 1){
		//SET_BIT(GPIOA_ODR,12);
		printf("Buzzer_Alarm is ON\n");
	}
	else if (i == 0){
		//RESET_BIT(GPIOA_ODR,12);
		printf("Buzzer_Alarm is OFF\n");
	}
}

void Set_Light_Alarm(int R, int G, int Y){
	if (R == 1){
		/*RESET_BIT(GPIOA_ODR,13);
		SET_BIT(GPIOA_ODR,14);
		SET_BIT(GPIOA_ODR,15);*/
		printf("Red_LED_Alarm is ON\n");
	}
	else if (G == 1){
		/*SET_BIT(GPIOA_ODR,13);
		RESET_BIT(GPIOA_ODR,14);
		SET_BIT(GPIOA_ODR,15);*/
		printf("Green_LED_Alarm is ON\n");
	}
	else
	{
		/*SET_BIT(GPIOA_ODR,13);
		SET_BIT(GPIOA_ODR,14);
		RESET_BIT(GPIOA_ODR,15);*/
		printf("Yellow_LED_Alarm is ON\n");
	}
}
/*
void GPIO_INITIALIZATION(){
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;

}*/

/** Pressure_Sensor generate random num **/
int generate_random_Num(int s, int e, int Num)
{
	int i;
	for(i = 0; i < Num; i++)
		return ((rand() % (e - s + 1)) + s);
}


