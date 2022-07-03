// Workshop 5
//Date: 2019/10/18
//Section:NBB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//at_home

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "SpellChecker.h"
#include "Movie.h"
#include "Book.h"

using namespace std;

namespace sdds {
	template <typename T>
	class Collection {
		string c_name;
		T* arr;
		size_t c_size;
		void(*observer)(const Collection<T>& a, const T& b) = nullptr;

	public:
		Collection(std::string name) {
			c_name = name;
			arr = nullptr;
			c_size = 0;
		}

		const std::string& name() const {
			return c_name;
		}
		~Collection() {
			delete[] arr;
		}
		size_t size() const {
			return c_size;
		}
		void setObserver(void(*observer1)(const Collection<T>& a, const T& b)) {
			observer = observer1;
		}
		Collection<T>& operator+=(const T& item) {
			bool isFound = false;
			for (size_t i = 0; i < c_size && !isFound; i++) {
				if (arr[i].title() == item.title()) {
					isFound = true;
				}
			}
				//if title is not found, we add an item.
			if (!isFound) {
				T* tmp = nullptr;
				tmp = new T[c_size + 1];//resize the array.
				for (size_t i = 0; i < c_size; i++) {
					tmp[i] = arr[i];
				}
				tmp[c_size++] = item;//add item to the resized array
				if (observer) {
					observer(*this, item);//call the observer function,
										  // which has a void return type and two arguments (const Collection<T>& a, const T& b)
				
				}
				delete[] arr;
				arr = tmp;
			}
			return *this;
		}
		//return the item of the idx position.
		T& operator[](size_t idx) const {
			if (idx < 0 || idx >= c_size) {
				throw out_of_range("Bad index [" + std::to_string(idx) +
					"]. Collection has [" + std::to_string(c_size) + "] items.");
			}
			return arr[idx];
		}
		T* operator[](std::string title) const {
			T* result = nullptr;
			if (title != "") {
				for (size_t i = 0; i < c_size; i++) {
					if (arr[i].title() == title) {
						result = &arr[i];//if the item exists, this function returns the item's address
					}
				}
			}
			else {
				result = nullptr;
			}
			return result;
		}
	};

	template <typename T>
	ostream& operator<<(ostream& os, const Collection<T>& con) {
		for (size_t i = 0; i < con.size(); i++) {
			os << con[i];
		}
		return os;
	}
}
