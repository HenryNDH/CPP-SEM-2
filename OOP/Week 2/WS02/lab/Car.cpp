#include "Car.h"
#include "cStrTools.h"
#include <iostream>
using namespace std;
namespace sdds {
	Car* DAofCars; //create a pointer to a Car structure
	int allocationSize; 
	int numOfCars;
	int carArraySize;
	//Function used to print message
	void VBPLE_Title() {
		cout << "Vehicle Border Passing Log Entry" << endl;
		cout << "Enter the data in the following format:" << endl;
		cout << "Make and model,LicensePlate,MilitaryTime<ENTER>" << endl;
		cout << "Exit the program by entering the following:" << endl;
		cout << "X,<ENTER>" << endl;
	}
	//Function used to allocate memory
	void initialize(int allocSize) {
		allocationSize = carArraySize = allocSize;
		DAofCars = new Car[allocationSize]{};
	}
	//Function used to deallocate memory
	void deallocate(Car& C) {
		delete[] C.CarModel;
		C.CarModel = nullptr;
	}
	//Function to check memory
	bool read(Car& C) {
		C = { 0 };

		bool flag = false;
		char buffer[60];

		read(buffer, 60, ',');

		if (buffer[0] != 'X') //Read variable until 'X'
		{
			flag = true;
			C.CarModel = new char[strLen(buffer) + 1]{};
			strCpy(C.CarModel, buffer);

			read(buffer, 60, ',');
			strCpy(C.LicensePlate, buffer);

			cin >> C.time;
		}
		return flag;
	}
	//Function to print
	void print(const Car& C) {
		cout << C.time << ": " << C.CarModel << "," << C.LicensePlate << std::endl;
	}
	void record(const Car& C) {
		if (numOfCars >= carArraySize) {
			Car* temp = new Car[carArraySize + allocationSize]{};
			for (int i = 0; i < carArraySize + allocationSize; i++) {
				temp[i] = { 0 };
			}
			for (int i = 0; i < carArraySize; i++) {
				temp[i].CarModel = DAofCars[i].CarModel;
				strCpy(temp[i].LicensePlate, DAofCars[i].LicensePlate);
				temp[i].time = DAofCars[i].time;
			}
			delete[] DAofCars;
			DAofCars = temp;
			carArraySize = carArraySize + allocationSize;
		}
		DAofCars[numOfCars].CarModel = C.CarModel;
		strCpy(DAofCars[numOfCars].LicensePlate, C.LicensePlate);
		DAofCars[numOfCars].time = C.time;
		numOfCars++;
	}
	void endOfDay() {
		for (int i = 0; i < numOfCars; i++) {
			print(DAofCars[i]);
			deallocate(DAofCars[i]);
		}
		delete[] DAofCars;
		DAofCars = nullptr;
	}
}