#ifndef AUTHENTICATOR_PATTERN_AUTHENTICATOR
#define AUTHENTICATOR_PATTERN_AUTHENTICATOR

#include <iostream>
#include "Admin.h"
#include "ProofOfID.h"

using namespace std;

class Authenticator
{
public:
	Authenticator();
	ProofofID * authenticateUser(Admin &s); //authenticate the inputted details
	void runAuthenticator(void);
private:
	string encryptDecrypt(string toEncrypt);
};

#endif // !AUTHENTICATOR_PATTERN_AUTHENTICATOR

