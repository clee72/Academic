//Perishable.cpp
//Date: 2019/08/04
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//ms5

#include <iostream>
#include<fstream>
#include"Perishable.h"
#include"Date.h"
#include"Error.h"
#include"Good.h"
#include"iGood.h"

using namespace std;

namespace aid {
	Perishable::Perishable() :Good('P') {
		m_expiryDate.Date::setEmpty();
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		Good::store(file, false);
		file << ',';
		file << m_expiryDate;
		if (newLine) {
			file << endl;
		}
		return file;
	}

	std::fstream& Perishable::load(std::fstream& file) {
		Good::load(file);
		m_expiryDate.read(file);
		file.get();
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Good::write(os, linear);
		if (!isEmpty() && isClear()) {
			if (linear) {
				m_expiryDate.write(os);
			}
			else {
				os << endl << " Expiry date: ";
				m_expiryDate.write(os);
			}
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is) {
		Good::read(is);
		Date temp;

		if (!is.fail()) {
			cout << " Expiry date (YYYY/MM/DD): ";
			temp.read(is);
			if (!temp.bad()) {
				m_expiryDate = temp;
			}
		}
		if (temp.bad()) {
			is.std::istream::setstate(std::ios::failbit);
			if (temp.errCode() == CIN_FAILED) {
				Good::message("Invalid Date Entry");
			}
			else if (temp.errCode() == YEAR_ERROR) {
				Good::message("Invalid Year in Date Entry");
			}
			else if (temp.errCode() == MON_ERROR) {
				Good::message("Invalid Month in Date Entry");
			}
			else if (temp.errCode() == DAY_ERROR) {
				Good::message("Invalid Day in Date Entry");
			}
			else if (temp.errCode() == PAST_ERROR) {
				Good::message("Invalid Expiry in Date Entry");
			}
		}
		return is;
	}

	const Date& Perishable::expiry() const {
		return m_expiryDate;
	}

	iGood* CreateProduct(char tag) {
		iGood* ptr;
		if (tag == 'N' || tag == 'n') {
			ptr = new Good();
		}
		else if (tag == 'P' || tag == 'p') {
			ptr = new Perishable();
		}
		else {
			ptr = nullptr;
		}
		return ptr;
	}
}





