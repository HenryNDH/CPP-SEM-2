/* ------------------------------------------------------
Workshop 9 part 1
Module: N/A
Filename: Text.h
Version 1.1
Author: Duy Hoang Nguyen
Revision History
-----------------------------------------------------------
Date
31/03/202
-----------------------------------------------------------*/
#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

namespace sdds {
	class Text {
	private: // Attribute
		char* m_content = nullptr;

	protected:
		//Methods
		const char& operator[](int index)const;

	public:
		//Constructor
		Text();
		//Rule of three 
			//destructor
		virtual ~Text();
			//copy constructor
		Text(const Text&);
			//copy assignment operator
		Text& operator =(const Text&);

		void setEmpty();

		//read
		std::istream& read(std::istream& istr);
		//write
		std::ostream& write(std::ostream& ostr) const;
	};
	std::istream& operator >>(std::istream& istr, Text& text);
	std::ostream& operator <<(std::ostream& ostr, const Text& text);

	int getFileLength(std::istream& is);
}
#endif // !SDDS_TEXT_H
