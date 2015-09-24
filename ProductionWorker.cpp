#include "ProductionWorker.h"

void ProductionWorker::setShift(int s)
{
	if (s == 1 || s == 2)
		workShift = s;
	else
		throw InvalidShift();
}

void ProductionWorker::setPayRate(double p)
{
	if (p >= 0)
		payRate = p;
	else
		throw InvalidPayRate();
}