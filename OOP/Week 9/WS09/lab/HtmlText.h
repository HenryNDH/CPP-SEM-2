/* ------------------------------------------------------
Workshop 9 part 1
Module: N/A
Filename: HtmlText.h
Version 1.1
Author: Duy Hoang Nguyen
Revision History
-----------------------------------------------------------
Date
31/03/202
-----------------------------------------------------------*/
#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H

#include "Text.h"

namespace sdds {
	class HtmlText : public Text
	{
	private:
		char* m_title = nullptr;

	public:
		//Constructor
		HtmlText();
		HtmlText(const char* htmlText);

		//Rule of three
		HtmlText(const HtmlText& htmlText);
		~HtmlText() override;
		HtmlText& operator =(const HtmlText&);

		//write override
		std::ostream& write(std::ostream&) const;
	};
	std::istream& operator >>(std::istream&, HtmlText&);
	std::ostream& operator <<(std::ostream&, const HtmlText&);
}

#endif