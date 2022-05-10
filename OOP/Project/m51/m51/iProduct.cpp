/*---------------------------------------------------------
Final Project Milestone M51
Version 1.0
Author	Hoang Duy Nguyen
StudentID: 108397217
Email: hdnguyen12@myseneca.ca
-----------------------------------------------------------
Date
2022/04/09
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "iProduct.h"

namespace sdds {
	std::istream& operator>>(std::istream& istr, iProduct& product) {
		product.read(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const iProduct& product) {
		product.display(ostr);
		return ostr;
	}
}