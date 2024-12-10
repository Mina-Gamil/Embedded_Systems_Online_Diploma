/*
--------------------------------------------------------------------------------------
Name        : Ex4-Reverse_Array_Element.c
Author      : Mina Gamil
Created On  : 11 Dec 2024
Description : Write a program in C to print the elements of an array in reverse order.
--------------------------------------------------------------------------------------
*/

#include <stdio.h>

int main(void)
{
	// Declare and Initialize Used Variable 
	int i, elements, num[20], *pnum = num;

	// Ask User to Enter Array Elements 
	printf("Input the number of elements to store in the array (max 15) : ");
	scanf("%d", &elements);
	printf("Input %d number of elements in the array :\n", elements);

	for (i = 0; i < elements; i++, pnum++)
	{
		printf("Element - %d : ", i + 1);
		scanf("%d", &num[i]);
	}
	pnum--;

	printf("The elements of array in reverse order are :\n");
	for(i = elements; i > 0; i-- , pnum--)
		printf("Element - %d : %d \n", i, *pnum);

	return 0;
}