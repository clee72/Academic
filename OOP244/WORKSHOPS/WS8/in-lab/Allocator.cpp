// Workshop 8
//Allocator.cpp
//Date: 2019/07/26
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//in_lab

#include <iostream>
#include"SavingsAccount.h"

using namespace std;

namespace sict {
	iAccount* CreateAccount(const char* accountType, double bal) {
		const double RATE = 0.05;
		iAccount*newSavings = nullptr;
		if (accountType[0] == 'S') {
			newSavings = new SavingsAccount(bal, RATE);
		}
		return newSavings;
	}
}