#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cStrTools.h"
#include "DNA.h"
#define MAXIMUM_SPACE 12346

using namespace std;
namespace sdds
{
	DNA dnaTemp[MAXIMUM_SPACE] = {};
	DNA* searchTemp = nullptr;
	int size = 2;
	int searchSize = 0;
	int i = 0;
	bool beginSearch(const char* filename)
	{
		FILE* fp = fopen(filename, "r");
		int scan = 1;
		bool fpCheck;
		if (fp == NULL)
		{
			cout << filename << " file not found!\n";
			fpCheck = false;
		}
		else
		{
			while (scan >= 1)
			{
				char strandTemp[1000] = { 0 };
				scan = fscanf(fp, "%d,%[^\n]", &dnaTemp[i].id, strandTemp);
				dnaTemp[i].strand = new char[strLen(strandTemp) + 1];
				strCpy(dnaTemp[i].strand, strandTemp);
				i++;
			}
			fclose(fp);
			cout << "DNA search program" << endl;
			fpCheck = true;
		}
		return fpCheck;
	}
	bool read(const char* subDNA)
	{
		bool match = false;
		searchTemp = new DNA[size];
		for (int j = 0; j < MAXIMUM_SPACE; j++)
		{
			char tmp_name[1000] = {};
			char tmp_finding[101] = {};
			toLowerCaseAndCopy(tmp_name, dnaTemp[j].strand);
			toLowerCaseAndCopy(tmp_finding, subDNA);
			if (strStr(tmp_name, tmp_finding) != NULL)
			{
				if (searchSize == size)
				{
					DNA* tmp_dna = nullptr;
					int newSize = size + searchSize;
					tmp_dna = new DNA[newSize];
					for (int p = 0; p < size; p++)
					{
						tmp_dna[p].id = searchTemp[p].id;
						tmp_dna[p].strand = searchTemp[p].strand;
					}
					delete[] searchTemp;
					searchTemp = nullptr;
					searchTemp = tmp_dna;
					size = newSize;
				}
				searchTemp[searchSize].id = dnaTemp[j].id;
				searchTemp[searchSize].strand = dnaTemp[j].strand;
				searchSize++;
				match = true;
			}
		}
		return match;
	}
	void sort() 
	{
		for (int l = 0; l < searchSize - 1; l++)
		{
			DNA sortTemp;
			for (int j = 0; j < searchSize - l - 1; j++)
			{
				if (searchTemp[j].id > searchTemp[j + 1].id)
				{
					sortTemp = searchTemp[j];
					searchTemp[j] = searchTemp[j + 1];
					searchTemp[j + 1] = sortTemp;
				}
			}
		}
	}
	void displayMatches()
	{
		cout << searchSize << " matches found:" << endl;
		for (int y = 0; y < searchSize; y++)
		{
			cout << y + 1 << ") " << searchTemp[y].id << ":" << endl;
			cout << searchTemp[y].strand << endl;
			cout << "======================================================================" << endl;
		}
	}
	void deallocate() {
		delete[] searchTemp;
		searchTemp = nullptr;
	}
	void endSearch()
	{
		cout << "DNA Search Program Closed." << endl;
		for (int l = 0; l < i; l++)
		{
			delete[] dnaTemp[l].strand;
			dnaTemp[l].strand = nullptr;
		}
		deallocate();
	}
}