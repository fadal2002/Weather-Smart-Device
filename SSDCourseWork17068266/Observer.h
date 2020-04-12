#ifndef OBSERVER_PATTERN_OBSERVER
#define OBSERVER_PATTERN_OBSERVER

using namespace std;

class Observer
{
public:
	//update the state of this observer
	virtual void update(float temperature, float humidity, float airPressure) = 0;
};


#endif // !OBSERVER_PATTERN_OBSERVER
