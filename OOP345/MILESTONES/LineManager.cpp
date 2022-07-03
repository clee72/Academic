//Final Project: MS3
// Name: Wonhwa Lee	
// Seneca Student ID: 076086149
// Seneca email: wlee72@myseneca.ca
// Date of completion: November 29, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"LineManager.h"
#include"Utilities.h"
#include"Task.h"

using namespace std;

LineManager::LineManager(const std::string& filename, std::vector<Task*>& task, std::vector<CustomerOrder>& custOrderToBeFilled) {
	fstream file(filename);
	string line;
	Utilities util;
	string item;

	//move all the CustomerOrder 
	for (size_t i = 0; i < custOrderToBeFilled.size(); i++) {
		ToBeFilled.push_front(move(custOrderToBeFilled[i]));
		m_cntCustomerOrder++;
	}

	//copy all the Task
		AssemblyLine = task;
		

	if (!file) {
		std::cout << "Error opening file" << endl;
	}
	else {
		if (file.is_open()) {
			while (getline(file, line)) {
				bool more = true;
				size_t next_pos = 0;
			
				item = util.extractToken(line, next_pos, more);
				for (size_t i = 0; i < task.size(); i++) {
					if (task[i]->getName() == item) {
						if (next_pos != 0) {
							item = util.extractToken(line, next_pos, more);
							for (size_t j = 0; j < task.size(); j++) {
								if (task[j]->getName() == item) {
									task[i]->setNextTask(*AssemblyLine[j]);
								}
							}
						}
					}
				}
			}
		}
	}
}

bool LineManager::run(std::ostream& os) {
	bool filled = false;
	CustomerOrder custOrder;
	//each element contains an address of a Task object.(e.g.,vector<Task*> t).
	//Therefore, we need to dereference to "AssemblyLine" to access "Task" object.
	if (!ToBeFilled.empty()) {
		*(AssemblyLine[4]) += move(ToBeFilled.back());
		ToBeFilled.pop_back();
	}

	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->runProcess(os);
	}
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		if (AssemblyLine[i]->moveTask()) {
			if (AssemblyLine[i]->getCompleted(custOrder)) {
				Completed.push_back(move(custOrder));

			}
		}
	}
	if (Completed.size() == m_cntCustomerOrder && ToBeFilled.empty()) {
		filled = true;
	}
	return filled;
}

void LineManager::displayCompleted(std::ostream& os) const {
	for (size_t i = 0; i < Completed.size(); i++) {
		if (Completed[i].getOrderFillState()) {
			Completed[i].display(os);
		}
	}
}

void LineManager::validateTasks() const {

	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->validate(cout);
	}
}

