/* ------------------------------------------------------
Workshop 9 part 1
Module: N/A
Filename: HtmlText.cpp
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

#include "HtmlText.h"

namespace sdds {
	HtmlText::HtmlText() : Text() {
		m_title = nullptr;
	}

	HtmlText::HtmlText(const char* htmlText)
	{
		if (m_title != nullptr)
		{
			delete[] m_title;
			m_title = nullptr;
		}

		m_title = new char[strlen(htmlText) + 1];
		strcpy(m_title, htmlText);
	}
	HtmlText::HtmlText(const HtmlText& htmlText) :Text::Text(htmlText) {
		if (m_title != nullptr)
		{
			delete[] m_title;
			m_title = nullptr;
		}

		m_title = new char[strlen(htmlText.m_title) + 1];
		strcpy(m_title, htmlText.m_title);
	}
	HtmlText::~HtmlText() {
		if (m_title != nullptr)
		{
			delete[] m_title;
			m_title = nullptr;
		}
	}

	HtmlText& HtmlText::operator =(const HtmlText& other)
	{
		Text::operator=(other);
		if (m_title != nullptr)
		{
			delete[] m_title;
			m_title = nullptr;
		}

		m_title = new char[strlen(other.m_title) + 1];
		strcpy(m_title, other.m_title);

		return *this;
	}
	std::ostream& HtmlText::write(std::ostream& ostr) const {
		int i = 0;
		bool ms = false;

		ostr << "<html><head><title>";
		if (m_title != nullptr)
			ostr << m_title;
		else
			ostr << "No Title";

		ostr << "</title></head>\n<body>\n";
		ostr << "<h1>" << m_title << "</h1>\n";

		while (Text::operator[](i) != 0)
		{
			switch (Text::operator[](i))
			{
			case '<':
				ostr << "&lt;";
				ms = false;
				break;

			case '>':
				ostr << "&gt;";
				ms = false;
				break;

			case '\n':
				ostr << "<br />\n";
				ms = false;
				break;

			case ' ':
				if (ms)
					ostr << "&nbsp;";
				else
				{
					ostr << " ";
					ms = true;
				}
				break;
			default:
				ostr << Text::operator[](i);
				ms = false;
				break;
			}

			i++;
		}

		ostr << "</body>\n</html>";

		return ostr;
	}

	std::istream& operator >>(std::istream& istr, HtmlText& text)
	{
		text.read (istr);
		return istr;
	}

	std::ostream& operator <<(std::ostream& ostr, const HtmlText& text)
	{
		text.write (ostr);
		return ostr;
	}
}