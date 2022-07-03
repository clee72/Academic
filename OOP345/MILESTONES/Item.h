

#pragma once
#include <string>
#include "Utilities.h"

using namespace std;
class Item {
	string m_name;
	string m_description;
	unsigned int m_serialNumber;
	unsigned int m_quantity;
	unsigned int static m_widthField;

public:
	Item(const std::string& record);
	const std::string& getName() const;
	const unsigned int getSerialNumber();
	const unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};
