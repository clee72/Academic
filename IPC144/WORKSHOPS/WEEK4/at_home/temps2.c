/*
	Name:           WONHWA LEE
	Student Number: 076089149
	Email:          wlee72@myseneca.ca
	Section:        SGG
	Workshop:       4 (at_home)
*/

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include<stdio.h>


int main(void)
{
	int  i, day, dVal;
	int numDay[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int high[10] = { 0 }, low[10] = { 0 };
	int highMax = high[0], lowMin = low[0];
	int highestDay = 0, lowestDay = 0;
	float sum = 0, aveDay = 0;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &day);
	printf("\n");

	while (3 > day || day > 10) {

		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &day);
		printf("\n");
	}

	for (i = 0; i < day; i++) {
		printf("Day %d - High: ", numDay[i]);
		scanf("%d", &high[i]);

		printf("Day %d - Low: ", numDay[i]);
		scanf("%d", &low[i]);
	}
	printf("\n");
	printf("Day  Hi  Low\n");
	


	for (i = 0; i < day; i++) {
		printf("%d    %d    %d\n", numDay[i], high[i], low[i]);
		
		if (high[i] > highMax) {
			highMax = high[i];
			highestDay = numDay[i];
		}
		if (low[i] < lowMin) {
			lowMin = low[i];
			lowestDay = numDay[i];
		}
	}

	printf("\nThe highest temperature was %d, on day %d\n", highMax, highestDay);
	printf("The lowest temperature was %d, on day %d\n", lowMin, lowestDay);
	printf("\n");

	do
	{
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", day);
		scanf("%d", &dVal);
		printf("\n");

		while (day < dVal || dVal == 0) {
			printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", day);
			scanf("%d", &dVal);
			printf("\n");
		}

		for (i = 0; i < dVal; i++) {
			aveDay = (float)high[i] / 2 + (float)low[i] / 2;
			sum += aveDay;
		}

		if (dVal <= day && dVal > 0) {
			printf("The average temperature up to day %d is: %.2f\n", dVal, sum/dVal);
			printf("\n");
		}

		sum = 0;
		aveDay = 0;

		if (dVal < 0) {
			printf("Goodbye!");
			printf("\n");
			break;
		}
	} while (1);


	return 0;
}
