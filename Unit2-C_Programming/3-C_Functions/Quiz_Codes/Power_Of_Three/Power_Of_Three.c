/*
 --------------------------------------------------------------------
 Name        : Power_Of_Three.c
 Author      : Mina Gamil
 Created On  : Nov 10, 2024
 Description : Check Number Entered by user is power of three or not 
---------------------------------------------------------------------
 */

#include <stdio.h>
#include <math.h>

int Power_Of_Three(unsigned int n);

int main(void)
{
    unsigned int n;
    printf("Please Enter a Number :");
    scanf("%d", &n);
    printf("%d ==> %d", n, Power_Of_Three(n));

    return 0;
}

int Power_Of_Three(unsigned int n)
{
    double  i = log(n) / log(3);

    if (i - (int)i == 0)
        return 0;
    else
        return 1;
}