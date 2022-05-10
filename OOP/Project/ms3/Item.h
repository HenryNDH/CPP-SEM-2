#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include "Status.h"
#include "iProduct.h"

namespace sdds {
	class Item : public iProduct
	{
	private:
		double m_price;
		int m_qty;
		int m_qtyNeeded;
		bool m_isLinear;
		char* m_desc;

	protected:
		Status m_state;
		int m_sku;
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
		int readSku(std::istream& istr);
	
	};
	int inputInt(std::istream& istr, int min, int max);
	double inputDouble(std::istream& istr, double min, double max);
}
#endif // !SDDS_ITEM_H