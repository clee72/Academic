// Good.cpp
//Date: 2019/07/30
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//ms3

#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Good.h"
using namespace std;

namespace aid {

	void Good::name(const char* n) {
		if (n == nullptr || n[0] == '\0') {
			delete[] g_name;
			g_name = nullptr;
		}
		else {
			if (g_name != nullptr) {
				delete[] g_name;
				g_name = nullptr;
			}
			g_name = new char[max_name_length + 1];
			strncpy(g_name, n, max_name_length);
			g_name[max_name_length] = '\0';
		}
	}

	const char* Good::name() const {
		const char* result;
		if (g_name != nullptr)
			result = g_name;
		else
			result = nullptr;
		return result;
	}

	const char* Good::sku() const {
		return g_sku;
	}

	const char* Good::unit() const {
		return g_unit;
	}

	bool Good::taxed() const {
		return g_taxable;
	}

	double Good::itemPrice() const {
		return g_price;
	}

	double Good::itemCost() const {
		double result = 0;
		if (g_taxable == true) {
			result = (itemPrice()*tax_rate) + itemPrice();
		}
		else {
			result = itemPrice();
		}
		return result;
	}

	void Good::message(const char* errorMessage) {
		g_errorState.message(errorMessage);
	}

	bool Good::isClear() const {
		return g_errorState.isClear();
	}

	Good::Good(char c) {
		g_type = c;
		g_sku[0] = '\0';
		g_unit[0] = '\0';
		g_name = nullptr;
		g_numItem_onHand = 0;
		g_numItem_need = 0;
		g_price = 0;
		g_taxable = false;
	}

	Good::Good(const char * sku, const char * name, const char * unit) {
		bool valid = sku != nullptr&&  name != nullptr && unit != nullptr;
		if (valid) {
			g_type = 'N';
			strncpy(g_sku, sku, max_sku_length);
			g_sku[max_sku_length] = '\0';
			Good::name(name);
			strncpy(g_unit, unit, max_unit_length);
			g_unit[max_unit_length] = '\0';
			g_numItem_onHand = 0;
			g_taxable = true;
			g_price = 0;
			g_numItem_need = 0;
		}
		else {
			setEmpty();
		}
	}

	Good::Good(const char* sku, const char* name, const char* unit, int numItem_onHand, bool taxable, double price, int numItem_need) {
		bool valid = sku != nullptr&&  name != nullptr && unit != nullptr;
		if (valid) {
			strncpy(g_sku, sku, max_sku_length);
			g_sku[max_sku_length] = '\0';
			Good::name(name);
			strncpy(g_unit, unit, max_unit_length);
			g_unit[max_unit_length] = '\0';
			g_numItem_onHand = numItem_onHand;
			g_taxable = taxable;
			g_price = price;
			g_numItem_need = numItem_need;
		}
		else {
			setEmpty();
		}
	}

	Good::Good(const Good& good) {
		strncpy(g_sku, good.g_sku, max_sku_length);
		g_sku[max_sku_length] = '\0';
		strncpy(g_unit, good.g_unit, max_unit_length);
		g_unit[max_unit_length] = '\0';
		g_numItem_onHand = good.g_numItem_onHand;
		g_numItem_need = good.g_numItem_need;
		g_price = good.g_price;
		g_taxable = good.g_taxable;
		g_errorState = good.g_errorState;

		delete[] g_name;
		g_name = nullptr;
		if (good.g_name != nullptr) {
			g_name = new char[max_name_length + 1];
			strncpy(g_name, good.g_name, max_name_length);
			g_name[max_name_length] = '\0';
		}
		else {
			g_name = nullptr;
		}
	}

	Good& Good::operator=(const Good& good) {
		if (this != &good) {
			strncpy(g_sku, good.g_sku, max_sku_length);
			g_sku[max_sku_length] = '\0';
			strncpy(g_unit, good.g_unit, max_unit_length);
			g_unit[max_unit_length] = '\0';

			g_numItem_onHand = good.g_numItem_onHand;
			g_numItem_need = good.g_numItem_need;
			g_price = good.g_price;
			g_taxable = good.g_taxable;
			g_errorState = good.g_errorState;

			delete[] g_name;
			g_name = nullptr;
			if (good.g_name != nullptr) {
				g_name = new char[max_name_length + 1];
				strncpy(g_name, good.g_name, max_name_length);
				g_name[max_name_length] = '\0';
			}
			else {
				g_name = nullptr;
			}
		}
		return *this;
	}

	Good::~Good() {
		delete[] g_name;
		g_name = nullptr;
	}

	std::fstream& Good::store(std::fstream& file, bool newLine) const {
		if (!isEmpty()) {
			file << g_type << ',' << g_sku << ',' << g_unit << ',' << g_name << ','
				<< g_numItem_onHand << ',' << g_numItem_need << ',' <<
				g_price << ',' << g_taxable;
			if (newLine) {
				file << endl;
			}
		}
		return file;
	}

	std::fstream& Good::load(std::fstream& file) {
		//char t_type;
		char t_sku[max_sku_length + 1];
		char t_unit[max_unit_length + 1];
		char t_name[max_name_length + 1];
		int t_numItem_onHand;
		int t_numItem_need;
		double t_price;
		bool t_taxable;
		Good temp;
		if (file.is_open()) {
			file.getline(t_sku, max_sku_length + 1, ',');
			file.getline(t_unit, max_unit_length + 1, ',');
			file.getline(t_name, max_name_length + 1, ',');

			file >> t_numItem_onHand;
			file.ignore();
			file >> t_numItem_need;
			file.ignore();
			file >> t_price;
			file.ignore();
			file >> t_taxable;
			file.ignore();
			temp = Good(t_sku, t_unit, t_name, t_numItem_onHand, t_numItem_need, t_price, t_taxable);
		}
		*this = temp;
		return file;
	}

	std::ostream& Good::write(std::ostream& os, bool linear) const {
		if (!g_errorState.isClear()) {
			g_errorState.message();
		}
		else {
			if (!isEmpty()) {
				if (linear) {
					os << left << setw(max_sku_length) << sku() << '|';
					os << left << setw(20) << name() << '|';
					os << right << fixed << setprecision(2) << setw(7) << itemCost() << '|';
					os << right << setw(4) << quantity() << '|';
					os << left << setw(10) << unit() << '|';
					os << right << setw(4) << qtyNeeded() << '|';
				}
				else {
					os << " Sku : " << sku() << endl;
					os << " Name (no spaces): " << setw(74) << name() << endl;
					os << " Price: " << itemPrice() << endl;

					if (taxed()) {
						os << " Price after tax: " << itemCost() << endl;
					}
					else {
						os << "N/A" << endl;
					}
					os << " Quantity on hand: " << quantity() << endl;
					os << " Quantity needed: " << qtyNeeded() << endl;
				}
			}
			else {
				os << left << setw(max_sku_length) << " " << '|';
				os << left << setw(20) << " " << '|';
				os << right << fixed << setprecision(2) << setw(7) << itemCost() << '|';
				os << right << setw(4) << quantity() << '|';
				os << left << setw(10) << unit() << '|';
				os << right << setw(4) << qtyNeeded() << '|';
			}
		}
		return os;
	}

	std::istream& Good::read(std::istream& is) {
		char sku[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit[max_unit_length + 1];
		char taxed_ = '\0';
		int numItem_onHand = 0;
		int numItem_need = 0;
		double price = 0;
		bool taxable = true;

		cout << " Sku: ";
		is.getline(sku, max_sku_length + 1);
		cout << " Name (no spaces): ";
		is.getline(name, max_name_length + 1);
		cout << " Unit: ";
		is.getline(unit, max_unit_length + 1);

		cout << " Taxed? (y/n): ";
		is >> taxed_;
		is.ignore();

		if (taxed_ == 'Y' || taxed_ == 'y' || taxed_ == 'N' || taxed_ == 'n') {
			if (taxed_ == 'Y' || taxed_ == 'y')
				taxable = true;
			else
				taxable = false;

			cout << " Price: ";
			is >> price;

			if (is.fail()) {
				g_errorState.message("Invalid Price Entry");
			}
			else {
				cout << " Quantity on hand: ";
				is >> numItem_onHand;
				is.ignore();

				if (is.fail()) {
					g_errorState.message("Invalid Quantity Entry");
				}
				else {
					cout << " Quantity needed: ";
					is >> numItem_need;
					is.ignore();

					if (is.fail()) {
						g_errorState.message("Invalid Quantity Needed Entry");
					}
					else {
						g_errorState.message();
						Good temp(sku, name, unit, numItem_onHand, taxable, price, numItem_need);
						*this = temp;
					}
				}
			}
		}
		else {
			g_errorState.message("Only (Y)es or (N)o are acceptable");
			is.std::istream::setstate(std::ios::failbit);
		}

		return is;
	}

	bool Good::operator==(const char* sku) const {
		return strcmp(g_sku, sku) == 0;
	}

	double Good::total_cost() const {
		double totalCost = 0;
		totalCost = itemCost()*quantity();
		return totalCost;
	}

	void Good::quantity(int n) {
		if (n > 0) {
			g_numItem_onHand = n;
		}
	}

	bool Good::isEmpty() const {
		return g_name == nullptr || g_sku[0] == '\0' || g_unit == '\0';
	}

	int Good::qtyNeeded() const {
		return g_numItem_need;
	}

	int Good::quantity() const {
		return g_numItem_onHand;
	}

	bool Good::operator>(const char* sku) const {
		bool result = false;
		if (strcmp(g_sku, sku) > 0)
			result = true;
		return result;
	}

	bool Good::operator>(const Good& obj) const {
		bool result = false;
		if (strcmp(g_name, obj.g_name) > 0)
			result = true;
		return result;
	}

	int Good::operator+=(int units) {
		int result = 0;
		if (units > 0)
			result = g_numItem_onHand + units;
		else {
			result = g_numItem_onHand;
		}
		return result;
	}

	std::ostream& operator<<(std::ostream& os, const Good& g) {
		g.write(os, true);
		return os;
	}

	std::istream& operator>>(std::istream& is, Good& g) {
		g.read(is);
		return is;
	}

	double operator+=(double& d, const Good& total) {
		d += total.total_cost();
		return d;
	}

	void Good::setEmpty() {
		g_type = 'N';
		g_sku[0] = '\0';
		g_unit[0] = '\0';
		g_name = nullptr;
		g_numItem_onHand = 0;
		g_numItem_need = 0;
		g_price = 0;
		g_taxable = false;
	}
}
