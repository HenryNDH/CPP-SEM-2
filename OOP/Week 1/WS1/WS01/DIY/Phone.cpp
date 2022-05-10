#define _CRT_SECURE_NO_WARNINGS
#include "Phone.h"
#include "cStrTools.h"
#include <iostream>
using namespace std;
namespace sdds {

	void phoneDir(const char* programTitle, const char* fileName) {
		//open file
		FILE* fp = fopen(fileName, "r");

		//declare struct
		struct Phone dir[50] = {0};
		int i = 0;
		int data = 0;
		bool existSignal = true;
		char search[MAXIMUM_CONTACT] = { 0 };

		//Header
		cout << programTitle << " phone direcotry search" << endl;
		cout<< "-------------------------------------------------------" << endl;

		//check if there is a file or not
		if (fp == NULL)
		{
			cout << fileName << " file not found!\n"; //if not find a file
		}
		else
		{
			while (data != EOF) //EOF = end of file scan -> end file
			{
				data = fscanf(fp, "%[^\t]\t%s\t%s\t%s\n", dir[i].name, dir[i].area, dir[i].prefix, dir[i].number);
				i++;
			}

			//loop until have a exit signal
			do
			{
				int j = 0;
				cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
				cout << "> ";
				cin >> search;
				if (search[0] != '!')
				{
					do
					{
						char nameBuffer[MAXIMUM_CONTACT] = {};
						char searchBuffer[MAXIMUM_CONTACT] = {};
						toLowerCaseAndCopy(searchBuffer, search);
						toLowerCaseAndCopy(nameBuffer, dir[j].name);
						if (strStr(searchBuffer, nameBuffer) != NULL)
						{
							searchResult(dir[j]);
						}
						j++;
					} while (j < MAXIMUM_CONTACT);
				}
				else if (search[0] == '!')
				{
					existSignal = false; // exit signal
				}
			} while (existSignal);
			fclose(fp);
		}
		cout << "Thank you for using " << programTitle << " directory." << endl;
	}
	void searchResult(struct Phone dir)
	{
		cout << dir.name << ":" << " (" << dir.area << ")" << " " << dir.prefix << "-" << dir.number << endl;
	}
}