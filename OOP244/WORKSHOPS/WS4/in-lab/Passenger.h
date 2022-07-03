//Workshop 4 - Constructors - Test Main
//File Passenger.h
//Author: Cornel
//Date: 2019/06/07
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca


// TODO: add file header comments here??????????????????????

// TODO: add header file guard here
#pragma once
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
const int M = 18;

// TODO: declare your namespace here
namespace sict {

	// TODO: define the Passenger class here
	class Passenger {
		char pName[M+1];
		char dest[M+1];
	public:
		Passenger();
		Passenger(const char*, const char*);
		bool isEmpty() const;
		void display() const;

	};
}
#endif