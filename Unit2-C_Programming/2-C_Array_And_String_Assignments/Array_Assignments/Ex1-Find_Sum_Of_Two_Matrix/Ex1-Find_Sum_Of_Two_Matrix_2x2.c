/*
 =============================================================
 Name        : Ex1-Find_Sum_Of_Two_Matrix_2x2.c
 Author      : Mina Gamil
 Created On  : Aug 28, 2024
 Description : Find The Sum Of Two Multidimensional Array 2x2
 ============================================================= 
*/

#include <stdio.h>


int main (void)
{
    float array_1[2][2];
    float array_2[2][2];
    int x, y;

    printf("Enter The Elements Of The 1st Matrix :\n");
    for(x = 0; x < 2; x++)
    {
        for (y = 0; y < 2; y++)
        {
            printf("Enter a%d%d: ", x + 1, y + 1);
            scanf("%f", &array_1[x][y]);
        }
    }
    printf("Enter The Elements Of The 2nd Matrix :\n");
    for(x = 0; x < 2; x++)
    {
        for (y = 0; y < 2; y++)
        {
            printf("Enter b%d%d: ", x + 1, y + 1);
            scanf("%f", &array_2[x][y]);
        }
    }
    printf("\n Sum Of Matrix:\n");
    for(x = 0; x < 2; x++)
    {
        for (y = 0; y < 2; y++)
        {
            array_1[x][y] += array_2[x][y];
            printf("   %.1f    ",array_1[x][y]);
        }
        printf("\n");
    }
    return 0;
}