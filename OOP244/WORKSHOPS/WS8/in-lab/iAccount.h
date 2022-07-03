//Workshop 8
//iAccount.h
//Date: 2019/07/26
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//in_lab


#pragma once
#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H

#include<iostream>
using namespace std;

namespace sict {

	class iAccount {

	public:
		virtual ~iAccount() {};
		virtual	bool credit(double c_amt) = 0;
		virtual bool debit(double d_amt) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream& os) const = 0;
	};

	iAccount* CreateAccount(const char* account, double bal);
}
#endif



