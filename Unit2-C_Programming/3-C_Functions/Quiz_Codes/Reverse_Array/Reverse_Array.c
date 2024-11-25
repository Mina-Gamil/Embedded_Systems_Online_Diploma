/*
 -------------------------------------------------
 Name        : Reverse_Array.c
 Author      : Mina Gamil
 Created On  : Nov 10, 2024
 Description : Reverse two arrays entered by user 
--------------------------------------------------
 */

#include <stdio.h>

void Reverse_Array(int Src[], int num);

int main(void)
{
    int Src[50];
    int num;

    printf("Please Enter Number of items in the array : ");
    scanf("%d", &num);

    printf("Please Enter Array To reverse : ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &Src[i]);
    }

    Reverse_Array(Src,num);

    printf("Reversed Array : ");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", Src[i]);
    }
    printf("\n");
    return 0;

}

void Reverse_Array(int Src[], int num)
{
    int i, j, Temp;

    for (i = 0, j = num - 1; i < j; i++, j--)
    {
        Temp = Src[i];
        Src[i] = Src[j];
        Src[j] = Temp;
    }
}