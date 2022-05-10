/*==============================================
Final project Milestone 2
Module: Menu and AidMan
Name: Hoang Duy Nguyen
ID: 108397217
Email: hdnguyen12@myseneca.ca
Section: ZAA
==============================================*/

#include <iostream>
#include "AidMan.h"
#include "Utils.h"
int main() {
   std::cout << "Enter the following:\nabc\n1\n2\n3\n4\n5\n6\n7\n8\n0\n--------\n";
   sdds::ut.testMode();
   sdds::AidMan().run();
   return 0;
}