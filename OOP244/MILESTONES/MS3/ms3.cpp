// Final Project - Milestone 3 - Good Module
// Version 3.7
// Date	2018-06-22
// 244_ms3_tester_prof.cpp
// Author	Fardad Soleimanloo, Chris Szalwinski, Cornel
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// --------------------------------------------------------------
//Date: 2019/07/30
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//ms3
/////////////////////////////////////////////////////////////////

#include "ms3_MyGood.h"
#include "Good.h"
#include "Good.h" // intentional

#define filename "ms3.txt"
using namespace std;
using namespace aid;

void test(const char* sku);
void dumpFile(fstream& f);

int main() {
	cout << "Checking constants:";
	cout << "\n------------------------------";
	cout << "\n\tmax_sku_length: " << max_sku_length;
	cout << "\n\tmax_unit_length: " << max_unit_length;
	cout << "\n\tmax_name_length: " << max_name_length;
	cout << "\n\ttax_rate: " << tax_rate;
	cout << "\n------------------------------n\n";

	fstream file(filename, ios::out);
	file.close();
	Test s(filename);
	Test u(filename, "4321", "Rice");
	cout << "Empty Good:" << endl << s << endl;
	cout << "u(\"4321\", \"Rice\"):" << endl << u << endl;
	cout << endl;
	cout << "Please enter the following information:" << endl;
	cout << " Sku: 1234" << endl;
	cout << " Name (no spaces): Blanket" << endl;
	cout << " Unit: pair" << endl;
	cout << " Taxed? (y/n): y" << endl;
	cout << " Price: 12.34" << endl;
	cout << " Quantity on hand: 12" << endl;
	cout << " Quantity needed: 23" << endl;
	test("1234");
	cout << "Please enter the following information:" << endl;
	cout << " Sku: abcd" << endl;
	cout << " Name (no spaces): Jacket" << endl;
	cout << " Unit: n/a" << endl;
	cout << " Taxed? (y/n): n" << endl;
	cout << " Price: 12.3" << endl;
	cout << " Quantity on hand: 11" << endl;
	cout << " Quantity needed: 22" << endl;
	test("abcd");
	dumpFile(file);
	cout << "----The End" << endl;
	return 0;
}

// test manages details of a single test case
//
void test(const char* sku) {
	fstream file(filename, ios::out);
	file.close();
	cout << endl;
	cout << "Enter Good Info: " << endl;
	Test s(filename);
	cin >> s;
	cout << "\nTesting:" << endl;
	cout << " s.store(): " << endl;
	s.store(file);
	cout << "  s: " << s << endl;
	Test t(filename);
	cout << " t.load(): " << endl;
	t.load(file);
	cout << "  t: " << t << endl;
	cout << " X(const X&): X v = s" << endl;
	Test v = s;
	cout << "  v: " << v << endl;
	cout << "  s: " << s << endl;
	cout << " X& operator=(const X&): u = t" << endl;
	Test u(filename);
	u = t;
	cout << "  t: " << t << endl;
	cout << "  u: " << u << endl;
	cout << " bool operator==(const char*) const: ";
	cout << (t == sku ? "OK" : "NOT OK") << endl;
	cout << " int operator+=(int): u += 100 " << endl;
	cout << "  u: " << u << endl;
	u += 100;
	cout << "  u: " << u << endl;
	cout << " double operator+=(double&, const Good&) : 200 += u" << endl;
	double res, val = 200.0;
	res = val += u;
	cout << "  ?:" << res << " = " << val << endl;
	cout << endl;
}

// dumpfile dumps contents of file f to the standard output stream
//
void dumpFile(fstream& f) {
	f.open(filename, ios::in);
	char ch;
	while (!f.get(ch).fail()) {
		cout.put(ch);
	}
	f.clear();
	f.close();
}
