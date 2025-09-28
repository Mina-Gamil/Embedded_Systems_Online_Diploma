/*
 * Delay.h
 *
 * Created: 3/16/2025 11:39:49 PM
 *  Author: Mina
 */ 


#ifndef DELAY_H_
#define DELAY_H_

#include <stdio.h>


void wait(uint32_t time)
{
	for (int i = 0; i < time * 2000; i++);
}


#endif /* DELAY_H_ */