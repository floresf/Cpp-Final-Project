#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.h"
#include <string>
using namespace std;

class ProductionWorker : public Employee
{

private:
	int workShift;
	double payRate;

public:
	// Exception classes
	class InvalidShift
	{};

	class InvalidPayRate
	{};

	// Constructors
	ProductionWorker()
	{
		workShift = 0;
		payRate = 0.0;
	}

	ProductionWorker(int s, double r)
	{
		workShift = s;
		payRate = r;
	}

	// Destructor
	~ProductionWorker()
	{};

	// Mutator Functions defined in ProductionWorker.cpp //////
	void setShift(int);                                 ///////
	                                                    ///////
	void setPayRate(double);                            ///////
	///////////////////////////////////////////////////////////

	// Accessor Functions
	int getShift() const
		{ return workShift; }

	double getPayRate() const
		{ return payRate; }

};

#endif