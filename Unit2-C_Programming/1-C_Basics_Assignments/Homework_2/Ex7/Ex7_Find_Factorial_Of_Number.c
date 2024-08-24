/*
 =========================================================
 Name        : Ex7_Find_Factorial_Of_Number.c
 Author      : Mina Gamil
 Created On  : Aug 24, 2024
 Description : Find Factorial Of A Number Entered By User
 =========================================================
 */

#include <stdio.h>


int main(void)
{
    // Declare An Integer To Store User Data
    int i, num, sum = 1;
    
    // Ask User To Enter Data
    printf("Enter An Integer: ");
    scanf("%d", &num);

    // Find The Factorial Of Entered Number
    if (num < 0)
    {
        printf("Error!!! Factorial of negative number doesn't exist.\n");
    }
    else if (num == 0)
    {
        printf("Factorial = 1\n");
    }
    else
    {
        for (i = 1; i <= num; i++)
        {
            sum *= i;
        }
        printf("Factorial = %d\n", sum);
    }
    return 0;
}