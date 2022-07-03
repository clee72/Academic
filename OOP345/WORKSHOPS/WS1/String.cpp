
// Workshop 1
//Date: 2019/09/14
//Section:NBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <iostream>
#include <cstring>
#include "String.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sdds {
	unsigned g_maxSize = 3;

	String::String(const char* str) {
		if (str != nullptr) {
			m_str = nullptr;
			m_str = new char[strlen(str) + 1];//dynamic allocation
			strncpy(m_str, str, strlen(str));
			m_str[strlen(str)] = '\0';
		}
		else {
			m_str = new char[1];
			m_str[0] = 0;
		}
	}

	String& String::operator=(const String& str) {
		if (this != &str) {//check if str is the same address as the current object
			delete[] m_str;
			m_str = nullptr;
			if (str.m_str != nullptr) {
				m_str = new char[g_maxSize];//dynamic allocation
				strncpy(m_str, str.m_str, g_maxSize);//copy strings
				m_str[g_maxSize] = 0;
			}
		}
		else {
			m_str = nullptr;

		}
		return *this;
	}

	void String::display(std::ostream& os) const {
		unsigned size = strlen(m_str);
		if (size < g_maxSize && m_str != nullptr) {//print strings depends on the size.
			os << m_str;
		}
		else {
			for (unsigned i = 0; i < g_maxSize; i++) {
				os << m_str[i];
			}
		}
	}

	ostream& operator<<(ostream& os, String& str) {
		static int counter = 1;//counter variable has one memory space in this translation unit
		os << counter++ << ": ";
		str.display(os);
		return os;
	}
}