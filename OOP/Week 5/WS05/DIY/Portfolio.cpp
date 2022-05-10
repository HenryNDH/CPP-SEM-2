/* ------------------------------------------------------
Workshop 5 part 2
Version 1
Author: Hoang Duy Nguyen
Email: hdnguyen12@myseneca.ca
ID: 108397217
-----------------------------------------------------------
Date      Feb 16 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include <cstring>
#include <iostream>

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }
    Portfolio::operator double() const
    {
        return m_value;
    }
    Portfolio::operator const char* () const
    {
        return m_stock;
    }
    Portfolio::operator char() const
    {
        return m_type;
    }
    Portfolio::operator bool() const
    {
        bool valid = false;
        if (m_type == 'G' || m_type == 'V' || m_type == 'I')
        {
            valid = true;
        }
        return valid;
    }
    Portfolio& Portfolio::operator+=(double other) 
    {
        if (other > 0 && this->m_value > 0 && this->m_value != other) 
        {
            this->m_value += other;
        }
        return *this;
    }
    Portfolio& Portfolio::operator-=(double other) 
    {
        if (other > 0 && this->m_value > 0 && this->m_value != other) 
        {
            this->m_value -= other;
        }
        return *this;
    }
    bool Portfolio::operator  ~() const
    {
        bool valid = false;
        if (m_value < 0)
        {
            valid = true;
        }
        return valid;
    }
    Portfolio& Portfolio::operator << (Portfolio& left)
    {
        if (bool(this) == true && bool(left) == true && !(this == &left))
        {
            this->m_value += left.m_value;
            left.emptyPortfolio();
        }

        return *this;
    }
    Portfolio& Portfolio::operator >> (Portfolio& right)
    {
        if (bool(this) == true && bool(right) == true && !(this == &right))
        {
            right.m_value += this->m_value;
            this->emptyPortfolio();
        }

        return *this;
    }
    double operator + (const Portfolio& left, const Portfolio& right)
    {
        double sum = 0;
        if (bool(left) && bool(right))
        {
            sum = double(left) + double(right);
        }
        return sum;
    }
    double operator += (double& left, const Portfolio& right)
    {
        left += double(right);
        return left;
    }
}