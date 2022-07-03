// Name:Wonhwa Lee
// Seneca Student ID:076086149
// Seneca email:wlee72@myseneca.ca
// Date of completion:November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Car.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace sdds {
	Car::Car(istream& in) {

		string temp;
		getline(in, temp, ',');
		m_maker = trim(temp);
		std::getline(in, temp, ',');
		trim(temp);

		if (temp == "" || temp == " " || temp == "n") {
			m_condition = "new";
		}
		else if (temp == "b") {
			m_condition = "broken";
		}
		else if (temp == "u") {
			m_condition = "used";
		}
		else {
			throw "Invalid record!";
		}

		std::getline(in, temp, ',');
		try {
			m_speed = std::stoi(trim(temp));
		}
		catch (...) {
			throw "Invalid record!";
		}
	}

	std::string& Car::trim(std::string& t) {
		while (t.size() > 0 && t[0] == ' ') {
			t.erase(0, 1);
		}
		while (t.size() > 0 && t[t.size() - 1] == ' ') {
			t.erase(t.size() - 1, 1);
		}
		return t;
	}

	string Car::condition() const {
		return m_condition;
	}

	double Car::topSpeed() const {
		return m_speed;
	}

	void Car::display(std::ostream& out) const {
		out << "| " << setw(10) << m_maker << " | " << setw(6) << left << condition() << std::fixed
			<< " | " << setw(6) << setprecision(2) << right << topSpeed() << " |";
	}

	Car::~Car() {}
}
