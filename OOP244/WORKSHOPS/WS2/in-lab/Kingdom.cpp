//Workshop 2: Dynamic Memory
//File Kingdom.cpp
//Author: Cornel
//Date: 2019/05/24
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca


#include "Kingdom.h"
#include <iostream>
using namespace std;
using namespace sict;


namespace sict {
	//function definition to dispaly information of population and kingdom name.
	void display(const Kingdom &kingdom) {
		cout << kingdom.m_name << ", " << "population " <<kingdom.m_population << endl;
	}
}