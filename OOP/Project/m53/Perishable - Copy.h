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
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H

#include "Item.h"
#include "Date.h"

namespace sdds {
	class Perishable : public Item {

	private:
		Date m_expiry;
		char* m_Instr = nullptr;

	public:
		//Constructor
		Perishable();

		//Rule of 3
		Perishable(const Perishable&);
		Perishable& operator =(const Perishable&);
		~Perishable();

		//Query
		const Date& expiry() const;

		int readSku(std::istream& istr) override;

		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);

		operator bool() const;


	};


}
#endif // !SDDS_PERISHABLE.H
