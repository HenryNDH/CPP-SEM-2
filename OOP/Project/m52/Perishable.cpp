/*---------------------------------------------------------
Final Project Milestone M52
Version 1.0
Author	Hoang Duy Nguyen
StudentID: 108397217
Email: hdnguyen12@myseneca.ca
-----------------------------------------------------------
Date
2022/04/09
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string.h>
#include "Utils.h"
#include "Perishable.h"
namespace sdds {

	Perishable::Perishable() :Item() {
		m_Instr = nullptr;
	}

	Perishable::Perishable(const Perishable& copy) : Item(copy) {
		if (m_Instr != nullptr) {
			delete[] m_Instr;
			m_Instr = nullptr;
		}
		if (copy.m_Instr != nullptr) {
			m_Instr = new char[strlen(copy.m_Instr) + 1];
			strcpy(m_Instr, copy.m_Instr);
		}
		m_expiry = copy.m_expiry;
	}

	Perishable& Perishable::operator =(const Perishable& copy) {
		Item::operator=(copy);
		if (m_Instr != nullptr) {
			delete[] m_Instr;
			m_Instr = nullptr;
		}
		if (copy.m_Instr != nullptr) {
			m_Instr = new char[strlen(copy.m_Instr) + 1];
			strcpy(m_Instr, copy.m_Instr);
		}
		m_expiry = copy.m_expiry;
		return *this;
	}

	Perishable::~Perishable() {
		delete[] m_Instr;
		m_Instr = nullptr;
	}

	const Date& Perishable::expiry() const {
		return m_expiry;
	}

	int Perishable::readSku(std::istream& istr) {
		m_sku = ut.getint(10000, 39999, "SKU:");
		return m_sku;
	}

	std::ofstream& Perishable::save(std::ofstream& ofstr) const {
		if (m_state) {
			Item::save(ofstr);
			ofstr << '\t';
			if (m_Instr != nullptr && m_Instr[0] != '\0') {
				ofstr << m_Instr;
			}
			ofstr << '\t';
			Date exp;
			exp = m_expiry;
			exp.formatted(false);
			ofstr << exp;
		}
		return ofstr;
	}

	std::ifstream& Perishable::load(std::ifstream& ifstr) {
		Item::load(ifstr);
		if (ifstr.peek() != '\n') {
			if (m_Instr != nullptr) {
				delete[] m_Instr;
				m_Instr = nullptr;
			}
			char buffer[1025];
			ifstr.getline(buffer, 1024, '\t');
			m_Instr = new char[strlen(buffer) + 1];
			strcpy(m_Instr, buffer);

			m_expiry.read(ifstr);
			ifstr.ignore();

		}
		if (ifstr.fail()) {
			m_state = "Input file stream read (perishable) failed!";
		}
		return ifstr;
	}
	std::ostream& Perishable::display(std::ostream& ostr)const {
		Date date = m_expiry;
		date.formatted(true);
		if (!Item::m_state) {
			ostr << m_state;
		}
		if (linear()) {
			Item::display(ostr);
			
			if (m_Instr && m_Instr[0] != '\0') {
				ostr << '*';
			}
			else {
				ostr << ' ';
			}
			date.writeLinear(ostr, true);
		}
		else
		{
			ostr << "Perishable ";
			Item::display(ostr);
			ostr << "Expiry date: ";
			date.writeLinear(ostr, true);
			if (m_Instr != nullptr && m_Instr[0] != '\0') {
				ostr << "\nHandling Instructions: ";
				ostr << m_Instr;
			}
			ostr << '\n';
		}
		return ostr;
	}
	std::istream& Perishable::read(std::istream& istr) {
		Item::read(istr);

		if (m_Instr != nullptr)
		{
			delete[] m_Instr;
			m_Instr = nullptr;
		}

		std::cout << "Expiry date (YYMMDD): ";

		m_expiry.read(istr);

		while (istr.peek() != '\n') istr.ignore(1024, '\n');
		istr.ignore();

		std::cout << "Handling Instructions, ENTER to skip: ";

		if (istr.peek() != '\n')
		{
			char buffer[1024 + 1] = { 0 };

			istr.get(buffer, 1024, '\n');
			while (istr.peek() != '\n') istr.ignore(1024, '\n');
			istr.ignore();

			if (m_Instr != nullptr)
			{
				delete[] m_Instr;
				m_Instr = nullptr;
			}

			m_Instr = new char[strlen(buffer) + 1];
			strcpy(m_Instr, buffer);
		}
		else
		{
			istr.ignore();
		}

		if (!istr.good())
		{
			Item::m_state = "Perishable console date entry failed!";
		}

		return istr;
	}
	Perishable::operator bool() const {
		return m_Instr != nullptr ? true : false;
	}
}