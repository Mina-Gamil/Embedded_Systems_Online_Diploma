/*
-----------------------------------------------------------------------------------------------
Name        : Ex1-Store_Student_Using_Struct.c
Author      : Mina Gamil
Created On  : 30 Nov 2024
Description : C Program To Store Student Data Entered By User Using Structure for Global Struct
-----------------------------------------------------------------------------------------------
*/

#include <stdio.h>

struct Sperson
{
    char name[50];
    int roll;
    float marks;
} Student;

void Store_Student_Using_Struct();
void Print_Student_Data();

int main(void)
{
    Store_Student_Using_Struct();
    Print_Student_Data();

    return 0;
}


void Store_Student_Using_Struct()
{
    printf("Enter Information Of Students: \n");

    // Ask and Store Name 
    printf("Enter Name: ");
    scanf("%s", Student.name);

    // Ask and Store roll
    printf("Enter Roll Number: ");
    scanf("%d", &Student.roll);

    // Ask and Store Marks
    printf("Enter Mark: ");
    scanf("%f", &Student.marks);
}

void Print_Student_Data()
{
    printf("\nDisplaying Information:\n");

    printf("Name: %s\n",Student.name);
    printf("Roll: %d\n",Student.roll);
    printf("Marks: %.2f\n",Student.marks);
}