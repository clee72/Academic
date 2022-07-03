// Name:Wonhwa Lee
// Seneca Student ID:076086149
// Seneca email:wlee72@myseneca.ca
// Date of completion:November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Racecar.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace sdds {

	Racecar::Racecar(std::istream& in) :Car(in) {
		std::string booster;
		std::getline(in, booster, ',');
		m_booster = std::stod(trim(booster));
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return ((m_booster+1) * Car::topSpeed());
	}
}
