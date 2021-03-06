// Week15_SofiaBadalova.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//student.txt looks like this..
//10001 john smith 1IT1 11 9 2017 14 6 1999  
//12345 mary burke 1IT1 12 9 2017 31 1 1999

FILE * openFile(char *fileName, char *mode);			//function declaration
void closeFile(FILE *fptr);


struct date						//data structures
{
	int day, month, year;
};
struct student
{
	int studentID;
	char firstName[20];
	char lastName[20];
	char courseID[10];
	int year;
	struct date registrationDate;
	struct date dateOfBirth;
	int averageGrade;
};

int main()
{
	int i;
	struct student records[2];
	FILE *ptr;
	int randNum;
	ptr = openFile("C://Users/Sofia/Documents/student.txt", "r");		//calls to open File

	for (i = 0; i < 2; i++) {			//scanf all info into data structure
		fscanf_s(ptr, "%d %s %s %s %d %d %d %d %d %d ", &records[i].studentID, records[i].firstName, 20, records[i].lastName, 20,
			records[i].courseID, 20, &records[i].registrationDate.day, &records[i].registrationDate.month, &records[i].registrationDate.year,
			&records[i].dateOfBirth.day, &records[i].dateOfBirth.month, &records[i].dateOfBirth.year);

		//Checks to see if loop works;
		printf(" %d %s %s %s %d %d %d %d %d %d \n", records[i].studentID, records[i].firstName, records[i].lastName,
			records[i].courseID, records[i].registrationDate.day, records[i].registrationDate.month, records[i].registrationDate.year,
			records[i].dateOfBirth.day, records[i].dateOfBirth.month, records[i].dateOfBirth.year);
	}

	srand(time(NULL));		//Generates random grade & puts that into average grade
	for (i = 0; i < 2; i++) {
		randNum = (rand() % 100) + 1;
		records[i].averageGrade = randNum;
		printf("%d \n", records[i].averageGrade);			//Checks to see if average grade is correct.
	}
	closeFile(ptr);			//closes file

	ptr = openFile("C://Users/Sofia/Documents/student.txt", "w");		//opens file again but this time with different mode

	for (i = 0; i < 2; i++) {			//prints the new updated version w/ average grade into File.
		fprintf_s(ptr, "%d %s %s %s %d %d %d %d %d %d %d \n", records[i].studentID, records[i].firstName, records[i].lastName,
			records[i].courseID, records[i].registrationDate.day, records[i].registrationDate.month, records[i].registrationDate.year,
			records[i].dateOfBirth.day, records[i].dateOfBirth.month, records[i].dateOfBirth.year, records[i].averageGrade);

		//Check if loop works
		printf("%d %s %s %s %d %d %d %d %d %d %d\n", records[i].studentID, records[i].firstName, records[i].lastName,
			records[i].courseID, records[i].registrationDate.day, records[i].registrationDate.month, records[i].registrationDate.year,
			records[i].dateOfBirth.day, records[i].dateOfBirth.month, records[i].dateOfBirth.year, records[i].averageGrade);
	}
	closeFile(ptr);
}

//function to open file
FILE * openFile(char *fileName, char *mode) {
	FILE *fptr;
	fopen_s(&fptr, fileName, mode);
	if (fptr == NULL)
	{
		printf("Error Opening The File \n");
		exit(1);
	}
	return fptr;
}
//function to close file
void closeFile(FILE *fptr)
{
	fclose(fptr);
}