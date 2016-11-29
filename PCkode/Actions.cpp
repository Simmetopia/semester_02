#include "Actions.h"


Actions::Actions(int& hour, int& minut)
{
	if(hour > 0 && hour < 24 && minut > 0 && minut < 60)
	hour_ = hour;
	minute_ = minut;
}

Actions::Actions()
{
}


Actions::~Actions()
{
}

void Actions::setTime(int& hour, int& minut)
{
	if (hour > 0 && hour < 24 && minut > 0 && minut < 60)
		hour_ = hour;
	minute_ = minut;
}
