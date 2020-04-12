#ifndef OBSERVER_PATTERN_SUBJECT
#define OBSERVER_PATTERN_SUBJECT

#include "Observer.h"
using namespace std;

class Subject
{
public:
	//Register an observer
	virtual void registerObserver(Observer *observer) = 0;
	
	//Unregister an observer
	virtual void removeObserver(Observer *observer) = 0;

	//Notify the registered observers when a change occures
	virtual void notifyObservers() = 0;
};


#endif // !OBSERVER_PATTERN_SUBJECT
