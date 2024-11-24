/*
 --------------------------------------------------------------------
 Name        : Sum_Numbers_1-100.c
 Author      : Mina Gamil
 Created On  : Nov 24, 2024
 Description : C Program to Sum Numbers From 1 to 100 without loop
---------------------------------------------------------------------
 */
 
 #include <stdio.h>

int Sum_Numbers(int n);

 int main(void)
{
    printf("Sum = %d\n", Sum_Numbers(1));
    return 0;
}

int Sum_Numbers(int n)
{
    int i = n;

    if (i == 100)
    {
        return 1;
    }
    else
    {
        return (i + Sum_Numbers(++i));
    }
}