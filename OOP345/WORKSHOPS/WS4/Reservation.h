// Name:Wonhwa Lee
// Seneca Student ID:076086149
// Seneca email:wlee72@myseneca.ca
// Date of completion:October 04, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor

#pragma once
#include <string>
using namespace std;

namespace sdds {
	class Reservation {

		string m_id;
		string m_name;
		string m_email;
		size_t m_partySize;
		size_t m_day;
		size_t m_hour;

	public:
		Reservation();
		Reservation(const std::string& m_res);
		friend ostream& operator<<(std::ostream& os, const Reservation& res);
	};
}