// Workshop 8
//Allocator.cpp
//Date: 2019/07/28
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#include <iostream>
#include"SavingsAccount.h"
#include"ChequingAccount.h"

using namespace std;

namespace sict {

	iAccount* CreateAccount(const char* accountType, double bal) {
		const double RATE = 0.05;
		const double TRANSFEE = 0.50;
		const double MONTHFEE = 2.00;

		iAccount*newAccount = nullptr;
		if (accountType[0] == 'S') {
			newAccount = new SavingsAccount(bal, RATE);
		}
		else if (accountType[0] == 'C') {
			newAccount = new ChequingAccount(bal, TRANSFEE, MONTHFEE);
		}
		else {
			newAccount = nullptr;
		}
		return newAccount;
	}
}