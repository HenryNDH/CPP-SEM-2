/* ------------------------------------------------------
Workshop 1 part 1
Module: N/A
Filename: w1p1.cpp
Version 1
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#include "cStrTools.h"
#include "Word.h"
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
