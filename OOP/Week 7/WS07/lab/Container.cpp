#define _CRT_SECURE_NO_WARNINGS
#include "Container.h"
#include <iostream>
#include <string.h>

using namespace std;
namespace sdds {

	//Construction
	Container::Container(const char* desc, int cap) {
		strcpy(m_content, desc);
		m_capacity = cap;
		m_volume = 0;
	}
	Container::Container(const char* desc,  int cap,  int vol) {
		strcpy(m_content, desc);
		m_capacity = cap;
		m_volume = vol;
	}

	//Protected modifier and queries:
	void Container::setEmpty() {
		m_content[0] = '\0';
		m_capacity = 0;
		m_volume = 0;
	}

	int Container::capacity() {
		return m_capacity;
	}

	int Container::volume() {
		return m_volume;
	}

	//Operations
	int Container::operator+=(int number) {
		int value = 0;
		int volume_buffer = this->m_volume;
		value = this->m_volume += number;
		if (this->m_volume > this->m_capacity)
		{
			this->m_volume = volume_buffer;
			value = this->m_capacity - number;
			this->m_volume += value;
		}
		return value;
	}

	int Container::operator-=(int number) {
		int value = 0;
		if (this->m_volume > number)
		{
			this->m_volume -= number;
			value = number;
		}
		else
		{
			value = this->m_volume;
			this->m_volume = 0;
		}
		return value;
	}

	//bool type conversion
	Container::operator bool() {
		bool valid = true;
		if (m_content[0] <= 0)
		{
			valid = false;
		}
		if(m_volume > m_capacity)
		{
			valid = false;
		}
		return valid;
	}

	//clear
	void Container::clear(int cap, const char* desc) {
		if (m_content != nullptr && m_capacity > 0) {
			this->m_volume = 0;
			this->m_capacity = cap;
			this->m_content[0] = '\0';
			strcpy(this->m_content, desc);
		}
	}

	//print
	std::ostream& Container::print(std::ostream& ostr) {
		if (bool(*this))
		{
			ostr << this->m_content << ": " << "(" << this->m_volume << "cc/" << this->m_capacity << ")";
		}
		else
		{
			ostr << "****: (**cc/***)";
		}
		return ostr;
	}

	//read
	std::istream& Container::read(std::istream& istr) {
		if (!bool(*this))
		{
			cin.ignore();
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			cin.ignore();
		}
		else
		{
			int value = 0;
			bool isFalse = true;
			cout << "Add to " << *this << endl;
			cout << "> ";
			while (isFalse)
			{
				if (istr >> value) {
					if (value > 1 && value < 999)
					{
						int x = *this += value;
						cout << "Added " << x << " CCs" << endl;
						isFalse = false;
					}
					else
					{
						cout << "Value out of range [1<=val<=999]: ";
					}
				}
				else {
					cout << "Invalid Integer, retry: ";
					cin.clear();
					cin.ignore(sizeof(value), '\n');
				}
			}
		}
		return istr;
	}

	//Insertions and extraction helper operator overloads
	std::ostream& operator <<(std::ostream& ostr, Container& c)
	{
		return c.print(ostr);
	}
	std::istream& operator >>(std::istream& istr, Container& c)
	{
		return c.read(istr);
	}
}