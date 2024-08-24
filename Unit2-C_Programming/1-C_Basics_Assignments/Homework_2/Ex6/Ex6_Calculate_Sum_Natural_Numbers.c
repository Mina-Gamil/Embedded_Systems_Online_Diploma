/*
 ==============================================================================
 Name        : Ex6_Calculate_Sum_Natural_Numbers.c
 Author      : Mina Gamil
 Created On  : Aug 24, 2024
 Description : Calculate The Sum Of Natural Numbers Of Number Entered By User
 ==============================================================================
 */

#include <stdio.h>


int main(void)
{
    // Declare Integer To Store Data 
    int i, num, sum = 0;

    // Ask User For An Integer
    printf("Enter An Integer: ");
    scanf("%d", &num);
    
    // Loop For the Integer To Calculate the sum of Natural Numbers
    for (i = 0; i <= num; i++)
    {
        sum += i;
    }
    
    // print The Sum To User
    printf("Sum = %d\n", sum);
    return 0;
}