/**
 *****************************
 * @file      : linked_list.h
 * @author    : Mina Gamil
 * @date      : Jan 13, 2025
 *****************************
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

/***** Included Nedded Libraries *****/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <conio.h>

// typedef enum Student_STATUS to follow up the process
typedef enum
{
	Not_Found,
	Found,
	Done,
	Deleted,
	Added,
	Viewed,
	Empty_List
}Student_STATUS;

// Struct Sdata fo store Student data 
struct Sdata
{
	int ID;
	char Name[40];
	float Height;
};

// struct SStudent is the node of the dynamic list 
struct SStudent
{
	struct Sdata Student;
	struct SStudent* pNextStudent;
};


/** Linked List API'S **/
Student_STATUS Add_Student();
Student_STATUS Delete_Student();
Student_STATUS Delete_All();
Student_STATUS View_Student_By_ID();
Student_STATUS View_Students();
Student_STATUS Find_By_Index();
int Find_List_Lenght(struct SStudent* first_Student);
Student_STATUS Find_From_End();
Student_STATUS Find_Middle_Student();
Student_STATUS Is_Looped();
Student_STATUS Reverse_List();

#endif /* LINKED_LIST_H_ */
