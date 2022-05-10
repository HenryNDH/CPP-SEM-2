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
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include "Status.h"
#include "iProduct.h"

namespace sdds {
	class Item : public iProduct
	{
	private:
		double m_price = 0;
		int m_qty = 0;
		int m_qtyNeeded = 0;
		bool m_isLinear = false;
		char* m_desc = nullptr;

	protected:
		Status m_state;
		int m_sku = 0;
		bool linear() const;

	public:
		//Construction
		Item();

		//Rule of three
		Item(const Item&);
		~Item();
		Item& operator =(const Item&);

		//virtual public query iProduct overrides 
		int qty()const;
		int qtyNeeded()const;
		operator double()const;
		operator bool()const;

		//virtual public modifier iProduct overrides
		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool isLinear);

		//public modifier
		void clear();
		//virtual operator== iProduct overrides
		bool operator==(int)const;
		bool operator==(const char*)const;

		//virtual Input/Output method iProduct overrides
		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		int readSku(std::istream&);

	};
	int inputInt(std::istream& istr, int min, int max);
	double inputDouble(std::istream& istr, double min, double max);
}
#endif // !SDDS_ITEM_H