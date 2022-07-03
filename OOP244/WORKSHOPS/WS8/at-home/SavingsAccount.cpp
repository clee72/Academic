// Workshop 8
//SavingsAccount.cpp
//Date: 2019/07/28
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#include<iostream>
#include <iomanip>
#include"SavingsAccount.h"

using namespace std;

namespace sict {

	SavingsAccount::SavingsAccount(double bal, double rate) :Account(bal) {

		if (rate > 0) {
			m_rate = rate;
		}
		else {
			m_rate = 0.0;
		}
	}

	void SavingsAccount::monthEnd() {
		Account::credit(Account::balance()*m_rate);
	}

	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << endl;
		os << "Balance: $" << fixed << setprecision(2) << Account::balance() << endl;
		os << "Interest Rate (%): " << m_rate * 100 << endl;
	}
}






