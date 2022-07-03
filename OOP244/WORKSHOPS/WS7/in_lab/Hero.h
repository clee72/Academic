//Workshop 7 
//Hero.h
//Date: 2019/07/19
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//in_lab


#pragma once
#ifndef SICT_HERO_H
#define SICT_HERO_H

using namespace std;


namespace sict {
	const int MAX_ROUNDS = 100;
	const int MAX_LENGTH = 40;
	class Hero {
		char m_name[MAX_LENGTH+1];
		int m_health;
		int m_strength;

	public:
		Hero();
		Hero(const char* name, int health, int strengh);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		std::ostream& display(std::ostream&os = std::cout)const;
	};
	ostream& operator<<(ostream& os, const Hero& hero);
	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif