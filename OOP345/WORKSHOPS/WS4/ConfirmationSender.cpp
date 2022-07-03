// Name:Wonhwa Lee
// Seneca Student ID:076086149
// Seneca email:wlee72@myseneca.ca
// Date of completion:October 08, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor


#include <iostream>
#include "ConfirmationSender.h"


namespace sdds {
	ConfirmationSender::ConfirmationSender() {
		c_reserv = nullptr;
		c_cnt = 0;
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& con) {
		c_cnt = con.c_cnt;
		if (c_cnt > 0) {
			c_reserv = const_cast<const Reservation**>(new Reservation*[c_cnt]);
			for (size_t i = 0; i < c_cnt; i++) {
				c_reserv[i] = con.c_reserv[i];
			}
		}
		else {
			c_reserv = nullptr;
		}
	}
	ConfirmationSender::~ConfirmationSender() {
		delete[] c_reserv;
	}
	//move constructor
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& con) {
		c_cnt = con.c_cnt;
		c_reserv = con.c_reserv;
		con.c_cnt = 0;
		con.c_reserv = nullptr;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool found = true;
		for (size_t i = 0; i < c_cnt && found; i++) {
			if (c_reserv[i] == &res) {
				found = false;
			}
		}//resize the array
		if (found) {
			Reservation** temp = new Reservation*[c_cnt + 1];
			for (size_t i = 0; i < c_cnt; i++) {
				temp[i] = const_cast<Reservation*>(c_reserv[i]);
			}
			delete[] c_reserv;
			c_reserv = const_cast<const Reservation**>(temp);
			c_reserv[c_cnt++] = &res;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool found = true;//delete the elements
		size_t i = 0;

		for (; i < c_cnt&& found; i++) {
			if (c_reserv[i] == &res) {
				found = false;
			}
		}
		if (!found) {
			for (; i < c_cnt; i++)
				c_reserv[i - 1] = c_reserv[i];

			if (c_cnt) {
				c_reserv[c_cnt - 1] = nullptr;
				c_cnt--;
			}
		}
		return *this;
	}
	ostream& operator<<(ostream& os, const ConfirmationSender& con) {
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (con.c_cnt == 0) {
			os << "The object is empty!" << endl;
		}
		else {
			for (size_t i = 0; i < con.c_cnt; i++)
				os << *con.c_reserv[i];
		}
		os << "--------------------------" << endl;
		return os;
	}

}