

#pragma once

#include "Item.h"
#include "CustomerOrder.h"
#include "Utilities.h"
#include <deque>


using namespace std;

class Task :public Item {
	deque <CustomerOrder> m_orders;
	Task* m_pNextTask;

public:
	Task(const std::string& line);
	Task(const Task& t) = delete;
	Task(const Task&& m) = delete;
	Task& operator=(Task& source) = delete;
	Task& operator=(Task&& source) = delete;

	void runProcess(std::ostream& os);
	bool moveTask();
	void setNextTask(Task& nest);
	bool getCompleted(CustomerOrder& orderCompleted);
	void validate(std::ostream& os);

	Task& operator+=(CustomerOrder&& source);
};
