//Date.h
//Date: 2019/07/11
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//ms1

#pragma once
#ifndef AID_DATE_H
#define AID_DATE_H

#define NO_ERROR 0
#define CIN_FAILED 1
#define DAY_ERROR 2
#define MON_ERROR 3
#define YEAR_ERROR 4
#define PAST_ERROR 5

namespace aid {
	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098;

	class Date {

		int year;
		int month;
		int mDay;
		int comp;
		int error;

		void errCode(int errorCode);
		int mdays(int year, int month) const;

	public:

		Date();
		Date(int, int, int);

		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		bool isEmpty() const;
		int errCode() const;
		bool bad() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};
	
	std::ostream& operator<< (std::ostream& ostr, const Date& date);
	std::istream& operator>> (std::istream& istr, Date& date);	
}
#endif