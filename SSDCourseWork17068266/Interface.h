#ifndef WEATHER_STATION_INTERFACE
#define WEATHER_STATION_INTERFACE

#include <iostream>
#include <string>

using namespace std;

class Interface //this is the template class of the interfaces
{
public:
	virtual void mainMenu(void) = 0; // this will print the main menu that the interface has
	virtual void optionHandler(void) = 0; // this will run the apropriate functions depending on the choice the user chooses in the main menu
};

class UserInterface : public Interface //this is the user interface which is accessable by anyone that runs the program
{
private:
	uint16_t choice = 0;
public:
	uint16_t getChoice(void)
	{
		return choice;
	}
	void mainMenu(void);
	void printWeatherData(void);
	void optionHandler(void);
};

class AdminInterface : public Interface //this is the admin interface and only accessable by users with an admin account
{
private:
	uint16_t option = 0;
	string uName;
	string uPass;
public:
	uint16_t getOption(void)
	{
		return option;
	}
	void mainMenu(void);
	void optionHandler(void);
	void addAdminAccount(void); //this function will allow the admin to create more admin accounts
};


#endif // !WEATHER_STATION_INTERFACE
