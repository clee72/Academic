// Workshop 2
//Date: 2019/09/21
//Section:NBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once

#include <iostream>
#include <chrono>
#include <string>

namespace sdds {
	const int R_MAX = 7;

	class TimedEvents {
		int recordNum;
		std::chrono::steady_clock::time_point m_start;
		std::chrono::steady_clock::time_point m_end;
		struct {
			std::string e_name;
			std::string t_unit;
			std::chrono::steady_clock::duration duration;
		}record[R_MAX];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* e_name);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& obj);
	};
}