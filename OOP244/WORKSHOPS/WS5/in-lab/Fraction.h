//Workshop 5 - Workshop 5: operator overloading
//File Fraction.h
//Date: 2019/06/16
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//in_lab

#pragma once
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {
	
	class Fraction {
		int nRator;
		int dNator;
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	
	public:
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		Fraction operator+ (const Fraction &) const;
	};
}
#endif

