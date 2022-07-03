//Workshop 5 - Workshop 5: operator overloading
//File Fraction.cpp
//Date: 2019/06/16
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//in_lab

#include<iostream>
#include "Fraction.h"
using namespace std;
using namespace sict;

namespace sict {
	Fraction::Fraction() {
		nRator = 0;
		dNator = 0;
	}
	Fraction::Fraction(int n, int d) {
		if (n < 0 || d <= 0) {
			nRator = 0;
			dNator = 0;
		}
		else {
			nRator = n;
			dNator = d;
			reduce();
		}
	}
	int Fraction::max() const {
		int result;
		if (nRator > dNator) {
			result = nRator;
		}
		else {
			result = dNator;
		}
		return result;
	}
	int Fraction::min() const {
		int result;
		if (nRator < dNator) {
			result = nRator;
		}
		else {
			result = dNator;
		}
		return result;
	}
	int Fraction::gcd() const {
		int mn = min();  
		int mx = max(); 
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) {
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}
	void Fraction::reduce() {
		int divide;
		divide = gcd();
		nRator /= divide;
		dNator /= divide;
	}
	void Fraction::display() const {
		
		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else {
			if (dNator != 1) {
				cout << nRator << "/" << dNator;
			}
			else {
				cout << nRator;
			}
		}
	}
	bool Fraction::isEmpty() const {
		bool result = false;
		if (nRator == 0 || dNator == 0) {
			result = true;
		}
		return result;
	}
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction sum;
		
		if (!isEmpty()&&!rhs.isEmpty()) {
			sum.nRator = (nRator*rhs.dNator + dNator*rhs.nRator);
			sum.dNator = dNator * rhs.dNator;
			sum.reduce();

		}
		else {
			sum.nRator = 0;
			sum.dNator = 0;
		}
		return sum;
	
	}
}