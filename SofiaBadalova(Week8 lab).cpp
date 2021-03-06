#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "ctype.h"
#include "string.h"

# define PI 3.14159265

int main()
{
	char options[10] = "";
	char ans;
	double deg, result, radVal;
	int i;

	do {
		printf("Enter Calculations using degrees, e.g.cos45 \n");
		scanf_s("%s %lf", &options, 10, &deg);
		radVal = deg*(PI / 180.00);

		for (i = 0; i <3; i++) { options[i] = tolower(options[i]); }


		if (!strcmp("cos", options))
		{

			result = cos(radVal);
			printf("cos( %.2lf ) = %.2lf \n", deg, result);
		}
		else if (!strcmp("sin", options))
		{

			result = sin(radVal);
			printf("sin( %.2lf ) = %.2lf \n", deg, result);
		}
		else if (!strcmp("tan", options))
		{

			result = tan(radVal);
			printf("tan( %.2lf ) = %.2lf \n", deg, result);
		}

		printf(" Would you like to do another calculation (y/n): ");
		scanf_s(" %c", &ans);
	} while (ans == 'Y' || ans == 'y');

	return 0;
}