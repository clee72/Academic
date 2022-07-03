// Workshop 6 - Class with a Resource
// Contact.h
//Date: 2019/07/05
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//in_lab

#pragma once
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H


namespace sict {
const int MAX_CHAR = 20;
	class Contact {
		char name[MAX_CHAR + 1];
		long long *pNum;
		int numPN;

	public:
		Contact();
		Contact(const char *,const long long *, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}
#endif
