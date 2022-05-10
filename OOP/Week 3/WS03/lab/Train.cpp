#include <iostream>
#include "Train.h"

namespace sdds
{
	void Train::set(const char* name, int people, double speed_)
	{
		bool valid = true;
		if (name != nullptr)
		{
			int len;
			for (len = 0; name[len]; len++);
			if (len > 0)
			{
				int i;
				for (i = 0; name[i]; i++) trainName[i] = name[i];
				trainName[i] = 0;
			}
			else
			{
				valid = false;
			}

			if (0 < people && people <= MAX_PEOPLE)
			{
				pNum = people;
			}
			else
			{
				valid = false;
			}

			if (0 < speed_ && speed_ <= MAX_SPEED)
			{
				speed = speed_;
			}
			else
			{
				valid = false;
			}
		}
		else
		{
			valid = false;
		}
		if (valid == false)
		{
			trainName[0] = { '\0' };
			pNum = 0;
			speed = 0; 
		}
	}
	const char* Train::getName() const
	{
		return trainName;
	}
	int Train::getNumberOfPeople() const
	{
		return pNum;
	}
	double  Train::getSpeed() const
	{
		return speed;
	}
	bool  Train::isSafeEmpty() const
	{
		bool safeState = false;
		if (pNum == 0 || speed == 0 || trainName[0] == '\0')
		{
			safeState = true;
		}
		return safeState;
	}
	void  Train::display() const
	{
		if (pNum != 0 || speed != 0 || trainName[0] != '\0')
		{
			cout << "NAME OF THE TRAIN : " << trainName << endl;
			cout << "NUMBER OF PEOPLE  : " << pNum << endl;
			cout << "SPEED             : " << speed << " km/h" << endl;
		}
		else
		{
			cout << "Safe Empty State!" << endl;
		}
	}
}