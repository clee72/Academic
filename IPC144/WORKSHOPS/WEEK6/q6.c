// -------------------------------------------------------
// Name      : WONHWA LEE	
// Student ID: 076086149
// Email     : wlee72@myseneca.ca
// Section   :  144SGG
// Assessment: In-Lab -> Quiz #6
// -----------------------------------------------------

// ==============================================================================================
// NOTE:
// Only modify the parts that state: "You do this!!!(See instructions describing the q6.c file)"
// ==============================================================================================

// 1. System library(ies) are always specified 1st
// 2. Followed by user library(ies)
#include <stdio.h>      

#include "animal.h" // This allows main() to "know" about the Animal data type and related functions
#include "tools.h"  // This allows main() to "know" about the functions available in the tools library

#define TEST_ITEMS 4

int main(void)
{
	int i;

	// -------------------------------------------------------
	// Animal array: Used for testing!
	// -------------------------------------------------------
	// !!! DO NOT MODIFY !!!
	struct Animal ostrich[TEST_ITEMS] = {
		{ 9000, 'F', 2016, 2018, "2019-02-15 (13:59 PM)" },
		{ 8000, 'M', 2010, 2017, "2019-02-16 (19:59 PM)" },
		{ 7000, '?', 2012, 2016, "2019-02-17 (23:59 PM)" }
	};
	// -------------------------------------------------------

	// Test:  Call the showWelcomeMessage function
	showWelcomeMessage();
	// Loop all records...
	for (i = 0; i < TEST_ITEMS; i++) {
		// Show the test iteration number as a title:
		// Test: Call API helper function displayTitleExt
		//      Argument-1: "Test-%d"
		//      Argument-2: i + 1
		//      Argument-3: '='
		displayTitleExt("Test-%d", i + 1, '=');

		// The 1st 3 records are already initialized with data, but all
		// records AFTER them need to be set with user input values.
		if (i > 2) {
			// Test: setting the animal information function!
			//      Argument-1: Address of the current ostrich element
			setAnimalInfo(&ostrich[i]);
		}

		// Test: display animal information function!
		//      Argument-1: Address of the current ostrich element
		displayAnimalInfo(&ostrich[i]);

		// Formatting: add newline so it looks nice
		printf("\n");

		// Test: Call API enterToContinue function
		enterToContinue();
		// Formatting: add newline so it looks nice
		printf("\n");
	}

	// Test:  Call the showGoodbyeMessage function
	showGoodbyeMessage();

	return 0;
}