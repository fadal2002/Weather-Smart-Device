#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>

using namespace std;

enum LoggerType { L_TEXT_FILE = 1, L_CONSOLE, L_BINARY_FILE };

class Logger
{
public:
	virtual void log(string msg) = 0;
	string getTimeDate(void);
};

#endif // !LOGGER_H
