//Workshop 4 - Constructors - Test Main
//File Passenger.cpp
//Author: Cornel
//Date: 2019/06/07
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca

// TODO: add file header comments here
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
// TODO: add your headers here
#include "Passenger.h"
using namespace std;
using namespace sict;
// TODO: continue your namespace here

namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {

		pName[0] = '\0';
		dest[0] = '\0';
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* p, const char* d) {
		if (p != nullptr && d != nullptr) {
			strncpy(pName, p, M + 1);
			pName[M] = '\0';
			strncpy(dest, d, M + 1);
			dest[M] = '\0';

		}
		else {
			pName[0] = '\0';
			dest[0] = '\0';
		}
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		bool valid = true;
		if (pName[0] == '\0' || dest[0] == '\0')
			valid = true;
		else
			valid = false;
		return valid;

	}
	// TODO: implement display query here
	void Passenger::display() const {
		if (!isEmpty()) {
			cout << pName << " - " << dest << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}
	}
}