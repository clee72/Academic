//Final Project: MS 3
// Name: Wonhwa Lee	
// Seneca Student ID: 076086149
// Seneca email: wlee72@myseneca.ca
// Date of completion: November 29, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
#include <fstream>
#include <cstring>

char Utilities::m_delimiter = 0;
void Utilities::setFieldWidth(size_t width) {
	m_widthField = width;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	std::string t;
	auto new_pos = str.find(getDelimiter(), next_pos);//find delimeter from the index # next_pos and return the postion of the delimeter
	t = str.substr(next_pos, new_pos - next_pos);
	if (t != "") more = true;

	size_t cnt = 0;
	try {
		if (t.find(m_delimiter) == std::string::npos) {
			cnt++;
			more = false;
			if (cnt == 2) throw 2;
		}
	}
	catch (...) {
		std::cout << "An exception occurred." << std::endl;
	}

	size_t len = strlen(t.c_str());
	if (m_widthField < len) {
		m_widthField = len;
	}
	next_pos = new_pos + 1;
	return t;
}

void Utilities::setDelimiter(const char del) {
	m_delimiter = del;
}

const char Utilities::getDelimiter() const {
	return m_delimiter;
}



