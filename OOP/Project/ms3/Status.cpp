/*---------------------------------------------------------
Final Project Milestone 3
Version 1.0
Author	Hoang Duy Nguyen
StudentID: 108397217
Email: hdnguyen12@myseneca.ca
-----------------------------------------------------------
Date
2022/26/03
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Status.h"
#include "Utils.h"

using namespace std;
namespace sdds {
    void Status::setCodeDes(const char* desc, const int code) {
        if (desc != nullptr) {
            m_desc = new char[strlen(desc) + 1];
            strcpy(m_desc, desc);
        }
        m_code = code;
    }
    //Construction
    Status::Status() {
        m_desc = nullptr;
        m_code = 0;
    }
    Status::Status(const char* desc, const int code) {
        delete m_desc;
        m_desc = nullptr;
        m_code = 0;
        setCodeDes(desc, code);
    }
    //Rule of three
    Status::Status(const Status& copy) {
        *this = copy;
    }
    Status& Status::operator=(const Status& copy) {
        if (this != &copy) {
            setCodeDes(copy.m_desc, copy.m_code);
        }
        return *this;
    }
    Status::~Status() {
        delete[] m_desc;
        m_desc = nullptr;
    }
    //Assignment operator overloads
    Status::operator int() const {
        return this->m_code;
    }
    Status::operator const char* () const {
        return this->m_desc;
    }
    Status::operator bool() const {
        return m_desc == nullptr;
    }
    //Type Conversion Overloads
    void Status::operator=(const char* desc) {
        delete[] m_desc;
        if (desc != nullptr) {
            m_desc = new char[strlen(desc) + 1];
            strcpy(m_desc, desc);
        }
        else
            m_desc = nullptr;
    }
    void Status::operator=(const int code) {
        m_code = code;
    }
    //clear method
    Status& Status::clear() {
        delete[] m_desc;
        m_desc = nullptr;
        m_code = 0;
        return *this;
    }
    ostream& operator << (ostream& ostr, const Status& status)
    {
        if (!status && int(status) != 0)
        {
            ostr << "ERR#" << int(status) << ": ";
            ostr << (const char*)(status);
        }
        else
        {
            ostr << (const char*)status;
        }

        return ostr;
    }
}