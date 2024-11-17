/*
 ----------------------------------------------------------------------------------------------------
 Name        : 4th_Significant_Of_Integer.c
 Author      : Mina Gamil
 Created On  : Nov 3, 2024
 Description : C Program to know the 4th Least Significant  bit of an integer number entered by user 
-----------------------------------------------------------------------------------------------------
 */

#include <stdio.h>

int main(void)
{
    int num,temp,shift;
    printf("Please Enter An Integer To Find 4th Least Significant bit : ");
    scanf("%d",&num);
    printf("%d in binary equal to => ", num);

    for (shift = 31; shift > 0; shift--)
    {
        temp = (num >> shift) & 1;
        printf("%d", temp);
    }

    printf("\n4th Least Significant bit of %d is %d \n", num, (num >> 3) & 1);
    return 0;
}