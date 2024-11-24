/*
 ---------------------------------------------------------------------------------
 Name        : Square_Root.c
 Author      : Mina Gamil
 Created On  : Nov 18, 2024
 Description : C Program to take number from user and calculate square root of it 
----------------------------------------------------------------------------------
 */
 
 #include <stdio.h>

float Square_Root(int n);

 int main(void)
 {
    // Declare used Variable 
    int num;
    float SQ;

    // Ask User To Enter Number And Store It 
    printf("Please Enter A Number :");
    scanf("%d", &num);

    // call Square_Root Function
    SQ = Square_Root(num);

    printf("Square Root Of %d = %.3f", num, SQ);

    return 0;
 }

 float Square_Root(int n)
 {
    // Declare Used Variable 
    float answer = n / 2, temp = 0;

    // Find the Square Root 
    while (answer != temp)
    {
        temp = answer;
        answer = (n / temp + temp) / 2;   
    }
    return answer;
 }