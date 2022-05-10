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
#include "Date.h"
#include "Item.h"
#include "Utils.h"
#include <fstream>
#include <iomanip>
#include "AidMan.h"
#include <string.h>
#include <iostream>
#include "iProduct.h"
#include "Perishable.h"


namespace sdds {
	unsigned int AidMan::menu() {
		std::cout << "Aid Management System" << std::endl;
		std::cout << "Date: " << Date() << std::endl;

		if (fileName == nullptr) {
			std::cout << "Data file: No file" << std::endl;
		}
		else
		{
			std::cout << "Data file: " << fileName << std::endl;
		}
		std::cout << "---------------------------------" << std::endl;
		return mainMenu.run();
	}
	AidMan::AidMan() : mainMenu{ 7,
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
		save();
		deallocate();
		delete[] fileName;
		fileName = nullptr;
	}
	void AidMan::run() {
		bool valid = true;
		while (valid) {
			int choose = 0;
			choose = menu();
			if (choose != 0 && fileName == nullptr && choose != 7) {
				choose = 7;
			}
			if (choose == 1) {
				std::cout << "\n****" << "List Items" << "****\n";
				list();
			}
			if (choose == 2)
			{
				std::cout << "\n****" << "Add Item" << "****\n";
				if (fileName != nullptr) {
					if (!(num_items < sdds_max_num_items)) {
						std::cout << "Database full!\n";
					}
					else
					{
						std::cout << "1- Perishable\n2- Non-Perishable\n-----------------\n0- Exit\n";
						std::cout << "> ";
						char buffer[25] = { 0 };
						std::cin.get(buffer, 24, '\n');
						while (enterCheck())
						{
							std::cin.ignore(24, '\n');
						}
						std::cin.ignore();
						int choose = 0;
						choose = atoi(buffer);
						if (choose == 1) {
							Perishable* newPerishable = new Perishable();
							int skuTemp = 0;
							skuTemp = newPerishable->readSku(std::cin);
							if (search(skuTemp) == -1)
							{
								newPerishable->read(std::cin);
								m_ptr[num_items] = newPerishable;
								num_items += 1;
							}
							else
							{
								std::cout << "Sku: " << skuTemp << " is already in the system, try updating quantity instead.\n\n";
								delete newPerishable;
								newPerishable = nullptr;
							}
						}
						else if (choose == 2) {
							Item* newItem = new Item();
							int skuTemp = 0;
							skuTemp = newItem->readSku(std::cin);
							if (search(skuTemp) == -1)
							{
								newItem->read(std::cin);
								m_ptr[num_items] = newItem;
								num_items += 1;
							}
							else
							{
								std::cout << "Sku: " << skuTemp << " is already in the system, try updating quantity instead.\n";
								delete newItem;
								newItem = nullptr;
							}
						}
						else if (choose == 0) {
							std::cout << "Aborted\n";
						}
					}
					std::cout << "\n";
				}
			}
			if (choose == 3)
			{
				std::cout << "\n****" << "Remove Item" << "****\n";
				char buffer[1025] = { 0 };
				std::cout << "Item description: ";
				std::cin.get(buffer, 1024, '\n');
				while (enterCheck()) std::cin.ignore(128, '\n');
				std::cin.ignore();
				if (list(buffer) > 0) {
					std::cout << "Enter SKU: ";
					int skuTemp = ut.getint(10000, 99999);
					if (search(skuTemp) != -1) {
						int index = search(skuTemp);
						std::cout << "Following item will be removed: \n";
						m_ptr[index]->linear(false);
						m_ptr[index]->display(std::cout);

						std::cout << "\nAre you sure?\n1- Yes!\n0- Exit\n> ";
						int choice = ut.getint(0, 1);
						if (choice == 1) {
							remove(search(skuTemp));
							std::cout << "Item removed!\n";

						}
						else
						{

							std::cout << "Aborted\n";
						}
					}
					std::cout << "\n";
				}

			}
			if (choose == 4)
			{
				std::cout << "\n****" << "Update Quantity" << "****\n";
				char buffer[1025] = { 0 };
				std::cout << "Item description: ";
				std::cin.get(buffer, 1024, '\n');
				while (enterCheck()) std::cin.ignore(128, '\n');
				std::cin.ignore();



				if (list(buffer) > 0)
				{
					std::cout << "Enter SKU: ";
					int skuTemp = ut.getint(10000, 99999);
					int skuSeach;
					skuSeach = search(skuTemp);
					if (skuSeach == -1)
					{
						std::cout << "SKU not found!\n";
					}
					else
					{
						std::cout << "1- Add\n2- Reduce\n0- Exit\n> ";
						int choice;
						choice = ut.getint(0, 2);
						if (choice == 1) {
							if (m_ptr[search(skuTemp)]->qty() == m_ptr[search(skuTemp)]->qtyNeeded())
							{
								std::cout << "Quantity Needed already fulfilled!\n";
							}
							else
							{
								std::cout << "Quantity to add: ";
								int changes = ut.getint(1, m_ptr[search(skuTemp)]->qtyNeeded());
								std::cout << (m_ptr[search(skuTemp)]->operator+=(changes)) << " items added!\n";
							}
						}
						else if (choice == 2)
						{
							if (m_ptr[search(skuTemp)]->qty() == 0)
							{
								std::cout << "Quaintity on hand is zero!\n";
							}
							else
							{
								std::cout << "Quantity to reduce: ";
								int changes = ut.getint(1, m_ptr[search(skuTemp)]->qty());
								std::cout << ((m_ptr[search(skuTemp)]->operator-=(changes))) << " items removed!\n";
							}
						}
						else
						{
							std::cout << "Aborted!\n";
						}
					}
					std::cout << "\n";
				}
				else
				{
					std::cout << "No matches found!\n";
				}

			}
			if (choose == 5)
			{
				std::cout << "\n****" << "Sort" << "****\n";

			}
			if (choose == 6)
			{
				std::cout << "\n****" << "Ship Items" << "****\n";

			}
			if (choose == 7)
			{
				std::cout << "\n****" << "New/Open Aid Database" << "****\n";
				load();
			}
			if (choose == 0)
			{
				std::cout << "Exiting Program!\n";
				valid = false;
			}
		}
	}
	void AidMan::save() {
		if (fileName != nullptr) {
			std::ofstream aidWrite(fileName, std::ofstream::out);
			for (int i = 0; i < num_items; i++) {
				if (m_ptr[i] != nullptr) {
					m_ptr[i]->save(aidWrite);
					aidWrite << "\n";
				}
			}
		}
	}
	void  AidMan::deallocate() {
		for (int i = 0; i < 100; i++) {
			delete m_ptr[i];
			m_ptr[i] = nullptr;
		}
		num_items = 0;
	}
	//menu 7 ------------------------------------------------------------------
	void AidMan::load() {
		save();
		deallocate();
		bool valid = true;
		char buffer[1025] = { 0 };

		std::cout << "Enter file name: ";
		std::cin.get(buffer, 1024, '\n');
		while (enterCheck()) {
			std::cin.ignore(1024, '\n');
		}
		std::cin.ignore();
		fileName = new char[strlen(buffer) + 1];

		strcpy(fileName, buffer);
		std::ifstream fp(fileName);
		if (fp.is_open() && fp.good()) {
			while (valid)
			{
				if (fp.peek() >= '1' && fp.peek() <= '3') {
					m_ptr[num_items] = new Perishable();
				}
				else if (fp.peek() >= '0' && fp.peek() <= '9') {
					m_ptr[num_items] = new Item();
				}
				else
				{
					fp.setstate(std::ios::badbit);
				}
				if (fp.good()) {
					m_ptr[num_items]->load(fp);
					num_items += 1;
				}
				else
				{
					if (m_ptr[num_items] != nullptr) {
						delete m_ptr[num_items];
						m_ptr[num_items] = nullptr;
					}
					valid = false;
				}
			}
			std::cout << num_items << " records loaded!\n\n";
			fp.close();
		}
		else
		{
			std::cout << "Failed to open " << fileName << " for reading!" << std::endl;
			std::cout << "Would you like to create a new data file?" << std::endl;
			std::cout << "1- Yes!\n0- Exit\n";

			int choose;
			choose = ut.getint(0, 1, ">");
			if (choose == 1) {
				std::ofstream ofstr(fileName);
				ofstr.close();
			}
			else if (choose == 0) {
				valid = false;
			}
		}
	}
	//menu 1 -----------------------------------------------------------------------------------------------------------
	int AidMan::list(const char* sub_desc)
	{
		int index = 0;
		if (sub_desc == nullptr)
		{
			std::cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry\n";
			std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
			for (int i = 0; i < num_items; i++)
			{
				m_ptr[i]->linear(true);
				std::cout << std::setfill(' ') << std::setw(4) << index + 1 << " | ";
				m_ptr[i]->display(std::cout);
				index += 1;
				std::cout << "\n";
			}
			std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
			if (index >= 1)
			{
				std::cout << "Enter row number to display details or <ENTER> to continue:\n";
				std::cout << "> ";
				if (enterCheck())
				{
					char buffer[1025] = { 0 };
					std::cin.get(buffer, 1024, '\n');
					while (enterCheck())
					{
						std::cin.ignore(1024, '\n');
					}
					std::cin.ignore();
					int choosce = 0;
					choosce = atoi(buffer);
					if (choosce > 0 && choosce <= index)
					{
						m_ptr[choosce - 1]->linear(false);
						m_ptr[choosce - 1]->display(std::cout);
						std::cout << "\n";
					}
				}
				else
				{
					std::cin.ignore();
				}
				std::cout << "\n";
			}
		}
		else
		{
			std::cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry\n";
			std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
			for (int i = 0; i < num_items; i++)
			{
				std::string str;
				str.assign(m_ptr[i]->operator const char* ()); //Assign m_desc to string

				if (str.find(sub_desc) != std::string::npos) //use find to search if sub_desc have position in the string AKA m_desc
				{
					m_ptr[i]->linear(true);
					std::cout << std::setfill(' ') << std::setw(4) << i + 1;
					std::cout << " | ";
					m_ptr[i]->display(std::cout);
					index += 1;
					std::cout << "\n";
				}
			}
			std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
		}
		if (index == 0)
		{
			std::cout << "The list is emtpy!";
		}
		return index;
	}
	bool AidMan::enterCheck() {
		return std::cin.peek() != '\n' ? true : false;
	}
	//Menu 2--------------------------------------------------------------------
	int AidMan::search(int sku) const {
		int investigate = -1;

		for (int i = 0; i < num_items; i++)
		{
			if (m_ptr[i]->operator==(sku))
			{
				investigate = i;
				i = num_items;
			}
		}
		return investigate;
	}
	//Menu 3---------------------------------------------------------------------
	void AidMan::remove(int index) {
		if (m_ptr[index] != nullptr)
		{
			delete m_ptr[index];
			m_ptr[index] = nullptr;
			for (int i = index + 1; i < num_items + 1; i++)
			{
				m_ptr[(i - 1)] = m_ptr[i];
			}
			num_items -= 1;
		}
	}

}