// Workshop 8
//ChequingAccount.h
//Date: 2019/07/28
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#pragma once
#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include "Account.h"

namespace sict {
	class ChequingAccount :public Account {
		double m_transFee;
		double m_monthFee;

	public:
		ChequingAccount(double bal, double transFee, double monthFee);
		bool credit(double credit);
		bool debit(double debit);
		void monthEnd();
		void display(std::ostream& os) const;
	};
}
#endif
