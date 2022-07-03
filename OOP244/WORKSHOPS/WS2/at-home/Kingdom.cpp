//Workshop 2: Dynamic Memory
//File Kingdom.cpp
//Author: Cornel
//Date: 2019/05/24
//Section:SBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca


#include "Kingdom.h"
#include <iostream>
using namespace std;
using namespace sict;


namespace sict {

  void display(const Kingdom& kingdom) {
    cout << kingdom.m_name << ", " << "population " << kingdom.m_population << endl;
  }

  void display(const Kingdom kingdom[], int n) {
    cout << "------------------------------" << endl;
    cout << "Kingdoms of SICT" << endl;
    cout << "------------------------------" << endl;
    int totalP = 0;
    for (int i = n - 1; i >= 0; i--) {
      totalP += kingdom[i].m_population;
      cout << i + 1 << ". " << kingdom[i].m_name << ", population " << kingdom[i].m_population << endl;
    }
    cout << "------------------------------" << endl;
    cout << "Total population of SICT: " << totalP << endl;
    cout << "------------------------------" << endl;
  }
}