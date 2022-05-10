//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <string>
//#include <occi.h>
//#include <iomanip>
//
//using oracle::occi::Environment;
//using oracle::occi::Connection;
//using namespace oracle::occi;
//
//void displayEmployee (Connection* conn, struct Employee emp);
//int findEmployee (Connection* conn, int employeeNumber, struct Employee* emp);
//int menu (void);
//void displayAllEmployees (Connection* conn);
//
//struct Employee
//{
//	int	 employeeNumber = 0;
//	char lastName [50] = { 0 };
//	char firstName [50] = { 0 };
//	char email [100] = { 0 };
//	char phone [50] = { 0 };
//	char extension [10] = { 0 };
//	char reportsTo [100] = { 0 };
//	char jobTitle [50] = { 0 };
//	char city [50] = { 0 };
//};
//
//struct Employee_Table
//{
//	int	 employeeNumber = 0;
//	char lastName [50] = { 0 };
//	char firstName [50] = { 0 };
//	char email [100] = { 0 };
//	char extension [10] = { 0 };
//	char officeCode [3];
//	int reportsTo = 0;
//	char jobTitle [50] = { 0 };
//};
//
//void addEmployee (Connection* conn)
//{
//	Employee_Table ems;
//
//	std::string stmtMSG;
//	stmtMSG.assign ("INSERT INTO employees(EMPLOYEENUMBER,LASTNAME,FIRSTNAME,EXTENSION,EMAIL,OFFICECODE,REPORTSTO,JOBTITLE) VALUES (");
//
//	std::cout << "Employee Number: ";
//	std::cin >> ems.employeeNumber;
//	while(std::cin.peek () != '\n') std::cin.ignore (20, '\n');
//	std::cin.ignore ();
//
//	std::cout << "Last Name: ";
//	std::cin.get (ems.lastName, 49, '\n');
//	while(std::cin.peek () != '\n') std::cin.ignore (20, '\n');
//	std::cin.ignore ();
//
//	std::cout << "First Name: ";
//	std::cin.get (ems.firstName, 49, '\n');
//	while(std::cin.peek () != '\n') std::cin.ignore (20, '\n');
//	std::cin.ignore ();
//
//	std::cout << "Extension: ";
//	std::cin.get (ems.extension, 9, '\n');
//	while(std::cin.peek () != '\n') std::cin.ignore (20, '\n');
//	std::cin.ignore ();
//
//	std::cout << "Email: ";
//	std::cin.get (ems.email, 99, '\n');
//	while(std::cin.peek () != '\n') std::cin.ignore (20, '\n');
//	std::cin.ignore ();
//
//	std::cout << "Office Code: ";
//	std::cin.get (ems.officeCode, 2, '\n');
//	while(std::cin.peek () != '\n') std::cin.ignore (20, '\n');
//	std::cin.ignore ();
//
//	std::cout << "Reports To: ";
//	std::cin >> ems.reportsTo;
//	while(std::cin.peek () != '\n') std::cin.ignore (20, '\n');
//	std::cin.ignore ();
//
//	std::cout << "Job Title: ";
//	std::cin.get (ems.jobTitle, 49, '\n');
//	while(std::cin.peek () != '\n') std::cin.ignore (20, '\n');
//	std::cin.ignore ();
//
//	stmtMSG.append (std::to_string (ems.employeeNumber));
//	stmtMSG.append (",");
//	stmtMSG.append (ems.lastName);
//	stmtMSG.append (",");
//	stmtMSG.append (ems.firstName);
//	stmtMSG.append (",");
//	stmtMSG.append (ems.extension);
//	stmtMSG.append (",");
//	stmtMSG.append (ems.email);
//	stmtMSG.append (",");
//	stmtMSG.append (ems.officeCode);
//	stmtMSG.append (",");
//	stmtMSG.append (std::to_string (ems.reportsTo));
//	stmtMSG.append (",");
//	stmtMSG.append (ems.jobTitle);
//
//	stmtMSG.append (");");
//
//	char* temp = new char [stmtMSG.length () + 1] { 0 };
//	strcpy (temp, stmtMSG.c_str ());
//
//	try
//	{
//		oracle::occi::Statement* stmt = conn->createStatement ();
//		oracle::occi::ResultSet* rs = stmt->executeQuery (temp);
//		conn->terminateStatement (stmt);
//	}
//	catch(SQLException& sqlExcp)
//	{
//		std::cout << sqlExcp.getErrorCode () << ": " << sqlExcp.getMessage ();
//	}
//
//	delete [] temp;
//}
//
//void displayAllEmployees (Connection* conn)
//{
//	std::string stmtMSG;
//	stmtMSG.assign ("SELECT * FROM employees");
//
//	oracle::occi::Statement* stmt = conn->createStatement ();
//	oracle::occi::ResultSet* rs = stmt->executeQuery (stmtMSG);
//
//	if(!rs->next ())
//	{
//		std::cout << "There is no employees’ information to be displayed.\n";
//	}
//	else
//	{
//		std::cout << std::left << std::setw (10) << "E" << std::setw (30) << "Employee Name" << std::setw (40) << "Email" << std::setw (18) << "Phone" << std::setw (8) << "Ext" << "Manager" << std::endl;
//		std::cout << std::right << std::setw (125) << std::setfill ('-') << " " << std::setfill (' ') << std::endl;
//
//		if(rs->getInt (1) > 0)
//		{
//			Employee manager;
//			int number = rs->getInt (7);
//			findEmployee (conn, number, &manager);
//
//			std::cout << std::left << std::setw (10) << rs->getString (1)
//				<< std::setw (30) << rs->getString (2) + rs->getString (3)
//				<< std::setw (40) << rs->getString (5);
//
//			{
//				std::string stmtMSG_s;
//				stmtMSG_s.assign ("SELECT officecode, phone FROM offices WHERE officecode = ");
//				stmtMSG_s.append (rs->getString (6));
//				oracle::occi::Statement* stmt_s = conn->createStatement ();
//				oracle::occi::ResultSet* rs_s = stmt_s->executeQuery (stmtMSG_s);
//
//				if(rs_s->next ())
//				{
//					std::cout << std::setw (18) << rs_s->getString (2).c_str ();
//				}
//
//				conn->terminateStatement (stmt_s);
//			}
//
//			std::cout << std::left << std::setw (8) << rs->getString (4)
//				<< (manager.firstName [0] == 0 ? "NULL" : manager.firstName) << " " << manager.lastName;
//			std::cout << std::endl;
//		}
//
//		while(rs->next ())
//		{
//			if(rs->getInt (1) > 0)
//			{
//				Employee manager;
//				int number = rs->getInt (7);
//				findEmployee (conn, number, &manager);
//
//				std::cout << std::left << std::setw (10) << rs->getString (1)
//					<< std::setw (30) << rs->getString (2) + rs->getString (3)
//					<< std::setw (40) << rs->getString (5);
//
//				{
//					std::string stmtMSG_s;
//					stmtMSG_s.assign ("SELECT officecode, phone FROM offices WHERE officecode = ");
//					stmtMSG_s.append (rs->getString (6));
//					oracle::occi::Statement* stmt_s = conn->createStatement ();
//					oracle::occi::ResultSet* rs_s = stmt_s->executeQuery (stmtMSG_s);
//
//					if(rs_s->next ())
//					{
//						std::cout << std::setw (18) << rs_s->getString (2).c_str ();
//					}
//
//					conn->terminateStatement (stmt_s);
//				}
//
//				std::cout << std::left << std::setw (8) << rs->getString (4)
//					<< (manager.firstName [0] == 0 ? "NULL" : manager.firstName) << " " << manager.lastName;
//				std::cout << std::endl;
//			}
//		}
//	}
//
//	conn->terminateStatement (stmt);
//}
//
//void displayEmployee (Connection* conn, struct Employee emp)
//{
//	int input = 0;
//	std::cout << "\nEmployee Number > ";
//	std::cin >> input;
//
//	if(findEmployee (conn, input, &emp))
//	{
//		std::cout << "\nemployeeNumber = " << emp.employeeNumber << std::endl;
//		std::cout << "lastName = " << emp.lastName << std::endl;
//		std::cout << "firstName = " << emp.firstName << std::endl;
//		std::cout << "email = " << emp.email << std::endl;
//		std::cout << "phone = " << emp.phone << std::endl;
//		std::cout << "extension = " << emp.extension << std::endl;
//		std::cout << "reportsTo = " << (emp.reportsTo [0] == 0 ? "NULL" : emp.reportsTo) << std::endl;
//		std::cout << "jobTitle = " << emp.jobTitle << std::endl;
//		std::cout << "city = " << emp.city << std::endl;
//	}
//	else
//	{
//		std::cout << "Employee " << input << " does not exist." << std::endl;
//	}
//}
//
//int findEmployee (Connection* conn, int employeeNumber, struct Employee* emp)
//{
//	int result = -1;
//
//	std::string stmtMSG;
//	stmtMSG.resize (80);
//	stmtMSG.assign ("SELECT * FROM employees WHERE employeeNumber = ");
//	if(employeeNumber > 0)
//	{
//		stmtMSG += std::to_string (employeeNumber);
//
//		oracle::occi::Statement* stmt = conn->createStatement ();
//		oracle::occi::ResultSet* rs = stmt->executeQuery (stmtMSG);
//
//		if(rs->next ())
//		{
//			emp->employeeNumber = rs->getInt (1);
//			strcpy (emp->lastName, rs->getString (2).c_str ());
//			strcpy (emp->firstName, rs->getString (3).c_str ());
//			strcpy (emp->email, rs->getString (5).c_str ());
//			{
//				std::string stmtMSG_s;
//				stmtMSG_s.assign ("SELECT officecode, phone FROM offices WHERE officecode = ");
//				stmtMSG_s.append (rs->getString (6));
//				oracle::occi::Statement* stmt_s = conn->createStatement ();
//				oracle::occi::ResultSet* rs_s = stmt_s->executeQuery (stmtMSG_s);
//
//				if(rs_s->next ())
//				{
//					strcpy (emp->phone, rs_s->getString (2).c_str ());
//				}
//
//				conn->terminateStatement (stmt_s);
//			}
//			strcpy (emp->extension, rs->getString (4).c_str ());
//
//			if(rs->getInt (7) > 0)
//			{
//				std::string stmtMSG_s;
//				stmtMSG_s.assign ("SELECT employeeNumber, firstname, lastname FROM employees WHERE employeeNumber = ");
//				stmtMSG_s.append (rs->getString (7));
//
//				oracle::occi::Statement* stmt_s = conn->createStatement ();
//				oracle::occi::ResultSet* rs_s = stmt_s->executeQuery (stmtMSG_s);
//
//				if(rs_s->next ())
//				{
//					std::string managerName;
//
//					managerName.assign (rs->getString (2));
//					managerName.append (rs->getString (3));
//
//					strcpy (emp->reportsTo, managerName.c_str ());
//				}
//				else
//				{
//					strcpy (emp->reportsTo, "NULL");
//				}
//
//				conn->terminateStatement (stmt_s);
//			}
//
//			strcpy (emp->jobTitle, rs->getString (8).c_str ());
//			{
//				std::string stmtMSG_s;
//				stmtMSG_s.assign ("SELECT officecode, city FROM offices WHERE officecode = ");
//				stmtMSG_s.append (rs->getString (6));
//				oracle::occi::Statement* stmt_s = conn->createStatement ();
//				oracle::occi::ResultSet* rs_s = stmt_s->executeQuery (stmtMSG_s);
//
//				if(rs_s->next ())
//				{
//					strcpy (emp->city, rs_s->getString (2).c_str ());
//				}
//
//				conn->terminateStatement (stmt_s);
//			}
//			result = 1;
//		}
//		else
//		{
//			result = 0;
//		}
//
//		conn->terminateStatement (stmt);
//	}
//	else
//	{
//		result = 0;
//	}
//
//	return result;
//}
//
//int menu (void)
//{
//	std::cout << "\n********************* HR Menu *********************\n";
//	std::cout << std::setw (35) << std::setfill ('-') << " " << std::endl << std::setfill (' ');
//	std::cout << "1 - Find Employee" << std::endl;
//	std::cout << "2 - Employee Report" << std::endl;
//	std::cout << "3 - Add Employee" << std::endl;
//	std::cout << "4 - Update Employee" << std::endl;
//	std::cout << "5 - Remove Employee" << std::endl;
//	std::cout << std::setw (35) << std::setfill ('-') << " " << std::endl << std::setfill (' ');
//	std::cout << "0 - EXIT" << std::endl;
//
//	int input = -1;
//	while(input < 0 || input > 5)
//	{
//		std::cout << "\n> ";
//		std::cin >> input;
//
//		if(input < 0 || input > 5)
//		{
//			std::cout << "Invalid Number! Please try again...\n";
//		}
//	}
//
//	return input;
//}
//
//int main (int argc, char* argv [])
//{
//	Environment* env = nullptr;
//	Connection* conn = nullptr;
//
//	std::string str;
//	std::string usr = "dbs211_221za24";
//	std::string pass = "30586885";
//	std::string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
//
//	try
//	{
//		env = Environment::createEnvironment (Environment::DEFAULT);
//		conn = env->createConnection (usr, pass, srv);
//		std::cout << "Connection is Successful!" << std::endl;
//	}
//	catch(SQLException& sqlExcp)
//	{
//		std::cout << sqlExcp.getErrorCode () << ": " << sqlExcp.getMessage ();
//	}
//
//	if(env != nullptr && conn != nullptr)
//	{
//		int option = 0;
//
//		while((option = menu ()) != 0)
//		{
//			switch(option)
//			{
//			case 1:
//				{
//					Employee emp_s;
//					int empNo = 0;
//					displayEmployee (conn, emp_s);
//
//					break;
//				}
//			case 2:
//				displayAllEmployees (conn);
//				break;
//
//			case 3:
//				addEmployee (conn);
//				break;
//
//			default:
//				std::cout << "Not Implemented!\n";
//				break;
//			}
//		}
//
//		std::cout << "Program Ended!" << std::endl;
//	}
//
//	if(env != nullptr && conn != nullptr) // Closing
//	{
//		env->terminateConnection (conn);
//		Environment::terminateEnvironment (env);
//	}
//
//	return 0;
//}