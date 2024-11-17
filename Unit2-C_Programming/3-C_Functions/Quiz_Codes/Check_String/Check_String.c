/*
 -------------------------------------------------------------------------------
 Name        : Check_String.c
 Author      : Mina Gamil
 Created On  : Nov 4, 2024
 Description : C Program to Check 2 Strings Entered by User are the same or not 
--------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char Str1[50];
    char UserName[50] = "Mina Gamil";
    printf("Please Enter UserName : ");
    gets(Str1);

    if (stricmp(Str1, UserName) == 0)
        printf("Both Are The Same\n");
    else
        printf("Both Are Not The Same\n");
    
    return 0;
}