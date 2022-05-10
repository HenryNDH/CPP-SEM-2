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
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "Utils.h"
#include "Status.h"
#define MAX_YEAR 2030
using namespace std;
namespace sdds {
    class Date
    {
        int m_year = 0;
        int m_month = 0;
        int m_day = 0;
        Status m_state;
        bool m_format = true;
        bool validate();
    public:
        int uniqueDateValue() const;
        //Construction
        Date();
        Date(int, int, int);
        //operator overloads for comparison (==, !=, <, >, <=, >=)
        bool operator==(const Date& D) const;
        bool operator!=(const Date& D) const;
        bool operator<(const Date& D) const;
        bool operator>(const Date& D) const;
        bool operator<=(const Date& D) const;
        bool operator>=(const Date& D) const;
        //state accessor
        const Status& state();
        //formatted modifier
        Date& formatted(bool flag = true);
        
        //bool conversion overload
        operator bool() const;
        //write method
        std::ostream& write(std::ostream& ostr) const;

        std::ostream& writeLinear(std::ostream& ostr, bool format) const;
        //read method
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const Date& D);
    std::istream& operator>>(std::istream& istr, Date& D);
}
#endif