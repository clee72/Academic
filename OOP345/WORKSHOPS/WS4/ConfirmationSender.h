// Name:Wonhwa Lee
// Seneca Student ID:076086149
// Seneca email:wlee72@myseneca.ca
// Date of completion:October 08, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor

#pragma once
#include <iostream>
#include"Reservation.h"
#include"Restaurant.h"
using namespace std;

namespace sdds {
	class ConfirmationSender {
		const Reservation** c_reserv;
		size_t c_cnt;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& con);
		~ConfirmationSender();
		ConfirmationSender(ConfirmationSender&& con);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend ostream& operator<<(ostream& os, const ConfirmationSender& con);
	};
}