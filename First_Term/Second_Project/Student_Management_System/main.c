/**
 **********************************************************
 @file           : main.c
 @date           : Feb 9, 2025
 @author         : Mina Gamil
 @brief          : main program for student data structure 
 **********************************************************
 */

#include <stdio.h>
#include "Student_Queue_Function.h"

FIFO_Buf_t Students_Buf;
Element_Type Students[60];
Buffer_STATUS state;

int main(void)
{
    FIFO_Init(&Students_Buf, Students, 50);
    int choice;
    printf("\n\t *** Welcome To Student Management System *** \n");
    printf("\t     ------------------------------------     \n");

    while (1)
    {
        printf("Choose The Task You Want To Perform \n");
        printf("----------------------------------- \n");
        printf("1. Add Student Details Manually. \n");
        printf("2. Add Student Details From Text File. \n");
        printf("3. Find Student Details By Roll Number. \n");
        printf("4. Find Student Details By First Name. \n");
        printf("5. Find Student Details By Course ID. \n");
        printf("6. Find Total Number Of Student. \n");
        printf("7. Delete Student Details By Roll Number. \n");
        printf("8. Update Student Details By Roll Number. \n");
        printf("9. Show All Students Details. \n");
        printf("10. Exit. \n");
        printf("----------------------------------- \n");
        printf("Please Enter Your Choice To Perform The Task: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            state = Add_Student_Manually(&Students_Buf);
            break;

        case 2:
            state = Add_Student_From_File(&Students_Buf);
            break;

        case 3:
            state = Find_Student_By_RollNumber(&Students_Buf);
            break;

        case 4:
            state = Find_Student_By_FirstName(&Students_Buf);
            break;

        case 5:
            state = Find_Student_By_CourseID(&Students_Buf);
            break;

        case 6:
            printf("----------------------------------- \n");
            state = Count_Student(&Students_Buf);
            break;

        case 7:
            state = Remove_Student_By_RollNumber(&Students_Buf);
            break;

        case 8:
            state = Update_Student_By_RollNumber(&Students_Buf);
            break;

        case 9:
            state = Print_All_Details(&Students_Buf);
            break;

        case 10:
            exit(0);
            break;
        
        default:
            break;
        }

        if (state == FIFO_Is_Null)
        {
            Message(Student list not exist);
        }
        else if (state == FIFO_Is_Full)
        {
            Message(Student list is Full);
        }
        else if (state == FIFO_Is_Empty)
        {
            Message(Student list is Empty);
        }
    }
    return 0;
}