// Workshop 6 - Class with a Resource
// Contact.cpp
//Date: 2019/07/05
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//in_lab

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

				if (countryCode > 0 && countryCode < 100 && areaCode >= 100 && areaCode <= 999 && sevenDigit >= 1000000 && sevenDigit <= 9999999) {
					cout << "(+" << countryCode << ")" << " " << areaCode << " " << firstThree
						<< "-" << setfill('0') << setw(4) << lastFour << endl;
				}
			}
		}
	}
}