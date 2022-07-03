// Workshop 8
//SavingsAccount.h
//Date: 2019/07/28
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#pragma once
#ifndef SICT_SAVINGSACCOUNT_
#define SICT_SAVINGSACCOUNT_
#include "Account.h"

using namespace std;

namespace sict {
	class SavingsAccount :public Account {
		double m_rate;
	public:
		SavingsAccount(double bal, double rate);
		void monthEnd();
		void display(std::ostream& os) const;
	};
}
#endif

