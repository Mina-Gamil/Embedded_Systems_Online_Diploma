/*
---------------------------------------------------------------------
Name        : Ex4-Store_10Students_Info_Using_Struct.c
Author      : Mina Gamil
Created On  : 2 Dec 2024
Description : C Program to Store Students Information Using Structure
---------------------------------------------------------------------
*/

#include <stdio.h>

struct Sperson
{
	char name[50];
	int roll;
	int marks;
};

// Functions Prototypes
struct Sperson Sask_Student_Data(int display);
void Print_Student_Data(struct Sperson S);

int main(void)
{
	// Variables Declaration
	int i, NumOfStudents = 10;
	struct Sperson Students[10];

	// Ask User For Data
	printf("Enter Informations Of Students: \n\n");
	for (int i = 0; i < NumOfStudents; i++)
	{
		Students[i] = Sask_Student_Data(i);
	}

	// Print Student Data
	printf("Displaying Information Of Students: \n\n");
	for (int i = 0; i < NumOfStudents; i++)
	{
		Print_Student_Data(Students[i]);
	}

	return 0;
}


struct Sperson Sask_Student_Data(int display)
{
	// Declare S Struct
	struct Sperson S;

	// Ask user for data and assign display to roll
	S.roll = display + 1;
	printf("For Roll Number %d\n",S.roll);

	// Ask user for name and assign it to S.name
	printf("Enter Name: ");
	scanf("%s", &S.name);

	// Ask user for marks and assign it to S.marks
	printf("Enter Marks: ");
	scanf("%d", &S.marks);
	printf("\n");

	return S;
}

void Print_Student_Data(struct Sperson S)
{
	// Print Student Roll
	printf("Informations For Roll %d: \n", S.roll);

	// Print Student Name 
	printf("Name: %s\n", S.name);

	// Print Student Marks
	printf("Marks: %d\n\n", S.marks);
}