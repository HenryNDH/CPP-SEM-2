/*---------------------------------------------------------
Final Project Milestone M56
Version 1.0
Author	Hoang Duy Nguyen
StudentID: 108397217
Email: hdnguyen12@myseneca.ca
-----------------------------------------------------------
Date
2022/04/10
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "Menu.h"
#include "iProduct.h"

using namespace std;
namespace sdds {
	const int sdds_max_num_items = 100;
	class AidMan {
		iProduct* m_ptr[sdds_max_num_items] = { nullptr };
		int num_items; //Obviously this number can not grow more than 100
		//Attributes
		char* fileName;
		//Menu
		Menu mainMenu; // declare object
		unsigned int menu();
	public:
		void save();
		void deallocate();
		int list(const char* sub_desc = nullptr); //Menu 1
		int search(int sku) const; //Menu 2
		void remove(int index); //Menu 3
		void load(); //Menu 7
		//Construction
		AidMan();
		//Rule Of Three
		~AidMan();
		//the public method run()
		void run();
		bool enterCheck();
	};
	
}