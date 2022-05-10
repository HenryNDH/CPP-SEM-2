#include "Line.h"

namespace sdds {
    Line::Line() {
        m_length = 0;
    }
    //Passes the Cstring to LblShape() and sets m_length
    Line::Line(const char* label, int length = 0) : LblShape(label) {
        if (length > 0) {
            m_length = length;
        }
    }
    void Line::getSpecs(std::istream& istr) {
        int length;
        //call getspecs of LblShape - read length ignore char \n
        LblShape::getSpecs(istr);
        istr >> length;
        if (!istr.fail()) {
            m_length = length;
        }
        istr.ignore(1000, '\n');
    }
    //    Separator
    //    ========================================
    void Line::draw(std::ostream& ostr) const {
        if (m_length > 0 && label() != NULL) {
            ostr << label() << std::endl;
            ostr.width(m_length);
            ostr.fill('=');
            ostr << '=';
        }
    }

} //namespace
