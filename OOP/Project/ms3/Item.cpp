/*---------------------------------------------------------
Final Project Milestone 3
Version 1.0
Author	Hoang Duy Nguyen
StudentID: 108397217
Email: hdnguyen12@myseneca.ca
-----------------------------------------------------------
Date
2022/26/03
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "iProduct.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <iomanip>

#include "Status.h"
#include "Item.h"

namespace sdds {
	Item::Item()
	{
		m_price = m_qty = m_qtyNeeded = 0;
		m_isLinear = false;
		m_desc = nullptr;
		m_sku = 0;
	}

	Item::Item(const Item& other)	
	{
		m_price = other.m_price;  
		m_qty = other.m_qty; 
		m_qtyNeeded = other.m_qtyNeeded; 
		m_isLinear = other.m_isLinear;
		if (m_desc != nullptr)
		{
			delete[] m_desc;
			m_desc = nullptr;
		}

		m_desc = new char[strlen(other.m_desc) + 1];
		strcpy(m_desc, other.m_desc);

		m_sku = other.m_sku;
		m_state = other.m_state;
	}

	Item::~Item()
	{
		if (m_desc != nullptr)
		{
			delete[] m_desc;
			m_desc = nullptr;
		}
	}

	Item& Item::operator =(const Item& other)
	{
		if (m_desc != nullptr)
		{
			delete[] m_desc;
			m_desc = nullptr;
		}

		m_desc = new char[strlen(other.m_desc) + 1];
		strcpy(m_desc, other.m_desc);

		m_price = other.m_price;
		m_qty = other.m_qty;
		m_qtyNeeded = other.m_qtyNeeded;
		m_isLinear = other.m_isLinear;

		m_state = other.m_state;
		m_sku = other.m_sku;

		return *this;
	}

	bool Item::linear() const
	{
		return m_isLinear;
	}

	int Item::qty()const
	{
		return m_qty;
	}

	int Item::qtyNeeded()const
	{
		return m_qtyNeeded;
	}

	Item::operator double()const
	{
		return m_price;
	}

	Item::operator bool()const
	{
		return m_isLinear;
	}

	int Item::operator-=(int qty)
	{
		m_qty -= qty;

		return m_qty;
	}

	int Item::operator+=(int qty)
	{
		m_qty += qty;

		return m_qty;
	}

	void Item::linear(bool isLinear)
	{
		m_isLinear = isLinear;
	}

	void Item::clear()
	{
		m_state.clear();
	}

	bool Item::operator==(int sku)const
	{
		return m_sku == sku;
	}

	bool Item::operator==(const char* desc)const
	{
		bool flag = false;

		for (int i = 0; i < (int)strlen(m_desc); i++)
		{
			if (m_desc[i] == desc[0])
			{
				bool search = true;

				for (int x = 0; x < (int)strlen(desc); x++)
				{
					if (m_desc[i + x] != desc[x])
					{
						search = false;
					}
				}

				if (search == true)
				{
					flag = true;
					i = (int)strlen(m_desc);
				}
			}
		}

		return flag;
	}

	std::ofstream& Item::save(std::ofstream& ofstr)const
	{
		if (m_state)
		{
			ofstr << m_sku << "\t" << m_desc << "\t" << m_qty << "\t" << m_qtyNeeded << "\t" << std::floor(m_price * 100.0) / 100.0;
		}

		return ofstr;
	}

	std::ifstream& Item::load(std::ifstream& ifstr)
	{

		if (m_desc != nullptr)
		{
			delete[] m_desc;
			m_desc = nullptr;
		}

		char buffer[512] = { 0 };

		ifstr.get(buffer, 512, '\t');
		m_sku = std::atoi(buffer);
		ifstr.ignore();

		ifstr.get(buffer, 512, '\t');
		m_desc = new char[strlen(buffer) + 1];
		strcpy(m_desc, buffer);
		ifstr.ignore();

		ifstr.get(buffer, 512, '\t');
		m_qty = atoi(buffer);
		ifstr.ignore();

		ifstr.get(buffer, 512, '\t');
		m_qtyNeeded = atoi(buffer);
		ifstr.ignore();

		ifstr >> m_price;
		ifstr.ignore();

		if (!ifstr.good())
		{
			m_state = "Input file stream read failed!";
		}

		return ifstr;
	}

	std::ostream& Item::display(std::ostream& ostr)const
	{
		if (m_state)
		{
			if (m_isLinear)
			{
				ostr << std::setw(5) << m_sku << " | ";
				if (strlen(m_desc) > 35)
				{
					for (int i = 0; i < 35; i++)
					{
						ostr << m_desc[i];
					}
				}
				else
				{
					ostr << std::setw(35) << std::left << m_desc;
				}

				ostr << " | ";
				ostr << std::setw(4) << std::right << m_qty << " | ";
				ostr << std::setw(4) << std::right << m_qtyNeeded << " | ";
				ostr << std::setw(7) << std::right << std::fixed << std::setprecision(2) << m_price << " |";
			}
			else
			{
				ostr << "AMA Item:\n";
				ostr << m_sku << ": " << m_desc << "\n";
				ostr << "Quantity Needed: " << m_qtyNeeded << "\n";
				ostr << "Quantity Available: " << m_qty << "\n";
				ostr << "Unit Price: $" << std::fixed << std::setprecision(2) << m_price << "\n";
				ostr << "Needed Purchase Fund: $" << std::fixed << std::setprecision(2) << (m_qtyNeeded - m_qty) * m_price << "\n";
			}
		}
		else
		{
			ostr << (const char*)m_state;
		}

		return ostr;
	}

	std::istream& Item::read(std::istream& istr)
	{
		if (m_desc != nullptr)
		{
			delete[] m_desc;
			m_desc = nullptr;
		}

		//m_state.clear();

		std::cout << "AMA Item:\n";
		std::cout << "SKU: " << m_sku << "\n";

		std::cout << "Description: ";
		std::string desc_temp;
		istr >> desc_temp;

		m_desc = new char[desc_temp.length() + 1];
		strcpy(m_desc, desc_temp.c_str());
		while (istr.peek() != '\n') istr.ignore(10000, '\n');
		istr.ignore();

		std::cout << "Quantity Needed: ";
		m_qtyNeeded = inputInt(istr, 1, 9999);

		std::cout << "Quantity On Hand: ";
		m_qty = inputInt(istr, 0, m_qtyNeeded);

		std::cout << "Unit Price: $";
		m_price = inputDouble(istr, 0, 9999);

		if (!istr.good())
		{
			std::cout << "Console entry failed!";
		}

		return istr;
	}

	int Item::readSku(std::istream& istr)
	{
		int result = 0;
		bool ready = 0;

		std::cout << "SKU: ";

		while (ready == 0)
		{
			bool isInt = true;

			char buffer[24] = { 0 };
			istr.get(buffer, 24, '\n');
			while (istr.peek() != '\n') istr.ignore(1000, '\n');
			istr.ignore();

			for (int i = 0; i < (int)strlen(buffer); i++)
			{
				if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i] > 0)
				{
					isInt = false;
				}
			}

			if (isInt != true)
			{
				std::cout << "Invalid Integer, retry: ";
			}
			else if (isInt && (atoi(buffer) < 40000 || atoi(buffer) > 99999))
			{
				std::cout << "Value out of range [40000<=val<=99999]: ";
			}
			else
			{
				result = atoi(buffer);
				ready = 1;
			}
		}

		m_sku = result;

		return result;
	}

	int inputInt(std::istream& istr, int min, int max)
	{
		int result;
		bool ready = 0;

		while (ready == 0)
		{
			bool isInt = true;
			char buffer[128] = { 0 };

			istr.get(buffer, 127, '\n');
			while (istr.peek() != '\n') istr.ignore(1000, '\n');
			istr.ignore();

			for (int i = 0; i < (int)strlen(buffer); i++)
			{
				if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i] > 0)
				{
					isInt = false;
				}
			}

			if (isInt != true)
			{
				std::cout << "Invalid Integer, retry: ";
			}
			else if (isInt && (atoi(buffer) < min || atoi(buffer) > max))
			{
				std::cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
			}
			else
			{
				result = atoi(buffer);
				ready = 1;
			}
		}

		return result;
	}

	double inputDouble(std::istream& istr, double min, double max)
	{
		double result;
		bool ready = 0;

		while (ready == 0)
		{
			bool isInt = true;
			char buffer[128] = { 0 };

			istr.get(buffer, 127, '\n');
			while (istr.peek() != '\n') istr.ignore(1000, '\n');
			istr.ignore();

			for (int i = 0; i < (int)strlen(buffer); i++)
			{
				if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i] > 0 && buffer[i] != '.')
				{
					isInt = false;
				}
			}

			if (isInt != true)
			{
				std::cout << "Invalid number, retry: ";
			}
			else if (isInt && (atof(buffer) < min || atof(buffer) > max))
			{
				std::cout << "Value out of range [" << std::fixed << std::setprecision(2) << min << "<=val<=" << std::fixed << std::setprecision(2) << max << "]: ";
			}
			else
			{
				result = atof(buffer);
				ready = 1;
			}
		}

		return result;
	}
}