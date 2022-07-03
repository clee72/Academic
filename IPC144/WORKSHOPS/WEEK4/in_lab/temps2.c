/*
	Name:           WONHWA LEE
	Student Number: 076089149
	Email:          wlee72@myseneca.ca
	Section:        SGG
    Workshop:       4 (in-lab)
*/

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include<stdio.h>

#define DAYNUMS 4

int main(void)
{
	int day, i;
	int high[DAYNUMS] = { 0 };
	int low[DAYNUMS] = { 0 };

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &day);
	printf("\n");

	
	while (!(3 <= day && day <= 10)) {

		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &day);
		printf("\n");
	}

	for (i = 0; i < DAYNUMS; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);

		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}
	printf("\n");
	printf("Day  Hi  Low\n");

	do {
		for (i = 0; i < DAYNUMS; i++) {

			printf("%d    %d    %d\n", i + 1, high[i], low[i]);

		}
	} while (i < DAYNUMS);

	return 0;
}