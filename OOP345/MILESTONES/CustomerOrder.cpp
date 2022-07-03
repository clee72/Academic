

#include "CustomerOrder.h"
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstring>

size_t CustomerOrder::m_widthField = 0;
CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(const CustomerOrder& err) {
	throw "error";
}

CustomerOrder::CustomerOrder(const std::string& record) {
	Utilities ut;
	bool more = true;
	size_t next_pos = 0;
	string custOrderRecord = record;
	m_cntItem = 0;
	m_name = ut.extractToken(custOrderRecord, next_pos, more);
	m_product = ut.extractToken(custOrderRecord, next_pos, more);
	m_cntItem = count(record.begin(), record.end(), ut.getDelimiter()) - 1;

	m_lstItem = new ItemInfo *[m_cntItem];
	for (size_t i = 0; i < m_cntItem; i++) {
		m_lstItem[i] = new ItemInfo(ut.extractToken(custOrderRecord, next_pos, more));
	}

	if (CustomerOrder::m_widthField < ut.getFieldWidth()) {
		CustomerOrder::m_widthField = ut.getFieldWidth();
	}
}

CustomerOrder::CustomerOrder(CustomerOrder&& m) noexcept {
	m_lstItem = nullptr;
	*this = std::move(m);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& m) noexcept {
	if (this != &m) {
		delete[] m_lstItem;
		m_name = m.m_name;
		m_product = m.m_product;
		m_cntItem = m.m_cntItem;
		m_lstItem = m.m_lstItem;

		m.m_name = "";
		m.m_product = "";
		m.m_cntItem = 0;
		m.m_lstItem = nullptr;
	}
	return *this;
}

CustomerOrder::~CustomerOrder() {

	delete[] m_lstItem;
}

bool CustomerOrder::getItemFillState(std::string str) const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == str)
			return (m_lstItem[i]->m_fillState);
	}
	return true;
}

bool CustomerOrder::getOrderFillState() const {
	bool flag = true;
	for (size_t i = 0; i < m_cntItem&&flag; i++) {
		if (!m_lstItem[i]->m_fillState) {
			flag = false;
		}
	}
	return flag;
}

void CustomerOrder::fillItem(Item& item, std::ostream& os) {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == item.getName()) {
			if (item.getQuantity() > 0) {
				item.updateQuantity();
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				m_lstItem[i]->m_fillState = true;
				os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << endl;
			}
			else {
				os << "Unable to fill " << m_name << m_product << "[" << m_lstItem[i]->m_itemName << "]" << endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream& out) const {
	out << m_name << " - " << m_product << endl;
	for (size_t i = 0; i < m_cntItem; i++) {

		out << "[" << std::setw(6) << setfill('0') << right << m_lstItem[i]->m_serialNumber
			<< "] " << std::left << std::setw(m_widthField) << setfill(' ')
			<< m_lstItem[i]->m_itemName << (getOrderFillState() ? " - FILLED" : " - MISSING") << endl;
	}
}
