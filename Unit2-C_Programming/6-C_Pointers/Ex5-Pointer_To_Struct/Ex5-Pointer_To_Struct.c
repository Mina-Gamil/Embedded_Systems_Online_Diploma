/*
-----------------------------------------------------------------
Name        : Ex5-Pointer_To_Struct.c
Author      : Mina Gamil
Created On  : 11 Dec 2024
Description : Write a program in C to show a pointer to an array 
              which contents are pointer to structure.
-----------------------------------------------------------------
*/

#include <stdio.h>


struct sEmployee
{
	char *sName;
	int sID;
};


int main(void)
{
	// Declare and Initialize Used Variables 
	struct sEmployee emp[3] = {{"Mina", 1000}, {"Moudi", 1001}, {"Alex", 1002}};
	struct sEmployee *arr[] = {emp, &emp[1], &emp[2]};
	struct sEmployee *(*p)[] = &arr;

	// Print Needed Values 
	printf("Exmployee Name : %s \n", (*(*p + 2))->sName);
	printf("Exmployee ID : %d \n", (*(*p + 2))->sID);

	return 0;
}