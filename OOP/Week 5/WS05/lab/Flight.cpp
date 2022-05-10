/* ------------------------------------------------------
Workshop 5 part 1
Version 1
Author: Hoang Duy Nguyen
Email: hdnguyen12@myseneca.ca
ID: 108397217
-----------------------------------------------------------
Date      Feb 16 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    // type conversion operators
    Flight::operator bool() const
    {
        bool valid = false;
        double min_fuel = m_passengers * 600;
        if (m_passengers > 0 && m_fuel >= min_fuel)
        {
            valid = true;
        }
        return valid;
    }
    Flight::operator int() const
    {
        return m_passengers;
    }
    Flight::operator double() const
    {
        return m_fuel;
    }
    Flight::operator const char* () const
    {
        return m_title;
    }

    //Unary member operator
    bool Flight::operator  ~() const
    {
        bool valid = false;
        if (m_passengers == 0)
        {
            valid = true;
        }
        return valid;
    }

    //Binary member operators
    Flight& Flight::operator = (Flight& other)
    {
        this->m_passengers = other.m_passengers;
        this->m_fuel = other.m_fuel;
        strcpy(this->m_title, other.m_title);
        other.emptyPlane();
        return *this;
    }
    Flight& Flight::operator = (int other)
    {
        if (other > 0 && other <= Boen747Capacity)
        {
            this->m_passengers = other;
        }
        return *this;
    }
    Flight& Flight::operator = (double other)
    {
        if (other > 0 && other <= FuelTankCapacity)
        {
            this->m_fuel = other;
        }
        return *this;
    }
    Flight& Flight::operator += (double other)
    {
        if (other > 0 && m_fuel < FuelTankCapacity)
        {
            this->m_fuel += other;
        }
        return *this;
    }
    Flight& Flight::operator += (int other)
    {
        if (other > 0 && m_passengers < Boen747Capacity)
        {
            this->m_passengers += other;
        }
        return *this;
    }
    Flight& Flight::operator -= (double other)
    {
        if (other > 0 && m_fuel - other >= 0)
        {
            this->m_fuel -= other;
        }
        return *this;
    }
    Flight& Flight::operator -= (int other)
    {
        if (other > 0 && m_passengers - other >= 0)
        {
            this->m_passengers -= other;
        }
        return *this;
    }
    Flight& Flight::operator << (Flight& left)
    {
        int add = 0;
        if (this->m_passengers + left.m_passengers > Boen747Capacity)
        {
            add = Boen747Capacity - left.m_passengers;
            left.m_passengers += add;
            this->m_passengers -= add;
        }
        else
        {
            left.m_passengers += this->m_passengers;
            this->m_passengers = 0;
        }
        return *this;
    }
    Flight& Flight::operator >> (Flight& right)
    {
        int add = 0;
        if (this->m_passengers + right.m_passengers > Boen747Capacity)
        {
            add = Boen747Capacity - right.m_passengers;
            right.m_passengers += add;
            this->m_passengers -= add;
        }
        else
        {
            right.m_passengers += this->m_passengers;
            this->m_passengers = 0;
        }
        return *this;
    }
    int operator + (const Flight& left, const Flight& right)
    {
        int sum = 0;
        if (bool(left) && bool(right))
        {
            sum = int(left) + int(right);
        }
        return sum;
    }
    int operator += (int& left, const Flight& right)
    {
        left += int(right);
        return left;
    }
}