/*
 ----------------------------------------------------------------------------
 Name        : Print_Unique_Number.c
 Author      : Mina Gamil
 Created On  : Nov 24, 2024
 Description : C Program to print unique number from an array entered by user 
-----------------------------------------------------------------------------
*/

#include <stdio.h>

int Unique_Number(int n,int array[]);

int main(void)
{
    // Declare Needed Variables 
    int i, Num, arr[100];

    // Ask User To Enter Number of Array Items And Store It 
    printf("Please Enter Number Of Array Items: ");
    scanf("%d", &Num);

    // Scan Arrays Values
    printf("Please Enter Values: "); 
    for (i = 0; i < Num; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Call Unique_Number Function 
    i = Unique_Number(Num, arr);

    // print Unique number
    printf("Unique Number : %d \n", i);

    return 0;
}

int Unique_Number(int n, int array[])
{
    // Declare used variables 
    int i, j, Unique = 0, unique_num = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if ((array[i] == array[j]) && (i != j))
            {
                Unique = 0;
                break;

            }
            else 
            {
                Unique = 1;
            }
        }
        if (Unique == 1)
        {
            unique_num = array[i];
        }
    }
    return unique_num;
}