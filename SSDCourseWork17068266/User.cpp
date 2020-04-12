#include "User.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

float User::RandomTemperature()
{
	float min = -30.00f;
	float max = 40.00f;
	srand((unsigned)time(NULL));
	float temperature = (max - min) * ((((float)rand()) / (float)RAND_MAX)) + min;
	return temperature;
}

float User::RandomHumidity()
{
	float min = 0.0f;
	float max = 100.0f;
	srand((unsigned)time(NULL));
	float humidity = (max - min) * ((((float)rand()) / (float)RAND_MAX)) + min;
	return humidity;
}

float User::RandomAirPressure()
{
	float min = 500.00f;
	float max = 2500.00f;
	srand((unsigned)time(NULL));
	float airPressure = (max - min) * ((((float)rand()) / (float)RAND_MAX)) + min;
	return airPressure;
}



