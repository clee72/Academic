//Workshop 2: Dynamic Memory
//File Kingdom.h
//Author: Cornel
//Date: 2019/05/24
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

namespace sict {
	
	struct Kingdom {
		char m_name[32];
		int m_population;
	};
	//function prototype declaration.
	void display(const Kingdom &kingdom);
}
#endif