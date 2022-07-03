//Workshop 3: Classes and Privacy
//File CRA_Account.h
//Author: Cornel
//Date: 2019/06/01
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca

#pragma once
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {
		char fName[max_name_length + 1];
		char gName[max_name_length + 1];
		int sNum;
		int year_[max_yrs];
		double balance_[max_yrs];
		int numYr;

	public:

		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);

	};
}
#endif