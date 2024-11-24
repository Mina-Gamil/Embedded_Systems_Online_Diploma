/*
 ---------------------------------------------------------
 Name        : Reverse_String.c
 Author      : Mina Gamil
 Created On  : Nov 25, 2024
 Description : C Program to Reverse String Entered By User 
----------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>

void Reverse_String(char array[]);

int main(void)
{
    // Declare Used Variable 
    char Word[100];

    // Ask User To Enter String 
    printf("Please Enter String : ");
    gets(Word);

    // Calling The Reverse_String Function
    Reverse_String(Word);

    // Print String After Reversing
    printf("String After Reversing: %s", Word);

    return 0;
}

void Reverse_String(char array[])
{
    // Declare Used Variables
    int i, j, done = 1, WordsNum, LastSpace = 0;
    int wordStart = 0;
    char Reverse[100];

    while (done)
    {
        WordsNum = 0;
        int str = strlen(array);

        // Looping To Get Number Of Words And Last Space Location
        for (i = 0; i < str; i++)
        {
            if (array[i] == ' ')
            {
                LastSpace = i;
                WordsNum++;
            }
            else if (WordsNum == 0 && i == str - 1)
            {
                LastSpace = 0;
            }
        }

        // Looping To Take The Word after The Last Space to New Location on Reverse
        for (i = LastSpace + 1, j = wordStart; i <= str; i++, j++)
        {
            if (LastSpace == 0)
            {
                Reverse[j] = array[i - 1];
            }
            else
            {
                Reverse[j] = array[i];
            }
        }
        
        // Add the last Location of the reversed array to start the new word 
        wordStart = j;

        // Put Null instead of copied word 
        array[LastSpace] = '\0';

        if (LastSpace == 0)
        {
            done = 0;
            Reverse[j] = ' ';
        }
        else
        {
            Reverse[--j] = ' ';
        }
    }

    // Copy The Reversed Array From Reverse To array
    for (i = 0; i < strlen(Reverse); i++)
    {
        array[i] = Reverse[i];
    }  
}