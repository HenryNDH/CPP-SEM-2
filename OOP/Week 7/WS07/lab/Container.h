#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

#include <iostream>
using namespace std;
namespace sdds {
	class Container {
	private:
		char m_content[50];
		int m_capacity;
		int m_volume;
	public:
		//Construction
		Container(const char* desc, int cap);
		Container(const char* desc, int cap, int vol);
	
	protected:
		//Protected modifier and queries: 
		void setEmpty();
		int capacity();
		int volume();
	public:
		//Operations
		int operator+=(int number);
		int operator-=(int number);
		//bool type conversion
		operator bool();
		//clear
		void clear(int m_capacity, const char* m_content);
		//print
		std::ostream& print(std::ostream& ostr);
		//read
		std::istream& read(std::istream& istr);
	};
	//Insertions and extraction helper operator overloads
	std::ostream& operator <<(std::ostream& ostr, Container& c);
	std::istream& operator >>(std::istream& istr, Container& c);
}
#endif