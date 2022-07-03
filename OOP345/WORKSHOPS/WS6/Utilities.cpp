// Name:Wonhwa Lee
// Seneca Student ID:076086149
// Seneca email:wlee72@myseneca.ca
// Date of completion:November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include "Utilities.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {

		Vehicle* result=nullptr;
		char tag;
		char delim;
		std::string line;
		std::getline(in, line);
		std::stringstream ss(line);
		ss >> tag >> delim;

		if (ss) {
			switch (tag) {
			case 'C':
			case 'c':
				result = new Car(ss);
				break;
			case 'R':
			case 'r':
				result = new Racecar(ss);
				break;
			default:
				throw tag;
				break;
			}
		}
		else {
			result = nullptr;
		}
		return result;
	}
}
