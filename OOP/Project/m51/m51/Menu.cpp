/*---------------------------------------------------------
Final Project Milestone M51
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
#include <iostream>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	void Menu::setEmpty() {
		delete[] m_list;
		m_list = nullptr;
		m_numOpt = 0;
	}
	//Construction
	Menu::Menu()
	{
		m_list = nullptr;
		m_numOpt = 0;
	}
	Menu::Menu(unsigned int numOpt, const char* list) {
		if (list != nullptr && numOpt <= 15) {
			ut.alocpy(m_list, list);
			m_numOpt = numOpt;
		}
		else
		{
			setEmpty();
		}
	}
	//Rule of three
	Menu::~Menu() {
		setEmpty();
	}

	//Methods
	unsigned int Menu::run() const {
		cout << m_list;
		cout << 0 << "- " << "Exit" << endl;
		return ut.getint(0, m_numOpt, ">");
	}

}