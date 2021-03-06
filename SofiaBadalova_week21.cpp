#include "stdafx.h"
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

struct Date {
	int month;
	int day;
	int year;
};
struct Time {
	int hour;
	int minutes;
};
struct worktime
{
	int employeeID;
	struct Date date;
	struct Time startTime;
	struct Time endTime;
};

struct worktime records[4];

void structCreate(int argc, char *argv[]);
void printFile();
void searchFile( char *argv[]);

void main(int argc, char *argv[])
{
	//PRINTS OFF WHAT IS in the array...
	for (int i = 0; i<argc; i++)
	{
		printf(" %s ", argv[i]);

	}

	
	 //break up input into different parts.
	char *type = argv[1];
	char op = type[1];
	
	switch (op)
	{
	case 'a': 
		structCreate( argc , argv);
		break;
	case 'p':
		printFile();
		break;
	case 's':
		searchFile(argv);
		break;
	default:
		printf("Incorrect information  - Quitting \n");
		break;
	} 
	

}


void structCreate(int argc, char *argv[]) {

	printf(" \n /a is selected \n");
	char delim[3] = "/:";
	char *token;
	int i = 2, j = 0;
	int length = (argc - 2 )/ 4;
	int ans = 0;


	for (j = 0; j < length; j++) {
		ans = 0;
		while ( ans != 1) {

			int day, month, year;		// temp arrays to hold vaiables
			int hour, min;

			records[j].employeeID = atoi(argv[i]);	//EMPLOYEE ID ..... i = 2   i= 6
			i++;

			char *tempDate = argv[i];			// i=3 i =7

			printf(" \n \n \n TEMP DATE IS %s \n ", tempDate);	// FULL DATE...

			token = strtok(tempDate, delim);			//breaking up the Date into specific parts.
			while (token != NULL) {
				//DAY
				day = atoi(token);
				records[j].date.day = day;
				token = strtok(NULL, delim);

				//MONTH
				month = atoi(token);
				records[j].date.month = month;
				token = strtok(NULL, delim);

				//YEAR
				year = atoi(token);
				records[j].date.year = year;
				token = strtok(NULL, delim);
			}
			i++;	// i = 4

			char *Time = argv[i];		// i = 4, i = 8 etc...

										//START TIME
			token = strtok(Time, delim);
			while (token != NULL) {
				//HOUR
				hour = atoi(token);
				records[j].startTime.hour = hour;
				token = strtok(NULL, delim);

				//MIN
				min = atoi(token);
				records[j].startTime.minutes = min;
				token = strtok(NULL, delim);
			}
			i++;

			char *EndTime = argv[i];		// i = 5, i =9;

											//End TIME.. Breaking up finishing time
			token = strtok(EndTime, delim);
			while (token != NULL) {
				//HOUR
				hour = atoi(token);
				records[j].endTime.hour = hour;
				token = strtok(NULL, delim);

				//MIN
				min = atoi(token);
				records[j].endTime.minutes = min;
				token = strtok(NULL, delim);
			}

			ans = i % 4;
		}
		i++; // i = 6
	}
	printf("The file contains now \n (but date is formulated differently.)...\n"); //Prints off what is currently in the file... But only as integers not wit
	for (i = 0; i < length; i++) {
		printf(" %d / %d /  %d , %d ,%d : %d, %d : %d \n", records[i].date.month,
			records[i].date.day, records[i].date.year,
			records[i].employeeID, records[i].startTime.hour, records[i].startTime.minutes,
			records[i].endTime.hour, records[i].endTime.minutes);
	}

		// CREATE FILE TO WRITE INTO... HERE WE PRINT INTO THE FILE
		FILE *fptr;
		char month[12][20] = { "January", "February", "March", "April", "May","June", "July", "August", "Septmeber", "October", "November", "December" };
		fptr = fopen("C://Users//Sofia/Documents/workLog.txt", "a+");

		for (i = 0; i < length; i++) {
			fprintf(fptr, "\n \" %s %d %d \",\" %d \", \"%d:%d\", \" %d:%d \" ", month[(records[i].date.month - 1)], records[i].date.day, records[i].date.year,
				records[i].employeeID, records[i].startTime.hour, records[i].startTime.minutes,
				records[i].endTime.hour, records[i].endTime.minutes);
		}
}

void printFile() {
	printf(" \n \n /p is selected \n \n ");

	//DECLERATION OF VARIABLES NEEDED...
	FILE *fptr;
	int i;
	fptr = fopen("C://Users//Sofia/Documents/workLog.txt", "r");
	char *token;
	char delim[10] = "\",  ";
	char namemonth[12][20] = { "January", "February", "March", "April", "May","June", "July", "August", "Septmeber", "October", "November", "December" };
	char temp[1000];
	char id[20], day[20], month[20], year[20], start[20], end[20];
	int monthNum = 0;
	char trash[10];

	fgets(trash, 10, fptr);			//Gets rid of the first line in the file...
	while(!feof(fptr)) {
		fgets(temp, 100, fptr);			// inputs the first line of data in the file, into temp array.


		token = strtok(temp, delim);		//finds the month number
			while (token != NULL) {
				strcpy(month, token);
				for (i = 0; i < 12; i++) {
					if (strcmp(namemonth[i], month) == 0) {
						monthNum = i + 1;				// saves into int array

					}
				}
				token = strtok(NULL, delim);
				//
				strcpy(day, token);				//Gets day
				token = strtok(NULL, delim);
				//
				strcpy(year, token);			//Gets YEAR
				token = strtok(NULL, delim);
				//
				strcpy(id, token);				//gets ID
				token = strtok(NULL, delim);
				//
				strcpy(start, token);			//Start time
				token = strtok(NULL, delim);
				//
				strcpy(end, token);			//End time
				token = strtok(NULL, delim);

				//Prints off what is inside the file..

				printf(" Date: %s / %d/ %s Employee: %s Start at: %s End At %s \n", day, monthNum, year, id, start, end);		
				break;
				}
			}
	fclose(fptr);
	}

void searchFile(char *argv[]) {
	printf("\n/s is selected\n");

	//DECLERATION OF VARIABLES NEEDED...
	FILE *fptr;
	fptr = fopen("C://Users//Sofia/Documents/workLog.txt", "r");
	char namemonth[12][20] = {"January", "February", "March", "April", "May","June", "July", "August", "Septmeber", "October", "November", "December" };
	char day[20][20], month[20][20],year[20][20],id[20][20], start[20][20], end[20][20];
	int	 monthNum[20];
	char trash[100];
	char trash1[10];
	char *token;
	int i = 0, count = 0;
	char delim[10] = "\", ";
	int found;

	//GETS RID OF FIRST LINE
	fgets(trash1, 10, fptr);

	for (i = 0; !feof(fptr); i++) {			// FINDS HOW MANY LINES OF DATA THERE IS.
		fgets(trash, 100, fptr);
	}
	count = i;		 // SAVES into COUNT.
	rewind(fptr); //REWINDS

	fgets(trash1, 10, fptr);		//GETS RID OF FIRST LINE AGAIN 
	
	while (!feof(fptr)) {
		for (i = 0; i < count; i++) {
			fgets(trash, 100, fptr);		//takes in line of data..

			token = strtok(trash, delim);

			while (token != NULL) {

				strcpy(month[i], token);			//Finds associated month name with number
				for (int j = 0; j < 12; j++) {
					if (strcmp(namemonth[j], month[i]) == 0) {
						monthNum[i] = j + 1;
						
					}

				}
				token = strtok(NULL, delim); // gets month
				strcpy(day[i], token);
				token = strtok(NULL, delim);	// gets day
				strcpy(year[i], token);
				token = strtok(NULL, delim); //gets year

				strcpy(id[i], token);			 // gets ID
				token = strtok(NULL, delim);

				strcpy(start[i], token);		// gets start time.
				token = strtok(NULL, delim);

				strcpy(end[i], token);			// get's end time
				token = strtok(NULL, delim);

				if (strstr(id[i], argv[2])) {			// if search number is same as the current ID.. WE PRINT.. else we skip
					printf("\n\n Date: %s/%d/%s Employee: %s started at: %s and ended at %s \n\n", day[i], monthNum[i], year[i], id[i], start[i], end[i]);

				}
				break;

			}
		}
	}

		//
	fclose(fptr);
}

