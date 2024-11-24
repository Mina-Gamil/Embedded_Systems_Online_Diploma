/*
 ----------------------------------------------------------------------
 Name        : Reverse_Array.c
 Author      : Mina Gamil
 Created On  : Nov 24, 2024
 Description : C Program to Reverse an Array of numbers Entered By User
-----------------------------------------------------------------------
 */

#include <stdio.h>

void Reverse_Array(int n, int array[]);

int main(void)
{
    // Declare Used Variables
    int i, Num, arr[50];

    // Ask User To Enter Number Of Items On The Array
    printf("Please Enter Number Of Array Items: ");
    scanf("%d", &Num);

    // Ask User To Enter Items Values
    printf("Please Enter Array Items Values: ");
    for (i = 0; i < Num; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Call Reverse_Array Function
    Reverse_Array(Num, arr);

    // Print Array After Reverse
    printf("Array After Reversing: ");
    for (i = 0; i < Num; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

void Reverse_Array(int n, int array[])
{
    int i, j, Temp;
    for (i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        Temp = array[j];
        array[j] = array[i];
        array[i] = Temp;
    }
}