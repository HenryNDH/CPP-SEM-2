#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>

#include "CarInventory.h"

namespace sdds {

	CarInventory::CarInventory()
	{
		resetInfo();
	}
	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		setInfo(type, brand, model, year, code, price);
	}

	CarInventory::~CarInventory()
	{
		if (m_type != NULL)
		{
			delete[] m_type;
			m_type = nullptr;
		}

		if (m_brand != NULL)
		{
			delete[]  m_brand;
			m_brand = nullptr;
		}

		if (m_model != NULL)
		{
			delete[] m_model;
			m_model = nullptr;
		}
	}

	void CarInventory::resetInfo()
	{
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		if (type != NULL)
		{
			if (m_type != NULL)
			{
				delete[] m_type;
				m_type = nullptr;
			}

			m_type = new char[strLen(type) + 1];
			strCpy(m_type, type);
		}

		if (brand != NULL)
		{
			if (m_brand != NULL)
			{
				delete[] m_brand;
				m_brand = nullptr;
			}

			m_brand = new char[strLen(brand) + 1];
			strCpy(m_brand, brand);
		}

		if (model != NULL)
		{
			if (m_model != NULL)
			{
				delete[] m_model;
				m_model = nullptr;
			}

			m_model = new char[strLen(model) + 1];
			strCpy(m_model, model);
		}

		m_year = year;
		m_code = code;
		m_price = price;

		return *this;
	}

	bool CarInventory::isValid() const
	{
		bool valid = false;
		if (m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code > 99 && m_code < 1000 && m_price > 0)
			valid = true;
		return valid;
	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{
		bool flag;
		if (m_type == nullptr || car.m_type == nullptr || m_model == nullptr || car.m_model == nullptr || m_brand == nullptr || car.m_brand == nullptr)
		{
			return false;
		}
		if (strCmp(m_type, car.m_type) == 0 && strCmp(m_model, car.m_model) == 0 && strCmp(m_brand, car.m_brand) == 0 && m_year == car.m_year)
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
		return flag;
	}

	void CarInventory::printInfo() const
	{
		cout << "| " << m_type << setw(13 - strLen(m_type)) << "| ";
		cout << m_brand << setw(19 - strLen(m_brand)) << "| ";
		cout << m_model << setw(19 - strLen(m_model)) << "| ";
		cout << m_year << setw(3) << "| ";
		cout << setw(4) << m_code << setw(3) << "| ";
		cout << setprecision(2) << setw(9) << fixed << m_price << " |";
		cout << endl;
	}

	bool find_similar(CarInventory car[], const int num_cars)
	{
		bool flag = false;

		for (int i = 0; i < num_cars; i++)
		{
			for (int j = i + 1; j < num_cars; j++)
			{
				if (car[i].isSimilarTo(car[j]))
				{
					flag = true;
				}
			}
		}

		return flag;
	}

	//CStrTools
	int strCmp(const char* s1, const char* s2)
	{
		int i;
		for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
		return s1[i] - s2[i];
	}

	void strCpy(char* des, const char* src)
	{
		int i;
		for (i = 0; src[i]; i++) des[i] = src[i];
		des[i] = 0;
	}

	int strLen(const char* str)
	{
		int len;
		for (len = 0; str[len]; len++);
		return len;
	}
}