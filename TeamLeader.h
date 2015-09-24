#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "ProductionWorker.h"
#include <string>
using namespace std;

class TeamLeader : public ProductionWorker
{
private:
	double monthlyBonus;
	int reqTrainHours;
	int attTrainHours;

public:
	// Exception Class
	class InvalidHours
	{};

	// Constructors
	TeamLeader()
	{
		monthlyBonus = 0.0;
		reqTrainHours = 0;
		attTrainHours = 0;
	}

	TeamLeader(double bonus, int req, int att)
	{
		monthlyBonus = bonus;
		reqTrainHours = req;
		attTrainHours = att;
	}

	// Destructor
	~TeamLeader()
	{};

	// Mutator Functions
	void setMonthlyBonus(double m)
	{ monthlyBonus = m; }

	void setReqHours(int r)
	{ reqTrainHours = r; }

	/////////////////////
	//////////////////////////Set in TeamLead.cpp ////
	void setAttHours(int);
	
	/////////////////////////////////////////////////
	///////////////////

	// Accessor Functions
	double getMonthlyBonus() const
	{ return monthlyBonus; }

	int getReqHours() const
	{ return reqTrainHours; }

	int getAttHours() const
	{ return attTrainHours; }

};

#endif