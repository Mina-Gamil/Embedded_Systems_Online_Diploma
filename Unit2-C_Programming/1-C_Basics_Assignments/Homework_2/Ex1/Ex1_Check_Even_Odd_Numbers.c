/*
 =======================================================
 Name        : Ex1_Check_Even_Odd_Numbers.c
 Author      : Mina Gamil
 Created On  : Aug 24, 2024
 Description : Check A Number Entered By User Is Even Or Odd
 =======================================================
*/

#include <stdio.h>

int main(void)
{
    // declare integer to store data from user 
    int user_num;

    // Ask and Fetch Data From User
    printf ("Enter An Integer You Want To Check : ");
    scanf("%d", &user_num);

    // Check If The Number Is Even Or Odd
    if (user_num % 2 == 0) 
    {
        printf("%d Is Even\n", user_num);
    }
    else
    {
        printf("%d Is Odd\n", user_num);
    }
    

}