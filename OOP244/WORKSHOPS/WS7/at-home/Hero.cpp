//Workshop 7 
//Hero.cpp
//Date: 2019/07/19
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//in_lab


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Hero.h"
#include<cstring>

using namespace std;

namespace sict {

	Hero::Hero() {
		m_name[0] = '\0';
		m_health = 0;
		m_strength = 0;
	}

	Hero::Hero(const char* name, int health, int strength) {
		if (name != nullptr && health > 0 && strength > 0) {
			strncpy(m_name, name, MAX_LENGTH);
			m_name[MAX_LENGTH] = '\0';
			m_health = health;
			m_strength = strength;
		}
		else {
			*this = Hero();
		}
	}

	void Hero::operator-=(int strength) {
		if (strength > 0) {
			m_health -= strength;
			if (m_health < 0) {
				m_health = 0;
			}
		}
		else if (strength < 0) {
			*this = Hero();
		}
	}

	bool Hero::isAlive() const {
		return m_health > 0;
	}

	int Hero::attackStrength() const {
		int result = m_strength;
		if (m_name == nullptr && m_health == 0 && m_strength == 0) {
			result = 0;
		}
		return result;
	}
	std::ostream& Hero::display(std::ostream&os)const {
		if (m_name == nullptr && m_health == 0 && m_strength == 0) {
			os << "No hero" << endl;
		}
		else {
			os << m_name;
		}
		return os;
	}

	std::ostream& operator<<(ostream& os, const Hero& hero) {
		return hero.display(os);
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero _first = first;
		Hero _second = second;
		const Hero* winner;

		int count = 0;
		while (_first.isAlive() && _second.isAlive() && count <= MAX_ROUNDS) {

			_first -= second.attackStrength();
			_second -= first.attackStrength();
			count++;
		}
		if (_first.isAlive()) {
			cout << "Ancient Battle! " << _first << " vs " << _second << " : ";
			cout << "Winner is " << _first << " in " << count << " rounds." << endl;
			winner = &first;
		}
		else {
			cout << "Ancient Battle! " << _first << " vs " << _second << " : ";
			cout << "Winner is " << _second << " in " << count << " rounds." << endl;
			winner = &second;
		}
		return *winner;
	}
}