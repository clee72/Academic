//Final Project: MS 3
// Name: Wonhwa Lee	
// Seneca Student ID: 076086149
// Seneca email: wlee72@myseneca.ca
// Date of completion: November 29, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <iostream>
#include <string>

class Utilities {
	size_t m_widthField = 1;
	static char m_delimiter;

public:
	void setFieldWidth(size_t n);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char del);
	const char getDelimiter() const;
};

