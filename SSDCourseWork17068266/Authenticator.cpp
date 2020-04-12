#include "Authenticator.h"
#include "AuthenticationInfo.h"
#include "Admin.h"
#include "Interface.h"
#include <iostream>
#include <string>

using namespace std;

Authenticator::Authenticator() { };

ProofofID * Authenticator::authenticateUser(Admin &s)
{
	//this function will check if the details inputted by the user are correct
	AuthenticationInfo ainfo;
	ProofofID *proofofID = nullptr;
	string Id = s.getId();
	string pass = s.getPassword();
	string token = "";
	if (ainfo.validateUser(Id, pass))
	{
		cout << "\nWelcome!";
		cout << "\nAuthenticated!\n";
		token = encryptDecrypt(Id + pass);
		proofofID = new ProofofID(token);
		s.setproofofID(token);
	}
	else
		cout << "Invalid user ID or Password. please try again";
	return proofofID;
};

string Authenticator::encryptDecrypt(string toEncrypt)
{
	//this is an encryption method different to the ASCII method that ive used to encrypt the account data files
	char key = 'A';
	string output = toEncrypt;
	for (unsigned int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] ^ key;
	return output;
}

void Authenticator::runAuthenticator(void)
{
	//this function will keep asking the user to login until he chooses to exit
	unsigned userExited = 0;
	
	while (!userExited)
	{
		Admin s;
		Authenticator a;
		ProofofID *proofofID = a.authenticateUser(s);
		if (proofofID != nullptr)
		{
			cout << "subject proof of id: " << s.getproofofID() << endl;
			cout << "system proof of id: " << proofofID->getproofID() << endl;
			AdminInterface adminI;
			adminI.mainMenu();
		}
		else
		{
			cout << "\nTry Again?"<< endl;
			cout << "Press (0) for Yes" << endl;
			cout << "Press (1) for No" << endl;
			cin >> userExited;
		}

	}
	
}