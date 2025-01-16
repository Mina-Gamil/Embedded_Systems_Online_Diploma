/**:
 *********************************************************************************
 * @file       : main.c
 * @author     : Mina Gamil
 * @date       : Jan 13, 2025
 * @brief      : C program to use school linked list to make school data structure
 *********************************************************************************
 */

/***** Included Nedded Libraries *****/
#include "linked_list.h"

/*** Define Macro for repeated part ***/
#define Result(...) 	printf("-------------------------------- \n");\
					    printf(__VA_ARGS__);\
				        printf("-------------------------------- \n\n");
						
/** Declare Needed Variables **/   
extern struct SStudent* gpFirstStudent;

/***** Main program body *****/
void main(void)
{
	char temp[10];                                                                       // Declare temp variable to store user chosen option 
	Student_STATUS Check;                                                                // Declare enum Check to store status of any process

	while(1)                                                                             // looping in infinite loop
	{                                                                                    // print all available options to user    
		printf("\t Choose from following operations \n");
		printf("\t -------------------------------- \n");	
		printf("1: Add Student\n");
		printf("2: Delete Student\n");
		printf("3: Delete All Students\n");
		printf("4: View One Student\n");
		printf("5: View All Student\n");
		printf("6: find Student by Index\n");
		printf("7: Find Student list Lenght\n");
		printf("8: Find Student from the End\n");
		printf("9: Find Middle Student\n");
		printf("10: Check The list is looped\n");
		printf("11: Reverse Student Linked list\n");
		printf("-------------------------------\n");
		printf("\nPlease Enter Option Number: ");

		gets(temp);                                                                      // fetch data from user
		printf("*****************************\n");                                       // check if user need new operation                           

		switch(atoi(temp))                                                               // switch case with user input to sun needed API
		{
			case 1:
				Check = Add_Student();
				if(Check == Added){                                                      // Check return value from function
					Result("|    ***** Adding Done *****   | \n")}                       // if yes print this sentence
				break;                                                                   // exit from switch condition
				                                                                         // and make the same for all the following cases
			case 2:
				Check = Delete_Student();
				if(Check == Deleted){
					Result("|    **** Deleting Done ****   | \n")}
				else if(Check == Not_Found){
					Result("|   *** Student Not Found ***  | \n")}
				else{
					Result("|   ** Empty Student List **   | \n")}
				break;
				
			case 3:
				Check = Delete_All();
				if(Check == Deleted){
					Result("|   *** Deleting All Done ***  | \n")}
				else{
					Result("|   ** Empty Student List **   | \n")}
				break;
				
			case 4:
				Check = View_Student_By_ID();
				if(Check == Viewed){
					Result("|* Done Printing Student Data *| \n")}
				else if(Check == Not_Found){
					Result("|   *** Student Not Found ***  | \n")}
				else{
					Result("|   ** Empty Student List **   | \n")}
				break;
				
			case 5:
				Check = View_Students();
				if(Check == Viewed){
					Result("|* Done Printing All Students *| \n")}
				else{             
					Result("|   ** Empty Student List **   | \n")}
				break;
				
			case 6:
				Check = Find_By_Index();
				if(Check == Viewed){
					Result("|* Done Printing Student Data *| \n")}
				else if (Check == Not_Found){
					Result("|  ** Index is Out of Range ** | \n")}
				else{
					Result("|   ** Empty Student List **   | \n")}
				break;
				
			case 7:
				Result("|  The Lenght Of List is : %d   |\n",Find_List_Lenght(gpFirstStudent))
				break;
				
			case 8:
				Check = Find_From_End();
				if(Check == Viewed){
					Result("|* Done Printing Student Data *| \n")}
				else{
					Result("|   ** Empty Student List **   | \n")}
				break;
				
			case 9:
				Check = Find_Middle_Student();
				if(Check == Viewed){
					Result("|* Done Printing Student Data *| \n")}
				else{
					Result("|   ** Empty Student List **   | \n")}
				break;
				
			case 10:
				Check = Is_Looped();
				if(Check == Found){
					Result("|  *** The list is looped ***  | \n")}
				else if (Check == Not_Found){
					Result("| ** The List in not Looped ** | \n")}
				else{
					Result("|   ** Empty Student List **   | \n")}
				break;
				
			case 11:
				Check = Reverse_List();
				if(Check == Done){
					Result("|*  Done Reverse Student Data *| \n")}
				else{
					Result("|   ** Empty Student List **   | \n")}
				break;
				
					
			default:                                                                     // if option not in given option run this part of code by default
				Result("|      *** Wrong Option ***    | \n");                           // print that option was wrong
				break;                                                                   // exit from switch condition and loop again
		}
	}
}
