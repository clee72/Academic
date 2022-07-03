//iGood.h
//Date: 2019/08/03
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//ms4

#ifndef AID_IGOOD_H
#define AID_IGOOD_H
#include <iostream>
#include <fstream>

namespace aid {

	class iGood {
	public:
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool operator==(const char* str) const = 0;
		virtual double total_cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const iGood&) const = 0;
	};

	std::ostream& operator<<(std::ostream& os, const iGood& good);
	std::istream& operator>>(std::istream& os, iGood& good);
	double operator+=(double& value, const iGood& good);
	iGood* CreateProduct(char tag);
}
#endif