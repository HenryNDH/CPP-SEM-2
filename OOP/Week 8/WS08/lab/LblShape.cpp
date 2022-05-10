#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <string>
namespace sdds {
    const char* LblShape::label() const {
        return m_label;
    }
    LblShape::LblShape() {
        delete[] m_label;
        m_label = nullptr;
    }
    LblShape::LblShape(const char* label) {
        if (m_label != nullptr)
        {
            delete[] m_label;
            m_label = nullptr;
        }
        if (label != nullptr && label[0] != '\0') {
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
    }
    LblShape::~LblShape() {
        delete[] m_label;
        m_label = nullptr;
    }
    void LblShape::getSpecs(std::istream& istr) {
        std::string label;
        getline(istr, label, ',');
        if (label[0] != '\0') {
            if (m_label != nullptr)
            {
                delete[] m_label;
                m_label = nullptr;
            }
            m_label = new char[strlen(label.c_str()) + 1];
            strcpy(m_label, label.c_str());
        }
    }


}