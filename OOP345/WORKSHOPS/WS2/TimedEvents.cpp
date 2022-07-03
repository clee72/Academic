// Workshop 2
//Date: 2019/09/21
//Section:NBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iomanip>
#include "TimedEvents.h"

namespace sdds {
	TimedEvents::TimedEvents() :recordNum(0) {}

	void TimedEvents::startClock() {
		m_start = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		m_end = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* e_name_) {
		auto e_na_ = std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_start);

		if (recordNum < R_MAX) {
			this->record[recordNum].e_name = e_name_;
			this->record[recordNum].t_unit = "nanoseconds";
			this->record[recordNum].duration = e_na_;
			recordNum++;
		}
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& obj) {
		os << "--------------------------\n";
		os << "Execution Times:\n";
		os << "--------------------------\n";
		for (int i = 0; i < obj.recordNum; i++)
			os << std::setw(20) << std::left
			<< obj.record[i].e_name << ' ' << std::setw(12) << std::right
			<< obj.record[i].duration.count() << ' '
			<< obj.record[i].t_unit << '\n';
		os << "--------------------------\n";
		return os;
	}
}