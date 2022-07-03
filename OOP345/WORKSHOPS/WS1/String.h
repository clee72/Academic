
// Workshop 1
//Date: 2019/09/14
//Section:NBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#pragma once
#include <iostream>

namespace sdds {
	extern unsigned g_maxSize;

	class String {
		char* m_str;//using pointer member variable to allocate memory dynamically
	public:
		String(const char* str);
		String& operator=(const String& str);
		void display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, String& obj);
}
