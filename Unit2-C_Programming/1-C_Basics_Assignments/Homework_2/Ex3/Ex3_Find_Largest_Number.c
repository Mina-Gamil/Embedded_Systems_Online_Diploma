/*
 ======================================================================
 Name        : Ex3_Find_Largest_Number.c
 Author      : Mina Gamil
 Created On  : Aug 24, 2024
 Description : Find The Largest Number Of Three Numbers Entered By User
 ======================================================================
 */


#include <stdio.h>


int main(void)
{
    // Declare 3 Floats Numbers To store the Entered Data
    float num1, num2, num3;

    // Ask And Fetch User Inputs
    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    // Check The Largest One 
    if (num1 > num2)
    {
        if (num1 > num3)
        {
            printf("Largest Number = %.2f\n", num1);
        }
        else
        {
            printf("Largest Number = %.2f\n", num3);
        }
    }
    else
    {
        if (num2 > num3)
        {
            printf("Largest Number = %.2f\n", num2);
        }
        else
        {
            printf("Largest Number = %.2f\n", num3);
        }
    }
    return 0;
}