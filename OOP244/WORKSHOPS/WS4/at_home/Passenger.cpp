//Workshop 4 - Constructors - Test Main
//File Passenger.cpp
//Date: 2019/06/11
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
// at_home

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<iomanip>
#include "Passenger.h"

using namespace std;

namespace sict
{
	Passenger::Passenger() {
		pName[0] = '\0';
		dest[0] = '\0';
		yDepart = 0;
		mDepart = 0;
		dDepart = 0;
	}

	Passenger::Passenger(const char* p, const char* d) {
		if (p != nullptr && d != nullptr) {
			strncpy(pName, p, M);
			pName[M] = '\0';
			strncpy(dest, d, M);
			dest[M] = '\0';
			yDepart = 2019;
			mDepart = 10;
			dDepart = 1;
		}
		else {
			*this = Passenger();
		}
	}

	Passenger::Passenger(const char* p, const char* d, int year, int month, int day) {
		if (p != nullptr && d != nullptr && year >= 2019 && year <= 2021 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
			strncpy(pName, p, M);
			pName[M] = '\0';
			strncpy(dest, d, M);
			dest[M] = '\0';
			yDepart = year;
			mDepart = month;
			dDepart = day;
		}
		else {
			*this = Passenger();
		}
	}

	bool Passenger::isEmpty() const {
		bool valid = false;
		if (pName[0] != '\0' && dest[0] != '\0' && yDepart >= 2019 && yDepart <= 2021 && mDepart >= 1 && mDepart <= 12 && dDepart >= 1 && dDepart <= 31)
			valid = false;
		else
			valid = true;

		return valid;
	}

	const char*Passenger::name() const {

		if (!isEmpty()) {
			return pName;
		}
		else {
			return "";
		}
	}

	bool Passenger::canTravelWith(const Passenger& p) const {
		bool result = false;
		if ((strcmp(dest, p.dest) == 0) && (yDepart == p.yDepart) && (mDepart == p.mDepart) && (dDepart == p.dDepart)) {
			result = true;
		}
		else {
			result = false;
		}
		return result;
	}

	void Passenger::display() const {
		if (!isEmpty()) {
			cout << pName << " - " << dest << " on "
				<< yDepart << "/" << setfill('0') << setw(2)
				<< mDepart << "/" << setfill('0') << setw(2)
				<< dDepart << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}
	}
}
