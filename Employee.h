#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{

private:
	// Variables for class
	string empName;
	int empNumber;
	string hireDate;
public:
	// Exception class
	class InvalidEmployeeNumber
	{};					// Empty class decaration

	// Constructors
	Employee()
	{
		empName = "";
		empNumber = 0;
		hireDate = "";
	}

	Employee(string name, int number, string date)
	{
		empName = name;
		empNumber = number;
		hireDate = date;
	}

	// Destructor
	~Employee()
	{};

	// Mutator functions
	void setName(string n)
		{ empName = n; }
	
	// Mutator defined in Employee.cpp /////
	void setNumber(int);               /////
	///////////////////////////////////////

	void setDate(string hire)
		{ hireDate = hire; }

	// Accessor functions
	string getName() const
		{ return empName; }
	
	int getNumber() const
		{ return empNumber; }

	string getDate() const
		{ return hireDate; }

};

#endif