#ifndef SDDS_CARINVENTORY_H
#define SDDS_CARINVENTORY_H

using namespace std;
namespace sdds
{
	class CarInventory
	{
	public:
		CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
		~CarInventory();
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;

	private:
		char* m_type = NULL;
		char* m_brand = NULL;
		char* m_model = NULL;
		int m_year = 0;
		int m_code = 0;
		double m_price = 0;
		void resetInfo();
	};
	bool find_similar(CarInventory car[], const int num_cars);
	int strLen(const char* str);
	int strCmp(const char* s1, const char* s2);
	void strCpy(char* des, const char* src);
}
#endif