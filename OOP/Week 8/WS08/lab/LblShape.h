#pragma once
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <stdio.h>
#include "Shape.h"
namespace sdds {
    class LblShape : public Shape {
        char* m_label = nullptr;
    protected:
        //returns the unmodifiable value of m_label
        const char* label() const;
    public:
        LblShape();
        LblShape(const char* label);
        ~LblShape();
        LblShape(const LblShape& L) = delete;
        LblShape& operator=(const LblShape& L) = delete;
        void getSpecs(std::istream& istr);
    };
}
#endif // !SDDS_LBLSHAPE_H
