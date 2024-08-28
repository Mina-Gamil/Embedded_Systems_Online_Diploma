/*
 ------------------------------------------------------------------------------------
 Name        : Ex3-Reverse_String.c
 Author      : Mina Gamil 
 Created On  : Aug 28, 2024
 Description : Find Reverse Of String Entered By User Without Using Library Function
 ------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>


int main(void)
{
    // Declare Variable To Be Used
    char Original[100], Reversed[100];
    int i, l;

    // Ask User To Enter String 
    printf("Enter The String : ");
    gets(Original);

    // Reverse String 
    l = strlen(Original);
    for (i = 0; i < l; i++)
    {
        Reversed[l - 1 - i] = Original[i];
    }

    // Print Reversed String 
    printf("Reverse String Is :");
    for (i = 0; i < l; i++)
    {
        printf("%c", Reversed[i]);
    }
    return 0;
}