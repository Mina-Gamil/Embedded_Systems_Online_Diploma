/*
 -----------------------------------------------------
 Name        : Ex2-Find_String_Length.c
 Author      : Mina Gamil
 Created On  : Aug 28, 2024
 Description : Find Length Of String Entered By User
 -----------------------------------------------------
 */

#include <stdio.h>


int main(void)
{
    // Declare Used Variable 
    char Sentence[100];
    int i = 0;

    // Ask User To Enter String
    printf("Enter A String: ");
    gets(Sentence);

    // Find String Length
    while (Sentence[i] != '\0')
    {
        i++;
    }

    // Print String Length
    printf("Length Of String: %d", i);
    return 0;
}