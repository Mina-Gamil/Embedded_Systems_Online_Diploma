/*
 -----------------------------------------------------------------------------
 Name        : Prime_Numbers.c
 Author      : Mina Gamil
 Created On  : Nov 19, 2024
 Description : C Program to take 2 numbers from user and print prime nummbers  
------------------------------------------------------------------------------
 */

#include <stdio.h>

void Prime_Numbers(int S, int E);

int main(void)
{
    // Declare used variables 
    int start, end;

    // ask user for numbers and store them 
    printf("Please enter first number : ");
    scanf("%d", &start);
    printf("Please enter second number : ");
    scanf("%d", &end);

    // Call Function to print Prime Numbers 
    Prime_Numbers(start, end);

    return 0;

}

void Prime_Numbers(int S, int E)
{
    int i, prime = 1;

    printf("Prime Numbers Between %d and %d : ", S, E);
    while (S <= E)
    {
        for (i = 2; i <= S / 2; i++)
        {
            if (S % i == 0)
            {
                prime = 0;
                break;
            }
            else
                prime = 1;
        }
        if (prime == 1)
        {
            printf("%d ", S);
        }
        S++;
    } 
}