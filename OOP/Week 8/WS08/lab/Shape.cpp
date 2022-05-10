/*
==============================================
Name: Hoang Duy Nguyen
ID: 108397217
Email: hdnguyen12@myseneca.ca
Section: ZAA
Workshop 8: Virtual Function
==============================================
*/
#include "Shape.h"

namespace sdds {
    std::ostream& operator<<(std::ostream& ostr, const Shape& S) {
        S.draw(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Shape& S) {
        S.getSpecs(istr);
        return istr;
    }
}