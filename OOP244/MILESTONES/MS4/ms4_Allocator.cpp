// Final Project - Milestone 4
// Version 3.7
// ms4_Allocator.cpp
// Date	2018/06/22
// Authors	Fardad Soleimanloo, Chris Szalwinski, Cornel
//
// For your final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// -----------------------------------------------------------
//Date: 2019/08/03
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//ms4
/////////////////////////////////////////////////////////////////

#include "ms4_MyGood.h"

namespace aid
{
	iGood* CreateProduct(char tag) {
		if (tag == 'n')
			return new MyGood("Good");
		else
			return new MyGood("Perishable");
	}
}