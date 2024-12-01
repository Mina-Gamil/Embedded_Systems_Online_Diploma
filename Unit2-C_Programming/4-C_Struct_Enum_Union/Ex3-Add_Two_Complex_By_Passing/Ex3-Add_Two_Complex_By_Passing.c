/*
-----------------------------------------------------------------------------------------
Name      : Ex3-Add_Two_Complex_By_Passing.c
Author    : Mina Gamil
Created On : 1 Dec 2024
Description : C Program to add 2 complex numbers by passing to functions entered by user
-----------------------------------------------------------------------------------------
*/

#include <stdio.h>

struct Scomplex
{
	float real;
	float imaginary;
};

struct Scomplex Sask_Data_From_User(char display[]);
struct Scomplex Sadd_Complex(struct Scomplex Num_1, struct Scomplex Num_2);


int main(void)
{
	// Declare 3 Used Struct
	struct Scomplex Num_1, Num_2, Res;

	// Ask user for first complex number 
	Num_1 = Sask_Data_From_User("For 1st Complex Number");

	// Ask user for first complex number 
	Num_2 = Sask_Data_From_User("For 2nd Complex Number");

	// Add 2 complex Together 
	Res = Sadd_Complex(Num_1, Num_2);

	// Print Result
	printf("Sum = %.1f + %.1fi\n", Res.real, Res.imaginary);

	return 0;
}


/*
	Function Takes String To Display 
	And ask the user to enter data 
	store the data and return the data 
	at the end of the function 
*/
struct Scomplex Sask_Data_From_User(char display[])
{
	// Declare Number Struct
	struct Scomplex number;

	// Ask For Data 
	printf("%s\n", display);

	printf("Please Enter Real And Imaginary respectively: ");
	scanf("%f , %f", &number.real, &number.imaginary);
	printf("\n");

	return number;
}


struct Scomplex Sadd_Complex(struct Scomplex Num_1, struct Scomplex Num_2)
{
	// Declare Result Struct
	struct Scomplex Res;

	// Adding Real And imaginary part 
	Res.real = Num_1.real + Num_2.real;
	Res.imaginary = Num_1.imaginary + Num_2.imaginary;

	return Res;
}