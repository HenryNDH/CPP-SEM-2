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
