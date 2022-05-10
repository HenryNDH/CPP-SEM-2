#include <iostream>
#include "AidMan.h"
#include "Utils.h"
#include "Date.h"


using namespace std;
namespace sdds {
	unsigned int AidMan::menu() {
		cout << "Aid Management System Version 0.1" << endl;
		cout << "Date: " << Date() << endl;
		
		if (fileName == nullptr) {
			cout << "Data file: No file" << endl;
		}
		else
		{
			cout << "Data file:  " << fileName << endl;
		}
		cout << "---------------------------------" << endl;
		return mainMenu.run();
	}
	AidMan::AidMan() : mainMenu {7,
			"1- List Items\n"
			"2- Add Item\n"
			"3- Remove Item\n"
			"4- Update Quantity\n"
			"5- Sort\n"
			"6- Ship Items\n"
			"7- New/Open Aid Database\n"
			"---------------------------------\n"
	} 
	{
		fileName = nullptr;
	}
	AidMan::~AidMan() {
		delete[] fileName;
		fileName = nullptr;
	}
	void AidMan::run() {
		bool valid = true;
		while (valid) {
			int choose = 0;
			choose = menu();
			if (choose == 1) {
				cout << "\n****" << "List Items" << "****\n\n";
				
			}
			if (choose == 2)
			{
				cout << "\n****" << "Add Item" << "****\n\n";
				
			}
			if (choose == 3)
			{
				cout << "\n****" << "Remove Item" << "****\n\n";

			}
			if (choose == 4)
			{
				cout << "\n****" << "Update Quantity" << "****\n\n";

			}
			if (choose == 5)
			{
				cout << "\n****" << "Sort" << "****\n\n";

			}
			if (choose == 6)
			{
				cout << "\n****" << "Ship Items" << "****\n\n";

			}
			if (choose == 7)
			{
				cout << "\n****" << "New/Open Aid Database" << "****\n\n";

			}
			if (choose == 0)
			{
				cout << "Exiting Program!\n";
				valid = false;
			}
		}
	}	
}