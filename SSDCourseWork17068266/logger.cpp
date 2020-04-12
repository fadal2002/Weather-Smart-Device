#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <ctime> 
#include "Logger.h"

using namespace std;

string Logger::getTimeDate(void)
{
	//this will get the time and data at any specified moment
	string timeDate;
	time_t * rawtime = new time_t;
	struct tm * timeinfo;
	time(rawtime);
	timeinfo = localtime(rawtime);
	timeDate = asctime(timeinfo);
	return timeDate;
}
