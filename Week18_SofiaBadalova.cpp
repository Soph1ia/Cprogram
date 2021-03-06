// Week18_SofiaBadalova.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"


typedef struct
{
	char *UserName;
	char *firstName;
	char *lastName;
	char *displayName;
	char *jobTitle;
	char *department;
	char *officeNumber;
	char *officePhone;
	char *mobilePhone;
	char *fax;
	char *address;
	char *city;
	char *state;
	char *zip;
	char *country;
} contact;

FILE *fptr;
contact *moreContacts;
FILE *openFile(char*fileName, char *mode);
void closeFile(FILE *fptr);
void printContact(contact *theContact);

int main()
{
	char temp[1000];
	char *token;
	const char s[2] = ",";
	int i = 0;
	char line[200];
	int len;

	fptr = openFile("C://Users//Sofia//Documents//content.txt", "r");
	if (fptr != NULL) {
		fgets(line, 200, fptr); // gets rid of first line.


		moreContacts = (contact *)calloc(5, sizeof(contact));
		while (!feof(fptr)) {
			if (fgets(temp, 200, fptr) != NULL) {
				
				token = strtok(temp, s);
				while (token != NULL) {
					
					len = strlen(token);
					moreContacts[i].UserName = (char *)malloc(len);
					strcpy(moreContacts[i].UserName, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].UserName);

					len = strlen(token);
					moreContacts[i].firstName = (char *)malloc(len);
					strcpy(moreContacts[i].firstName, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].firstName);

					len = strlen(token);
					moreContacts[i].lastName = (char *)malloc(len);
					strcpy(moreContacts[i].lastName, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].lastName);

					len = strlen(token);
					moreContacts[i].displayName = (char *)malloc(len);
					strcpy(moreContacts[i].displayName, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].displayName);

					len = strlen(token);
					moreContacts[i].jobTitle = (char *)malloc(len);
					strcpy(moreContacts[i].jobTitle, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].jobTitle);

					len = strlen(token);
					moreContacts[i].department = (char *)malloc(len);
					strcpy(moreContacts[i].department, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].department);

					len = strlen(token);
					moreContacts[i].officeNumber = (char *)malloc(len);
					strcpy(moreContacts[i].officeNumber, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].officeNumber);

					len = strlen(token);
					moreContacts[i].officePhone = (char *)malloc(len);
					strcpy(moreContacts[i].officePhone, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].officePhone);

					len = strlen(token);
					moreContacts[i].mobilePhone = (char *)malloc(len);
					strcpy(moreContacts[i].mobilePhone, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].mobilePhone);

					len = strlen(token);
					moreContacts[i].fax = (char *)malloc(len);
					strcpy(moreContacts[i].fax, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].fax);

					len = strlen(token);
					moreContacts[i].address = (char *)malloc(len);
					strcpy(moreContacts[i].address, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].address);

					len = strlen(token);
					moreContacts[i].city = (char *)malloc(len);
					strcpy(moreContacts[i].city, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].city);

					len = strlen(token);
					moreContacts[i].state = (char *)malloc(len);
					strcpy(moreContacts[i].state, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].state);

					len = strlen(token);
					moreContacts[i].zip = (char *)malloc(len);
					strcpy(moreContacts[i].zip, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].zip);

					len = strlen(token);
					moreContacts[i].country = (char *)malloc(len);
					strcpy(moreContacts[i].country, token);
					token = strtok(NULL, s);
					//printf("%s \n", moreContacts[i].country);
					
					i++;
				}
			}
		}
		printContact(moreContacts);
	}
	free(moreContacts);
	closeFile(fptr);
}

FILE *openFile(char*filename, char*mode) {
	FILE *ptr;
	ptr = fopen(filename, mode);
	if (ptr == NULL) {
		printf("File couldn't be open");
		return(0);
	}
	return (ptr);
}

void closeFile(FILE *fptr) {
	fclose(fptr);
}


void printContact(contact *theContact) {
	int i = 0;
	for (i = 0; i < 5; i++) {
		printf("User Name: %s \n First Name: %s \n Last Name: %s \n DisplayName: %s\n Job Title: %s \n Department: %s \n Office Number: %s\n Office Phone: %s \n Mobile Phone: %s \n Fax: %s \n Address: %s \n City: %s \n State: %s \n ZIP: %s \n Country or Region: %s \n",
			theContact[i].UserName, theContact[i].firstName, theContact[i].lastName, theContact[i].displayName,
			theContact[i].jobTitle, theContact[i].department, theContact[i].officeNumber, theContact[i].officePhone, theContact[i].mobilePhone, 
			theContact[i].fax,theContact[i].address, theContact[i].city, theContact[i].state, theContact[i].zip, theContact[i].country);
	}
}