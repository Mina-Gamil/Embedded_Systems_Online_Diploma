/*
 ===========================================================
 Name        : Ex4-Insert_Element_To_Array.c
 Author      : Mina Gamil
 Created On  : Aug 28,2024
 Description : Insert Element into an Array entered by User
 ===========================================================
 */


#include <stdio.h>


int main(void)
{
    int array[100];
    int i, n, l, count;

    printf("Enter The Number Of Elements : ");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
    {
        scanf("%d", &array[i]);
        //array[i] = i + 1;
        //printf("%d  ", array[i]);
    }
    printf("Enter The Element To Be Inserted : ");
    scanf("%d", &n);

    printf("Enter The Location : ");
    scanf("%d", &l);

    
    for (i = count + 1; i > 0; i--)
    {   
        array[i] = i == l - 1 ? array[i] = n : array[i - 1];
    }
    for (i = 0; i < count + 1; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}