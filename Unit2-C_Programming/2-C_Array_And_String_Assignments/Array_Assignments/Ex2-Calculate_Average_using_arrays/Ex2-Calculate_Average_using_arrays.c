/*
 =======================================================================
 Name        : Ex2-Calculate_Average_using_arrays
 Author      : Mina Gamil
 Created On  : Aug 28, 2024
 Description : Find The Average of numbers entered by user using arrays
 ======================================================================= 
*/

#include <stdio.h>


int main(void)
{
    float array[100], sum = 0;
    int i, count;

    printf("Enter The Number Of Data: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
    {
        printf("%d. Enter Number: ", i + 1);
        scanf("%f", &array[i]);
        sum += array[i];
    }
    printf("Average = %.2f", sum / i);
    return 0;
}