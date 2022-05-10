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
	bool Train::changeSpeed(double speedChange)
	{
		double newSpeed = 0;
		newSpeed = getSpeed() + speedChange;
		if (newSpeed >= 0 && newSpeed <= MAX_SPEED)
		{
			speed = newSpeed;
		}
		else if (newSpeed > MAX_SPEED)
		{
			speed = MAX_SPEED;
		}
		else
		{
			speed = 0;
		}
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(2);
		return speed;
	}
	bool Train::loadPeople(int peopleChange)
	{
		int newPeople = 0;
		newPeople = getNumberOfPeople() + peopleChange;
		if (newPeople >= 0 && newPeople <= MAX_PEOPLE)
		{
			pNum = newPeople;
		}
		else if (newPeople > MAX_PEOPLE)
		{
			pNum = MAX_PEOPLE;
		}
		else
		{
			pNum = 0;
		}
		return pNum;
	}
	int transfer(Train& first, Train& second)
	{
		int count = 0;
		int numMove = 0;
		int flag = 0;
		
		count = first.getNumberOfPeople() + second.getNumberOfPeople();
		if (count > MAX_PEOPLE)
		{
			numMove = MAX_PEOPLE - first.getNumberOfPeople();
			first.loadPeople(numMove);
			second.loadPeople(-numMove);
		}
		else
		{
			numMove = second.getNumberOfPeople();
			first.loadPeople(numMove);
			second.loadPeople(-numMove);
		}
		
		if (first.isSafeEmpty() || second.isSafeEmpty())
		{
			flag = -1;
		}
		else
		{
			flag = 0;
		}
		return flag;
	}
}