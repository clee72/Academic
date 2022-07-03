//Workshop 4 - Constructors - Test Main
//File Passenger.h
//Date: 2019/06/11
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#pragma once
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

const int M = 18;

namespace sict {

	class Passenger {
		char pName[M+1];
		char dest[M+1];
		int yDepart;
		int mDepart;
		int dDepart;

	public:
		Passenger();
		Passenger(const char*, const char*);
		Passenger(const char*, const char*, int, int, int);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};
}
#endif 