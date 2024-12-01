/*
---------------------------------------------------------------------------------------------
Name        : Ex1-Store_Student_Using_Struct_General.c
Author      : Mina Gamil
Created On  : 30 Nov 2024
Description : C Program To Store Student Data Entered By User Using Structure for any student
---------------------------------------------------------------------------------------------
*/

#include <stdio.h>

// Define Srtuct Sperson
struct Sperson
{
    char name[50];
    int roll;
    float marks;
};

struct Sperson Store_Student_Using_Struct();
void Print_Student_Data(struct Sperson Student);

int main(void)
{
    struct Sperson Student;
    Student = Store_Student_Using_Struct();
    Print_Student_Data(Student);

    return 0;
}


struct Sperson Store_Student_Using_Struct()
{
    // Declare Student Struct 
    struct Sperson Student;

    printf("Enter Information Of Students: \n");

    // Ask and Store Name 
    printf("Enter Name: ");
    scanf("%s", Student.name);

    // Ask and Store roll
    printf("Enter Roll: ");
    scanf("%d", &Student.roll);

    // Ask and Store Marks
    printf("Enter Mark: ");
    scanf("%f", &Student.marks);

    return Student;
}

void Print_Student_Data(struct Sperson Student)
{

    printf("\nDisplaying Information:\n");

    printf("Name: %s\n", Student.name);
    printf("Roll: %d\n", Student.roll);
    printf("Marks: %.2f\n", Student.marks);
}