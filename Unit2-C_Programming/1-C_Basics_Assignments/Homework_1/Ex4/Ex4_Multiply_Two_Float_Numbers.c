/*
 ======================================================================================================================
 Name        : Ex4_Multiply_Two_Float_numbers
 Author      : Mina Gamil
 Created on	 : Aug 24, 2024
 Description : Multiply Two Float Numbers Entered by user
 ======================================================================================================================
 */

#include <stdio.h>

int main(void)
{
    float num1, num2;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    printf("Product: %f", num1 * num2);
    return 0;
}