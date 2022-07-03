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

namespace  sdds {
	class Movie {
		string _title;
		size_t _year;
		string _desc;

	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker.operator()(_title);
			spellChecker.operator()(_desc);
		}
		friend ostream& operator<<(ostream& os, const Movie& m);
	};
}
