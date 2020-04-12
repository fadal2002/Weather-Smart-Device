#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <ctime>
#include "WeatherLogger.h"
#include "weatherData.h"

using namespace std;

void WeatherLogger::log(string msg)
{
	ofstream outFile("WeatherLog.txt", fstream::app);
	if (outFile)
	{
		outFile << msg;
		outFile.close();
	}
	else
	{
		ofstream outFile;
		outFile.open("WeatherLog.txt", fstream::app);


		outFile << msg;
		outFile.close();
	}
}