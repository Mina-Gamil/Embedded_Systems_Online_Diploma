/**
 ***********************************************************
 * @file             : info.c
 * @author           : Mina Gamil 
 * @date             : 24 Dec. 2024
 * @brief            : C program to make static library 
 ***********************************************************
*/

/***** Include All Needed Header Files And Library Header File ******/
#include <stdio.h>
#include "info.h"


/***** vPrint_Details Function Print All Person Details *****/
/*****   And Some File Details From Predefined Macros   *****/
void vPrint_Details(void* vPtr)
{
	/***** Declare And Assign Void Pointer To person Struct Using Casting *****/
	volatile Sperson_t* person = (volatile Sperson_t*) vPtr;

	/***** Print Some File Details Form Predefined Macros In C *****/
	printf("This is %s file ,Created on %s ,At %s O'Clock\n", __FILE__, __DATE__, __TIME__);
	printf("Your are now in line %d in %s Function\n", __LINE__, __func__);

	/***** Print person Data *****/
	printf("My Name Is: %s %s and I have %d years old\n", person->FirstName, person->SecondName, person->Age);
	printf("Thanks Eng.Kerolos\n");
}