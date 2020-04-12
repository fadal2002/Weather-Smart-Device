#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

using namespace std;
#include "Logger.h"

class AccountLogger : public Logger
{
public:
	void log(string msg); // a function to log a message everytime an account has been created
};

#endif // !CONSOLELOGGER_H
