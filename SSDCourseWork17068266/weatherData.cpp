#include "weatherData.h"
#include "EncryptDecrypt.h"
#include "LoggerDecorator.h"
#include "WeatherLogger.h"
#include "Logger.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

void WeatherData::registerObserver(Observer *observer)
{
	observers.push_back(observer);
}

void WeatherData::removeObserver(Observer *observer)
{
	auto iterator = find(observers.begin(), observers.end(), observer);

	if (iterator != observers.end()) //if observer found
	{
		observers.erase(iterator); // remove observer
	}
}

void WeatherData::notifyObservers()
{
	//notify all observers
	for (Observer *observer : observers)
	{
		observer->update(temperature, humidity, airPressure);
	}
}

void WeatherData::setState()
{
	User stationUser;


	this->temperature = stationUser.RandomTemperature();
	this->humidity = stationUser.RandomHumidity();
	this->airPressure = stationUser.RandomAirPressure();
	cout << endl;
	notifyObservers();
}

void WeatherData::getLiveData()
{
	unsigned formatType = 3; // encrypted format
	string temp;
	string humidity;
	string pressure;
	Logger *log = nullptr;
	float fatalPressure = 2500;

	ifstream Read("SimulatedData.txt");
	while (Read.good())
	{
		getline(Read, temp);
		getline(Read, humidity);
		getline(Read, pressure);

		cout << "\n" << log->getTimeDate() << "				|		";
		cout <<"" << temp << " (C)		|		" << humidity << "%		|		" << pressure << " Millibars		" << endl;
		if (stoi(pressure) >= fatalPressure)
		{
			cout << "\n\nThe air pressure has reached fatal levels... SOUNDING THE ALARMS!!!!!!" << endl;
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
			string msg = "\nThe weather is:  Temperature: " + temp + " Celsius" + "  Humidity: " +
				humidity + "%" + "  Air pressure: " + pressure + " millibars ------- Recorded at: " + logger->getTimeDate();
			logger->log(msg);
			ed.writeEncrypt("WeatherEncryptionCheck.txt");
			
		}
		else
		{
			Logger *logger = nullptr;
			logger = new LoggerDecorator(new WeatherLogger(), formatType);
			string msg = "\nThe weather is:  Temperature: " + temp + " Celsius" + "  Humidity: " +
				humidity + "%" + "  Air pressure: " + pressure + " millibars ------- Recorded at: " + logger->getTimeDate();
			logger->log(msg);
			ed.writeEncrypt("WeatherEncryptionCheck.txt");
			
		}
		Sleep(1000);
	}
}