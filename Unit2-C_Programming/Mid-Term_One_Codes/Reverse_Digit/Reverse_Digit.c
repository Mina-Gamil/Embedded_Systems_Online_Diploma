/*
 ------------------------------------------------------------------------
 Name        : Reverse_Digit.c
 Author      : Mina Gamil
 Created On  : Nov 19, 2024
 Description : C Program to take number from user and reverse it's order   
-------------------------------------------------------------------------
 */

#include <stdio.h>

int Reverse_Digit(int n);

int main(void)
{
    // Declare used variable 
    int num ,rev;

    // Ask user To Enter Number And Store it 
    printf("Please Enter A Number: ");
    scanf("%d", &num);

    // Call Reverse Function 
    rev = Reverse_Digit(num);
    printf("Reverse Of %d => %d", num, rev);

    return 0;
}

int Reverse_Digit(int n)
{
    int reverse = 0;

    while (n != 0)
    {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    return reverse;
}