// Name:Wonhwa Lee
// Seneca Student ID:076086149
// Seneca email:wlee72@myseneca.ca
// Date of completion:October 08, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor

#include"Restaurant.h"

using namespace std;

namespace sdds {
	Restaurant::Restaurant() {}
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		//dynamic allocation for the number of reservation
		m_numReser = cnt;
		m_reserv = new Reservation[m_numReser];
		for (size_t i = 0; i < m_numReser; i++) {
			//assign reservation information to the current object by dereferencing the pointer(array elements)
			m_reserv[i] = *reservations[i];
		}
	}
	Restaurant::Restaurant(const Restaurant& rest) {
		if (this != &rest) {
			m_numReser = rest.m_numReser;
			if (rest.m_reserv != nullptr) {
				m_reserv = new Reservation[m_numReser];
				for (size_t i = 0; i < m_numReser; i++) {
					m_reserv[i] = rest.m_reserv[i];
				}
			}
			else {
				m_reserv = nullptr;
			}
		}
	}
	Restaurant& Restaurant::operator=(const Restaurant& rest) {
		if (this != &rest) {//self assignment checking
			if (rest.m_reserv != nullptr) {
				delete[] m_reserv;
				m_reserv = new Reservation[m_numReser];
				for (size_t i = 0; i < m_numReser; i++) {
					m_reserv[i] = rest.m_reserv[i];
				}
			}
			m_numReser = rest.m_numReser;
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant && rest) {
		*this = move(rest);
	}
	//move operator:transferring temporary object to the existing object
	Restaurant& Restaurant::operator=(Restaurant && rest) {
		if (this != &rest) {
			m_numReser = rest.m_numReser;
			rest.m_numReser = 0;
			m_reserv = rest.m_reserv;
			rest.m_reserv = nullptr;
		}
		return *this;
	}
	Restaurant::~Restaurant() {
		delete[] m_reserv;
		m_reserv = nullptr;
	}
	size_t Restaurant::size() const {
		return m_numReser;
	}
	ostream& operator<<(ostream & os, const Restaurant& rest) {
		os << "--------------------------" << std::endl
			<< "Fancy Restaurant" << std::endl
			<< "--------------------------" << std::endl;
		if (rest.m_numReser == 0) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < rest.m_numReser; i++) {
				os << rest.m_reserv[i];
			}
		}
		os << "--------------------------" << std::endl;

		return os;
	}
}