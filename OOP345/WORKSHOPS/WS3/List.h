// Workshop 3
//Date: 2019/10/1
//Section:NBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#pragma once
#include <iostream>
#include "LVPair.h"

namespace sdds {

	template <typename T, size_t N>
	class List {
		T a[N];
		size_t n = { 0 };

	public:
		size_t size() const { return n; }
		const T& operator[](size_t i) const {
			const T& t = a[i];
			return t;
		}
		void operator+=(const T& tt) {
			if (n < N) {
				a[n] = tt;
				n++;
			}
		}
	};

	template <typename L, typename V, typename T, size_t N>
	class LVList : public List<T, N> {
	public:
		V accumulate(const L& label) const {
			V m_sumVal = SummableLVPair<L, V>::getInitialValue();
			
			for (size_t i = 0; i < ((List<T, N>&)*this).size(); i++) {
		// It checks two keys matched by comparing the receving object label and the List object's label. 
		//If they are matched, we append the item into the "m_sumVal.
				if (label == ((List<T, N>&)*this)[i].key()) {
					m_sumVal = ((List<T, N>&)*this)[i].sum(label, m_sumVal);
				}
			}
			return m_sumVal;
		}
	};
}
