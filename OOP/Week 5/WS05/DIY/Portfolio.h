/* ------------------------------------------------------
Workshop 5 part 2
Version 1
Author: Hoang Duy Nguyen
Email: hdnguyen12@myseneca.ca
ID: 108397217
-----------------------------------------------------------
Date      Feb 16 2022
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>
using namespace std;
namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:
       void emptyPortfolio();
       Portfolio();
       Portfolio(double value, const char* stock, char type);
       void dispPortfolio() const;
       ostream& display() const;
       operator double() const;
       operator const char* () const;
       operator char () const;
       operator bool() const;
       Portfolio& operator += (double other);
       Portfolio& operator -= (double other);
       bool operator  ~() const;
       Portfolio& operator << (Portfolio& other);
       Portfolio& operator >> (Portfolio& other);
   };
   double operator + (const Portfolio& left, const Portfolio& right);
   double operator += (double& left, const Portfolio& right);
}
#endif // SDDS_Portfolio_H_