/*
 ===================================================================
 Name        : Ex5_Check_Is_Alphabet_Or_Not.c
 Author      : Mina Gamil
 Created On  : Aug 24, 2024
 Description : Check a character Entered By User Is Alphabet or not
 ===================================================================
 */


#include <stdio.h>


int main(void)
{
    // Declare char To Store Alphabet
    char alphabet;

    // Ask and Fetch Data From User 
    printf("Enter a Character: ");
    scanf("%c", &alphabet);

    // Check The Entered Character
    if ((alphabet >= 'a' && alphabet <= 'z') || (alphabet >= 'A' && alphabet <= 'Z'))
    {
        printf("%c Is An Alphabet\n", alphabet);
    }
    else
    {
        printf("%c Is Not An Alphabet\n", alphabet);
    }
    return 0;
}