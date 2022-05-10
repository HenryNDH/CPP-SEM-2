/* ------------------------------------------------------
Workshop 9 part 1
Module: N/A
Filename: Text.cpp
Version 1.1
Author: Duy Hoang Nguyen
Revision History
-----------------------------------------------------------
Date
31/03/202
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Text.h"

namespace sdds {
	const char& Text::operator[](int index)const {
		char ch = 0;
		return !(m_content == nullptr || index > (int)strlen(m_content)) ? m_content[index] : ch;
	}

	//Constructor
	Text::Text() {
		m_content = nullptr;
	}

	//Rule of three 
	//destructor
	Text::~Text() {
		setEmpty();
	}

	//copy constructor
	Text::Text(const Text& other) {
		if (m_content != nullptr)
		{
			setEmpty();
		}

		m_content = new char[strlen(other.m_content) + 1];
		strcpy(m_content, other.m_content);
	}

	//copy assignment operator
	Text& Text::operator =(const Text& other) {
		if (m_content != nullptr)
		{
			setEmpty();
		}
		m_content = new char[strlen(other.m_content) + 1];
		strcpy(m_content, other.m_content);
		return *this;
	}

	void Text::setEmpty() {
		delete[] m_content;
		m_content = nullptr;
	}

	//read
	std::istream& Text::read(std::istream& istr)
	{
		if (m_content != nullptr)
		{
			delete[] m_content;
			m_content = nullptr;
		}

		m_content = new char[getFileLength(istr) + 2]{};
		istr.get(m_content, getFileLength(istr) + 1, std::ios::end);

		return istr;
	}

	//write
	std::ostream& Text::write(std::ostream& ostr) const
	{
		if (m_content != nullptr)
		{
			ostr << m_content;
		}

		return ostr;
	}

	std::istream& operator >>(std::istream& istr, Text& text)
	{
		text.read(istr);
		return istr;
	}

	std::ostream& operator <<(std::ostream& ostr, const Text& text)
	{
		text.write(ostr);
		return ostr;
	}

	int getFileLength(std::istream& is) {
		int len{};
		if (is) {
			// save the current read position
			std::streampos cur = is.tellg();
			// go to the end
			is.seekg(0, std::ios::end);
			// let what is the positions (end position = size)
			len = (int)is.tellg();
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}
}