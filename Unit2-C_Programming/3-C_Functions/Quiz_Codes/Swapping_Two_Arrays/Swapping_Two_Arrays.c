/*
 ---------------------------------------------------------------------------------
 Name        : Swapping_Two_Arrays.c
 Author      : Mina Gamil
 Created On  : Nov 3, 2024
 Description : C Program to Swap Two Arrays entered by user with different lenght  
----------------------------------------------------------------------------------
 */

#include <stdio.h>

int main(void)
{
    // Declaration of Used Variables and arrays
    int Arr1[50],Arr2[50],Temp[50];
    int Arr1Size,Arr2Size,i;

    // Ask User To Enter First Array
    printf("Please Enter First Array Size: ");
    scanf("%d", &Arr1Size);
    printf("Please Enter First Array items: ");
    for (i = 0; i < Arr1Size; i++)
        scanf("%d", &Arr1[i]);

    // Ask User To Enter Second Array
    printf("Please Enter Second Array Size: ");
    scanf("%d", &Arr2Size);
    printf("Please Enter Second Array items: ");
    for (i = 0; i < Arr2Size; i++)
        scanf("%d", &Arr2[i]);

    printf("First Array Before Swapping => ");
    for (i = 0; i < Arr1Size; i++)
        printf("%d ", Arr1[i]);
    
    printf("\nSecond Array Before Swapping => ");
    for (i = 0; i < Arr2Size; i++)
        printf("%d ", Arr2[i]); 

    // Swapping Arrays and Sizes 
    for (i = 0; i < Arr1Size || i < Arr2Size; i++)
    {
        Temp[i] = Arr2[i];
        Arr2 [i] = Arr1[i];
        Arr1[i] = Temp[i];
    }
    i = Arr1Size;
    Arr1Size = Arr2Size;
    Arr2Size = i;

    printf("\nFirst Array After Swapping => ");
    for (i = 0; i < Arr1Size; i++)
        printf("%d ", Arr1[i]);
    
    printf("\nSecond Array After Swapping => ");
    for (i = 0; i < Arr2Size; i++)
        printf("%d ", Arr2[i]);

    return 0;
}