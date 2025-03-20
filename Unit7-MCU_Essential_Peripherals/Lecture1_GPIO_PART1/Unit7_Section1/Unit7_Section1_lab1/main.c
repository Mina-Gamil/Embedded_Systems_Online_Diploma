/*
 * Unit7_Section1_lab1.c
 *
 * Created: 3/16/2025 4:20:03 PM
 * Author : Mina Gamil
 */ 

#define F_CPU  8000000ul
#include <util/delay.h>

#include "Utils.h"
#include "MemoryMap.h"
#include "Delay.h"


int main(void)
{
	int i;
	DDRD = 0xE0;
	PORTD = 0x0;
	
    while (1) 
    {
		for (i = 0; i <= 7; i++)
		{
			setbit(PORTD,i);
			wait(1000);
		}
		for (i = 7; i >= 0; i--)
		{
			resetbit(PORTD, i);
			wait(1000);
		}
    }
	return 0;
}

