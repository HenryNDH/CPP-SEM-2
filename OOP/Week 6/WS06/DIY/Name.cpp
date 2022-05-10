#define _CRT_SECURE_NO_WARNINGS
#include "Name.h"

namespace sdds {
	Name::~Name() {
		if (m_Fname != nullptr)
		{
			delete[] m_Fname;
			m_Fname = nullptr;
		}
		if (m_Mname != nullptr)
		{
			delete[] m_Mname;
			m_Mname = nullptr;
		}
		if (m_Lname != nullptr)
		{
			delete[] m_Lname;
			m_Lname = nullptr;
		}
	}
}