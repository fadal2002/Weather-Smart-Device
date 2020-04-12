#ifndef OBSERVER_PATTERN_WEATHERDATA
#define	OBSERVER_PATTERN_WEATHERDATA

#include <vector>
#include <algorithm>
#include <iostream>
#include "subject.h"
#include "Observer.h"

class WeatherData : public Subject
{
private:
	vector<Observer *> observers; //vector that will store all the observers

	float temperature = 0.0f;
	float humidity = 0.0f;
	float airPressure = 0.0f;

public:
	float getTemp(void)
	{
		return temperature;
	}

	float getHumidity(void)
	{
		return humidity;
	}

	float getAirPressure(void)
	{
		return airPressure;
	}

	void registerObserver(Observer *observer) override;
	
	void removeObserver(Observer *observer) override;

	void notifyObservers() override;

	//create the new state of the weather station

	void setState(void); 
	void getLiveData(void);

};


#endif // !OBSERVER_PATTERN_WEATHERDATA

