// +----------------------------------------------------+
// | ================================================== |
// | =                                                = |
// | = ///////   /////     /////    //         ////// = |
// | =   //     //   //   //   //   //        //      = |
// | =   //     //   //   //   //   //        /////// = |
// | =   //     //   //   //   //   //             // = |
// | =   //      /////     /////    ///////   /////   = |
// | =                                                = |
// | =           #       #####    ######              = |
// | =          ###     ##   ##     ##                = |
// | =         ## ##    ##   ##     ##                = |
// | =        ##   ##   ######      ##                = |
// | =        #######   ##          ##                = |
// | =        ##   ##   ##          ##                = |
// | =        ##   ##   ##        ######              = |
// | =                                                = |
// | =      !!!  DO NOT MODIFY THIS FILE  !!!         = |
// | =                                                = |
// | ================================================== |
// +----------------------------------------------------+

#ifndef TOOLS__H
#define TOOLS__H

//======================================================
// Displaying Stuff...

// Show a banner (line above and below title using lineChar)
// Example: displayBanner("Title", '*');
void displayBanner(const char *title, char lineChar);

// Show a title (line below title using lineChar)
// Example: displayTitle("Title", '=');
void displayTitle(const char *title, char lineChar);

// Show a title with a single int substitution (with line below title using lineChar)
// Example: displayTitleExt("Topic-%d", 4, '-')
void displayTitleExt(const char *title, int sub, char lineChar);


//======================================================
// Date Stuff...

// Displays to standard output the current date/time in Format:YYYY-MM-DD (hh:mm:ss)
void displayCurrentDateTime(void);

// Assigns the current date/time to dt in Format:YYYY-MM-DD (hh:mm:ss)
// If dtSize is not large enough, dt will be set to "?"
void setCurrentDateTime(char *dt, int dtSize);

// Get the current year (returns -1 on error)
int getCurrentYear();

// Get the current numerical month (returns -1 on error)
int getCurrentMonth();

// get the current month day (returns -1 on error)
int getCurrentDay();

// Get years difference between year1 and year2 (order doesn't matter)
// Return value is absolute (never negative)
int getYearsDiff(int year1, int year2);

//======================================================
// Input Control Stuff...

// Guarantees a whole number is entered from standard input and returns the entered int value
int getInt();

// Guarantees a whole number is entered from standard input within a range (inclusive)
// returns: the int value entered by the user and will be within the specified min/max range
int getIntRange(int min, int max);

// Get gender initial (F=Female, M=Male, [optional: ?=Undefined])
char getGender(int allowUndefined);

// Pause for Input (Press enter to continue)
void enterToContinue(void);

#endif // TOOLS__H