// Workshop 8
//Account.h
//Date: 2019/07/26
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//in_lab


#pragma once
#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H
#include "iAccount.h"
using namespace std;

namespace sict{
	class Account :public iAccount {
		double m_balance;

	public:
		Account(double bal);
		bool credit(double c_amt);
		bool debit(double d_amt);
		
	protected:
		double balance() const;
	};
}
#endif
