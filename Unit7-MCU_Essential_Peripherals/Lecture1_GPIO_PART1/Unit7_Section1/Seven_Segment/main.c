/*
 * Seven_Segment.c
 *
 * Created: 3/19/2025 10:15:54 PM
 * Author : Mina
 */ 

#define F_CPU  8000000ul

#include "MemoryMap.h"
#include "Delay.h"



int main(void)
{
    DDRC = 0xff;
	
    while (1) 
    {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				for (int c = 0; c < 10; c++)
				{
					PORTC = 0b0111 | (j << 4);
					wait(1);
					PORTC = 0b1011 | (i << 4);
					wait(1);
				}
			}
		}
    }
	return 0;
}

