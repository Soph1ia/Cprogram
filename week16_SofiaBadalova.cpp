// week16_SofiaBadalova.cpp :  program reads in the data into an array of the data structures.
//program  provides the option to the user to print out the year &
//month with the highest of the chosen data types.

#include "stdafx.h"
#include "stdio.h"
#include "string.h"


FILE * openFile(char *fileName, char*mode);		//function declaration.
void closeFile(FILE *ptr);
void printTempMax();
void printTempMin();
void printAFDMax();
void printRainMax();
void printSunMax();

//structure
struct data
{
	int year;
	int month[12];
	double tmax[12];
	double tmin[12];
	int frostDays[12];
	double rain[12];
	double sun[12];
};

struct data records[59];		//Global Declr. of struct records

int main()
{
	int i, j;
	int opt = 0;
	char line[400];
	FILE *fptr;

	fptr = openFile("C://Users/Sofia/Documents/rainfall.txt", "r");
	if (fptr) {
		//gets rid of sentences stuff
		for (i = 0; i < 7; i++) {
			fgets(line, 400, fptr);
		}

		//scanf in data, and prints to check if correct
		for (j = 0; j < 59; j++) {
			for (i = 0; i < 12; i++) {
				fscanf_s(fptr, "%d %d %lf %lf %d %lf %lf", &records[j].year, &records[j].month[i], &records[j].tmax[i], &records[j].tmin[i], &records[j].frostDays[i], &records[j].rain[i], &records[j].sun[i]);

			}
		}
	}

	// Gives User Option of Tables
	printf(" Choose Option: \n 1: Temp Max \n 2: Temp Min \n 3: Air Frost Days Max \n 4: Rain Max \n 5: Sun Max \n 0: Exit \n");
	scanf_s(" %d", &opt);

	do {					// loops with switch cases calling functions.
		switch (opt) {

		case 1:
			printTempMax();
			break;
		case 2:
			printTempMin();
			break;
		case 3:
			printAFDMax();
			break;
		case 4:
			printRainMax();
			break;
		case 5:
			printSunMax();
			break;
		default:
			printf("Number not an option.. Please select from 1-5 or 0 to exit.\n\n\n");
			break;

		}
		printf(" Choose Option: \n 1: Temp Max \n 2: Temp Min \n 3: Air Frost Days Max \n 4: Rain Max \n 5: Sun Max \n 0: Exit \n");
		scanf_s(" %d", &opt);
	} while (opt != 0);

	closeFile(fptr);		//closes file

}


FILE * openFile(char *fileName, char*mode) {				//open file function
	FILE *ptr;
	fopen_s(&ptr, fileName, mode);
	if (ptr == NULL) {
		printf("Cannot Open File\n");
		return(0);
	}
	return(ptr);

}

void closeFile(FILE *ptr) {					//close file function
	fclose(ptr);
}


void printTempMax()				//finds and prints highest temp
{
	float tempMax = 0.0;
	int year = 0, ssn = 0;
	char season[12][12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	int i, j;

	for (i = 0; i < 59; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (records[i].tmax[j] > tempMax)
			{
				year = records[i].year;
				ssn = records[i].month[j];
				tempMax = records[i].tmax[j];
			}
		}
	}
	printf("Max Temperature was %.2lf in %s of year %d\n\n", tempMax, season[ssn - 1], year);
}

void printTempMin() {					//finds and prints min Temp
	float tempMin = 100;
	int year = 0, ssn = 0;
	char season[12][12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	int i, j;

	for (i = 0; i < 59; i++) {
		for (j = 0; j < 12; j++) {
			if (records[i].tmin[j] < tempMin && records[i].tmin[j] != EOF) {
				year = records[i].year;
				ssn = records[i].month[j];
				tempMin = records[i].tmin[j];
			}
		}
	}


	printf("Min Temperature was %.2lf in %s of year %d\n\n", tempMin, season[ssn - 1], year);
}

void printAFDMax()			// finds and prints Frost Days Max
{
	float frostMax = 0.0;
	int year = 0, ssn = 0;
	char season[12][12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	int i, j;

	for (i = 0; i < 59; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (records[i].frostDays[j] > frostMax)
			{
				year = records[i].year;
				ssn = records[i].month[j];
				frostMax = records[i].frostDays[j];
			}
		}
	}
	printf(" MaxAir Frost Days was %.2lf days in %s of year %d \n\n", frostMax, season[ssn - 1], year);
}

void printRainMax()			// finds and prints max rain 
{
	float rainMax = 0.0;
	int year = 0, ssn = 0;
	char season[12][12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	int i, j;

	for (i = 0; i < 59; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (records[i].rain[j] > rainMax)
			{
				year = records[i].year;
				ssn = records[i].month[j];
				rainMax = records[i].rain[j];
			}
		}
	}
	printf(" Max Rain was %.2lf mm in %s of year %d \n\n", rainMax, season[ssn - 1], year);
}

void printSunMax()			// finds and prints max sun.
{
	float sunMax = 0.0;
	int year = 0, ssn = 0;
	char season[12][12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	int i, j;

	for (i = 0; i < 59; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (records[i].sun[j] > sunMax)
			{
				year = records[i].year;
				ssn = records[i].month[j];
				sunMax = records[i].sun[j];
			}
		}
	}
	printf(" Max Sun was %.2lf hours in  %s of year %d \n\n", sunMax, season[ssn - 1], year);
}