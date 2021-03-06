// Week14_SofiaBadalova.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

void charAddresses(char *string); // 1st function to do
void commaToSpace(char *str); // 2nd function to do
void printWord(char *start); //3rd function to do
char *nextWord(char *start); // 4th function to do


void main()
{
	int i = 0;
	char location[200] = "7825,CREEK VALLEY,SACRAMENTO,95828,CA";
	char *ptr;

	// 1. Prints out address and content of each char
	charAddresses(location);

	// 2. call function to replace all the commas in the input string with tabs
	commaToSpace(location);

	puts(" \n Without commas: \n ");
	puts(location);
	puts("");

	// 3. instead of printing characters (using putchar) until a '\0', printWord prints characters until a space ' '
	puts("First Word");
	printWord(location);

	puts("Second Word");
	printWord(location + 5);

	puts("Third Word");
	printWord(location + 11);
	puts("");

	// starting from the first character in the input string, each call to "nextWord" should return the next word in the string
	// e.g. if the input string is "Hi there everyone" :
	// first call to nextWord should return the address of the letter 't' of "there"
	// second call to nextWord should return the address of the first letter 'e'of "everyone"
	// third call to nextWord should return NULL
	ptr = location;
	while (ptr)
	{
		// instead of printing characters (using putchar) until a '\0', printWord prints characters until a space ' '
		printWord(ptr);
		printf("\n");
		ptr = nextWord(ptr);
	} 

}


void charAddresses(char *string)
{
	char *pt[38];
	int i;
	for (i = 0; i < 38; i++) {
		pt[i] = &string[i];
	}
	printf("%s %10s \n", "Address", "Char");
	for (i = 0; i < 38; i++) {
		printf("%x %10c\n", pt[i], *pt[i]);
	}
} 

void commaToSpace(char *str) {
	char *ptr[38];
	int i;
	for (i = 0; i < 38; i++) {
		ptr[i] = &str[i];
	}
	for (i = 0; i < 38; i++) {
		if (*ptr[i] == ',' ) {
			*ptr[i] = ' ';
		}
	}

}


void printWord(char *start)
{
	int i = 0;
	char *ptr[38];
	for (i = 0; i < 38; i++) {
		ptr[i] = &start[i];
	}
	for (i = 0; i < 38; i++) {
		printf("%c", *ptr[i]);
		if (*ptr[i] == ' ') {
			printf("\n");
			break;
		}
	}
	
}

char *nextWord(char *start)
{
	int i = 0;
	char *ptr[38];
	// insert your code here
	// of course it should only return NULL if there are no more words
	// HINT: 'return (start+i)' will return member [i] of the array (string) pointed at by 'start'
	for (i = 0; i < 38; i++) {
		ptr[i] = &start[i];
	}
	for (i = 0; i < 38; i++) {
		if (*ptr[i] == ' ') {
			i++;
			return (start + i);
		}
	}
	return NULL;
}