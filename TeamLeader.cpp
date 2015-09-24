#include "TeamLeader.h"

void TeamLeader::setAttHours(int h)
{
	if (h < 0 || h > 200)
		throw InvalidHours();
	else
		attTrainHours = h;
}