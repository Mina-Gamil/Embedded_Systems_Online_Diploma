/*
 =======================================================================================
 Name        : Ex8_Simple_Calculator.c
 Author      : Mina Gamil
 Created On  : Aug 24, 2024
 Description : Simple Calculator to Add, Subtract, Multiply or Divide Using Switch Case
 =======================================================================================
 */

#include <stdio.h>


int main(void)
{
    // Declare Variables To store Inout Data
    char operation;
    float num1, num2;

    // Ask user to chose the operator
    printf("Enter operator either + or - or * or divide : ");
    scanf("%c", &operation);

    // Ask User to enter the operands
    printf("Enter two operands: ");
    scanf("%f %f", &num1, &num2);

    switch (operation)
    {
    case '+':
        printf("%.1f + %.1f = %.1f\n", num1, num2, num1 + num2);
        break;
    case '-':
        printf("%.1f - %.1f = %.1f\n", num1, num2, num1 - num2);
        break;
    case '*':
        printf("%.1f * %.1f = %.1f\n", num1, num2, num1 * num2);
        break;
    case '/':
        printf("%.1f / %.1f = %.1f\n", num1, num2, num1 / num2);
        break;
    default:
        printf("Error! Please Enter Correct Operator");
        break;
    }
    return 0;
}