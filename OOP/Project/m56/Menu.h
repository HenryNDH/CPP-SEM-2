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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

using namespace std;
namespace sdds {
	class Menu {
		//Create a class called Menu. This class has two attributes.
	private:
		unsigned int m_numOpt = 0;
		char* m_list = nullptr;
		void setEmpty();

	public:
		//Construction
		Menu();
		Menu(unsigned int numOpt, const char* list);

		//Rule of three
		Menu(const Menu&) = delete;
		void operator=(const Menu&) = delete;
		~Menu();

		//Methods
		unsigned int run() const;
	};
}
#endif // !SDDS_MENU_H