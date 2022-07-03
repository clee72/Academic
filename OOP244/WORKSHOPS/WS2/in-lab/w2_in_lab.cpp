
//Workshop 2: Dynamic Memory
//File: w2_in_lab.cpp
//Author: Cornel
//Date: 2019/05/24
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca

#include <iostream>
#include "Kingdom.h"
#include "Kingdom.h" // intentional

using namespace std;
using namespace sict;

void read(sict::Kingdom&);

int main() {
	int count = 0; // the number of kingdoms in the array

	 Kingdom *pKingdom = nullptr;
	cout << "==========" << endl
		 << "Input data" << endl
		 << "==========" << endl
		 << "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	pKingdom = new Kingdom[count];
	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		read(pKingdom[i]);
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		 << "The 2nd kingdom entered is" << endl
		 << "------------------------------" << endl;
	sict::display(pKingdom[1]);
	cout << "------------------------------" << endl << endl;

	delete[] pKingdom;
	pKingdom = nullptr;
	return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(sict::Kingdom& kingdom) {

	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
