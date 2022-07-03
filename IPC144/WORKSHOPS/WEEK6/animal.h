// -------------------------------------------------------
// Name      : WONHWA LEE	
// Student ID: 076086149
// Email     : wlee72@myseneca.ca
// Section   :  144SGG
// Assessment: In-Lab -> Quiz #6
// ---

// =================================================================================================
// NOTE:
// Only modify the parts that state: "You do this!!!(See instructions describing the animal.h file)"
// =================================================================================================

#ifndef ANIMAL__H
#define ANIMAL__H

#define DATE_LEN 22

struct Animal
{
    int tagID;                          // Note: Possible range 1000 - 9999
    char gender;                        // Note: Possible values: M | F | ?
    int yearBorn;
    int yearAcquired;
    char dateTimeCreated[DATE_LEN + 1]; // Note: Formatted as 'YYYY-MM-DD (hh:mm AM)'
};

// Set animal argument with user input values
void setAnimalInfo(struct Animal *animal);

// Show the animal info
void displayAnimalInfo(const struct Animal *animal);

// Show an opening banner message
void showWelcomeMessage(void);

// Show a goodbye banner message
void showGoodbyeMessage(void);
#endif // ANIMAL__H
