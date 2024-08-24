/*
 =======================================================================
 Name        : Ex2_Check_Vowel_Consonant_Alphabet.c
 Author      : Mina Gamil
 Created On  : Aug 24, 2024
 Description : Check An Alphabet Entered By User Is Vowel Or Consonant
 =======================================================================
*/

#include <stdio.h>


int main(void)
{
    // declare char To store user input 
    char Alphabet;

    // Ask user to Enter char and fetch it
    printf("Enter An Alphabet: ");
    scanf("%c", &Alphabet);

    // Check The Alphabet
    if (Alphabet == 'a' || Alphabet == 'e' || Alphabet == 'i' || Alphabet == 'o' || Alphabet == 'u' ||
        Alphabet == 'A' || Alphabet == 'E' || Alphabet == 'I' || Alphabet == 'O' || Alphabet == 'U')
    {
        printf("%c Is A Vowel\n", Alphabet);
    }
    else
    {
        printf("%c Is A Consonant\n", Alphabet);
    }
    return 0;
}