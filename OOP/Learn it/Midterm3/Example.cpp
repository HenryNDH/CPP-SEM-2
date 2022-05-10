#define _CRT_SECURE_NO_WARNINGS
/*------------------------1------------------------*/

//#include <iostream>
//
//using namespace std;
//const int NC = 31;
//
//struct Student {
//	int id;
//	float grade;
//	char name[NC];
//};
//
//int main()
//
//{
//	const int NOStdnts = 3;
//	Student william = { 2019, 77.6, "William" };
//	Student harper = { 2020, 78.5, "Harper" };
//	Student jackson = { 2021, 79.5, "Jackson" };
//
//	// TODO-1: Define an array of pointers to point to the objects william, harper, and jackson.
//	Student* Arr[3] = { &william, &harper, &jackson };
//
//	// TODO-2: Write a code to print the data using a loop through the array-of-pointers.
//	for (int i = 0; i < NOStdnts; i++) {
//		cout << "=====================" << endl;
//		cout << "id: " << Arr[i]->id << endl;
//		cout << "grade: " << Arr[i]->grade << endl;
//		cout << "name: " << Arr[i]->name << endl;
//	}
//}

/*------------------------2------------------------*/
//class Mark {
//    int m_value;
//public:
//    // Assume your prototype goes here
//    Mark();
//};
//// Assume that your implementation will be inserted here 
//Mark::Mark() {
//    m_value = 0;
//}

/*------------------------3------------------------*/
//#include "string.h"
//class Car {
//	char* type;
//	int price;
//	int num_of_doors;
//public:
//	Car() {
//		num_of_doors = 4;
//	};
//	// Your declaration goes here
//	Car(int, const char*);
//};
//// Your implementation goes here  
//Car::Car(int price_, const char* type_) { // L2
//	*this = Car(); // L3
//	price = price_; //L4
//	type = new char[strlen(type_) + 1]; //L5, 6
//	strcpy(type, type_);
//}

/*------------------------4------------------------*/
//#include <iostream>
//struct Fruit {
//    char name[30];
//    int sweetness;
//};
//
//int main() {
//    int fruitNum = 0;
//    std::cout << "Enter a number for Fruits desired: " << std::endl;
//    std::cin >> fruitNum;
//
//    // TODO: Allocate dynamic memory for an array of Fruits using fruitNum
//    Fruit* fruit = nullptr;
//    fruit = new Fruit[fruitNum];
//
//    // TODO: Accept user input for each fruit's name and sweetness in the array
//    for (int i = 0; i < fruitNum; ++i) {
//        std::cout << "Enter the fruit's name: " << std::endl;
//        std::cin >> fruit[i].name;
//        std::cout << "Enter the fruit's sweetness: " << std::endl;
//        std::cin >> fruit[i].sweetness;
//    }
//
//    // TODO: Deallocate any dynamic memory used
//    delete[] fruit;
//    fruit = nullptr;
//}

/*------------------------5------------------------*/
//#include <string.h>
//class Cat {
//    char* name;
//    int age;
//public:
//    Cat(const char* m_name, int m_age);
//};
//Cat::Cat(const char* m_name, int m_age) {
//    if (m_name && m_name[0] != '\0' && m_age > 0) {
//        name = new char[strlen(m_name) + 1];
//        strcpy(name, m_name);
//        age = m_age;
//    }
//    else
//    {
//        name = nullptr;
//        age = 0;
//    }
//}

/*------------------------6------------------------*/
//#include <iostream>
//#include "string.h"
//const int LEN = 20;
//
//using namespace std;
//
//struct Course {
//	char* courseCode;
//	int   credits;
//};
//
//int main() {
//	Course* courses;
//	char code[LEN + 1];
//	int numberOfCourses;
//	cout << "Enter the number of courses: " << endl;
//	cin >> numberOfCourses;
//
//	// TO-DO: Write the 5 lines of code that are missing
//	courses = new Course[numberOfCourses];				     // (1)DMA for courses
//
//	for (int i = 0; i < numberOfCourses; i++) {				 // (2)loop
//		cout << "Enter a course code : ";
//		cin >> code;
//		courses[i].courseCode = new char[strlen(code) + 1];  // (3)DMA for coursecode
//		strcpy(courses[i].courseCode, code);				 // (4)seting the coursecode
//		cout << "Enter course credits : ";
//		cin >> courses[i].credits;							 // (5)getting the course credit
//
//	} // end of an iteration
//
//	return 0;
//
//}

/*------------------------7------------------------*/
//#include <iostream>
//const double max_fuel = 365.7;
//class Car {
//	char model[20];
//	double fuel;
//public:
//	bool refuel(double fuel_);
//};
//bool Car::refuel(double fuel_) {
//	bool ret = true;
//	if (model[0] != '\0') {
//		fuel += fuel_;
//		fuel = fuel > max_fuel ? max_fuel : fuel;
//	}
//	else
//	{
//		ret = false;
//	}
//	return ret;
//}