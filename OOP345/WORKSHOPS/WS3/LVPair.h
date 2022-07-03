// Workshop 3
//Date: 2019/10/1
//Section:NBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#pragma once
#include <iostream>
#include <string>

namespace sdds {
	template <typename L, typename V>
	class LVPair {
		L m_label;
		V m_value;

	public:
		LVPair() :m_label{ }, m_value{ } {}
		LVPair(const L& label, const V& value) :m_label(label), m_value(value) {}
		const L& key() const {
			return m_label;
		}
		const V& value() const {
			return m_value;
		}
		virtual void display(std::ostream& os)const {
			os << key() << ":" << value() << std::endl;
		}
	};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {

		static V initialSum;
		static size_t widthVal;

	public:
		static const V& getInitialValue() { return initialSum; }
		SummableLVPair() {}
		SummableLVPair(const L& lbl, const V& value) :LVPair<L, V>(lbl, value) {
			if (widthVal < lbl.size()) {
				widthVal = lbl.size();
			}
		}

		V sum(const L& lbl, const V& val) const {
			return val + LVPair<L, V>::value();
		}

		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(widthVal);
			os << LVPair<L, V>::key() << " : " << LVPair<L, V>::value() << std::endl;
			os.unsetf(std::ios::right);
		}
	};

	template <typename L, typename V>
	size_t SummableLVPair<L, V>::widthVal = 0u;

	template<>
	int SummableLVPair<std::string, int>::initialSum = 0;

	template<>
	std::string SummableLVPair<std::string, std::string>::initialSum = "";

	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& value) const {
		//to eliminate unnecessary commas
		if (value == "") {
			return LVPair<std::string, std::string>::value() + value;
		}
		else {
			return (value + ", " + LVPair<std::string, std::string>::value());
		}
	}
}