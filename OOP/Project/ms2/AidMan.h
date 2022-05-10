#include <iostream>
#include "Menu.h"

using namespace std;
namespace sdds {

	class AidMan {
		//Attributes
		char* fileName;
		//Menu
		Menu mainMenu; // declare object
		unsigned int menu();

	public:
		
		//Construction
		AidMan();
		//Rule Of Three
		~AidMan();
		//the public method run()
		void run();
	};
}