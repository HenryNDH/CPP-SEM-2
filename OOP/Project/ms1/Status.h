#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
using namespace std;
namespace sdds {
	class Status {
	//Status Class
	private:
		char* m_desc;
		int m_code;
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