/*
 * Unit7_Section1_lab2.c
 *
 * Created: 3/16/2025 5:08:15 PM
 * Author : Mina Gamil
 */ 

#define F_CPU  8000000ul
#include <util/delay.h>

#include "Utils.h"
#include "MemoryMap.h"
#include "Delay.h"


int main(void)
{
	int i = 5;
    DDRD = 0xF0;
    while (1) 
    {
		if (readbit(PIND, 0) == 1 && !(i == 8))
		{
			setbit(PORTD, i);
			i++;
		}
		
		if (readbit(PIND, 1) == 1 && !(i == 5))
		{
			i--;
			resetbit(PORTD, i);
		}
		wait(10000);
    }
	return 0;
}