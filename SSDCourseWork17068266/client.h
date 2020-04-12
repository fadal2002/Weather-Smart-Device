#ifndef OBSERVER_PATTERN_CLIENT
#define OBSERVER_PATTERN_CLIENT

#include <iostream>
#include "Observer.h"

using namespace std;

//this client will implement the observer interface
class Client : public Observer
{
private:
	uint16_t id;
public:

	Client(uint16_t id);

	virtual void update(float temperature, float humidity, float airPressure) override; //this will update the observers everytime the weather data changes
};


#endif // !OBSERVER_PATTERN_CLIENT
