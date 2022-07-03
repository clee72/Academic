//Final Project: MS 3
// Name: Wonhwa Lee	
// Seneca Student ID: 076086149
// Seneca email: wlee72@myseneca.ca
// Date of completion: November 29, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Item.h"
#include "Utilities.h"
#include <string>
#include <iomanip>

using namespace std;
unsigned int Item::m_widthField = 0;

Item::Item(const std::string& record) {
	
	Utilities u;
	bool more = true;
	size_t next_p = 0;

	m_name = u.extractToken(record, next_p, more);
	m_widthField = u.getFieldWidth();
	m_serialNumber = stoi(u.extractToken(record, next_p, more));
	m_quantity = stoi(u.extractToken(record, next_p, more));
	m_description = u.extractToken(record, next_p, more);
}

const std::string& Item::getName() const {
	return m_name;
}

const unsigned int Item::getSerialNumber() {
	unsigned int tmp = m_serialNumber;
	m_serialNumber++;
	return tmp;
}

const unsigned int Item::getQuantity() const {
	return m_quantity;
}

void Item::updateQuantity() {
	if (m_quantity > 0) {
		m_quantity -= 1;
	}
}

void Item::display(std::ostream& os, bool full) const {
	os << setw(m_widthField) << left << getName() << " [" <<right<<setfill('0')<< setw(6) << m_serialNumber << setfill(' ') << "]";
	if (!full) {
		os << endl;
	}
	else {
		os << " Quantity: " << left << setw(m_widthField) << getQuantity() << right << " Description: " << m_description << endl;
	}
}
