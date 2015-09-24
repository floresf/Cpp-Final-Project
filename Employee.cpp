#include "Employee.h"


void Employee::setNumber(int numE)
{
	if (numE < 0 || numE > 9999)
		throw InvalidEmployeeNumber();
	else
		empNumber = numE;
}