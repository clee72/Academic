// Workshop 5
//Date: 2019/10/18
//Section:NBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#pragma once
#include <iostream>
#include <string>
#include "SpellChecker.h"
using namespace std;

namespace sdds {
	class Book {
		string m_author;
		string m_title;
		string m_country;
		size_t m_year;
		double m_price;
		string m_desc;

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);

		//This is a template function, it must be implemented in the header!
		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker.operator()(m_desc);
		}
		friend ostream& operator<<(ostream& os, const Book& b);
	};
}
