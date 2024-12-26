/**
 ****************************************************
 * @file         : main.c
 * @author       : Mina Gamil 
 * @date         : 26 Dec. 2024
 * @brief        : First Try Of Static Lib 
 ****************************************************
 */

/***** Include All Needed Header Files And Library Header File ******/
#include <stdio.h>
#include "info.h"

/***** Define Person And Assign Data to it *****/
Sperson_t Person = {"Mina", "Gamil", 30};

/* Declare and Define Void pointer*/
void* vPtr = &Person;

/****** Main Function ******/
int main(void)
{
	/***** Call Function From info.a Static Library *****/
	vPrint_Details((void*) vPtr);
	return 0;
}