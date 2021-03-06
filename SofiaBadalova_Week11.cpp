// SofiaBadalova_Week11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define numThrows 1000  

char getRandomLowercaseLetter();
void initialiseArray(int array[], int len);
void printfLine(int len);

int main()
{
	char result;
	int freq[26];
	char alphabet[26];
	int max=0;
	int index;
	int i;
	srand(time(NULL));

	initialiseArray(freq, 26);

	// random letter and index
	for (int i = 0; i < numThrows; i++) {
     result = getRandomLowercaseLetter();
	 index = result - 'a';
	 freq[index]++;
	}

	//find max
	for (i = 0; i < 26; i++) {
		if (freq[i] > max) {
			max = freq[i];
		}
	}

	//alphabet
	for (i = 0; i < 26; i++) {
		alphabet[i] = i + 97; 
	}

	// printing here.
	printf("num Throws = 4000,  Max Freq = %d , scale = 0-40 \n", max);

	for (i = 0; i < 26; i++)
	{
		printf("\n%c - %d ", alphabet[i], freq[i]);
		printfLine(freq[i]);

	}
	printf("\n");
    return 0;
}

char getRandomLowercaseLetter()
{
	char  result;
	int i;
	result = 'a' + (rand() % 26);
	return result;
}

void initialiseArray(int array[], int len)
{
	for (int i = 0; i < len; i++) {
		array[i] = 0; 
	}
}

void printfLine(int len) {
	for (int i = 0; i < len; i++) {
		printf("*");
	}
}

