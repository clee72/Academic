// Workshop 8
//ChequingAccount.cpp
//Date: 2019/07/28
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"

using namespace std;

namespace sict {

	ChequingAccount::ChequingAccount(double bal, double transFee, double monthFee) :Account(bal) {

		if (transFee > 0) {
			m_transFee = transFee;
		}
		else {
			m_transFee = 0.0;
		}

		if (monthFee > 0) {
			m_monthFee = monthFee;
		}
		else {
			m_monthFee = 0.0;
		}
	}

	bool ChequingAccount::credit(double credit) {
		bool result = false;
		if (Account::credit(credit)) {
			Account::debit(m_transFee);
			result = true;
		}
		return result;
	}

	bool ChequingAccount::debit(double debit) {
		bool result = false;
		if (Account::debit(debit)) {
			Account::debit(m_transFee);
			result = true;
		}
		return result;
	}

	void ChequingAccount::monthEnd() {
		credit(debit(m_monthFee));
	}

	void ChequingAccount::display(std::ostream& os)const {
		os << "Account type: Chequing" << endl;
		os << "Balance: $" << fixed << setprecision(2) << balance() << endl;
		os << "Per Transaction Fee: " << fixed << setprecision(2) << m_transFee << endl;
		os << "Monthly Fee: " << fixed << setprecision(2) << m_monthFee << endl;
	}
}