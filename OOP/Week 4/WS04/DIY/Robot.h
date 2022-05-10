#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H

namespace sdds
{
	class Robot
	{
	public:
		Robot();
		Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed);
		~Robot();
		Robot& set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed);
		void display() const;
		bool isValid() const;
		bool isDeployed() const;
		void setLocation(const char* location);
		void setDeployed(bool deployed);
		const char* getName() const;
		const char* getLocation() const;
		const double speed() const;
	private:
		char* m_name = NULL;
		char* m_location = NULL;
		double m_weight = 0;
		double m_width = 0;
		double m_height = 0;
		double m_speed = 0;
		bool   m_deployed = 0;
		void resetInfo();
	};
	int conrtolRooomReport(const Robot robot[], int num_robots);
	int strCmp(const char* s1, const char* s2);
	void strCpy(char* des, const char* src);
	int strLen(const char* str);
}
#endif // !SDDS_ROBOT_H