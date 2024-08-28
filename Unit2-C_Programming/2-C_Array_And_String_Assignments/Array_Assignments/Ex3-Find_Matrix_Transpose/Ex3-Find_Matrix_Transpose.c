/*
 ==========================================
 Name        : Ex3-Find_Matrix_Transpose.c
 Author      : Mina Gamil
 Created On  : Aug 28, 2024
 Description : Find Matrix Transpose
 ========================================== 
*/

#include <stdio.h>


int main(void)
{
    int array[100][100];
    int trans[100][100];
    int x, y, Rows, Columns;

    printf("Enter rows and column of the matrix: ");
    scanf("%d %d", &Rows, &Columns);
    
    printf("\nEnter Elements Of Matrix:\n");
    for (x = 0; x < Rows; x++)
    {
        for (y = 0; y < Columns; y++)
        {
            printf("Enter elements a%d%d: ", x + 1, y + 1);
            scanf("%d", &array[x][y]);
            trans[y][x] = array[x][y];
        }
    }
    
    printf("\nEntered Matrix:\n");
    for (x = 0; x < Rows; x++)
    {
        for (y = 0; y < Columns; y++)
        {
            printf(" %d  ", array[x][y]);
        }
        printf("\n");
    }

    printf("\nTranspose Of Matrix:\n");
    for (x = 0; x < Columns; x++)
    {
        for (y = 0; y < Rows; y++)
        {
            printf(" %d  ", trans[x][y]);
        }
        printf("\n");
    }
    return 0;
}