/*      Name           :WONHWA LEE
 Student Number : 076086149
 Email          : wlee72@myseneca.ca
 Section        : SGG
 Workshop       : 2 (at - home)
 */

#define _CRT_SECURE_NO_WARNINGS
 // Paste your in-lab code below and upgrade it to the at-home specifications

  // Start your code below:
#include<stdio.h>
int main(void) {

	double enteredAmt, gst, totalDue;
	double const tax = .13;
	int totalCents;
	int loonies, quarters, dimes, nickels, pennies;
	int quarterAmt, dimeAmt, nickelAmt, pennyAmt, balOwing;
	//enter amount
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &enteredAmt);
	//gst calculation
	gst = enteredAmt * tax;
	printf("GST: %.2f\n", gst);
	//total balance calculation
	totalDue = enteredAmt + gst + 0.005;
	printf("Balance owing: $%.2lf\n", totalDue);

	totalCents = totalDue * 100;
	//Loonies calculation
	quarterAmt = (int)totalCents % 100;
	loonies = totalCents;
	printf("Loonies required: %d, ", loonies / 100);
	printf("balance owing $%.2lf\n", quarterAmt / 100.0f);
	//Quarters calculation
	dimeAmt = quarterAmt % 25;
	quarters = quarterAmt / .25;
	printf("Quarters required: %d, ", quarters / 100);
	printf("balance owing $%.2lf\n", dimeAmt / 100.0f);
	//Dimes calculation
	nickelAmt = dimeAmt % 10;
	dimes = dimeAmt / .1;
	printf("Dimes required: %d, ", dimes / 100);
	printf("balance owing $%.2lf\n", nickelAmt / 100.0f);
	//Nickels calculation
	pennyAmt = nickelAmt % 5;
	nickels = nickelAmt / .05;
	printf("Nickels required: %d, ", nickels / 100);
	printf("balance owing $%.2lf\n", pennyAmt / 100.0f);
	//Pennies calculation
	balOwing = pennyAmt;
	pennies = pennyAmt / .01;
	printf("Pennies required: %d, ", pennies / 100);
	printf("balance owing $%.2lf\n", balOwing / 100);


	return 0;
}
