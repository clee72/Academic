// Workshop 9
//Data.h
//Date: 2019/08/02
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//in_lab

#ifndef SICT_DATA_H
#define SICT_DATA_H

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;

	// max returns the largest item in data
	template<typename T>
	T max(const T*data, int n) {
		int i;
		T _max = data[0];
		for (i = 1; i < n; i++) {
			if (_max < data[i]) {
				_max = data[i];
			}
		}
		return _max;
	}

	// min returns the smallest item in data
	template <typename T>
	T min(const T* data, int n) {
		int i;
		T _min = data[0];
		for (i = 1; i < n; i++) {
			if (_min > data[i]) {
				_min = data[i];
			}
		}
		return _min;
	}


	// sum returns the sum of n items in data 
	template <typename T>
	T sum(const T* data, int n) {
		int i;
		T _sum = 0;
		for (i = 0; i < n; i++) {
			_sum += data[i];
		}
		return _sum;
	}

	// average returns the average of n items in data
	template <typename T>
	double average(const T* data, int n) {
		return sum(data, n) / n;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	template <typename T>
	bool read(std::istream& input, T* data, int n) {
		bool ret = false;
		int i;
		for (i = 0; i < n; i++) {
			input.ignore();
			input >> data[i];
			ret = true;
			if (input.fail()) {
				ret = false;
			}
		}
		return ret;
	}

	// display inserts n items of data into std::cout
	template <typename T>
	void display(const char* name, const T* data, int n) {
		int i;
		cout.width(20);
		cout << name;
		for (i = 0; i < n; i++) {
			cout.width(15);
			cout << data[i];
			cout << right;
		}
		cout << endl;
	}

	template <typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}
#endif

