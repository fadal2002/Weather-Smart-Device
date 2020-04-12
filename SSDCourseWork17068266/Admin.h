#ifndef AUTHENTICATOR_PATTERN_SUBJECT
#define AUTHENTICATOR_PATTERN_SUBJECT

#include <iostream>
#include <string>

using namespace std;

class Admin
{
private:
	string id;
	string password;
	string proofID;
public:
	Admin(string a, string pass); //creating an admin account 
	Admin();
	string getId();
	string getPassword();
	void setproofofID(string proof);
	string getproofofID();
};

#endif // !AUTHENTICATOR_PATTERN_SUBJECT

