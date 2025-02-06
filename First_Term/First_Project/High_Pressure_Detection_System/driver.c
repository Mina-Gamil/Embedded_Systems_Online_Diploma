#include "driver.h"
#include <stdint.h>
#include <stdio.h>

void Delay(int nCount)
{
	for(; nCount != 0; nCount--);
}

int getPressureVal(){
	return (GPIOA_IDR & 0xFF);
}

void Set_Buzzer_Alarm(int i){
	if (i == 0){
		SET_BIT(GPIOA_ODR,12);
	}
	else if (i == 1){
		RESET_BIT(GPIOA_ODR,12);
	}
}

void Set_Light_Alarm(int R, int G, int Y){
	if (R == 1){
		RESET_BIT(GPIOA_ODR,13);
		SET_BIT(GPIOA_ODR,14);
		SET_BIT(GPIOA_ODR,15);
	}
	else if (G == 1){
		SET_BIT(GPIOA_ODR,13);
		RESET_BIT(GPIOA_ODR,14);
		SET_BIT(GPIOA_ODR,15);
	}
	else
	{
		SET_BIT(GPIOA_ODR,13);
		SET_BIT(GPIOA_ODR,14);
		RESET_BIT(GPIOA_ODR,15);
	}
}

void GPIO_INITIALIZATION(){
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;

}
