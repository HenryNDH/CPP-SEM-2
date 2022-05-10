/* ------------------------------------------------------
Workshop 5 part 1
Version 1
Author: Hoang Duy Nguyen
Email: hdnguyen12@myseneca.ca
ID: 108397217
-----------------------------------------------------------
Date      Feb 16 2022
-----------------------------------------------------------*/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

	const int Boen747Capacity = 388;
	const int FuelTankCapacity = 238840;

	class Flight {

		int m_passengers = 0;
		double m_fuel = 0;
		char m_title[16];
		void emptyPlane();

	public:
		Flight();
		Flight(int passengers, double fuel, const char* title);
		std::ostream& display()const;

		// type conversion operators
		operator bool() const;
		operator int() const;
		operator double() const;
		operator const char* () const;

		//Unary member operator
		bool operator  ~() const;

		//Binary member operators
		Flight& operator = (Flight& other);
		Flight& operator = (int other);
		Flight& operator = (double other);
		Flight& operator += (double other);
		Flight& operator += (int other);
		Flight& operator -= (double other);
		Flight& operator -= (int other);
		Flight& operator << (Flight& other);
		Flight& operator >> (Flight& other);
	};
	int operator + (const Flight& left, const Flight& right);
	int operator += (int& left, const Flight& right);
}
#endif // SDDS_FLIGHT_H