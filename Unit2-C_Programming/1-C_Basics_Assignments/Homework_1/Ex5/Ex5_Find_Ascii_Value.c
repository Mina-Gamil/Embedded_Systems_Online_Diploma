/*
 ======================================================================================================================
 Name        : Ex5_Find_Ascii_Value.c
 Author      : Mina Gamil
 Created on	 : Aug 24, 2024
 Description : Find Ascii Value For An Charactar Entered By User
 ======================================================================================================================
 */

#include <stdio.h>

int main(void)
{
    char a;
    printf("Enter a character: ");
    scanf("%c", &a);
    printf("ASCII value of %c = %d", a, a);
    return 0;
}
