#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

FILE *openFile(char *fileName, char *mode);					//function declerations
void closeFile(FILE *ptr);
void searchName(char string[]);
void searchCompany(char string[]);
void searchCity(char string[]);
void searchCounty(char string[]);
void searchState(char string[]);
void searchZIP(char string[]);

struct record {
	char firstName[20];
	char lastName[20];
	char companyName[20];
	char address[20];
	char city[20];
	char county[20];
	char state[20];
	char zip[20];
	char phone1[20];
	char phone2[20];
	char email[20];
	char web[20];
};
//struct with all data info

struct record data[1000];
FILE *fptr;

int main()
{
	int i, j;
	char temp[1000];
	char trash[100];
	char *token;
	const char s[2] = ",";
	int opt;
	char needle[20];
	char a[] = { "C://Users//sofia//Documents//week17File.txt" };
	char b[] = { "r" };
	fptr = openFile(a, b);


	if (fptr != NULL) {
		for (i = 0; i < 1; i++) { fscanf(fptr, "%s", trash, 200); }

		while (!feof(fptr)) {
			//gets rid of first line.
			fgets(trash, 200, fptr);
			i = 0; j = 0;

			while (!feof(fptr)) {
				if (fgets(temp, 200, fptr) != NULL) {
					while (temp[j] != '\0')
					{
						if (temp[j] == '-' || temp[j] == '"') temp[j] = ' ';
						j++;
					}

					//seperates the temp into designated parts of struct.

					token = strtok(temp, s);
					while (token != NULL)
					{
						strcpy(data[i].firstName, token); // first name
						token = strtok(NULL, s);
						//
						strcpy(data[i].lastName, token); // last name
						token = strtok(NULL, s);
						//
						strcpy(data[i].companyName, token); //company name
						token = strtok(NULL, s);
						//
						strcpy(data[i].address, token); // address
						token = strtok(NULL, s);
						//
						strcpy(data[i].city, token); // city
						token = strtok(NULL, s);
						//
						strcpy(data[i].county, token);  //county
						token = strtok(NULL, s);
						//
						strcpy(data[i].state, token);  //state
						token = strtok(NULL, s);
						//
						strcpy(data[i].zip, token);  //zip
						token = strtok(NULL, s);
						//
						strcpy(data[i].phone1, token);	//phone1
						token = strtok(NULL, s);
						//
						strcpy(data[i].phone2, token);		//phone2
						token = strtok(NULL, s);
						//
						strcpy(data[i].email, token);		//email
						token = strtok(NULL, s);
						//
						strcpy(data[i].web, token);		//web address.
						token = strtok(NULL, s);
					}
					i++;
				}
			}
		}
	}



	//set of switch statements to call functions for search.
	do {
		//asks user to input search type
		printf("Options: \n 1- search by name \n 2- search by company \n 3-search by city \n 4- search by county \n 5- search by state \n 6- search by zip \n 0- exit...\n ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0:

			break;

		case 1: //name
			printf("enter all <or part> of the first name or surname you are looking for: \n");
			scanf("%s", needle, 20);
			i = 0;
			while (needle[i]) {
				needle[i] = tolower(needle[i]);
				i++;
			}
			searchName(needle);
			break;

		case 2: //company
			printf("Enter all <or part> of the company name you are looking for: \n");
			scanf("%s", needle, 20);
			//changes to lower case
			i = 0;
			while (needle[i]) {								//changes to lower case
				needle[i] = tolower(needle[i]);
				i++;
			}
			searchCompany(needle);
			break;

		case 3:
			printf("Enter all <or part> of the city name you are looking for: \n");
			scanf("%s", needle, 20);
			i = 0;
			while (needle[i]) {
				//changes to lower case
				needle[i] = tolower(needle[i]);
				i++;
			}
			searchCity(needle);
			break;

		case 4:
			printf("Enter all <or part> of the county name you are looking for: \n");
			scanf("%s", needle, 20);								//changes to lower case
			i = 0;
			while (needle[i]) {
				needle[i] = tolower(needle[i]);
				i++;
			}
			searchCounty(needle);
			break;

		case 5:
			printf("Enter all <or part> of the state name you are looking for: \n");
			scanf("%s", needle, 20);
			i = 0;
			while (needle[i]) {
				needle[i] = tolower(needle[i]);
				i++;
			}
			searchState(needle);
			break;

		case 6:
			printf("Enter all <or part> of the ZIP  you are looking for: \n");
			scanf("%s", needle, 20);
			//changes to lower case...
			i = 0;
			while (needle[i]) {
				needle[i] = tolower(needle[i]);
				i++;
			}
			searchZIP(needle);
			break;

		default:
			printf("Put in value 1-6 only, or else 0 to exit..");
			break;


		}
		fclose(fptr);			//closes fle
	} while (opt != 0);
	return 0;
}


FILE *openFile(char *fileName, char *mode) {
	FILE *ptr;
	ptr = fopen(fileName, mode);
	if (ptr == NULL) {
		printf("File couldn't be open\n");
	}
	return (ptr);
}

void closeFile(FILE *ptr) {
	fclose(ptr);
}

//functions for search

void searchName(char string[]) {
	int i = 0, j = 0;
	char *temp;
	char *temp2;
	char tempfirst[20];
	char templast[20];

	for (i = 0; i < 500; i++) {
		strcpy(tempfirst, data[i].firstName);
		while (tempfirst[j]) {
			tempfirst[j] = tolower(tempfirst[j]);
			j++;
		}
		j = 0;
		strcpy(templast, data[i].lastName);
		while (templast[j]) {
			templast[j] = tolower(templast[j]);
			j++;
		}
		temp = strstr(tempfirst, string);
		temp2 = strstr(templast, string);
		if (temp != NULL) {
			printf("First Name: %s \nLast Name: %s \nCompany Name: %s\nAddress Name: %s\nCity: %s\nCounty: %s\nState: %s\nZip: %s\nPhone#1: %s \nPhone #2: %s\nemail: %s\nweb: %s\n\n\n ", data[i].firstName, data[i].lastName, data[i].companyName, data[i].address, data[i].city,
				data[i].county, data[i].state, data[i].zip, data[i].phone1, data[i].phone2, data[i].email, data[i].web);
		}
		if (temp2 != NULL) {
			printf("First Name: %s \nLast Name: %s \nCompany Name: %s\nAddress Name: %s\nCity: %s\nCounty: %s\nState: %s\nZip: %s\nPhone#1: %s \nPhone #2: %s\nemail: %s\nweb: %s\n\n\n ", data[i].firstName, data[i].lastName, data[i].companyName, data[i].address, data[i].city,
				data[i].county, data[i].state, data[i].zip, data[i].phone1, data[i].phone2, data[i].email, data[i].web);
		}
	}

}

void searchCompany(char string[]) {
	int i = 0, j = 0;
	char *temp;
	char tempCompany[100];
	for (i = 0; i < 500; i++) {
		strcpy(tempCompany, data[i].companyName);
		while (tempCompany[j]) {
			tempCompany[j] = tolower(tempCompany[j]);
			j++;
		}
		temp = strstr(tempCompany, string);
		if (temp != NULL) {
			printf("First Name: %s \nLast Name: %s \nCompany Name: %s\nAddress Name: %s\nCity: %s\nCounty: %s\nState: %s\nZip: %s\nPhone#1: %s \nPhone #2: %s\nemail: %s\nweb: %s\n \n\n", data[i].firstName, data[i].lastName, data[i].companyName, data[i].address, data[i].city,
				data[i].county, data[i].state, data[i].zip, data[i].phone1, data[i].phone2, data[i].email, data[i].web);
		}
	}

}

void searchCity(char string[]) {
	int i=0, j=0;
	char *temp;
	char tempCity[100];

	for (i = 0; i < 500; i++) {
		strcpy(tempCity, data[i].city);
		while (tempCity[j]) {
			tempCity[j] = tolower(tempCity[j]);
			j++;
		}
		temp = strstr(tempCity, string);
		if (temp != NULL) {
			printf("First Name: %s \nLast Name: %s \nCompany Name: %s\nAddress Name: %s\nCity: %s\nCounty: %s\nState: %s\nZip: %s\nPhone#1: %s \nPhone #2: %s\nemail: %s\nweb: %s\n \n\n", data[i].firstName, data[i].lastName, data[i].companyName, data[i].address, data[i].city,
				data[i].county, data[i].state, data[i].zip, data[i].phone1, data[i].phone2, data[i].email, data[i].web);
		}
	}

}

void searchCounty(char string[]) {
	int i = 0, j = 0;
	char *temp;
	char tempCounty[100];

		for (i = 0; i < 500; i++) {
			strcpy(tempCounty, data[i].county);
			while (tempCounty[j]) {
				tempCounty[j] = tolower(tempCounty[j]);
				j++;
			}
			temp = strstr(tempCounty, string);
			if (temp != NULL) {
				printf("First Name: %s \nLast Name: %s \nCompany Name: %s\nAddress Name: %s\nCity: %s\nCounty: %s\nState: %s\nZip: %s\nPhone#1: %s \nPhone #2: %s\nemail: %s\nweb: %s\n \n\n", data[i].firstName, data[i].lastName, data[i].companyName, data[i].address, data[i].city,
					data[i].county, data[i].state, data[i].zip, data[i].phone1, data[i].phone2, data[i].email, data[i].web);
			}
		}

	}

void searchState(char string[]) {
	int i=0, j=0;
	char *temp;
	char tempState[100];
	for (i = 0; i < 500; i++) {
		strcpy(tempState, data[i].state);
		while (tempState[j]) {
			tempState[j] = tolower(tempState[j]);
			j++;
		}
		temp = strstr(tempState, string);
		if (temp != NULL) {
			printf("First Name: %s \nLast Name: %s \nCompany Name: %s\nAddress Name: %s\nCity: %s\nCounty: %s\nState: %s\nZip: %s\nPhone#1: %s \nPhone #2: %s\nemail: %s\nweb: %s\n \n\n", data[i].firstName, data[i].lastName, data[i].companyName, data[i].address, data[i].city,
				data[i].county, data[i].state, data[i].zip, data[i].phone1, data[i].phone2, data[i].email, data[i].web);
		}
	}

}

void searchZIP(char string[]) {
	int i=0, j=0;
	char *temp;
	char tempZIP[100];
	for (i = 0; i < 500; i++) {
		strcpy(tempZIP, data[i].zip);
		while (tempZIP[j]) {
			tempZIP[j] = tolower(tempZIP[j]);
			j++;
		}
		temp = strstr(tempZIP, string);
		if (temp != NULL) {
			printf("First Name: %s \nLast Name: %s \nCompany Name: %s\nAddress Name: %s\nCity: %s\nCounty: %s\nState: %s\nZip: %s\nPhone#1: %s \nPhone #2: %s\nemail: %s\nweb: %s\n \n\n", data[i].firstName, data[i].lastName, data[i].companyName, data[i].address, data[i].city,
				data[i].county, data[i].state, data[i].zip, data[i].phone1, data[i].phone2, data[i].email, data[i].web);
		}
	}

}