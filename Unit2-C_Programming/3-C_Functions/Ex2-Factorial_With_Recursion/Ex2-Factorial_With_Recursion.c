/*
 -----------------------------------------------------------------------
 Name        : Ex2-Factorial_With_Recursion.c
 Author      : Mina Gamil
 Created On  : Oct 12, 2024
 Description : Find Factorial of number entered by user using recursion
------------------------------------------------------------------------
 */

#include <stdio.h>

int factRecur(int n);

int main(void)
{
    int num, prod;
    printf("Enter an positive integar: ");
    scanf("%d", &num);
    prod = factRecur(num);
    printf("Factorial of %d = %d", num, prod);
    return 0;
}

int factRecur(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factRecur(n-1);
}