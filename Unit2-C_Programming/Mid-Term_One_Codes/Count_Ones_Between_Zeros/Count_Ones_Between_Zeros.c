/*
---------------------------------------------------------------------------------------------
 Name        : Count_Ones_Between_Zeros.c
 Author      : Mina Gamil
 Created On  : Nov 25, 2024
 Description : C Program to Count Max numbers of ones Between Zeros in Number Entered By user    
---------------------------------------------------------------------------------------------
 */

#include <stdio.h>

int Count_Ones_Between_Zeros(unsigned int n);

int main(void)
{
    // Declare used Variable
    int num;

    // Ask User To Enter Number And Store it
    printf("Please Enter A Number: ");
    scanf("%d", &num);

    // Call Count_Ones_Between_Zeros Function and print the result
    printf("Number Of Ones In %d is equal %d\n", num, Count_Ones_Between_Zeros(num));

    return 0;
}

int Count_Ones_Between_Zeros(unsigned int n)
{
    // Declare Used variables
    int count = 0, prevCount = 0;

    // Looping To Get Number Of Ones
    while (n != 0)
    {
        n >>= 1;
        if (n & 1)
        {
            count++;
        }
        else if (count > prevCount)
        {
            prevCount = count;
            count = 0;
        }
        else
        {
            count = 0;
        }
    }
    return prevCount;
}