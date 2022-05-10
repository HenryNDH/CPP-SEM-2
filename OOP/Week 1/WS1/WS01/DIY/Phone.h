#pragma once
#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H
#include <iostream>
#include <iomanip>
namespace sdds {
	const int MAX_NAME_LEN = 50;
	const int MAXIMUM_CONTACT = 50;
	struct Phone {
		char name[MAX_NAME_LEN];
		char area[4];
		char prefix[4];
		char number[5];
	};
	void phoneDir(const char* programTitle, const char* fileName);
	void searchResult(struct Phone dir);
}
#endif