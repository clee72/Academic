// Workshop 8
//Account.cpp
//Date: 2019/07/28
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#include<iostream>
#include "Account.h"

using namespace std;

namespace sict {

	Account::Account(double bal) {
		if (bal < 0 || bal == 0)
			m_balance = 0;
		else
			m_balance = bal;
	}

	bool Account::credit(double c_amt) {
		bool result = false;
		if (c_amt > 0) {
			m_balance += c_amt;
			result = true;
		}
		return result;
	}

	bool Account::debit(double d_amt) {
		bool result = false;
		if (d_amt > 0) {
			m_balance -= d_amt;
			result = true;
		}
		return result;
	}

	double Account::balance() const {
		return m_balance;
	}
}
