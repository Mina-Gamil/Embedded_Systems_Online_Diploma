/*
 * Unit7_Section1_Lab3.c
 *
 * Created: 3/19/2025 10:13:41 PM
 * Author : Mina
 */ 

#define F_CPU  8000000ul
#include "MemoryMap.h"
#include "Delay.h"
#include "Utils.h"


int main(void)
{
	DDRD = 0xF0;
    while (1) 
    {
		if (readbit(PIND, 0) == 1)
		{
			setbit(PORTD, 4);
			wait(1000);
			resetbit(PORTD, 4);
			wait(1000);
		}
    }
}