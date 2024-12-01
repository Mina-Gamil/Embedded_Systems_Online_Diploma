/*
------------------------------------------------------------------
Name        : Ex2-Add_Two_Distances_Using_Struct.c
Author      : Mina Gamil
Created On  : 1 Dec 2024
Description : Program to add 2 Distances in Feet-inch using Struct
------------------------------------------------------------------ 
*/

#include <stdio.h>

struct Sdistance
{
	int feet;
	float inch;
	
};

struct Sdistance Sask_Distance_From_User(char display[]);
struct Sdistance Sadd_Distance(struct Sdistance Distance_1, struct Sdistance Distance_2);


int main(void)
{
    // Declare 2 Struct 
    struct Sdistance Distance_1,Distance_2, Result;

    // Ask User For 1st Distance
    Distance_1 = Sask_Distance_From_User("Enter Information For 1st Distance");

    // Ask User For 2nd Distance
    Distance_2 = Sask_Distance_From_User("Enter Information For 2nd Distance");

    // Add Distance Together
    Result = Sadd_Distance(Distance_1,Distance_2);

    // Print Result 
    printf("Sum Of Distances %d' - %.1f\"\n", Result.feet, Result.inch);

    return 0;
}


struct Sdistance Sask_Distance_From_User(char display[])
{
	// Declare Distance Struct
	struct Sdistance Distance;

	// Ask For Distance
	printf("%s\n", display);

	// Ask For Feet
	printf("Enter Feet: ");
	scanf("%d", &Distance.feet);

	// Ask For Inch
	printf("Enter inch: ");
	scanf("%f", &Distance.inch);
	printf("\n");

	return Distance;
}


struct Sdistance Sadd_Distance(struct Sdistance Distance_1, struct Sdistance Distance_2)
{
	// Declare Result Struct
	struct Sdistance Result;

	// Add Feet And Inch
	Result.feet = Distance_1.feet + Distance_2.feet;
	Result.inch = Distance_1.inch + Distance_2.inch;

	// Check if Inches more than 12 ==> 1 feet = 12 inches 
	if (Result.inch >= 12)
	{
		Result.feet++;
		Result.inch -= 12;
	}

	return Result;
}