/*
------------------------------------------------------------------------
Name        : Ex5-Find_Circle_Area.c
Author      : Mina Gamil
Created On  : 2 Dec 2024
Description : C program to find circle area , passing argument to macros
------------------------------------------------------------------------
*/

#include <stdio.h>

// Define Macros
#define Pi 3.14159265
#define Area(r)  (Pi*r*r)


int main(void)
{
	// Define Variables 
	float r;

	// Ask User Data
	printf("Enter The Radius: ");
	scanf("%f", &r);

	// Print Area
	printf("Area = %.2f\n", Area(r));

	return 0;

}