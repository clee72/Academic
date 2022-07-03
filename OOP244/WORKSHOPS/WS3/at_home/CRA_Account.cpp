//Workshop 3: Classes and Privacy
//File CRA_Account.cpp
//Author: Cornel
//Date: 2019/06/01
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace sict;
using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		int digits = 0, lastDigit = 0, even = 0, sum = 0, tSum = 0, diff = 0, hDec = 0;
		int sin2 = sin;

		fName[0] = '\0';
		gName[0] = '\0';
		sNum = 0;

		if (sin2 >= min_sin && sin2 <= max_sin && familyName[0] != '\0' && givenName[0] != '\0') {
			lastDigit = sin2 % 10;
			for (int i = 0; i < 5; i++)
			{
				digits = sin2 % 100;
				even = (digits / 10) * 2;
				sum += (digits % 10) + (even / 10) + (even % 10);
				sin2 /= 100;
			}

			tSum = sum - lastDigit;
			hDec = ((tSum / 10) + 1) * 10;
			diff = hDec - tSum;

			if (diff == lastDigit) {
				sNum = sin;
				strncpy(fName, familyName, max_name_length + 1);
				fName[max_name_length] = '\0';
				strncpy(gName, givenName, max_name_length + 1);
				gName[max_name_length] = '\0';
			}
		}

		numYr = 0;
	}

	void CRA_Account::set(int year, double balance)
	{
		if (!isEmpty() && numYr < max_yrs) {
			year_[numYr] = year;
			balance_[numYr] = balance;
			numYr++;
		}
	}

	void CRA_Account::display() const
	{
		if (!isEmpty()) {
			cout << "Family Name: " << fName << endl;
			cout << "Given Name : " << gName << endl;
			cout << "CRA Account: " << sNum << endl;
			cout.setf(ios::fixed);
			cout.precision(2);
			for (int i = 0; i < max_yrs; i++) {
				cout << "Year (" << year_[i] << ") ";
				if (balance_[i] > 2.00) {
					cout << "balance owing: " << balance_[i] << endl;
				}
				else if (balance_[i] < -2.00) {
					cout << "refund due: " << -balance_[i] << endl;
				}
				else {
					cout << "No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

	bool CRA_Account::isEmpty() const
	{
		bool result = false;
		if (sNum < min_sin || sNum > max_sin)
			result = true;
		else
			result = false;
		return result;
	}

}