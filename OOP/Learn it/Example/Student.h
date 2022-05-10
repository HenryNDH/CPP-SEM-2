#define _CRT_SECURE_NO_WARNINGS
// Student.h

#include <iostream>
const int NC = 30;
const int NG = 20;

class Person {                   // start of Base Class Definition
    char name[NC + 1];
public:
    void set(const char* n);    // input value -> name
    void displayName(std::ostream&) const;
};                              // end of Base Class Definition

class Student : public Person { // start of Derived Class Definition 
    int no;
    float grade[NG];
    int ng;
public:
    Student();
    Student(int);
    Student(int, const float*, int);
    void display(std::ostream&) const;
};