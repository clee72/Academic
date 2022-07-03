// Workshop 5
//Date: 2019/10/18
//Section:NBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#include <iostream>
#include <string>
#include "Book.h"
#include <algorithm>
#include <iomanip>

using namespace std;

namespace sdds {
	Book::Book() {
		string m_author = "";
		string m_title = "";
		string m_country = "";
		string m_desc = "";
	}
	const string& Book::title() const {
		return m_title;
	}
	const std::string& Book::country() const {
		return m_country;
	}
	const size_t& Book::year() const {
		return m_year;
	}
	double& Book::price() {
		return m_price;
	}
	Book::Book(const std::string& strBook) {

		std::string temp = strBook.substr(0, strBook.length());
		temp = strBook.substr(0, strBook.length());

		m_author = temp.substr(0, temp.find(","));
		temp.erase(0, temp.find(",") + 1);

		m_title = temp.substr(0, temp.find(","));
		m_title.erase(0, m_title.find_first_not_of(" "));
		m_title.erase(m_title.find_last_not_of(" ") + 1);
		temp.erase(0, temp.find(",") + 1);

		m_country = temp.substr(0, temp.find(","));
		m_country.erase(0, m_country.find_first_not_of(" "));
		m_country.erase(m_country.find_last_not_of(" ") + 1);
		temp.erase(0, temp.find(",") + 1);

		string str_price = temp.substr(0, temp.find(","));
		str_price.erase(0, str_price.find_first_not_of(" "));
		str_price.erase(str_price.find_last_not_of(" ") + 1);
		m_price = stod(str_price);
		temp.erase(0, temp.find(",") + 1);

		string str_year = temp.substr(0, temp.find(","));
		str_year.erase(0, str_year.find_first_not_of(" "));
		str_year.erase(str_year.find_last_not_of(" ") + 1);
		m_year = stoi(str_year);
		temp.erase(0, temp.find(",") + 1);

		m_desc = temp.substr(0, temp.find(".") + 2);
		m_desc.erase(0, m_desc.find_first_not_of(" "));
		m_desc.erase(m_desc.find_last_not_of("\n") + 1);
	}
	ostream& operator<<(ostream& os, const Book& b) {

		os << setw(20) << b.m_author << " | ";
		os << setw(22) << b.m_title << " | ";
		os << setw(5) << b.m_country << " | ";

		os << setw(4) << b.m_year << " | ";
		os << setw(6) << setprecision(2) << fixed << b.m_price << " | ";
		os << b.m_desc << endl;

		return os;
	}
}
