//Final Project: MS 3
// Name: Wonhwa Lee	
// Seneca Student ID: 076086149
// Seneca email: wlee72@myseneca.ca
// Date of completion: November 29, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include"Task.h"
#include"Utilities.h"


Task::Task(const std::string& line) :Item(line) {

	m_pNextTask = nullptr;
}

void Task::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {//if not empty,
		if (!m_orders.back().getOrderFillState()) {//need to be filled

			m_orders.back().fillItem(*this, os);
		}
	}

}

bool Task::moveTask() {
	bool res = false;
	if (!m_orders.empty()) {
		if (m_orders.back().getItemFillState(getName()) && m_pNextTask != nullptr) {//item doesn't exist in the order, true
			*m_pNextTask += std::move(m_orders.back());
			m_orders.pop_back();//after moved, it needs to be taken out.
		}
		res = true;
	}
	return res;

}

void Task::setNextTask(Task& task) {

	if (m_pNextTask != nullptr)
		delete m_pNextTask;
	m_pNextTask = &task;
}

bool Task::getCompleted(CustomerOrder& cust) {
	bool res = false;
	if (!m_orders.empty() && m_orders.back().getOrderFillState()) {
		cust = move(m_orders.back());
		m_orders.pop_back();

		res = true;
	}
	return res;

}

void Task::validate(std::ostream& os) {
	if (m_pNextTask == nullptr) {
		os << getName() << " --> " << "END OF LINE" << endl;
	}
	else {
		os << getName() << " --> " << m_pNextTask->getName() << endl;
	}
}

Task& Task::operator+=(CustomerOrder&& m) {
	m_orders.push_front(std::move(m));
	return *this;
}


