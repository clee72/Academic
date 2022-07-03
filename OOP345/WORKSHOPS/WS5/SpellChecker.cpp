// Workshop 5
//Date: 2019/10/18
//Section:NBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#include "SpellChecker.h"
#include <fstream>
#include <string>

using namespace std;

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		fstream file(filename);
		string str;
		size_t i = 0;
		if (file) {
			do {
				if (file.is_open()) {
					getline(file, str);
					auto badEnd = str.find(' ');
					m_badWords[i] = str.substr(0, badEnd + 1);
					m_badWords[i].erase(0, m_badWords[i].find_first_not_of(' '));
					m_badWords[i].erase(m_badWords[i].find_last_not_of(' ') + 1);

					auto goodEnd = str.find('\r', badEnd + 1);
					m_goodWords[i] = str.substr(badEnd + 1, goodEnd - badEnd - 1);
					m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(' '));
					m_goodWords[i].erase(m_goodWords[i].find_last_not_of(' ') + 1);
					i++;
				}
			} while (!file.eof() && i < M);

		}
		else {
			throw "Bad file name!";
		}
	}

	void SpellChecker::operator()(std::string& text) const {
		size_t found;
		for (size_t i = 0; i < M; i++) {
			while ((found = text.find(m_badWords[i])) != string::npos) {
				text.replace(found, m_badWords[i].length(), m_goodWords[i]);
			}
		}
	}
}
