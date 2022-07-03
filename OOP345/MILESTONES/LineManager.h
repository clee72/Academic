//Final Project: MS 3
// Name: Wonhwa Lee	
// Seneca Student ID: 076086149
// Seneca email: wlee72@myseneca.ca
// Date of completion: November 29, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include "Task.h"
using namespace std;


class LineManager {
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;

public:
	LineManager(const std::string& filename, std::vector<Task*>& task, std::vector<CustomerOrder>& custOrder);
	bool run(std::ostream& os);
	void displayCompleted(std::ostream& os) const;
	void validateTasks() const;
};
