#ifndef LOGGER_DECORATOR_PATTERN
#define LOGGER_DECORATOR_PATTERN

#include <iostream>
#include <string>
#include "Logger.h"

using namespace std;

enum formatType { NO_FORMAT = 1, HTML_FORMAT, ENC_FORMAT };

class LoggerDecorator : public Logger
{
	unsigned formatType;
	Logger * contents;
	void log(string msg);
	string encryptDecrypt(string toEncrypt);
public:
	LoggerDecorator(Logger * contents, unsigned formatType); //this will create any type of logger needed
	virtual string formatMessage(string msg); //this will log the message in any type of format needed
	
};

#endif // !LOGGER_DECORATOR_PATTERN
