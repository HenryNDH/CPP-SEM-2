#define _CRT_SECURE_NO_WARNINGS
#include"Phone.h"
#include"cStrTools.h"
using namespace std;
namespace sdds {
	void phoneDir(const char* programTitle, const char* fileName) {
		

	}
	void searchResult(struct Phone dir) {
		cout << dir.name << ":" << " (" << dir.area << ")" << " " << dir.prefix << "-" << dir.number << endl;
	}
}