#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <ctime>
#include "AccountLogger.h"
using namespace std;

void AccountLogger::log(string msg)
{
	//this will log a message to a log text file everytime an admin account has been created
	ofstream outFile("AccountsLog.txt", fstream::app);
	if (outFile) // checking if the file already exists
	{
		outFile << msg;
		outFile.close();
	}
	else // if file doesnt exist create a new file
	{
		ofstream outFile;
		outFile.open("AccountsLog.txt", fstream::app);


		outFile << msg;
		outFile.close();
	}
	
}
