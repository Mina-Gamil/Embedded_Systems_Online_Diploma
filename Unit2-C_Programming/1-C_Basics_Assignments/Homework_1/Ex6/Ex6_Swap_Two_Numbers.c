/*
 =================================================================
 Name        : Ex6_Swap_Two_Numbers.c
 Author      : Mina Gamil
 Created on  : Aug 24, 2024
 Description : Porgram To Swap Two Numbers Entered By User
 =================================================================
*/

#include <stdio.h>

int main(void)
{
    //declare float variables 
    float num1, num2, temp_num;

    // Ask User To Enter Two Numbers to swap
    printf("Enter value of a: ");
    scanf("%f", &num1);
    printf("Enter value of b: ");
    scanf("%f", &num2);

    // swapping the two numbers 
    temp_num = num1;
    num1 = num2;
    num2 = temp_num;

    // Print The Values After Swapping With 2 friction digits only. 
    printf("\nAfter swapping, value of a = %.2f\n", num1);
    printf("After swapping, value of b = %.2f\n", num2);
    return 0;
}