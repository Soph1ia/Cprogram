// Week19_SofiaBadalova.cpp : Searches file using linked lists
//

#include "stdafx.h"
#include "stdio.h"
#include <malloc.h>
#include "stdlib.h"
#include "string.h"

struct result
{
	char last[40];
	char first[40];
	int age;
	char email[40];
	struct result *next;
};

struct result *first, *current, *newest;
FILE *openFile(char *filename, char *mode);
void closeFile(FILE *ptr);
void findAndPrint(int ans);

int main()
{
	FILE *fptr;
	char line[1000];
	char trash[100];
	char delim[2] = ",";
	char *token;
	int ans = 0;
	first = NULL;


	fptr = openFile("C://Users//Sofia//Documents//week19.txt", "r");
	if (fptr) {
		fgets(trash, 100, fptr);
		while (!feof(fptr)) {
			if (fgets(line, 200, fptr) != NULL) {
				token = strtok(line, delim);
				while (token != NULL) {
					newest = (struct result *)malloc(sizeof(struct result));

					strcpy(newest->last, token);
					token = strtok(NULL, delim);

					strcpy(newest->first, token);
					token = strtok(NULL, delim);

					newest->age = atoi(token);
					token = strtok(NULL, delim);

					strcpy(newest->email, token);
					token = strtok(NULL, delim);

				}

				if (first == NULL) {
					first = newest;
					current = newest;
				}
				else
				{
					current->next = newest;
					current = newest;
				}
			}
		}
	}
	current->next = NULL;		//closing linked list
								// Calling function to find age and print
	do {
		printf("Enter the age you're looking for (insert 0 to exit)");
		scanf("%d", &ans);
		if (ans != 0) {
			findAndPrint(ans);
		}
		else {
			printf("Exiting...\n");
			return(0);
		}
	} while (ans != 0);

	// freeing all allocations
	free(newest);
	free(current);
	free(first);
	closeFile(fptr);
}

FILE *openFile(char *filename, char *mode) {
	FILE *ptr;
	ptr = fopen(filename, mode);
	if (ptr == NULL) {
		printf("File couldn't be opened\n");
		return(0);
	}
	return(ptr);
}

void closeFile(FILE *ptr) {
	fclose(ptr);
}

void findAndPrint(int ans) {
	if (first == NULL) {
		puts("Error in printing ages");
	}

	else {
		current = first;
		do {
			if (ans == current->age) {
				printf("\n Person of Age %d , Called %s %s \n", current->age, current->first, current->last);

			}
		} while ((current = current->next) != NULL);
	}
}
