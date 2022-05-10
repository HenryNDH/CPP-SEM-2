#pragma once
#ifndef  SDDS_TRAIN_H
#define SDDS_TRAIN_H
#define MAX_NAME_LEN  20
#define MAX_PEOPLE  1000
#define MAX_SPEED  320
using namespace std;
namespace sdds
{
	class Train
	{
		char trainName [MAX_NAME_LEN+1];
		int pNum;
		double speed;
	public:
		void set(const char* name, int people, double speed_);
		void display() const;
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
	};
}
#endif //  SDDS_TRAIN_H

