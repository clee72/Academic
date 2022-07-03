//Workshop 3: Classes and Privacy
//File CRA_Account.cpp
//Author: Cornel
//Date: 2019/05/31
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS

#include "CRA_Account.h"
#include <iostream>
#include <cstring>
#include <iomanip> 

using namespace std;
using namespace sict;


namespace sict {
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		int i;
		bool valid = true;
		if (sin > max_sin || sin <min_sin) {
			valid = false;
		}
		else
			valid = true;
		if (valid) {
				strncpy(fName, familyName,max_name_length+1);
				strncpy(gName ,givenName, max_name_length+1);
				fName[max_name_length] = '\0';
				gName[max_name_length] = '\0';
				sNum = sin;
			}else {//set an empty state
			sNum = 0;
			fName[0] = '\0';
			gName[0] = '\0';
		}
	}
	bool CRA_Account::isEmpty() const {
		bool result = false;

		if (sNum != 0 && fName[0] != '\0'&& gName[0] != '\0')
			result = false;
		else
			result = true;

		return result;
	}
	void CRA_Account::display() const {
		if (sNum != 0) {
			cout << "Family Name: " << fName << endl;
			cout << "Given Name : " << gName << endl;
			cout << "CRA Account: " << sNum << endl;
		}
	}

}