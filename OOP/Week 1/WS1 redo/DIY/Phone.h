#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H
#include <iostream>
#include <iomanip>
namespace sdds {
	const int MAX_NAME_LEN = 50;
	const int MAX_CONTACT = 50;
	struct Phone {
		char name[MAX_NAME_LEN];
		int area[4];
		int prefix[4];
		int number[5];
	};
	void phoneDir(const char* programTitle, const char* fileName);
	void searchResult(struct Phone dir);
}
#endif 