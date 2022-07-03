// Workshop 6 - Class with a Resource
// w6_in_lab.cpp
// Cornel
// 2019/5/26
///////////////////////////////
//Date: 2019/07/05
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//in_lab

#include <iostream>
#include "Contact.h"
#include "Contact.h" // intentional

using namespace std;
using namespace sict;

int main()
{
	cout << "----------------------------------------" << endl;
	cout << "Maximum no of characters in a name: " << sict::MAX_CHAR << endl;
	cout << "----------------------------------------" << endl;
	cout << "Testing the default constructor!" << endl;
	cout << "----------------------------------------" << endl;
	sict::Contact empty; // sict:: intentional
	empty.display();
	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "Testing an invalid contact!" << endl;
	cout << "----------------------------------------" << endl;
	Contact bad(nullptr, nullptr, 0);
	bad.display();
	Contact alsoBad("", nullptr, 0);
	alsoBad.display();
	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "Testing the constructor with parameters!" << endl;
	cout << "----------------------------------------" << endl;
	Contact temp("A contact with a very looooong name!", nullptr, 0);
	temp.display();
	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "Testing a valid contact!" << endl;
	cout << "----------------------------------------" << endl;
	long long phoneNumbers[] = { 1416123456LL, 14161234567LL, 1416234567890LL,
		14162345678LL, -1LL, 124163456789LL,
		14161230002LL };
	Contact someContact("John Doe", phoneNumbers, 7);
	someContact.display();
	cout << "----------------------------------------" << endl << endl;

	return 0;
}