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
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
using namespace std;
namespace sdds {
	class Status {
		//Status Class
	private:
		char* m_desc = nullptr;
		int m_code = 0;
	public:
		void setCodeDes(const char*, const int);
		//Construction
		Status();
		Status(const char* desc, const int code);
		//Rule of three
		Status(const Status& copy);
		Status& operator=(const Status& copy);
		~Status();
		//Assignment operator overloads
		operator int() const;
		operator const char* () const;
		operator bool() const;
		//Type Conversion Overloads
		void operator=(const char*);
		void operator=(const int);
		//The clear() method
		Status& clear();
	};
	std::ostream& operator<<(std::ostream& ostr, const Status& status);
}
#endif