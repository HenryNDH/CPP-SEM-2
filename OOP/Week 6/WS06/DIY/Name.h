#ifndef SDDS_NAME_H
#define SDDS_NAME_H

namespace sdds {
	class Name {
		char* m_Fname;
		char* m_Mname;
		char* m_Lname;

	public:
		Name(const char* Fname, const char* Mname, const char* Lname);
		~Name();
	};
}
#endif