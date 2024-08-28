/*
 ----------------------------------------------------------------
 Name        : Ex1-Find_Frequency_Of_Characters_In_String.c
 Author      : Mina Gamil
 Created On  : Aug 28, 2024
 Description : Ask User TO Inter String And Character And Check 
               How Many Times Character Reapeted
-----------------------------------------------------------------
 */


#include <stdio.h>
#include <string.h>


int main(void)
{
    // Declare Variables To Be Used
    char Sentence[100], Character;
    int i,count = 0;

    // Ask User Ton Enter Sentence 
    printf("Enter A String: ");
    gets(Sentence);

    // Ask User To Enter Character to find
    printf("Enter A Character To Find Frequency: ");
    scanf("%c", &Character);

    // Find Frequency 
    for (i = 0; i < strlen(Sentence); i++)
    {
        if(Sentence[i] == Character)
        {
            count++;
        }
    }

    // Print Frequency
    printf("Frequency Of %c = %d", Character, count);
    return 0;
}