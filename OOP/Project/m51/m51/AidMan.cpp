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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "AidMan.h"
#include "Utils.h"
#include "Date.h"
#include <fstream>
#include "Item.h"
#include "Perishable.h"
#include <string.h>
#include <iomanip>

using namespace std;
namespace sdds {
	unsigned int AidMan::menu() {
		cout << "Aid Management System" << endl;
		cout << "Date: " << Date() << endl;

		if (fileName == nullptr) {
			cout << "Data file: No file" << endl;
		}
		else
		{
			cout << "Data file: " << fileName << endl;
		}
		cout << "---------------------------------" << endl;
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
				cout << "\n****" << "List Items" << "****\n";
				list();
			}
			if (choose == 2)
			{
				cout << "\n****" << "Add Item" << "****\n";

			}
			if (choose == 3)
			{
				cout << "\n****" << "Remove Item" << "****\n";

			}
			if (choose == 4)
			{
				cout << "\n****" << "Update Quantity" << "****\n";

			}
			if (choose == 5)
			{
				cout << "\n****" << "Sort" << "****\n";

			}
			if (choose == 6)
			{
				cout << "\n****" << "Ship Items" << "****\n";

			}
			if (choose == 7)
			{
				cout << "\n****" << "New/Open Aid Database" << "****\n";
				load();
			}
			if (choose == 0)
			{
				cout << "Exiting Program!\n";
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
		char buffer[1025] = {0};

		std::cout << "Enter file name: ";
		std::cin.get(buffer, 1024, '\n');
		while (std::cin.peek() != '\n') std::cin.ignore(1024, '\n');
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
		int count = 0;

		if (sub_desc == nullptr)
		{
			std::cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry\n";
			std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";

			for (int i = 0; i < num_items; i++)
			{
				m_ptr[i]->linear(true);
				std::cout << std::setfill(' ') << std::setw(4) << count + 1;
				std::cout << " | ";
				m_ptr[i]->display(std::cout);
				count += 1;
				std::cout << "\n";
			}
			std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";

			if (count >= 1)
			{
				std::cout << "Enter row number to display details or <ENTER> to continue:\n";
				std::cout << "> ";
				if (std::cin.peek() != '\n')
				{
					char buffer[1024 + 1] = { 0 };
					std::cin.get(buffer, 1024, '\n');
					while (std::cin.peek() != '\n') std::cin.ignore(1024, '\n');
					std::cin.ignore();
					int choice = 0;
					choice = atoi(buffer);
					if (choice > 0 && choice <= count)
					{
						m_ptr[choice - 1]->linear(false);
						m_ptr[choice - 1]->display(std::cout);
						std::cout << "\n";
					}
				}
				else
				{
					std::cin.ignore();
				}
			}
		}
		else
		{
			std::cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry\n";
			std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
			for (int i = 0; i < num_items; i++)
			{
				std::string str;
				str.assign((const char*)m_ptr[i]);
				if (str.find(sub_desc) != std::string::npos)
				{
					m_ptr[i]->linear(true);
					std::cout << std::setfill(' ') << std::setw(4) << count + 1;
					std::cout << " | ";
					m_ptr[i]->display(std::cout);
					count += 1;
					std::cout << "\n";
				}
			}
			std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
			if (count >= 1)
			{
				std::cout << "Enter row number to display details or <ENTER> to continue:\n";
				std::cout << "> ";

				if (std::cin.peek() != '\n')
				{
					char buffer[1024 + 1] = { 0 };
					std::cin.get(buffer, 1024, '\n');
					while (std::cin.peek() != '\n') std::cin.ignore(1024, '\n');
					std::cin.ignore();
					int choice = 0;
					choice = atoi(buffer);
					if (choice > 0 && choice <= count)
					{
						m_ptr[choice - 1]->linear(false);
						m_ptr[choice - 1]->display(std::cout);
					}
				}
				else
				{
					std::cin.ignore();
				}
			}
		}
		if (count == 0)
		{
			std::cout << "The list is emtpy!";
		}
		std::cout << "\n";
		return count;
	}
}