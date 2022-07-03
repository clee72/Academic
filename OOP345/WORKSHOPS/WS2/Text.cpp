
// Workshop 2
//Date: 2019/09/21
//Section:NBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include "Text.h"
#include <string>
#include <fstream>

namespace sdds {

	Text::Text() :m_str{ nullptr }, str_num{ 0 } {}

	//file stream: read strings from the file
	Text::Text(const std::string& fname) {
		std::ifstream fin(fname);
		str_num = 0;
		m_str = nullptr;

		if (!fin) { return; }
		while (!fin.eof()) {
			char my_char = fin.get();
			if (my_char == ' ') {
				str_num++;
			}
		}

		m_str = new std::string[str_num];
		for (int i = 0; i < str_num; i++) {
			std::getline(fin, m_str[i], ' ');
		}
	}

	//copy constructor
	Text::Text(const Text& t) {
		*this = t;
	}

	//move constructor
	Text::Text(Text&& m) { *this = std::move(m); }

	//copy assignment operator
	Text& Text::operator=(const Text& t) {
		if (this != &t) {
			str_num = t.str_num;
			if (t.m_str != nullptr) {
				m_str = new std::string[str_num];
				for (int i = 0; i < str_num; i++) {
					m_str[i] = t.m_str[i];
				}
			}
		}
		else {
			m_str = nullptr;
		}
		return *this;
	}
	//move assingment operator
	Text& Text::operator=(Text&& m) {
		if (this != &m) {
			m_str = m.m_str;
			str_num = m.str_num;
			m.m_str = nullptr;//set to empty state
			m.str_num = 0;
		}
		return *this;
	}
	//destructor
	Text::~Text() {
		delete[] m_str;
		m_str = nullptr;
	}

	size_t Text::size() const {
		return str_num;
	}
}
