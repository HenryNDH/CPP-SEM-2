#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

using namespace std;
namespace sdds {
	class Menu {
		//Create a class called Menu. This class has two attributes.
	private:
		unsigned int m_numOpt = 0;
		char* m_list = nullptr;
		void setEmpty();

	public:
		//Construction
		Menu();
		Menu(unsigned int numOpt, const char* list);

		//Rule of three
		Menu(const Menu&) = delete;
		void operator=(const Menu&) = delete;
		~Menu();

		//Methods
		unsigned int run() const;
	};
}
#endif // !SDDS_MENU_H