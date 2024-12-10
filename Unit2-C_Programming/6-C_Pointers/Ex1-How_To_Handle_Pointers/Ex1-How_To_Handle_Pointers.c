/*
-------------------------------------------------------------------------------------------
Name        : Ex1-How_To_Handle_Ponters.c
Author      : Mina Gamil
Created On  : 10 Dec 2024
Description : Write a program in C to demonstrate how to handle the pointers in the program
-------------------------------------------------------------------------------------------
*/

#include <stdio.h>

int main(void)
{
	// Declare and Initialize Used Variable
	int *ab = NULL;
	int m = 29;

	// Print Address And Value Of m
	printf("Address Of m : 0x%p\n", &m);
	printf("Value Of m : %d\n\n", m);

	// Now Will Assign ab With m Address
	ab = &m;
	printf("Now ab is assigned with the address of m.\n");
	printf("Address Of pointer ab : 0x%p\n", ab);
	printf("Content Of pointer ab : %d\n\n", *ab);

	// Now Will Assign 34 to m
	m = 34;
	printf("The Value of m assigned to 34 now.\n");
	printf("Address Of pointer ab : 0x%p\n", ab);
	printf("Content Of pointer ab : %d\n\n", *ab);

	// Now Will Assign 7 to pointer ab
	*ab = 7;
	printf("The pointer variable ab is assigned with the value 7 now\n");
	printf("Address Of m : 0x%p\n", &m);
	printf("Value Of m : %d\n\n", m);

	return 0;
}