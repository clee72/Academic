
//Workshop 7 
//SuperHero.cpp
//Date: 2019/07/23
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "SuperHero.h"
using namespace std;

namespace sict {

	SuperHero::SuperHero() :Hero() {
		m_bonus = 0;
		m_defend = 0;
	}

	SuperHero::SuperHero(const char* name, int health, int attack, int bonus, int defend) : Hero(name,health, attack) {
		m_bonus = bonus;
		m_defend = defend;
	}

	int SuperHero::attackStrength() const {
		int result = Hero::attackStrength() + m_bonus;
		if (m_bonus == 0 || m_defend == 0) {
			result = 0;
		}
		return result;
	}

	int SuperHero::defend() const {
		int result = m_defend;
		if (m_bonus == 0 || m_defend == 0) {
			result = 0;
		}
		return result;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero _first = first;
		SuperHero _second = second;
		int count = 0;
		const SuperHero *winner;

		while (_first.isAlive() && _second.isAlive() && count <= MAX_ROUNDS) {
			_first -= _second.attackStrength() - _first.defend();
			_second -= _first.attackStrength() - _second.defend();
			count++;
		}
		if (_first.isAlive()) {
			cout << "Super Fight! " << _first << " vs " << _second << " : Winner is " << _first << " in " << count << " rounds." << endl;
			winner= &first;
		}
		else {
			cout << "Super Fight! " << _first << " vs " << _second << " : Winner is " << _second << " in " << count << " rounds." << endl;
			winner=&second;
		}
		return *winner;
	}
}





