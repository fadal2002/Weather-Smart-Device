#include "client.h"
#include "WeatherLogger.h"
#include "EncryptDecrypt.h"
#include "LoggerDecorator.h"
#include "Logger.h"
#include <iostream>
#include <fstream>

using namespace std;

void Client::update(float temperature, float humidity, float pressure)
{
	
	float fatalPressure = 2500;
	unsigned formatType = 3; //encrypted format
	//this will print out the changed values
		cout << "---Client (" << id << ") Data---\tTemperature: " << temperature << " Celsius"
			<< "\t\tHumidity: " << humidity << "%"
			<< "\t\tAir pressure: " << pressure << " millibars"
			<< endl;
		if (pressure >= fatalPressure)
		{
			cout << "The air pressure has reached fatal levels... SOUNDING THE ALARMS!!!" << endl;
		}
		EncryptDecrypt ed;
		ifstream WeatherEncCheck("WeatherEncryptionCheck.txt");
		string EncryptionCheck;
		getline(WeatherEncCheck, EncryptionCheck);
		if (EncryptionCheck == "Decrypted")
		{
			ed.logEncryptor("WeatherLog.txt");
			Logger *logger = nullptr;
			logger = new LoggerDecorator(new WeatherLogger(), formatType);
			string msg = "\nThe weather is:  Temperature: " + to_string(temperature) + " Celsius" + "  Humidity: " +
				to_string(humidity) + "%" + "  Air pressure: " + to_string(pressure) + " millibars ------- Recorded at: " + logger->getTimeDate();
			logger->log(msg);
			ed.writeEncrypt("WeatherEncryptionCheck.txt");
			
		}
		else
		{
			Logger *logger = nullptr;
			logger = new LoggerDecorator(new WeatherLogger(), formatType);
			string msg = "\nThe weather is:  Temperature: " + to_string(temperature) + " Celsius" + "  Humidity: " +
				to_string(humidity) + "%" + "  Air pressure: " + to_string(pressure) + " millibars ------- Recorded at: " + logger->getTimeDate();
			logger->log(msg);
			ed.writeEncrypt("WeatherEncryptionCheck.txt");
			
		}
}

Client::Client(uint16_t id)
{
	//setting an id to the client 
	this->id = id;
}