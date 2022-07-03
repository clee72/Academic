// -------------------------------------------------------
// Name      : WONHWA LEE	
// Student ID: 076086149
// Email     : wlee72@myseneca.ca
// Section   :  144SGG
// Assessment: In-Lab -> Quiz #6
// -------------------------------------------------------

// =================================================================================================
// NOTE:
// Only modify the parts that state: "You do this!!!(See instructions describing the animal.c file)"
// =================================================================================================

#include <stdio.h>

// Include the animal.h header file containing the function prototypes
#include "animal.h"

// Include the tools.h API header file so you can use the tools module helper functions:
#include "tools.h"

// +-----------------------------------------------------------------------+
// | Define the function body for the setAnimalInfo function:              |
// +-----------------------------------------------------------------------+
void setAnimalInfo(struct Animal *animal)
{
	printf("Enter tag ID:        ");
	animal->tagID = getIntRange(1000, 9999);

	// Get the gender from the user (hint: call API function)
	animal->gender = getGender(1);

	printf("Enter Birth Year:    ");
	animal->yearBorn = getInt();

	printf("Enter Acquired Year: ");
	animal->yearAcquired = getIntRange(1995, getCurrentYear());

	// Set the date time created member (hint: call API function)
	setCurrentDateTime(animal->dateTimeCreated, DATE_LEN);
}

// +-----------------------------------------------------------------------+
// | Define the function body for the displayAnimalInfo function:          |
// +-----------------------------------------------------------------------+
void displayAnimalInfo(const struct Animal *animal)
{
	// Calculate and store to a variable the Animal's age: (current year - animal's birth year)
	int age = getYearsDiff(getCurrentYear(), animal->yearBorn);

	// Calculate and store to a variable the Animal's age when acquired: (acquired year - animal's birth year)
	int ageWhenAcquired = getYearsDiff(animal->yearAcquired, animal->yearBorn);

	// Calculate and store to a variable the number of years the animal has been on the farm: (current year - acquired year)
	int yrsOwned = getYearsDiff(getCurrentYear(), animal->yearAcquired);

	// Formatting: Leave this newline
	printf("\n");

	// Display title

	displayTitle("Details:", '~');

	// Show the tag ID
	printf("\tTag ID: %d\n", animal->tagID);

	// Show the gender in all capital letters as full words based on the gender member value
	printf("\tGender: ");
	if (animal->gender == 'F') {
		printf("FEMALE\n");
	}
	else if (animal->gender == 'M') {
		printf("MALE\n");
	}
	else {
		printf("UNDEFINED\n");
	}

	// Show the animal's birth year
	printf("\tYear Born: %d\n", animal->yearBorn);

	// Show the animal age (Hint: use the 'age' variable already calculated from above)
	printf("\tAge: ");
	if (age < 0) {
		printf("UNKNOWN\n");
	}
	else {
		printf("%d\n", age);
	}

	// Show the year the animal was acquired (year the animal was brought to the farm)
	printf("\tYear Acquired: %d\n", animal->yearAcquired);

	// Show the animal age when it was acquired (Hint: use 'ageWhenAcquired' variable already calculated from above)
	printf("\tAge when acquired: ");
	if (ageWhenAcquired < 0) {
		printf("UNKNOWN\n");
	}
	else {
		printf("%d\n", ageWhenAcquired);
	}

	// Display how many years the animal has been on the farm (since it was aquired)
	// (Hint: use the 'yrsOwned' variable already calculated from above)
	printf("\tYears on the farm: ");
	if (yrsOwned < 0) {
		printf("UNKNOWN\n");
	}
	else {
		printf("%d\n", yrsOwned);
	}

}

// +-----------------------------------------------------------------------+
// | Define the function body for the showWelcomeMessage function:         |
// +-----------------------------------------------------------------------+
void showWelcomeMessage(void)
{
	// Call the tools API helper function: displayBanner
	// Argument-1: IPC144 - OSTRICH PETTING ZOO
	// Argument-2: askterisk symbol

	displayBanner("IPC144 - OSTRICH PETTING ZOO", '*');

}

// +-----------------------------------------------------------------------+
// | Define the function body for the showGoodbyeMessage function:         |
// +-----------------------------------------------------------------------+
void showGoodbyeMessage(void)
{
	// Call the tools API helper function: displayBanner
	// Argument-1: ZOO CLOSED - SEE YOU TOMORROW!
	// Argument-2: hash/number-sign symbol

	displayBanner("ZOO CLOSED - SEE YOU TOMORROW!", '#');
}

