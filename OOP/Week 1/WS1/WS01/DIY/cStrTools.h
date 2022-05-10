#pragma once
#ifndef SDDS_CSTRTOOLS_H
#define SDDS_CSTRTOOLS_H
namespace sdds {
	void toLowerCaseAndCopy(char des[], const char source[]);
	char toLower(char ch);
	int strLen(const char* str);
	int strnCmp(const char* s1, const char* s2, int len);
	const char* strStr(const char* str, const char* find);
}
#endif