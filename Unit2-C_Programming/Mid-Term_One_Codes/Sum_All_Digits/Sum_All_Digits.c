/*
 --------------------------------------------------------------------
 Name        : Sum_All_Digits.c
 Author      : Mina Gamil
 Created On  : Nov 18, 2024
 Description : C Program to take number from user and Sum all digits
---------------------------------------------------------------------
 */
 
 #include <stdio.h>

void SumAllDigits(int n);

 int main(void)
 {
    // Declare used integers 
    int num;

    // Ask User to enter number and Store the number in Variable num 
    printf("Please Enter Number :");
    scanf("%d", &num);

    // Call Sum Function 
    SumAllDigits(num);

    return 0;
 }

 void SumAllDigits(int n)
 {
    int sum = 0;
    do
    {
        sum += n % 10;
        n = n / 10;
        
    } while (n != 0);
    printf("Sum Of Digits : %d", sum);
 }