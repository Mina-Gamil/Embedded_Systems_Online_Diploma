#ifndef STUDENT_MANAGEMENT_SYSTEM_H_
#define STUDENT_MANAGEMENT_SYSTEM_H_

/** Include All Needed Libraries**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** Define Used Macros **/
#define Element_Type struct sinfo

#define Error(...)  	printf("----------------------------------- \n");\
						printf("| [ERROR] "__VA_ARGS__);\
						printf("----------------------------------- \n")

#define Info(...)       printf("[INFO] "__VA_ARGS__)

#define Message(...) 	printf("----------------------------------- \n");\
					    printf("%s \n",#__VA_ARGS__);\
				        printf("----------------------------------- \n")

struct sinfo
{
    char fName[30];
    char sName[30];
    int rollNumber;
    float GPA;
    int course_ID[5];
};

/** Define Typedef struct FIFO buffer**/
typedef struct
{
	unsigned int length;              // Buffer Length got from user
	unsigned int count;               // items counter init. to Zero
	Element_Type* base;               // pointer indicate to base address and never change
	Element_Type* head;               // pointer indicate to head where the data enqueue
	Element_Type* tail;               // pointer indicate to tail where the data dequeue
}FIFO_Buf_t;

typedef enum
{
	FIFO_No_Error,
	FIFO_Is_Full,
	FIFO_Is_Null,
	FIFO_Is_Empty,
	Student_Added,
	Student_Not_Found,
	Student_Found,
	Student_Removed,
	error
}Buffer_STATUS;

/** Students Queue API's **/
Buffer_STATUS FIFO_Init(FIFO_Buf_t* Fifo_Buf, Element_Type* Buf, unsigned int len);
Buffer_STATUS Add_Student_Manually(FIFO_Buf_t* FIFO_Buf);
Buffer_STATUS Add_Student_From_File(FIFO_Buf_t* FIFO_Buf);
Buffer_STATUS Find_Student_By_RollNumber(FIFO_Buf_t* FIFO_Buf);
Buffer_STATUS Find_Student_By_FirstName(FIFO_Buf_t* FIFO_Buf);
Buffer_STATUS Find_Student_By_CourseID(FIFO_Buf_t* FIFO_Buf);
Buffer_STATUS Count_Student(FIFO_Buf_t* FIFO_Buf);
Buffer_STATUS Remove_Student_By_RollNumber(FIFO_Buf_t* FIFO_Buf);
Buffer_STATUS Update_Student_By_RollNumber(FIFO_Buf_t* FIFO_Buf);
Buffer_STATUS Print_All_Details(FIFO_Buf_t* FIFO_Buf);

/** Common API's **/
void print_One_Student(Element_Type* Current_Head);
Element_Type* Check_Roll_Number(FIFO_Buf_t* FIFO_Buf, int rollNumber);
int Check_Course_ID(FIFO_Buf_t* FIFO_Buf, int ID);
Buffer_STATUS List_Status(FIFO_Buf_t* FIFO_Buf);

#endif /*STUDENT_MANAGEMENT_SYSTEM_H_*/