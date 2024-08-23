/*
 ======================================================================================================================
 Name        : Ex2_Print_an_integer_Entered_by_a_User.c
 Author      : Mina Gamil
 Created on	 : Aug 24, 2024
 Description : Print an integar Entered by a user
 ======================================================================================================================
 */

#include <stdio.h>

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("You entered: %d", number);
    return 0;
}