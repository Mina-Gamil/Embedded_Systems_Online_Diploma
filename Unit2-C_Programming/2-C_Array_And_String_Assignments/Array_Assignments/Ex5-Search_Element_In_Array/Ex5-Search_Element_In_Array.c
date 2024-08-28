/*
 =====================================================================
 Name        : Ex5-Search_Element_In_Array.c
 Author      : Mina Gamil
 Created On  : Aug 28, 2024
 Description : Searh Element Entered By User In Array Entered By User 
 =====================================================================
 */


#include <stdio.h>


int main(void)
{
    // declare Variables to be used 
    int array[100];
    int i, n, l, count;
    
    // Ask User To Enter Number Of Elements
    printf ("Enter Number Of Elements : ");
    scanf("%d", &count);

    // Scan Number Of Elements Entered By User
    for (i = 0; i < count; i++)
    {
        scanf("%d", &array[i]);
    }

    // Ask User To Enter Element to Search 
    printf("Enter The Element To Be Searched : ");
    scanf("%d", &n);

    // Search in Array 
    for (i = 0; i < count; i++)
    {
        if (array[i] == n)
        {
            l = i + 1;
        }
    }

    // Print Location of Element
    printf("Number Found At The Location = %d", l);
    return 0;    
}