/* ------------------------------------------------------
Workshop 1 part 1
Module: ZDD
Filename: w1p1.cpp
Version 1
Author	Hoang Duy Nguyen
Student ID: 108397217
Email: hdnguyen12@myseneca.ca
Revision History
-----------------------------------------------------------
Date       01-18-2022
-----------------------------------------------------------*/
#include "Word.h"
#include <iostream>

	using namespace std;
	using namespace sdds;
int main() {
   char filename[256];
   programTitle();
   cout << "Enter filename: ";
   cin >> filename;
   wordStats(filename);
   return 0;
}
