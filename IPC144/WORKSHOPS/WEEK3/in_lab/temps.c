/*
	Name:           WONHWA LEE
	Student Number: 076089149
	Email:          wlee72@myseneca.ca
	Section:        SGG
	Workshop:       3 (at_home)
*/

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>

#define NUMS 4

int main(void)
{

	int i = 0;
	int highestDay, lowestDay;
	int highVal, lowVal, maxTemp = 0, minTemp = 0;
	int max = 0, min = 0;
	double aveHigh = 0, aveLow = 0, sumHigh = 0, sumLow = 0, aveTemp = 0;


	printf("---=== IPC Temperature Analyzer ===---\n");



	do {


		printf("Enter the high value for day %d: ", i + 1);
		scanf("%d", &highVal);
		printf("\n");

		printf("Enter the low value for day %d: ", i + 1);
		scanf("%d", &lowVal);
		printf("\n");

		if (-40 <= lowVal && lowVal < highVal &&  highVal <= 40) {
			i++;


			sumHigh += highVal;
			sumLow += lowVal;
			if (highVal > maxTemp) {
				max = highVal;
				highestDay = i + 1;

			}
			if (lowVal < minTemp) {
				min = lowVal;
				lowestDay = i + 1;
			}

		}

		else {
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
		}


	} while (i < NUMS);
	aveLow = sumLow / (NUMS);
	aveHigh = sumHigh / (NUMS);
	aveTemp = (sumHigh + sumLow) / (2 * NUMS);
	printf("The average(mean) LOW temperature was :%.2f \n", aveLow);
	printf("The average(mean) HIGH temperature was :%.2f \n", aveHigh);
	printf("The average(mean) temperature was :%.2f\n", aveTemp);
	printf("The highest temperature was %d, on day %d \n", maxTemp, highestDay);
	printf("The highest temperature was %d, on day %d \n", minTemp, lowestDay);
	return 0;
}