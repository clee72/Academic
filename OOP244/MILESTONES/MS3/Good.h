// Good.h
//Date: 2019/07/30
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//ms3

#pragma once
#ifndef AID_GOOD_H
#define AID_GOOD_H
#include <iostream>
#include <fstream>
#include "Error.h"

namespace aid {
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;

	class Good :public Error{
		char g_type;
		char g_sku[max_sku_length+1];
		char g_unit[max_unit_length+1];
		char* g_name=nullptr;
		int g_numItem_onHand;
		int g_numItem_need;
		double g_price;
		bool g_taxable;
		Error g_errorState;

	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double itemPrice() const;
		double itemCost() const;
		void message(const char*);
		bool isClear() const;

	public:
		Good(char type='N');
		Good(const char* sku, const char* name, const char* unit);
		Good(const char* sku, const char* name, const char* unit, int numItem_onHand, bool taxable, double price, int numItem_need);
		Good(const Good&);
		Good& operator=(const Good&);
		~Good();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const Good&) const;
		int operator+=(int);
		void setEmpty();
	};

	std::ostream& operator<<(std::ostream&, const Good&);
	std::istream& operator>>(std::istream&, Good&);
	double operator+=(double&, const Good&);
}
#endif
