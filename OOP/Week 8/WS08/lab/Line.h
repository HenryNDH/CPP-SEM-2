#pragma once
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
#include <stdio.h>
namespace sdds {
    class Line : public LblShape {
    private:
        int m_length; //length of the Line in characters
    public:
        Line();
        Line(const char* label, int length);
        virtual ~Line() {};
        void getSpecs(std::istream& istr);
        void draw(std::ostream& ostr) const;
    };
}
#endif // !SDDS_LINE_H
