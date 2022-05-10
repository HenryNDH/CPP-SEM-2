#include "Rectangle.h"
namespace sdds {
	Rectangle::Rectangle() {
		m_width = m_height = 0;
	}
	Rectangle::Rectangle(const char* label, int width, int height) :LblShape(label) {
		if (width > (int)strlen(LblShape::label()) + 2 && height > 3) {
			m_width = width;
			m_height = height;
		}
	}
	void Rectangle::getSpecs(std::istream& istr) {
		int width, height;
		char delimiter;
		LblShape::getSpecs(istr);
		istr >> width >> delimiter >> height;
		if (!istr.fail()) {
			istr.ignore(1000, '\n');
			m_width = width;
			m_height = height;
		}
	}
	/*
	 +----------------------------+
	 |Container                   |
	 |                            |
	 |                            |
	 +----------------------------+
	 */
	void Rectangle::draw(std::ostream& ostr) const {
		if (m_width > 0 && m_height > 0) {
			//first line: '-' character (m_width - 2) > + > newline
			ostr << '+';
			ostr.width(m_width - 2);
			ostr.fill('-');
			ostr << '-' << '+' << std::endl;
			//second line: (m_width-2) spaces > label() left > '|' > newline
			ostr << '|';
			ostr.width(m_width - 2);
			ostr.fill(' ');
			ostr << std::left << label() << '|' << std::endl;
			//Next line(s): '|' > (m_width-2) spaces > '|' > newline
			for (int i = 0; i < (int)(m_height)-3; i++) {
				ostr << '|';
				ostr.width(m_width - 2);
				ostr.fill(' ');
				ostr << ' ' << '|' << std::endl;
			}
			//Last line: same as first
			ostr << '+';
			ostr.width(m_width - 2);
			ostr.fill('-');
			ostr << '-' << '+';
		}
	}
}