/*
-------------------------------------------------------------------------------
Name        : Ex3-Reverse_String_Using_Pointers.c
Author      : Mina Gamil
Created On  : 10 Dec 2024
Description : Write a program in C to print a string in reverse using a pointer
-------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	// Declare Used Variables
	char Word[100];
	char *pstr = Word;
	int i;

	// Ask User To Input String and store the input to word
	printf("Pointer : Print a string in reverse order :\n");
	printf("-------------------------------------------\n");
	printf("Input a string : ");
	scanf("%s", &Word);

	// Assign last char address to pstr
	pstr += strlen(Word) - 1;

	printf("Reverse of the string is : ");

	for (i = strlen(Word) - 1; i >= 0; i--, pstr--)
		printf("%c", *pstr);
	printf("\n\n");

	return 0;
}