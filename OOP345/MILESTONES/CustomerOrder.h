//Final Project: MS 3
// Name: Wonhwa Lee	
// Seneca Student ID: 076086149
// Seneca email: wlee72@myseneca.ca
// Date of completion: November 29, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include "Utilities.h"
#include "Item.h"
#include <future>
#include <iostream>

using namespace std;

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem;
	static size_t m_widthField;
	
public:
	CustomerOrder();
	CustomerOrder(const CustomerOrder& order);
	explicit CustomerOrder(const std::string& str);
	CustomerOrder& operator=(CustomerOrder& c_order)=delete;//prevent copy
	CustomerOrder(CustomerOrder&& mc) noexcept;
	CustomerOrder& operator=(CustomerOrder&& ma) noexcept ;
	~CustomerOrder();
	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream&);
	void display(std::ostream&) const;

};

