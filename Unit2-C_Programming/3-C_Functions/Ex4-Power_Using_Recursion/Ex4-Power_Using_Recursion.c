/*
 --------------------------------------------------------------------
 Name        : Ex4-Power_Using_Recursion.c
 Author      : Mina Gamil
 Created On  : Oct 12, 2024
 Description : Find Power of a number entered by user using recursion
---------------------------------------------------------------------
 */

#include <stdio.h>

// Function Prototype
int poweRecur(int b, int p);

// main Function
int main(void)
{
    // used variables 
    int base, power, result;

    // Ask and scan base and power numbers
    printf("Enter base number: ");
    scanf("%d", &base);
    printf("Enter power number(positive integer): ");
    scanf("%d", &power);

    // use poweRecur() Function to get the power of the base by pathing base and power values
    result = poweRecur(base, power);

    // printing the result 
    printf("%d ^ %d = %d \n", base, power, result);

    // return 0 to indicate that everything done correctly
    return 0;
}

// powerRecur Function used to find the value of number (base) powered by another number (power) by pathing two variables 
int poweRecur(int b, int p)
{
    if (p <=0)
        return 1;
    else
        return b * poweRecur(b, p - 1);
}