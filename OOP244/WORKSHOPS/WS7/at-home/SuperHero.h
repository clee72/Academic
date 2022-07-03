//Workshop 7 
//SuperHero.h
//Date: 2019/07/23
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#pragma once
#ifndef SICT_SUPERHERO
#define SICT_SUPERHERO
#include "Hero.h"

namespace sict {
	
	class SuperHero :public Hero {
		int m_bonus;
		int m_defend;
	public:
		SuperHero();
		SuperHero(const char* name, int health, int attack, int bonus, int defend);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}


#endif 

