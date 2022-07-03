// Workshop 9
//Data.cpp
//Date: 2019/08/02
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//in_lab


#include<iostream>
#include <iomanip>
#include "Data.h"

using namespace std;

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//

	// answers outputs statistics for visual validation of data
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		int populationDiff = (population[n - 1] - population[0]);
		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is " << fixed << setprecision(2) << populationDiff / 1000000.00 << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		cout << "Violent Crime trend is ";
		if ((violentCrimeRate[n - 1] - violentCrimeRate[0]) < 0) {
			cout << "down" << endl;
		}
		else if (violentCrimeRate[n - 1] - violentCrimeRate[0] > 0) {
			cout << "up" << endl;
		}
		else {
			cout << "the same" << endl;
		}

		// Q3 print the GTA number accurate to 0 decimal places
		cout << "There are " << average(grandTheftAuto, n) / 1000000.00 << " million Grand Theft Auto incidents on average a year" << endl;

		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;
	}
}