#include <iostream>
#include "Container.h"
#include "Pack.h"
#include <cstring>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sdds {
	//Construction
	Pack::Pack(const char* desc, int size, int unitsize, int numberofunit)
		: Container (desc, size* unitsize, numberofunit* unitsize)
	{
		if (unitsize > 0) {
			m_unitsize = unitsize;
		}
	}
	//operation
	int Pack::operator+=(int number) {
		int value = (Container::operator+=(number * m_unitsize) / m_unitsize);
		//unit change
		return value;
	}
	int Pack::operator-=(int number) {
		int value = (Container::operator-=(number * m_unitsize) / m_unitsize);
		//unit change
		return value;
	}
	//queries
	int Pack::unit() {
		return m_unitsize;
	}
	int Pack::numUnits() {
		return this-> volume() / m_unitsize;
	}
	int Pack::size()
	{
		return this->capacity() / m_unitsize;
	}
	//clear
	void Pack::clear(int p_size, int unitsize, const char* desc)
	{
		if (unitsize > 0)
		{
			Container::clear(p_size * unitsize, desc);
			m_unitsize = unitsize;
		}
	}
	//print
	std::ostream& Pack::print(std::ostream& ostr)
	{
		this->Container::print(ostr);
		if (this->m_unitsize > 0)
		{
			ostr << ", " << this->numUnits() << " in a pack of " << this->size();
		}
		return ostr;
	}
	//read
	std::istream& Pack::read(std::istream& istr)
	{
		if (!bool(*this))
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			cin.ignore();
		}
		else
		{

			if (this->numUnits() < this->size())
			{
				cout << "Add to " << *this << endl;
				int value = 0;
				bool valid = true;
				cout << "> ";
				while (valid)
				{
					if (istr >> value) {
						if (value > 1 && value <= this->size() - this->numUnits())
						{
							*this += value;
							cout << "Added " << value << endl;
							valid = false;
						}
						else
						{
							cout << "Value out of range [1<=val<=" << this->size() - this->numUnits() << "]: ";
							value = 0;
						}
					}
					else {
						cout << "Invalid Integer, retry: ";
						cin.clear();
						cin.ignore(sizeof(value), '\n');
					}
				}
			}
			else
			{
				cin.ignore();
				cout << "Pack is full!, press <ENTER> to continue...";
				cin.ignore();
			}

		}
		return istr;
	}
	//insertionsand extraction helper operator overloads
	std::ostream& operator <<(std::ostream& ostr, Pack& c)
	{
		return c.print(ostr);
	}
	std::istream& operator >>(std::istream& istr, Pack& c)
	{
		return c.read(istr);
	}
}