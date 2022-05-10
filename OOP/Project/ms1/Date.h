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
        int m_year;
        int m_month;
        int m_day;
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
        //read method
        std::istream& read(std::istream& istr);
	};
    std::ostream& operator<<(std::ostream& ostr, const Date& D);
    std::istream& operator>>(std::istream& istr, Date& D);
}
#endif