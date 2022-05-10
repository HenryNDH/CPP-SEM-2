/*---------------------------------------------------------
Final Project Milestone M54
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
#include <iostream>
#include <iomanip>
#include "Utils.h"
#include "Status.h"
#include "Date.h"
#include <math.h>  

using namespace std;
namespace sdds
{
    bool Date::validate() {
        bool valid = true;
        if (m_year < sdds_testYear || m_year > MAX_YEAR || m_month < 1 || m_month > 12 || m_day < 1 || m_day > ut.daysOfMon(m_month, m_year)) {
            if (m_year < sdds_testYear || m_year > MAX_YEAR) {
                m_state.setCodeDes("Invalid year in date", 1);
                valid = false;
            }
            else if (m_month < 1 || m_month > 12) {
                m_state.setCodeDes("Invalid month in date", 2);
                valid = false;
            }
            else if (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year)) {
                m_state.setCodeDes("Invalid day in date", 3);
                valid = false;
            }
        }
        return valid;;
    }
    int Date::uniqueDateValue() const {
        return (m_year * 372) + (m_month * 31) + m_day;
    }
    Date::Date() {
        m_day = sdds_testDay;
        m_month = sdds_testMon;
        m_year = sdds_testYear;
    }
    Date::Date(int year, int month, int day) {
        m_year = year;
        m_month = month;
        m_day = day;
        validate();
    }
    bool Date::operator==(const Date& Date) const {
        return this->uniqueDateValue() == Date.uniqueDateValue();
    }
    bool Date::operator!=(const Date& Date) const {
        return this->uniqueDateValue() != Date.uniqueDateValue();
    }
    bool Date::operator<(const Date& Date) const {
        return this->uniqueDateValue() < Date.uniqueDateValue();
    }
    bool Date::operator>(const Date& Date) const {
        return this->uniqueDateValue() > Date.uniqueDateValue();
    }
    bool Date::operator<=(const Date& Date) const {
        return this->uniqueDateValue() <= Date.uniqueDateValue();
    }
    bool Date::operator>=(const Date& Date) const {
        return this->uniqueDateValue() >= Date.uniqueDateValue();
    }
    const Status& Date::state() {
        return m_state;
    }
    Date& Date::formatted(bool flag) {
        m_format = false;
        return *this;
    }
    Date::operator bool() const {
        Status State;
        return State.operator bool();
    }
    std::ostream& Date::write(std::ostream& ostr) const {
        if (m_format) {
            ostr << m_year << '/';
            ostr.width(2);
            ostr.fill('0');
            ostr << m_month << '/';
            ostr.width(2);
            ostr << m_day;
        }
        else {
            ostr << m_year % 100;
            ostr.width(2);
            ostr.fill('0');
            ostr << m_month;
            ostr.width(2);
            ostr << m_day;
        }
        return ostr;
    }

    std::ostream& Date::writeLinear(std::ostream& ostr, bool format) const {
        if (format) {
            ostr << m_year << '/';
            ostr.width(2);
            ostr.fill('0');
            ostr << m_month << '/';
            ostr.width(2);
            ostr << m_day;
        }
        else {
            ostr << m_year % 100;
            ostr.width(2);
            ostr.fill('0');
            ostr << m_month;
            ostr.width(2);
            ostr << m_day;
        }
        return ostr;
    }
    std::istream& Date::read(std::istream& istr) {
        int dummy = 0;
        bool isNumber = true;
        char ch = 0;

        ch = istr.peek();
        istr >> dummy;

        if (!std::isdigit(ch) && dummy == 0)
        {
            isNumber = false;
        }

        if (isNumber)
        {
            if (dummy / 100000 >= 1)
            {
                m_year = 2000 + dummy / 10000;
                m_month = dummy / 100 - ((m_year - 2000) * 100);
                m_day = dummy - ((dummy / 100) * 100);
                if (!validate())
                {
                    istr.setstate(std::ios::badbit);
                }
            }
            else if (dummy / 1000 >= 1)
            {
                m_month = dummy / 100;
                m_day = dummy - ((dummy / 100) * 100);
                if (!validate())
                {
                    istr.setstate(std::ios::badbit);
                }
            }
            else
            {
                m_month = 0;
                m_day = 0;
                validate();
                istr.setstate(std::ios::badbit);
            }
        }
        else
        {
            m_state = "Invalid date value";
            istr.setstate(std::ios::badbit);
        }

        return istr;
    }
    std::ostream& operator<<(std::ostream& ostr, const Date& Date) {
        return Date.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, Date& Date) {
        return Date.read(istr);
    }
}