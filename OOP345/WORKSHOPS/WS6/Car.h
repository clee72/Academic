// Name:Wonhwa Lee
// Seneca Student ID:076086149
// Seneca email:wlee72@myseneca.ca
// Date of completion:November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "Vehicle.h"

using namespace std;

namespace sdds {
	class Car:public Vehicle {
		string m_maker;
		string m_condition;
		size_t m_speed;

	public:
		Car() = default;
		Car(std::istream& is);
		double topSpeed() const;
		void display(std::ostream&) const;
		std::string condition() const;
		std::string& trim(std::string& t);
		~Car();
	};
}
