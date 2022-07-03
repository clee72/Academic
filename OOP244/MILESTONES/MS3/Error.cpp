//Error.cpp
//Date: 2019/07/30
//Section:SAB
//Name:WONHWA LEE
//Student No.:076086149
//Email:wlee72@myseneca.ca
//ms2

#pragma warning(disable : 4996)
#include<iostream>
#include"Error.h"
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

namespace aid {

	Error::Error(const char* errorMessage) {
		if (errorMessage == nullptr || errorMessage[0] == '\0') {
			errMsg = nullptr;
		}
		else {
			errMsg = new char[strlen(errorMessage) + 1];
			strncpy(errMsg, errorMessage, strlen(errorMessage));
			errMsg[strlen(errorMessage)] = '\0';
		}
	}

	Error::~Error() {
		delete[] errMsg;
		errMsg = nullptr;
	}

	void Error::clear() {
		delete[] errMsg;
		errMsg = nullptr;
	}

	bool Error::isClear() const {
		bool result = false;
		if (errMsg == nullptr || errMsg[0] == '\0')
			result = true;
		else
			result = false;
		return result;
	}

	void Error::message(const char* str) {
		clear();
		if (str != nullptr && str[0] != '\0') {
			errMsg = new char[strlen(str) + 1];
			strncpy(errMsg, str, strlen(str));
			errMsg[strlen(str)] = '\0';
		}
		else {
			errMsg = nullptr;
		}
	}

	const char* Error::message() const {
		char* result;
		if (errMsg == nullptr || errMsg[0] == '\0') {
			result = nullptr;
		}
		else {
			result = errMsg;
		}
		return result;
	}

	std::ostream& operator<<(std::ostream& os, const Error& err) {
		if (!err.isClear()) {
			os << err.message();
		}
		return os;
	}
}