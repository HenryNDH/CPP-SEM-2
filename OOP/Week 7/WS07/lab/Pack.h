#ifndef sdds_pack_h
#define sdds_pack_h

#include "Container.h"

using namespace std;
namespace sdds {
	class Pack : public Container {
	private:
		//attribute
		int m_unitsize;
	public:
		//construction
		Pack(const char* desc, int size, int unitsize = 330, int numberofunit = 0);

		//operations
		int operator+=(int number);
		int operator-=(int number);
		//queries
		int unit();
		int numUnits();
		int size();
		//clear
		void clear(int p_size, int u_size, const char* desc);
		//print
		std::ostream& print(std::ostream& ostr);
		//read
		std::istream& read(std::istream& istr);
	};
	//insertionsand extraction helper operator overloads
	std::ostream& operator <<(std::ostream& ostr, Pack& c);
	std::istream& operator >>(std::istream& istr, Pack& c);
}
#endif // !sdds_pack_h