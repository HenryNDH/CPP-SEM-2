#pragma once
#ifndef SDDS_DNA_H
#define SDDS_DNA_H
namespace sdds
{
	struct DNA
	{
		int id;
		char* strand = nullptr;
	};
	bool beginSearch(const char* filename);
	bool read(const char* subDNA);
	void sort();
	void displayMatches();
	void deallocate();
	void endSearch();
}
#endif