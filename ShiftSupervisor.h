#ifndef SHIFTSUPERVISOR_H
#define SHIFTSUPERVISOR_H

#include "Employee.h"
#include <string>
using namespace std;

class ShiftSupervisor : public Employee
{
private:
	double anSalary;
	double anProdBonus;

public:
	// Constructors
	ShiftSupervisor()
	{
		anSalary = 0.0;
		anProdBonus = 0.0;
	}

	ShiftSupervisor(double salary, double bonus)
	{
		anSalary = salary;
		anProdBonus = bonus;
	}

	// Destructor
	~ShiftSupervisor()
	{};

	// Mutator Functions
	void setSalary(double s)
	{ anSalary = s; }

	void setAnBonus(double b)
	{ anProdBonus = b; }

	// Accessor Functions
	double getSalary() const
	{ return anSalary; }

	double getBonus() const
	{ return anProdBonus; }
};

#endif