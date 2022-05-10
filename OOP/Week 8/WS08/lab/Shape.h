#pragma once
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
namespace sdds {
    class Shape {
    public:
        //methods
        virtual void draw(ostream& ostr) const = 0;
        virtual void getSpecs(istream& istr) = 0;
        virtual ~Shape() {};
    };
    ostream& operator<<(ostream& ostr, const Shape& S);
    istream& operator>>(istream& istr, Shape& S);
}
#endif // !SDDS_SHAPE_H
