// Name:Wonhwa Lee
// Seneca Student ID:076086149
// Seneca email:wlee72@myseneca.ca
// Date of completion:November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#include <vector>
#include "Vehicle.h"
#include <list>
#include <iterator>
#include <iostream>

namespace sdds {

	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {

			std::vector<Vehicle*>::const_iterator it;
			for (it = m_vehicles.begin(); it != m_vehicles.end(); ++it) {
				if (test(*it)) {
					vehicles.push_back(*it);//*it (object of m_vehicle)
				}
			}
		}
	};
}
