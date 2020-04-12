#include "Interface.h"
#include "AuthenticationInfo.h"
#include <iostream>
#include <fstream>
#include "weatherData.h"
#include "EncryptDecrypt.h"
#include "AccountLogger.h"
#include "LoggerDecorator.h"
#include "client.h"
#include "Logger.h"
#include "User.h"
#include "Authenticator.h"
using namespace std;

void UserInterface::printWeatherData(void)
{
	//printing the weather data
		WeatherData weatherStation;
		Client one(1);

		weatherStation.registerObserver(&one);
		weatherStation.setState();
	
}

void UserInterface::mainMenu(void)
{
	//printing the users main menu
	cout << "\n====={Weather Station}=====" << endl;
	cout << "Press (1) to get the weather data" << endl;
	cout << "Press (2) to get live weather data" << endl;
	cout << "Press (3) to login as adminstirator" << endl;
	cout << "Press (4) to exit the Weather Station" << endl;
	cin >> choice;
	
}

void UserInterface::optionHandler(void)
{
	//this will run functions depending on what option the user chooses in the main menu
	Authenticator authenticator;
	WeatherData wd;
	AuthenticationInfo ai;
	mainMenu();
	if (getChoice() == 1)
	{
		//print the weather data
		printWeatherData();
		//print the main menu and run option handler together
		optionHandler();

	}
	else if (getChoice() == 2)
	{
		//print out simulated live weather data
		cout << "=============================================================================" <<
			"=====================================================================" << endl;
		cout << "	Time/Date		|		Temperature(C)		|		Humidity	|		Air Pressure		" << endl;
		wd.getLiveData();
		optionHandler(); // print the main menu and run option handler together
	}
	else if (getChoice() == 3)
	{
		//allow the user to login as an administirator 
		authenticator.runAuthenticator();
	}
	else if (getChoice() == 4)
	{
		//exit program
		exit(0);
	}
	else
	{
		//choice input checker
		cout << "Invalid choice" << endl;
	}
}

void AdminInterface::mainMenu(void)
{
	//a function that will print the admin main menu
	AuthenticationInfo ai;
	cout << "\n====={Administirator Page}===== " << endl;
	cout << "Press (1) to get the weather data" << endl;
	cout << "Press (2) to get live weather data" << endl;
	cout << "Press (3) to add new Administirator account" << endl;
	cout << "Press (4) to view the weather log" << endl;
	cout << "Press (5) to view the account log" << endl;
	cout << "Press (6) to log out" << endl;
	cin >> option;
	optionHandler();
}


void AdminInterface::addAdminAccount(void)
{
	//this function will allow the administirator to create an admin account
	AuthenticationInfo ai;
	EncryptDecrypt ed;
	unsigned formatType = 3;
	ai.decryptAccountData(); //decrypting account data
	ofstream ofs;
	//add the account details to the account data file
	ofs.open("Accounts.txt", std::ios_base::app);
	cout << "Enter the user name: "; cin >> uName;
	ofs << uName << endl;
	cout << "Enter the password: "; cin >> uPass;
	ofs << uPass << endl;

	cout << "\nAccount added successfuly!!" << endl;

	ifstream AccountLogEncCheck("AccountLogEncryptionCheck.txt");
	string encryptionCheck;
	getline(AccountLogEncCheck, encryptionCheck);
	if (encryptionCheck == "Decrypted") // if the account log file is not encrypted
	{
		ed.logEncryptor("AccountsLog.txt"); // encrypt the log file
		//log the time the admin account was created at
		Logger *logger = nullptr;
		logger = new LoggerDecorator(new AccountLogger(), formatType);
		string msg = "\nA new Administirator account has been created. ------ Recorded at: " + logger->getTimeDate();
		logger->log(msg);
		ed.writeEncrypt("AccountLogEncryptionCheck.txt");
		
	}
	else
	{
		//log the time the admin account was created at
		Logger *logger = nullptr;
		logger = new LoggerDecorator(new AccountLogger(), formatType);
		string msg = "\nA new Administirator account has been created. ------ Recorded at: " + logger->getTimeDate();
		logger->log(msg);
		ed.writeEncrypt("AccountLogEncryptionCheck.txt");
		
	}
	mainMenu();
}

void AdminInterface::optionHandler()
{
	AuthenticationInfo ai;
	WeatherData wd;
	UserInterface ui;
	EncryptDecrypt ed;
	if (option == 1)
	{
		//print the weather data
		ui.printWeatherData();
		//print main menu
		mainMenu();
	}
	else if (option == 2)
	{
		//print simulated live data
		cout << "=============================================================================" <<
			"=====================================================================" << endl;
		cout << "	Time/Date		|		Temperature(C)		|		Humidity	|		Air Pressure		" << endl;
		wd.getLiveData();
		mainMenu();
	}
	else if (option == 3)
	{
		//decrypt the account data file
		ai.decryptAccountData();
		//create an admin account and add it to the account data file
		addAdminAccount();
	}
	else if (option == 4)
	{
		//decrypt the weather log so that the admin is able to read it 
		ed.logDecryptor("WeatherLog.txt");
		cout << "The Weather Log is now readable." << endl;
		//print the admin main menu
		mainMenu();
	}
	else if (option == 5)
	{
		//decrypt the account log so that the admin is able to read it 
		ed.logDecryptor("AccountsLog.txt");
		cout << "The Accounts Log is now readable." << endl;
		//print the admin main menu 
		mainMenu();
	}
	else if (option == 6)
	{
		//before loggging out encrypt all the files that has been decrypted by the admin
		ifstream Read("WeatherEncryptionCheck.txt");
		string weatherLogCheck;
		getline(Read, weatherLogCheck);
		if (weatherLogCheck == "Decrypted")
		{
			ed.logEncryptor("WeatherLog.txt");
		}
		ifstream Read1("AccountLogEncryptionCheck.txt");
		string accountLogCheck;
		getline(Read1, accountLogCheck);
		if (accountLogCheck == "Decrypted")
		{
			ed.logEncryptor("AccountsLog.txt");
		}

		ui.optionHandler();

	}
	else
	{
		//choice input checker
		cout << "Invalid Option!!!!" << endl;
	}
}