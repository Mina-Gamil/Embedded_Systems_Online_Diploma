/*
 =====================================================
 Name        : Ex7_Swap_Without_temp.c
 Author      : Mina Gamil
 Created On  : Aug 25, 2024
 Description : Swap Two Numbers without temp variable
 =====================================================
 */

#include <stdio.h>


int main(void)
{
    // Declare 2 Variables to store data
    float x, y;

    // Ask User to Enter Data 
    printf("Please Enter two namber to swap: ");
    scanf("%f %f", &x, &y);

    // Swap Numbers 
    x = x + y;
    y = x - y;
    x = x - y;

    printf("Numbers After Swap: %.1f %.1f \n", x, y);
    return 0;
}