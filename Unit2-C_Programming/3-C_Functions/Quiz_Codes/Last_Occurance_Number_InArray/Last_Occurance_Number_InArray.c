/*
 -----------------------------------------------------------------------------------
 Name        : Last_Occurance_Number_InArray.c
 Author      : Mina Gamil
 Created On  : Nov 3, 2024
 Description : C Program to find last occurance of a number in array entered by user
------------------------------------------------------------------------------------
 */

#include <stdio.h>

int Last_Occurance(int Array[], int size, int number);

int main(void)
{
    int i, num, ArrSize, Arr[50];
    printf("Please Enter Array Size: ");
    scanf("%d", &ArrSize);
    printf("Please Enter Array: ");

    for (i = 0; i < ArrSize; i++)
        scanf("%d", &Arr[i]);

    printf("Please Enter Number you want to get last Occurance : ");
    scanf("%d", &num);    

    i = Last_Occurance(Arr, ArrSize, num);
    printf("The Occurance Of Number %d Is %d \n", num, i);
    return 0;
}

int Last_Occurance(int Array[], int size, int number)
{
    int i, r;
    while (i < size)
        r = Array[i++] == number ? i : -1;
    
    return r;
}