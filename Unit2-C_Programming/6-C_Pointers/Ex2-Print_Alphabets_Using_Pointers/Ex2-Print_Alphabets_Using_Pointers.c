/*
------------------------------------------------------------------------------
Name        : Ex2-Print_Alphabets_Using_Pointers.c
Author      : Mina Gamil
Created On  : 10 Dec 2024
Description : Write a program in C to print all the alphabets using a pointer.
------------------------------------------------------------------------------
*/

#include <stdio.h>

int main(void)
{
	// Declare and Initialize Used Variables 
	int i;
	char Alphabet[26];
	char *p = Alphabet;

	// Print Alphabets 
	printf("\nThe Alphabets Are :\n");
	for (i = 0; i < 26; i++)
	{
		*p = 'A'+ i;
		printf("%c \t", *p);
		p++;
	}
	printf("\n\n");
	p = Alphabet;
	return 0;
}