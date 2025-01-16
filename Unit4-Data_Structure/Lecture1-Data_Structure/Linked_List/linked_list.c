/**
 **************************************************
 * @file       : linked_list.c
 * @author     : Mina Gamil
 * @date       : Jan 13, 2025
 * @brief      : c program for student linked list 
 **************************************************
 */

/***** Included Nedded Libraries *****/
#include "linked_list.h"

struct SStudent* gpFirstStudent = NULL;                                                   // create global pointer to point to the first student in the list "head of the list" 

										/***** Fetch Data and Fill New Student to linked list Function *****/
void Fill_Data(struct SStudent* pStudent)
{
	char temp[40];                                                                        // Declare char array to store all fetched data 	
	printf("Enter Student ID        : ");                                                 // Ask User For New Student ID 
	pStudent->Student.ID = atoi(gets(temp));                                              // Fetch data and assign it to New student ID 
	printf("Enter Student Full Name : ");                                                 // Ask User For New Student Name 
	gets(pStudent->Student.Name);                                                         // Fetch Data from User directly to new student name 
	printf("Enter Student Height    : ");                                                 // Ask User For New Student Height 
	pStudent->Student.Height = atof(gets(temp));                                          // Fetch data and assign it to new student height
}

										/***** Add New Student to linked list API *****/
Student_STATUS Add_Student()
{
	struct SStudent* pLastStudent = NULL;                                                 // Create pointer to check last student 
	struct SStudent* pNewStudent = NULL;                                                  // Create pointer to point to the new student 

	if(!gpFirstStudent)                                                                   // Check if the head of list point to any address 
	{                                                                                     // if yes we will create new student and assign the pointer to it 
		pNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));                 // using malloc to create new student 
		gpFirstStudent = pNewStudent;                                                     // point the head of list to first student
	}
	else
	{                                                                                     // if now we will loop to find the last student
		pLastStudent = gpFirstStudent;                                                    // first assign list head to the last student pointer 
		while(pLastStudent->pNextStudent)                                                 // then start looping until find the student have null in the next student pointer 
			pLastStudent = pLastStudent->pNextStudent;                                    // assign next student pointer to last student pointer to find the last student 
		pNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));                 // using malloc to create new student 
		pLastStudent->pNextStudent = pNewStudent;                                         // assign the address of new student to the next pointer of the last student
	}
	Fill_Data(pNewStudent);                                                               // fill data entered by user to the new student
	pNewStudent->pNextStudent = NULL;                                                     // Assign new student , pNextStudent pointer to NULL

	return Added;                                                                         // return student status Adding done
}

										/***** Delete Student from linked list API *****/
Student_STATUS Delete_Student()
{
	if(gpFirstStudent)                                                                    // if gpFirstStudent point to address mean that list is existing 
	{
		char temp[10];                                                                    // Declare temp string to store Student ID
		int Selected_ID;                                                                  // Declare Selected_ID to store student ID to be deleted
		printf("Please Enter Student ID To Be Deleted: ");                                // Ask user to enter student ID to be deleted
		gets(temp);                                                                       // Get the answer from user
		Selected_ID = atoi(temp);                                                         // Convert string to integer using atoi feature
		struct SStudent* pCurrent_Student = gpFirstStudent;                               // Create Current pointer to point to the current student and assign it to first student
		struct SStudent* pPrevious_Student = NULL;                                        // Create Previous pointer to point to the previous student
		
		while(pCurrent_Student)                                                           // loop till the end of the list 
		{
			if(pCurrent_Student->Student.ID == Selected_ID)                               // check if current student ID is the Selected one
			{                                                                             // if both ID are the same we need to check the previous student 
				if(!pPrevious_Student)                                                    // if there is no previous student that mean selected ID is the first ID 
					gpFirstStudent = pCurrent_Student->pNextStudent;                      // So we will assign gpFirstStudent pointer to the second element directly 
				else                                                                      // if there is previous student that mean Selected ID to the first student
					pPrevious_Student->pNextStudent = pCurrent_Student->pNextStudent;     // So we will assign nextstudent pointer current student to nextstudent pointer of previous student 

				free(pCurrent_Student);                                                   // then we free the memory allocated before 
				return Deleted;                                                           // return Deleted which mean that the student deleted
			}                                                                             // if surrent student ID is not the Selected one 
			pPrevious_Student = pCurrent_Student;                                         // assign current student pointer to previous student pointer 
			pCurrent_Student = pCurrent_Student->pNextStudent;                            // and assign current-NextStudent to current student and continue looping
		}                                                                                 // if we finish looping and cannot find the Selected ID in the list  
		return Not_Found;                                                                 // so we return Not_Found that mean Selected ID not found in the list 
	}
	else                                                                                  // if gpFirstStudent is equal NULL that mean there is no list 
		return Empty_List;                                                                // So we return Empty_List 
}

										/***** Delete All Students from linked list API *****/
Student_STATUS Delete_All()
{
	if(gpFirstStudent)                                                                    // if gpFirstStudent point to address mean that list is existing 
	{
		struct SStudent* pSelected = NULL;                                                // Create pSelected pointer to select to the student to be deleted
		while(gpFirstStudent)                                                             // looping till we reach the last student 
		{
			pSelected = gpFirstStudent;                                                   // assign gpFirstStudent to pSelected
			gpFirstStudent = pSelected->pNextStudent;                                     // assign next student to gpFirstStudent
			free(pSelected);                                                              // free allocated memory pointed by pSelected
		}
		return Deleted;                                                                   // once we finished send Deleted to announce that process Success
	}
	else                                                                                  // if gpFirstStudent is equal NULL that mean there is no list 
		return Empty_List;                                                                // So we return Empty_List 
		
}
										/***** View One Students from linked list API *****/
Student_STATUS View_Student_By_ID()
{	
	if(gpFirstStudent)                                                                    // if gpFirstStudent point to address mean that list is existing 
	{
		char temp[10];                                                                    // Delare temp string to store Student ID
		int Selected_ID;                                                                  // Declare Selected_ID to store student ID to be deleted
		printf("Please Enter Student ID To Show Data: ");                                 // Ask user to enter student ID to be deleted
		gets(temp);                                                                       // Get the answer from user 
		Selected_ID = atoi(temp);                                                         // Convert string to integer using atoi feature
		struct SStudent* pSelected = gpFirstStudent;                                      // Create Selected pointer assign to it, first student    
		
		while(pSelected)                                                                  // Looping till find the selected ID student
		{
			if(pSelected->Student.ID == Selected_ID)                                      // check if Selected ID equal to pSelected student
			{                                                                             // if yes print all data of the student
				printf("--------------------------------------\n");
				printf("\t** Info Student ID: %d **\n", Selected_ID);
				printf("Student ID     : %d\n", pSelected->Student.ID);
				printf("Student Name   : %s\n", pSelected->Student.Name);
				printf("Student Height : %.2f\n", pSelected->Student.Height);
				printf("\t---------------------\n");
				return Viewed;                                                            // and return viewed to announce that process Done Successfully
			}
			pSelected = pSelected->pNextStudent;                                          // if not find assign pSelected pointer to the next student
		}                                                                                 // if loop finished and Selected ID not found
		return Not_Found;                                                                 // Return Not_Found to announce that student ID not found in list
	}
	else                                                                                  // if gpFirstStudent is NULL that announce there is no list
		return Empty_List;                                                                // So return Empty_List
}
										/***** View All Students from linked list API *****/
Student_STATUS View_Students()
{
	if(gpFirstStudent)
	{
		int Record_No = 1;                                                                // Declare Record_No and declare it to 1
		struct SStudent* pCurrent_Student = gpFirstStudent;                               // Create pointer Current student and assign first student pointer to it
	
		while(pCurrent_Student)                                                           // looping till the end of the list printing all students data
		{
			printf("\t Record Number %d\n", Record_No);
			printf("Student ID     : %d\n", pCurrent_Student->Student.ID);
			printf("Student Name   : %s\n", pCurrent_Student->Student.Name);
			printf("Student Height : %.2f\n", pCurrent_Student->Student.Height);
			printf("\t---------------------\n");

			pCurrent_Student = pCurrent_Student->pNextStudent;                            // Assign next student address to current student pointer
			Record_No++;                                                                  // Increment Record_No
		}
		return Viewed;                                                                    // if viewed to announce that all data printed successfully
	}
	else                                                                                  // else if gpFirstStudent is NULL , announce that there is no list
		return Empty_List;                                                                // so return Empty_List
}

										/***** Find Student By Index from linked list API *****/
Student_STATUS Find_By_Index()
{
	if(gpFirstStudent)                                                                    // Check if the list is existing or there is no list 
	{                                                                                     // if list is existing will execute the following 
		int index, count = 0;                                                             // Declare and initialize to zero index counter , and index variable to hold index 
		char temp[10];                                                                    // Declare temp array to hold user data entered 
		struct SStudent* pSelected = gpFirstStudent;                                      // Declare local pointer and assign it to gpFirstStudent to use it in looping 
		printf("Please Enter Student Index: ");                                           // Ask user for Student index 
		index = atoi(gets(temp));                                                         // take data from user and conver it to integer and assign it to index
		
		while(pSelected)                                                                  // looping till the end of the list 
		{
			if(count == index)                                                            // Check if Current index is equal to required index 
			{                                                                             // if yes print student data 
				printf("\t---------------------\n");
				printf("\t** Student Index No.: %d **\n", index);
				printf("Student ID     : %d\n", pSelected->Student.ID);
				printf("Student Name   : %s\n", pSelected->Student.Name);
				printf("Student Height : %.2f\n", pSelected->Student.Height);
				printf("\t---------------------\n");
				return Viewed;                                                            // and return viewed to indicate that student found and printed
			}
			pSelected = pSelected->pNextStudent;                                          // Assign pSelected to the next student address
			count++;                                                                      // increment count 
		}
		return Not_Found;	                                                              // if loop finished and not found the index return not found  
	}
	else                                                                                  // if there is no list existing 
		return Empty_List;                                                                // return Empty list        
}

										/***** Find Lenght of linked list Using Recursive API *****/
int Find_List_Lenght(struct SStudent* first_Student)
{
	struct SStudent* Head = first_Student;                                                // Create Head pointer and assign it to first student
	if(!Head)                                                                             // if we Reach the end of the list return 0
		return 0;                                                                      
	else                                                                                  // Else we will send 1 + Check the second address 
		return 1 + Find_List_Lenght(Head->pNextStudent);	
}

										/***** Find Student from The End of Linked List API *****/
Student_STATUS Find_From_End()
{
	if(gpFirstStudent)                                                                    // Check if the list is existing 
	{
		char temp[10];
		int Index_From_End;                                                               // Create int variable to hold Index Number 
		struct SStudent* main = gpFirstStudent;                                           // Declare main pointer and assign it to first student 
		struct SStudent* ref = gpFirstStudent;                                            // Declare reference pointer and assign it to first student
		printf("Please Enter No. Of Index form the end: ");                               // Ask user for input the number of needed index
		Index_From_End = atoi(gets(temp));                                                // get the input from User
		while(ref)                                                                        // Start Looping till the end of the list 
		{
			if(!Index_From_End)
			{
				main = main->pNextStudent;                                                // Assign main to next student 
				ref = ref->pNextStudent;                                                  // Assign reference to next student 
			}
			else
			{
				ref = ref->pNextStudent;                                                  // Assign main to next student till Index_From_End = 0
				Index_From_End--;                                                         // Decrement Index_From_End
			}
		}
		printf("\t Student Number: %d From the End\n", atoi(temp));
		printf("Student ID     : %d\n", main->Student.ID);
		printf("Student Name   : %s\n", main->Student.Name);
		printf("Student Height : %.2f\n", main->Student.Height);
		printf("\t---------------------\n");
		return Viewed;                                                                    // if viewed to announce that all data printed successfully
	}
	else                                                                                  // if there is no list existing 
		return Empty_List;                                                                // return Empty list
}

										/***** Find Middle Student of Linked List API *****/
Student_STATUS Find_Middle_Student()
{
	if(gpFirstStudent)                                                                    // Check if the list is existing 
	{
		int number = 1;                                                                   // Declare number index the student 
		struct SStudent* faster = gpFirstStudent;                                         // Declare faster pointer and assign it to gpFirstStudent
		struct SStudent* slower = gpFirstStudent;                                         // Declare Slower pointer and assign it to gpFirstStudent
		
		while(faster && faster->pNextStudent)
		{
			faster = faster->pNextStudent->pNextStudent;                                  // assign the next of next student to faster 
			slower = slower->pNextStudent;                                                // assign the next student 
			number++;                                                                     // increment number 
		}
		printf("\tStudent Number: %d, is the middle student\n", number);
		printf("Student ID     : %d\n", slower->Student.ID);
		printf("Student Name   : %s\n", slower->Student.Name);
		printf("Student Height : %.2f\n", slower->Student.Height);
		printf("\t---------------------\n");
		return Viewed;  
	}
	else                                                                                  // if there is no list existing 
		return Empty_List;                                                                // return Empty list
}

										/***** Check if the list is looped API *****/
Student_STATUS Is_Looped()
{
	if(gpFirstStudent)                                                                    // Check if list is existing
	{
		struct SStudent* faster = gpFirstStudent;                                         // Declare faster pointer and assign it to gpFirstStudent
		struct SStudent* slower = gpFirstStudent;                                         // Declare Slower pointer and assign it to gpFirstStudent
		
		while(faster && faster->pNextStudent)
		{
			faster = faster->pNextStudent->pNextStudent;                                  // assign the next of next student to faster 
			slower = slower->pNextStudent;                                                // assign the next student 
			if(slower == faster)                                                          // if slower equal to faster then 
				return Found;                                                             // print not found to indicate that the list is looped 
		}
		return Not_Found;                                                                 // if looping finished and not found loop , then print not found means no loop
	}
	else                                                                                  // if there is no list existing 
		return Empty_List;                                                                // return Empty list
}

										/***** Reverse The Student List API *****/
Student_STATUS Reverse_List()
{
	if(gpFirstStudent)
	{
		struct SStudent* pCurrent = gpFirstStudent;                                       // current pointer point to the current student 
		struct SStudent* pNext = NULL;                                                    // Next pointer point to the next student  and assign it to NULL
		struct SStudent* pPrevious = NULL;                                                // previous pointer point to the previous student and assign it to NULL
		
		while(pCurrent)                                                                   // loop till current student reach the end of the list 
		{
			pNext = pCurrent->pNextStudent;                                               // Assign Next pointer to next student address 
			pCurrent->pNextStudent = pPrevious;                                           // Assign Next student pointer of current student to previous student			
			pPrevious = pCurrent;                                                         // Assign Current Student to Previous student 
			pCurrent = pNext;                                                             // Assign next student to Current student 
		}
		gpFirstStudent = pPrevious;                                                       // Assign previous Student to the head of the list 
		return Done;                                                                      // Return Done 
	} 
	else                                                                                  // if there is no list existing 
		return Empty_List;                                                                // return Empty list	
	
}
