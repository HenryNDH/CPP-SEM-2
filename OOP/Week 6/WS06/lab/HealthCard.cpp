#define  _CRT_SECURE_NO_WARNINGS
#include "HealthCard.h"
namespace sdds {
	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
		return(name != nullptr && name[0] != '\0' && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9);
	}
	void HealthCard::setEmpty()
	{
		delete[] this->m_name;
		this->m_name = nullptr;
	}
	void HealthCard::allocateAndCopy(const char* name) 
	{
		setEmpty();
		this->m_name = new char[strlen(name) + 1]{};
		strcpy(this->m_name, name);
	}
	void HealthCard::extractChar(std::istream& istr, char ch) const 
	{
		char next;
		next = istr.peek();
		if (next != ch) {
			istr.setstate(std::ios::failbit);
		}
		else
		{
			istr.get();
		}
	}
	std::ostream& HealthCard::printIDInfo(std::ostream& ostr)const 
	{
		ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
		return ostr;
	}
	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
	{
		if (validID(name, number, vCode, sNumber))
		{
			allocateAndCopy(name);
			this->m_number = number;
			strcpy(this->m_vCode, vCode);
			strcpy(this->m_sNumber, sNumber);
		}
		else
		{
			setEmpty();
		}
	}
	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
	{
		set(name, number, vCode, sNumber);
	}
	HealthCard::HealthCard(const HealthCard& hc)
	{
		if (hc)
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		else
			setEmpty();
	}
	HealthCard& HealthCard::operator=(const HealthCard& hc)
	{
		if (this != &hc) //check for self copy
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		return *this;
	}
	HealthCard::~HealthCard()
	{
		if (m_name != NULL)
		{
			delete[] this->m_name;
			this->m_name = nullptr;
		}
	}
	HealthCard::operator bool() const
	{
		return (this->m_name != nullptr);
	}
	std::ostream& HealthCard::print(std::ostream& ostr, bool toFile) const 
	{
		if (*this) {
			if (toFile) {
				ostr << this->m_name << ",";
				printIDInfo(ostr);
				ostr << endl << flush;
			}
			else {
				ostr.width(50);
				ostr.fill('.');
				ostr.setf(std::ios::left);
				ostr << this->m_name;
				printIDInfo(ostr);
			}
		} return ostr;
	}
	std::istream& HealthCard::read(std::istream& istr) 
	{
		char name[MaxNameLength];
		long long number;
		char vcode[3];
		char snumber[10];
		istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> number;
		extractChar(istr, '-');
		istr.get(vcode, 3, ',');
		extractChar(istr, ',');
		istr.get(snumber, 10, '\n');
		if (!istr.fail()) {
			set(name, number, vcode, snumber);
		}
		istr.clear();
		istr.ignore(1000, '\n');
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc) 
	{
		if (hc)
			hc.print(ostr, false);
		else
			ostr << "Invalid Health Card Record";
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, HealthCard& hc) 
	{
		return hc.read(istr);
	}
}
