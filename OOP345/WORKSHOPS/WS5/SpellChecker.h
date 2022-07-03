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

using namespace std;

namespace  sdds {
	const size_t M = 5;
	class SpellChecker {
		string m_badWords[M] = { " " };
		string m_goodWords[M] = { " " };

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}
