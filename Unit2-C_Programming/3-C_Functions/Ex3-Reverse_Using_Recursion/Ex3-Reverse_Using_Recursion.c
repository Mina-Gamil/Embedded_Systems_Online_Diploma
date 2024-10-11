/*
 -----------------------------------------------------------------
 Name        : Ex3-Reverse_Using_Recursion.c
 Author      : Mina Gamil
 Created On  : Oct 12, 2024
 Description : Reverse a sentence entered by user using recursion
------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>

void revRecur(void);

int main(void)
{
    printf("Enter a sentence : ");
    revRecur();
    return 0;

}

void revRecur(void)
{
    char c;
    scanf("%c", &c);
    if (c != '\n')
    {
        revRecur(); 
        printf("%c", c);
    }       
}