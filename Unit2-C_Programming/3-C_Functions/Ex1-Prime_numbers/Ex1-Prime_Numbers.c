/*
 -------------------------------------------------------------------
 Name        : Ex1-Prime_Numbers.c
 Author      : Mina Gamil
 Created On  : Oct 8, 2024
 Description : Find prime numbers between 2 numbers entered by user
--------------------------------------------------------------------
 */

#include <stdio.h>

void primeNumber(int S, int E);

int main(void)
{
    int Start, End;

    printf("Enter Two Numbers(Intervals): ");
    scanf("%d %d", &Start, &End);
    primeNumber(Start, End);
}

void primeNumber(int S, int E)
{
    int prime = 0, i;
    printf("prime numbers between %d and %d are: ", S, E);
    for (; S <= E; S++)
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
        
        
    }
}