/*
 --------------------------------------------------------------
 Name        : Clear_Bit.c
 Author      : Mina Gamil
 Created On  : Nov 10, 2024
 Description : Clear Specified bit from number entered by user
---------------------------------------------------------------
 */

#include <stdio.h>

int Clear_bit(int num, int bit);

int main(void)
{
    int num, bit;

    printf("Inout Number : ");
    scanf("%d", &num);

    printf("Bit Position : ");
    scanf("%d", &bit);

    printf("Result : %d" , Clear_bit(num, bit));

    return 0;
}

int Clear_bit(int num, int bit)
{
    return num &= ~(1 << bit);
}