#include "LoggerDecorator.h"
#include "WeatherLogger.h"
#include "AccountLogger.h"
#include "Logger.h"
#include <iostream>
#include <fstream>

using namespace std;

LoggerDecorator::LoggerDecorator(Logger * acontents, unsigned aformatType)
	: contents(acontents), formatType(aformatType) //the constructor will create any type of logger needed
{

}

void LoggerDecorator::log(string msg)
{
	//this will log a message with any format needed
	msg = formatMessage(msg);
	contents->log(msg);
}

string LoggerDecorator::encryptDecrypt(string toEncrypt)
{
	//a function that will encrypt and decrypt a string
	char key = 'A';
	string output = toEncrypt;
	for (int i = 0; i < toEncrypt.size(); i++)
	{
		output[i] = toEncrypt[i] + key;
	}
	return output;
}

string LoggerDecorator::formatMessage(string msg)
{
	//this function will change any string to the specified format
	switch (formatType)
	{
	case NO_FORMAT:
		return msg;
		break;
	case HTML_FORMAT:
	{
		return "<HTML><BODY> <b>" + msg + "</b> </BODY></HTML>";
	}
	break;
	case ENC_FORMAT:
	{
		return encryptDecrypt(msg);
	}
	break;
	default:
		return msg;
		break;
	}
}