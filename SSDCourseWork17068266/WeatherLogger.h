#ifndef TXTFILELOGGER_H
#define TXTFILElOGGER_H
#include "Logger.h"

class WeatherLogger : public Logger
{
public:
	void log(string msg);
};

#endif // !TXTFILELOGGER_H
