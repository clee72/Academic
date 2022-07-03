// Name:Wonhwa Lee
// Seneca Student ID:076086149
// Seneca email:wlee72@myseneca.ca
// Date of completion:October 8, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor


#pragma once
#include "Reservation.h"
#include <iostream>
using namespace std;

namespace sdds {
	class Restaurant {
		Reservation* m_reserv = nullptr;
		size_t m_numReser = 0;
	public:
		Restaurant();
		Restaurant(Reservation* reservation[], size_t cnt);
		Restaurant(const Restaurant& rest);
		Restaurant& operator=(const Restaurant& rest);
		Restaurant(Restaurant && rest);
		Restaurant& operator=(Restaurant && rest);
		~Restaurant();
		size_t size() const;
		friend ostream& operator<<(ostream & os, const Restaurant& rest);
	};













}