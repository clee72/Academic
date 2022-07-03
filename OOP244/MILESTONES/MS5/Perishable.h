//Perishable.h
//Date: 2019/08/04
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//ms5

#ifndef AID_PERISHABLE_H
#define AID_PERISHABLE_H

#include<fstream>
#include"Good.h"
#include "Date.h"

namespace aid {

	class Perishable :public Good {
		Date m_expiryDate;
	public:
		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};
}
#endif