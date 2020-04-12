#ifndef AUTHENTICATION_INFO
#define AUTHENTICATION_INFO

#include <iostream>
#include <string>
#include <map>

using namespace std;

class AuthenticationInfo
{
private:
	map<string, string> Users; // this will store users data without any encryption
	map<string, string> EncryptedUsers; // this will store users data after encrypting them
public:
	AuthenticationInfo(); 
	bool validateUser(string name, string password); // this will authenticate the users info inputted
	void encryptAccountData(); // this function will encrypt user data using the ASCII method
	void decryptAccountData(); // this function will decrypt user data using the ASCII method
};


#endif // !AUTHENTICATION_INFO
