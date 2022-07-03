// Workshop 6 - Class with a Resource
// Contact.cpp
//Date: 2019/07/09
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#pragma warning(disable : 4996)
#include<iostream>
#include "Contact.h"
#include<cstring>
#include<iomanip>
using namespace std;

namespace sict {

	Contact::Contact() {
		name[0] = '\0';
		pNum = nullptr;
		numPN = 0;
	}

	Contact::Contact(const Contact& con) {
		if (numPN != con.numPN && con.numPN > 0)
			numPN = con.numPN;

		if (con.name[0] != '\0'&& con.name != nullptr) {
			strncpy(name, con.name, MAX_CHAR);
			name[MAX_CHAR] = '\0';
		}
		else
			name[0] = '\0';

		if (con.pNum != nullptr) {
			pNum = new long long[numPN];
			for (int i = 0; i < numPN; i++)
				pNum[i] = con.pNum[i];
		}
		else
			pNum = nullptr;
	}

	Contact& Contact::operator=(const Contact& c) {
		if (this == &c) {
			return *this;
		}
		else {
			if (c.isEmpty()) {
				name[0] = '\0';
				pNum = nullptr;
				numPN = 0;
			}
			else {
				strncpy(name, c.name, MAX_CHAR);
				name[MAX_CHAR] = '\0';
				pNum = nullptr;

				if (c.pNum != nullptr) {
					numPN = c.numPN;
					pNum = new long long[numPN];
					for (int i = 0; i < numPN; i++) {
						pNum[i] = c.pNum[i];
					}
				}
			}
		}
		return *this;
	}

	Contact& Contact::operator+=(long long p) {
		int countryCode = 0;
		int areaCode = 0;
		int sevenDigit = 0;

		countryCode = (p / 10000000) / 1000;
		areaCode = (p / 10000000) % 1000;
		sevenDigit = p % 10000000;

		bool valid = (countryCode > 0 && countryCode < 100 && areaCode >= 100 && areaCode <= 999 && sevenDigit >= 1000000 && sevenDigit <= 9999999);

		if (valid && !isEmpty()) {
			long long* pNum2 = nullptr;
			pNum2 = new long long[numPN + 1];
			for (int i = 0; i < numPN; i++) {
				pNum2[i] = pNum[i];
			}
			delete[] pNum;
			pNum = nullptr;
			pNum = pNum2;
			pNum[numPN] = p;
			numPN++;
		}
		return *this;
	}

	Contact::Contact(const char* na, const long long* pn, int n) {
		int countryCode = 0;
		int areaCode = 0;
		int sevenDigit = 0;

		if (na != nullptr && na[0] != '\0') {
			long long *pNum2 = nullptr;
			pNum2 = new long long[n];
			numPN = 0;
			strncpy(name, na, MAX_CHAR);
			name[MAX_CHAR] = '\0';

			for (int i = 0; i < n; i++) {
				countryCode = (pn[i] / 10000000) / 1000;
				areaCode = (pn[i] / 10000000) % 1000;
				sevenDigit = pn[i] % 10000000;
			}

			bool valid = countryCode > 0 && countryCode < 100 && areaCode >= 100 && areaCode <= 999 && sevenDigit >= 1000000 && sevenDigit <= 9999999;

			for (int i = 0; i < n && valid; i++) {
				pNum2[numPN] = pn[i];
				numPN++;
			}
			pNum = new long long[numPN];

			for (int i = 0; i < numPN; i++) {
				pNum[i] = pNum2[i];
			}
			delete[] pNum2;
			pNum2 = nullptr;
		}
		else {
			*this = Contact();
		}
	}

	Contact::~Contact() {
		delete[] pNum;
		pNum = nullptr;
	}

	bool Contact::isEmpty() const {
		bool result = false;
		if (name[0] == '\0' && pNum == nullptr && numPN == 0) {
			result = true;
		}
		return result;
	}

	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			int countryCode = 0;
			int areaCode = 0;
			int sevenDigit = 0;
			int lastFour, firstThree = 0;

			cout << name << endl;

			for (int i = 0; i < numPN; i++) {
				countryCode = (pNum[i] / 10000000) / 1000;
				areaCode = (pNum[i] / 10000000) % 1000;
				sevenDigit = pNum[i] % 10000000;
				firstThree = sevenDigit / 10000;
				lastFour = sevenDigit % 10000;

				if (countryCode > 0 && countryCode < 100 && areaCode >= 100 && areaCode <= 999) {
					cout << "(+" << countryCode << ")" << " " << areaCode << " " << firstThree
						<< "-" << setfill('0') << setw(4) << lastFour << endl;
				}
			}
		}
	}
}
