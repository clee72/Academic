// Date.cpp
//Date: 2019/08/04
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//ms5

#include<iostream>
#include "Date.h"
#include<iomanip>
using namespace std;

namespace aid {

	Date::Date() {
		year = 0;
		month = 0;
		mDay = 0;
		error = NO_ERROR;
		comp = 0;
	}

	void Date::setEmpty() {
		year = 0;
		month = 0;
		mDay = 0;
		error = NO_ERROR;
		comp = 0;
	}

	Date::Date(int yr, int mth, int day) {
		int mDays = mdays(yr, mth);

		if (yr < min_year || yr > max_year) {
			setEmpty();
			error = YEAR_ERROR;
		}
		else if (mth < 1 || mth>12) {
			setEmpty();
			error = MON_ERROR;
		}
		else if (day<1 || day>mDays) {
			setEmpty();
			error = DAY_ERROR;
		}

		else if (yr >= min_year && yr <= max_year && mth >= 1 && mth <= 12 && day >= 1 && day <= mDays) {
			comp = yr * 372 + mth * 31 + day;
			if (comp >= min_date) {
				year = yr;
				month = mth;
				mDay = day;
				error = NO_ERROR;
			}
			else {
				error = PAST_ERROR;
			}
		}
		else {
			setEmpty();
		}
	}

	int Date::mdays(int year, int mon) const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode) {
		error = errorCode;
	}

	bool Date::operator==(const Date& rhs) const {
		return this->comp == rhs.comp;
	}

	bool Date::operator!=(const Date& rhs) const {
		return this->comp != rhs.comp;
	}

	bool Date::operator<(const Date& rhs) const {
		return this->comp < rhs.comp;
	}

	bool Date::operator>(const Date& rhs) const {
		return this->comp > rhs.comp;
	}

	bool Date::operator<=(const Date& rhs) const {
		return this->comp <= rhs.comp;
	}

	bool Date::operator>=(const Date& rhs) const {
		return this->comp >= rhs.comp;
	}

	bool Date::isEmpty() const {
		return year == 0 || month == 0 || mDay == 0;

	}
	int Date::errCode() const {
		return error;
	}

	bool Date::bad() const {
		return error != NO_ERROR;
	}

	std::istream& Date::read(std::istream& istr) {

		char ignore;
		istr >> year >> ignore >> month >> ignore >> mDay;
		int mDays = mdays(year, month);

		if (istr.fail()) {
			setEmpty();
			error = CIN_FAILED;
		}
		else if (year < min_year || year > max_year) {
			setEmpty();
			error = YEAR_ERROR;
		}
		else if (month < 1 || month>12) {
			setEmpty();
			error = MON_ERROR;
		}
		else if (mDay<1 || mDay>mDays) {
			setEmpty();
			error = DAY_ERROR;
		}
		else if (year * 372 + month * 31 + mDay < min_date) {
			setEmpty();
			error = PAST_ERROR;
		}
		else {
			istr.clear();

			error = NO_ERROR;
		}
		comp = year * 372 + month * 31 + mDay;
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr) const {
		char del = '/';
		ostr << year << del;
		ostr.fill('0');
		ostr.width(2);
		ostr << month << del;
		ostr.fill(' '); // 
		ostr.width(2);
		ostr << mDay;
		return ostr;
	}

	std::ostream& operator<< (std::ostream& ostr, const Date& date) {
		date.write(ostr);
		return ostr;
	}

	std::istream& operator>> (std::istream& istr, Date& date) {
		date.read(istr);
		return istr;
	}
}