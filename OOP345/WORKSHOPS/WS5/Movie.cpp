// Workshop 5
//Date: 2019/10/18
//Section:NBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#include "Movie.h"
#include <iomanip>
using namespace std;

namespace sdds
{
	Movie::Movie() {
		_title = "";
		_year = 0;
		_desc = "";
	}
	const std::string& Movie::title() const {
		return _title;
	}
	Movie::Movie(const std::string& strMovie) {
		string tmp = strMovie.substr(0, strMovie.length());

		//substract string before comma(,)
		_title = tmp.substr(0, strMovie.find(","));
		//remove the leading space
		_title.erase(0, _title.find_first_not_of(" "));
		//remove the trailing space
		_title.erase(_title.find_last_not_of(" ") + 1);
		//remove strings of m_title (including ",")
		//erase: remove string before the comma(","), so add +1, we want to remove the comma(","), too.
		tmp.erase(0, tmp.find(",") + 1);

		string str_yr = tmp.substr(0, tmp.find(","));
		str_yr.erase(0, str_yr.find_first_not_of(" "));
		str_yr.erase(str_yr.find_last_not_of(" ") + 1);
		_year = stoi(str_yr);
		tmp.erase(0, tmp.find(",") + 1);

		_desc = tmp.substr(0, tmp.find(".") + 2);//substrace strings of the _desc(including "." and "\n"), so add +2;
		_desc.erase(0, _desc.find_first_not_of(" "));
		_desc.erase(_desc.find_last_not_of(" \n") + 1);//return newline.

	}
	ostream& operator<<(ostream& os, const Movie& m) {
		os << setw(40) << m._title << " | " << setw(4) << m._year << " | " << m._desc << endl;
		return os;
	}
}
