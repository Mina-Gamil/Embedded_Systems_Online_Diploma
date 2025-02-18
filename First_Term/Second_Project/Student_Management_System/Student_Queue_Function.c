/**
 **********************************************************
 @file           : Student_Queue_Function.c
 @date           : Feb 10, 2025
 @author         : Mina Gamil
 @brief          : C program for student functions 
 **********************************************************
 */


#include "Student_Queue_Function.h"

// Define Needed Macros - Buffer top
#define buffer_top  (FIFO_Buf->base + ((FIFO_Buf->length - (unsigned int) 1) * sizeof(Element_Type)))

/* Declare Used Variable*/
int i, j;

                                        /** FIFO Initialization API **/
Buffer_STATUS FIFO_Init(FIFO_Buf_t* Fifo_Buf, Element_Type* Buf, unsigned int len)
{
    if(!Buf)
    {
        return FIFO_Is_Null;
    }
    else
    {
        Fifo_Buf->length = len;
        Fifo_Buf->count = 0;
        Fifo_Buf->base = Buf;
        Fifo_Buf->head = Buf;
        Fifo_Buf->tail = Buf;

        return FIFO_No_Error;
    }
}

                                        /** Add Student Manually **/
Buffer_STATUS Add_Student_Manually(FIFO_Buf_t* FIFO_Buf)
{
    int temp;

    if(List_Status(FIFO_Buf) != FIFO_No_Error && List_Status(FIFO_Buf) != FIFO_Is_Empty)
    {
        return List_Status(FIFO_Buf);
    }
    else
    {
        Message(Add Student Details);
        printf("\t| Enter Student Roll Number : ");
        scanf("%d", &temp);
        if (Check_Roll_Number(FIFO_Buf, temp) != NULL)
        {
            Error("Roll Number %d is already taken \n", temp);
            return error;
        }
        else 
        {
            FIFO_Buf->head->rollNumber = temp;
        }

        printf("\t| Enter Student First Name : ");
        scanf("%s", FIFO_Buf->head->fName);

        printf("\t| Enter Student Second Name : ");
        scanf("%s", FIFO_Buf->head->sName);

        printf("\t| Enter GPA obtained : ");
        scanf("%f", &FIFO_Buf->head->GPA);

        printf("\t| Enter Course ID For Each Course : \n");
        printf("\t| ------------------------- \n");
        for (i = 0; i < 5; i++)
        {
            printf("\t\t| Course %d ID : ", i + 1);
            scanf("%d", &temp);
            while (Check_Course_ID(FIFO_Buf, temp) == 1)
            {
                Error("This Course ID Already Chosen \n");
                printf("\t\t| Course %d ID : ", i + 1);
                scanf("%d", &temp);
            }
            FIFO_Buf->head->course_ID[i] = temp;
        }
        
        FIFO_Buf->count++;
        if (FIFO_Buf->head == buffer_top) {FIFO_Buf->head = FIFO_Buf->base;}
        else { FIFO_Buf->head++;}

        printf("----------------------------------- \n");
        Info("Student Details is Added Successfully \n");
        printf("----------------------------------- \n");
        Count_Student(FIFO_Buf);

        return Student_Added;
    }
}

                                        /** Add Student From File **/
Buffer_STATUS Add_Student_From_File(FIFO_Buf_t* FIFO_Buf)
{
    FILE* fptr = fopen("Student.txt", "r");
    int temp;

    if(List_Status(FIFO_Buf) != FIFO_No_Error && List_Status(FIFO_Buf) != FIFO_Is_Empty)
    {
        return List_Status(FIFO_Buf);
    }
    else
    {
        while (!feof(fptr))
        {
            fscanf(fptr,"%d", &temp);
            if (Check_Roll_Number(FIFO_Buf, temp) != NULL)
            {
                Error("Roll Number %d is already taken \n", temp);
                fscanf(fptr,"%*s %*s %*f %*d %*d %*d %*d %*d");
            }
            else 
            {
                FIFO_Buf->head->rollNumber = temp;
                fscanf(fptr,"%s", FIFO_Buf->head->fName);
                fscanf(fptr,"%s", FIFO_Buf->head->sName);
                fscanf(fptr,"%f", &FIFO_Buf->head->GPA);
                for (i = 0; i < 5; i++)
                {
                    fscanf(fptr, "%d", &FIFO_Buf->head->course_ID[i]);
                }
                Info("Roll Number %d saved successfully\n", FIFO_Buf->head->rollNumber);
                FIFO_Buf->count++;
                if (FIFO_Buf->head == buffer_top) {FIFO_Buf->head = FIFO_Buf->base;}
                else { FIFO_Buf->head++;}
            }
        }
        fclose(fptr);
        printf("----------------------------------- \n");
        Info("Students Details Added Successfully.\n");
        printf("----------------------------------- \n");
        Count_Student(FIFO_Buf);

        return Student_Added;
    }
}

                                        /** Find Student Using Roll Numbr **/
Buffer_STATUS Find_Student_By_RollNumber(FIFO_Buf_t* FIFO_Buf)
{
    int temp;
    Element_Type* temp_ptr;

    if(List_Status(FIFO_Buf) != FIFO_No_Error && List_Status(FIFO_Buf) != FIFO_Is_Full)
    {
        return List_Status(FIFO_Buf);
    }
    else
    {
        printf("----------------------------------- \n");
        printf("Enter Student Roll Number : ");
        scanf("%d", &temp);
    
        temp_ptr = Check_Roll_Number(FIFO_Buf, temp);

        if (temp_ptr)
        {
            printf("----------------------------------- \n");
            printf("Student Roll Number %d Details :-\n", temp);
            printf("----------------------------------- \n");
            print_One_Student(temp_ptr);
            printf("----------------------------------- \n");
            return FIFO_No_Error;
        }

        Error("Roll Number %d Not Found. \n", temp);
        return Student_Not_Found;
    }
}

                                        /** Find Student Using First Name **/
Buffer_STATUS Find_Student_By_FirstName(FIFO_Buf_t* FIFO_Buf)
{
    char temp_Name[30];
    int flag = 0;
    int temp_count = 0;
    Element_Type* temp_ptr;

    if(List_Status(FIFO_Buf) != FIFO_No_Error && List_Status(FIFO_Buf) != FIFO_Is_Full)
    {
        return List_Status(FIFO_Buf);
    }
    else
    {
        temp_ptr = FIFO_Buf->base;

        printf("----------------------------------- \n");
        printf("Enter Student First Name : ");
        scanf("%s", temp_Name);
        

        while (temp_count != FIFO_Buf->count)
        {
            if (strcmpi(temp_Name, temp_ptr->fName) == 0)
            {
                printf("----------------------------------- \n");
                printf("Student with First Name %s Details :-\n", temp_Name);
                printf("----------------------------------- \n");
                print_One_Student(temp_ptr);
                flag++;
            }
            temp_count++;
            temp_ptr++;
        }
        printf("----------------------------------- \n");
        if (flag == 0)
        {
            Error("No Student With First Name %s. \n", temp_Name);
            return Student_Not_Found;
        }
        else
        {
            return Student_Found;
        }  
    }
}

                                        /** Find Student Using Course ID **/
Buffer_STATUS Find_Student_By_CourseID(FIFO_Buf_t* FIFO_Buf)
{
    int temp, flag = 0;
    int temp_count = 0;
    Element_Type* temp_ptr;

    if(List_Status(FIFO_Buf) != FIFO_No_Error && List_Status(FIFO_Buf) != FIFO_Is_Full)
    {
        return List_Status(FIFO_Buf);
    }
    else
    {
        temp_ptr = FIFO_Buf->base;

        printf("----------------------------------- \n");
        printf("Enter Student Course ID : ");
        scanf("%d", &temp);
        printf("----------------------------------- \n");
        printf("Students Enroll Course ID %d Details :-\n", temp);
        printf("----------------------------------- \n");

        while (temp_count != FIFO_Buf->count)
        {
            for (i = 0; i < 5; i++)
            {
                if (temp == temp_ptr->course_ID[i])
                {
                    printf("\t| ------------------------- \n");
                    printf("\t| Student First Name  : %s\n", temp_ptr->fName);
                    printf("\t| Student Second Name : %s\n", temp_ptr->sName);
                    printf("\t| Student Roll Number : %d\n", temp_ptr->rollNumber);
                    printf("\t| Student GPA Number  : %.2f\n", temp_ptr->GPA);
                    flag++;
                }
            }
            temp_count++;
            temp_ptr++;
        }
        
        if (flag == 0)
        {
            Error("No Student Enrolled Course ID %d. \n", temp);
            return Student_Not_Found;
        }
        else
        {
            printf("----------------------------------- \n");
            return Student_Found;
        }
    }
}

                                        /** Find Total Number of Students **/
Buffer_STATUS Count_Student(FIFO_Buf_t* FIFO_Buf)
{
    if(List_Status(FIFO_Buf) != FIFO_No_Error && List_Status(FIFO_Buf) != FIFO_Is_Full)
    {
        return List_Status(FIFO_Buf);
    }
    else
    {
        Info("Total Number Of Student is %d \n", FIFO_Buf->count);
        Info("You Can Add Up To %d Students \n", FIFO_Buf->length);
        Info("You Can Add %d More Students \n", FIFO_Buf->length - FIFO_Buf->count);
        printf("----------------------------------- \n");
        return FIFO_No_Error;
    }
}

                                        /** Remove Student Using Roll Numbr **/
Buffer_STATUS Remove_Student_By_RollNumber(FIFO_Buf_t* FIFO_Buf)
{
    int temp;
    Element_Type* temp_ptr = NULL;
    Element_Type* Dest_ptr = NULL;

    if(List_Status(FIFO_Buf) != FIFO_No_Error && List_Status(FIFO_Buf) != FIFO_Is_Full)
    {
        return List_Status(FIFO_Buf);
    }
    else
    {
        printf("----------------------------------- \n");
        printf("Enter Student Roll Number to Delete: ");
        scanf("%d", &temp);

        Dest_ptr = Check_Roll_Number(FIFO_Buf, temp);
        temp_ptr = Dest_ptr;

        if (!Dest_ptr)
        {
            Error("Student Roll Number %d Not Found\n", temp);
            return Student_Not_Found;
        }
        else
        {
            struct sinfo Zero;
            while (temp_ptr != FIFO_Buf->head)
            {
                temp_ptr++;
                *(Dest_ptr) = *(temp_ptr);
                *(temp_ptr) = Zero;
                Dest_ptr++;
            }
            printf("----------------------------------- \n");
            Info("Student Roll Number %d Removed Successfully.\n", temp);
            printf("----------------------------------- \n");
            FIFO_Buf->count--;
            FIFO_Buf->head--;
            return Student_Removed;
        } 
    }
}

                                        /** update Student Using Roll Numbr **/
Buffer_STATUS Update_Student_By_RollNumber(FIFO_Buf_t* FIFO_Buf)
{
    int temp,choice;
    Element_Type* temp_ptr = NULL;

    if(List_Status(FIFO_Buf) != FIFO_No_Error && List_Status(FIFO_Buf) != FIFO_Is_Full)
    {
        return List_Status(FIFO_Buf);
    }
    else
    {
        printf("----------------------------------- \n");
        printf("Enter Student Roll Number To Update : ");
        scanf("%d", &temp);

        temp_ptr = Check_Roll_Number(FIFO_Buf, temp);

        if(!temp_ptr)
        {
            Error("Student Roll Number %d Not Found\n", temp);
            return Student_Not_Found;
        }
        else
        {
            printf("----------------------- \n");
            printf("1. First Name.\n");
            printf("2. Second Name.\n");
            printf("3. Roll Number.\n");
            printf("4. GPA Number.\n");
            printf("5. Courses ID.\n");
            printf("Choose option to update : ");
            scanf("%d", &choice);
            printf("----------------------------------- \n");

            switch (choice)
            {
            case 1:
                printf("Enter New First Name : ");
                scanf("%s", temp_ptr->fName);
                break;
            
            case 2:
                printf("Enter New Second Name : ");
                scanf("%s", temp_ptr->sName);
                break;

            case 3:
                printf("Enter New Roll Number : ");
                scanf("%d", &temp);
                if(Check_Roll_Number(FIFO_Buf, temp) == NULL)
                {
                    temp_ptr->rollNumber = temp;
                }
                else
                {
                    Error("Roll Number %d is already taken \n", temp);
                    return error;
                }
                break;

            case 4:
                printf("Enter New GPA Number : ");
                scanf("%f", &temp_ptr->GPA);
                break;

            case 5:
                printf("\t Course 1 ID.\n");
                printf("\t Course 2 ID.\n");
                printf("\t Course 3 ID.\n");
                printf("\t Course 4 ID.\n");
                printf("\t Course 5 ID.\n");
                printf("\tChoose Course to update : ");
                scanf("%d", &temp);
                printf("Enter New Course %d ID : ", temp);
                scanf("%d", &temp_ptr->course_ID[temp-1]);
                break;

            default:
                break;
            }
            printf("----------------------------------- \n");
            Info("\tUPDATED SUCCESSFULLY!\n");
            printf("----------------------------------- \n");
        }
    }
}

                                        /** Print All Students Details **/
Buffer_STATUS Print_All_Details(FIFO_Buf_t* FIFO_Buf)
{
    Element_Type* temp_ptr;
    unsigned int temp_Count = 0;

    if(List_Status(FIFO_Buf) != FIFO_No_Error && List_Status(FIFO_Buf) != FIFO_Is_Full)
    {
        return List_Status(FIFO_Buf);
    }
    else
    {
        printf("----------------------------------- \n");
        temp_ptr = FIFO_Buf->base;
        while (temp_Count != FIFO_Buf->count)
        {
            printf("\t| ------------------------- \n");
            printf("\t| Student First Name  is %s\n", temp_ptr->fName);
            printf("\t| Student Second Name is %s\n", temp_ptr->sName);
            printf("\t| Student Roll Number is %d\n", temp_ptr->rollNumber);
            printf("\t| Student GPA Number  is %.2f\n", temp_ptr->GPA);
            for (i = 0; i < 5; i++)
            {
                printf("\t  | Student Course %d ID is %d \n", i + 1, temp_ptr->course_ID[i]);
            }
            temp_Count++;
            temp_ptr++;
        }
        printf("----------------------------------- \n");
        return FIFO_No_Error;
    }
}

                                        /** print Student API **/
void print_One_Student(Element_Type* Current_Head)
{
    Element_Type* temp_ptr = Current_Head;

    printf("\t| ------------------------- \n");
    printf("\t| Student First Name  : %s\n", temp_ptr->fName);
    printf("\t| Student Second Name : %s\n", temp_ptr->sName);
    printf("\t| Student Roll Number : %d\n", temp_ptr->rollNumber);
    printf("\t| Student GPA Number  : %.2f\n", temp_ptr->GPA);
    for (i = 0; i < 5; i++)
    {
        printf("\t  | Student Course %d ID %d \n", i + 1, temp_ptr->course_ID[i]);
    }
}

                                        /** Check Student Roll Numbr API **/
Element_Type* Check_Roll_Number(FIFO_Buf_t* FIFO_Buf, int rollNumber)
{
    Element_Type* Temp_pointer = FIFO_Buf->base;
    for (i = 0; i < (int)FIFO_Buf->count; i++)
    {
        if (rollNumber == Temp_pointer->rollNumber)
        {
            return Temp_pointer;
        }
        Temp_pointer++;
    }
    return NULL;
}

                                        /** Check Student Course ID API **/
int Check_Course_ID(FIFO_Buf_t* FIFO_Buf, int ID)
{
    for(j = 0; j < 5; j++)
    {
        if (FIFO_Buf->head->course_ID[j] == ID)
        {
            return 1;
        }
    }
    return 0;
}

                                        /** Check Student List Status   API **/
Buffer_STATUS List_Status(FIFO_Buf_t* FIFO_Buf)
{
    if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
    {
        return FIFO_Is_Null;
    }
    else if (FIFO_Buf->count == FIFO_Buf->length)
    {
        return FIFO_Is_Full;
    }
    else if (FIFO_Buf->count == 0)
    {
        return FIFO_Is_Empty;
    }
    else
    {
        return FIFO_No_Error;
    }
}
