/*
-------------------------------------------------------------------------------
Name        : Ex3-Reverse_String_Using_Pointers_2.c
Author      : Mina Gamil
Created On  : 11 Dec 2024
Description : Write a program in C to print a string in reverse using a pointer
-------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	// Declare Used Variables
	char Word[100];
	char rev[100];
	char *pstr = Word;
	char *prev = rev;
	int i;

	// Ask User To Input String and store the input to word
	printf("Pointer : Print a string in reverse order :\n");
	printf("-------------------------------------------\n");
	printf("Input a string : ");
	scanf("%s", &Word);

	// Assign last char address to pstr
	pstr += strlen(Word) - 1;
	i = strlen(Word) - 1;

	// reverse and store reverse string to array rev
	for (; i >= 0; i--, pstr--, prev++)
		*prev = *pstr;

	// Print reverse string
	printf("Reverse of the string is : %s\n\n", rev);

	return 0;
}