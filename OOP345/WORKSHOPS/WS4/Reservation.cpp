// Name:Wonhwa Lee
// Seneca Student ID:076086149
// Seneca email:wlee72@myseneca.ca
// Date of completion:October 08, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor

#include <iostream>
#include <algorithm>
#include <iomanip>
#include"Reservation.h"

using namespace std;

namespace sdds {

	Reservation::Reservation() {
		string m_id = "";
		string m_name = "";
		string m_email = "";
	}
	Reservation::Reservation(const std::string& m_res) {
		m_id = m_res.substr(0, m_res.find(':'));
		//move(), erase() returns the strings without ' '.
		m_id.erase(remove(m_id.begin(), m_id.end(), ' '), m_id.end());

		m_name = m_res.substr(m_res.find(':') + 1, m_res.find(',') - 1);
		m_name.erase(remove(m_name.begin(), m_name.end(), ' '), m_name.end());

		m_name = m_res.substr(m_res.find(':') + 1, m_res.find(',') - m_res.find(':') - 1);
		m_name.erase(remove(m_name.begin(), m_name.end(), ' '), m_name.end());

		auto emailEnd = m_res.find(',', m_res.find(',') + 1);
		m_email = m_res.substr(m_res.find(',') + 1, emailEnd - m_res.find(',') - 1);
		m_email.erase(remove(m_email.begin(), m_email.end(), ' '), m_email.end());
		m_email.insert(0, "<");
		m_email.append(">");

		auto numEnd = m_res.find(',', emailEnd + 1);
		m_partySize = stoi(m_res.substr(emailEnd + 1, numEnd - emailEnd));

		auto dayEnd = m_res.find(',', numEnd + 1);
		m_day = stoi(m_res.substr(numEnd + 1, dayEnd - numEnd));

		m_hour = stoi(m_res.substr(dayEnd + 1, m_res.length() - dayEnd));
	}

	ostream& operator<<(ostream& os, const Reservation& r) {

		string str_temp = "";

		if (r.m_hour >= 6 && r.m_hour <= 9) {
			str_temp = "Breakfast on day ";
		}
		else if (r.m_hour >= 11 && r.m_hour <= 15) {
			str_temp = "Lunch on day ";
		}
		else if (r.m_hour >= 17 && r.m_hour <= 21) {
			str_temp = "Dinner on day ";
		}
		/*	else {
				str_temp = "Drinks on day ";
			}*/
		else if ((r.m_hour >= 22 && r.m_hour <= 24) || (r.m_hour == 5) || (r.m_hour == 10) || (r.m_hour == 16)) {
			str_temp = "Drinks on day ";
		}
		os << "Reservation " << r.m_id << ": " << setw(10) << right << r.m_name << "  "
			<< setw(20) << left << r.m_email << "    " << str_temp << r.m_day << " @ "
			<< r.m_hour << ":00 for " << r.m_partySize << " people." << endl;

		return os;
	};
}