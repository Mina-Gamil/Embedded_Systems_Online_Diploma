/*
 ------------------------------------------------------------------------
 Name        : Count_Ones.c
 Author      : Mina Gamil
 Created On  : Nov 19, 2024
 Description : C Program to take number from user and Count Ones on it   
-------------------------------------------------------------------------
 */

#include <stdio.h>

int Count_Ones(unsigned int n);

int main(void)
{
    // Declare used Variable
    int num;
    int ones = 0;

    // Ask User To Enter Number And Store it
    printf("Please Enter A Number: ");
    scanf("%d", &num);

    // Call Count_Ones Function
    ones = Count_Ones(num);

    printf("Number Of Ones In %d is equal %d\n", num, ones);

    return 0;

}

int Count_Ones(unsigned int n)
{
    int count = 0;
    while (n != 0)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}