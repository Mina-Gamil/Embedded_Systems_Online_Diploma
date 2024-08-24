/*
 ===================================================================
 Name        : Ex4_Check_Positive_Negative_Numbers.c
 Author      : Mina Gamil
 Created On  : Aug 24, 2024
 Description : Check Entered Number By User Is Positive or Negative
 =================================================================== 
 */

#include <stdio.h>

int main(void)
{
    // Declare float to store Entered Data
    float num;

    // Ask and fetch Data from User
    printf("Enter A Number: ");
    scanf("%f", &num);

    // Check if the number is negative or positive
    if (num == 0)
    {
        printf("You Entered Zero.\n");
    }
    else if(num > 0)
    {
        printf("%.2f Is Positive\n", num);
    }
    else
    {
        printf("%.2f Is Negative\n", num);
    }
    return 0;
}