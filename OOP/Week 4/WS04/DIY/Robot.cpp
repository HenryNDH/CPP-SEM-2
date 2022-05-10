#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>

#include "Robot.h"
using namespace std;
namespace sdds {
	int conrtolRooomReport(const Robot robot[], int num_robots)
	{
		int value = -1;
		int index = 0;
		cout << "                        ------ Robot Control Room -----" << endl;
		cout << "                    ---------------------------------------" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
		for (int i = 0; i < num_robots; i++)
		{
			if (robot[i].isValid() != false)
			{
				robot[i].display();
			}
			else
			{
				value = i;
				i = num_robots;
			}
		}
		if (value == -1)
		{
			int counter = 0;
			for (int i = 0; i < num_robots; i++)
			{
				if (robot[i].isDeployed() != false)
				{
					counter++;
				}
			}
			for (int i = 0; i < num_robots; i++)
			{
				for (int j = i + 1; j < num_robots; j++)
				{
					if (robot[i].speed() > robot[j].speed())
					{
						index = i;
					}
				}
			}
			cout << "|=============================================================================|" << endl;
			cout << "| SUMMARY:                                                                    |" << endl;
			cout << "| " << counter << " robots are deployed.                                                      |" << endl;
			cout << "| The fastest robot is:                                                       |" << endl;
			cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
			cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
			robot[index].display();
			cout << "|=============================================================================|" << endl;
		}
		return value;
	}
	bool Robot::isDeployed() const
	{
		return m_deployed;
	}
	void Robot::setLocation(const char* location)
	{
		if (m_location != NULL)
		{
			delete[]  m_location;
			m_location = nullptr;
		}
		if (location != NULL)
		{
			strCpy(m_location, location);
		}
	}
	void Robot::setDeployed(bool deployed)
	{
		m_deployed = deployed;
	}
	const char* Robot::getName() const
	{
		return m_name;
	}
	const char* Robot::getLocation() const
	{
		return m_location;
	}
	const double Robot::speed() const
	{
		return m_speed;
	}
	Robot::Robot()
	{
		resetInfo();
	}
	Robot::Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed)
	{
		set(name, location, weight, width, height, speed, deployed);
	}

	Robot::~Robot()
	{
		if (m_name != NULL)
		{
			delete[] m_name;
			m_name = nullptr;
		}

		if (m_location != NULL)
		{
			delete[]  m_location;
			m_location = nullptr;
		}
	}

	void Robot::resetInfo()
	{
		m_name = NULL;
		m_location = NULL;
		m_weight = 0;
		m_width = 0;
		m_height = 0;
		m_speed = 0;
		m_deployed = false;
	}

	Robot& Robot::set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed)
	{
		if (name != NULL)
		{
			if (m_name != NULL)
			{
				delete[] m_name;
				m_name = nullptr;
			}

			m_name = new char[strLen(name) + 1];
			strCpy(m_name, name);
		}

		if (location != NULL)
		{
			if (m_location != NULL)
			{
				delete[] m_location;
				m_location = nullptr;
			}

			m_location = new char[strLen(location) + 1];
			strCpy(m_location, location);
		}

		m_weight = weight;
		m_width = width;
		m_height = height;
		m_speed = speed;
		m_deployed = deployed;
		return *this;
	}

	bool Robot::isValid() const
	{
		bool valid = false;
		if (m_name != nullptr && m_location != nullptr && m_weight > 0 && m_width > 0 && m_height > 0 && m_speed > 0)
			valid = true;
		return valid;
	}
	

	void Robot::display() const
	{
		cout << "| " << m_name << setw(13 - strLen(m_name)) << "| ";
		cout << m_location << setw(18 - strLen(m_location)) << "| ";
		cout << setprecision(1) << fixed << setw(6) << m_weight << " | ";
		cout << setprecision(1) << fixed << "   " << m_width << setw(3) << "| ";
		cout << setprecision(1) << setw(6) << fixed << m_height << " |";
		cout << setprecision(1) << setw(7) << fixed << m_speed << " |";
		if (m_deployed == true)
		{
			cout << " YES" << setw(7) << "|" << endl;
		}
		else
		{
			cout << " NO" << setw(8) << "|" << endl;
		}
	}
	

	//CStrTools
	int strCmp(const char* s1, const char* s2)
	{
		int i;
		for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
		return s1[i] - s2[i];
	}

	void strCpy(char* des, const char* src)
	{
		int i;
		for (i = 0; src[i]; i++) des[i] = src[i];
		des[i] = 0;
	}

	int strLen(const char* str)
	{
		int len;
		for (len = 0; str[len]; len++);
		return len;
	}
}