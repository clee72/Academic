// Workshop 2
//Date: 2019/09/21
//Section:NBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#include <string>

namespace sdds {
	class Text {

		std::string* m_str;
		int str_num;

	public:
		Text();
		Text(const std::string&);
		Text(const Text& t);
		Text(Text&& t);
		Text& operator=(const Text& t);
		Text& operator=(Text&& t);
		~Text();
		size_t size() const;
	};
}