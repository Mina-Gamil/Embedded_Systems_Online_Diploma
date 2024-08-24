/*
 ======================================================================================================================
 Name        : Ex3_Adding_Two_integers.c
 Author      : Mina Gamil
 Created on	 : Aug 24, 2024
 Description : Adding Two Integers Entered by user
 ======================================================================================================================
 */

#include <stdio.h>

int main(void)
{
    int num1, num2;
    printf("Enter Two Integars: ");
    scanf("%d %d", &num1, &num2);
    printf("Sum: %d", num1 + num2);
    return 0;
}