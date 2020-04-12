#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin(string aId, string apass) : id(aId), password(apass) //setting a username and password for the new account
{
	proofID = ""; // setting a proof of id to the account
}

Admin::Admin()
{
	cout << "\nEnter UserID: " << endl;
	cin >> id; //asking the user for the username
	cout << "\nEnter Password: " << endl;
	cin >> password; //asking the user for the password
	proofID = "";
}

string Admin::getId() { return id; };
string Admin::getPassword() { return password; };

void Admin::setproofofID(string proof)
{
	proofID = proof;
};

string Admin::getproofofID()
{
	return proofID;
}