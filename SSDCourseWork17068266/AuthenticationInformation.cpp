#include <iostream>
#include <fstream>
#include "AuthenticationInfo.h"
#include "EncryptDecrypt.h"

using namespace std;

#define KEY 23 // this is the key for the encryption and decryption

AuthenticationInfo::AuthenticationInfo()
{
	string un, pw; // these will temporary store the username and password
	ifstream Read("Accounts.txt"); // accessing the text file that has the account data
	ifstream AccountsDataEncCheck("AccountsDataEncryptionCheck.txt"); // accessing the file that stores wether the account file is encrypted or not
	string encryptionCheck; // this string variable will either store "Encrypted" or "Decrypted" depending on what it says on hte "AccountsDataEncryptionCheck.txt"
	getline(AccountsDataEncCheck, encryptionCheck);
	if (encryptionCheck == "Encrypted") // checks if the account data file is encrypted
	{
		ifstream ReadEncryption("Accounts.txt"); // accessing the encrypted file
		while (ReadEncryption.good()) // going through the text file
		{
			getline(ReadEncryption, un); //getting the firstline and storing it as the username
			getline(ReadEncryption, pw); //getting the secondline and storing it as a password
			if (un == "" || pw == "") //if the password or username is an empty line
			{
				break; // end while loop
			}
			else
			{
				EncryptedUsers.insert(pair<string, string>(un, pw)); // insert the encrypted username and password in the EncryptedUsers map
			}
		}
		decryptAccountData(); // decrypt the data in the account text file so that it can be user for authentications
	}
	while (Read.good()) // going through the Decrypted account data file 
	{
		//same process as before. getting the usernames and passwords from the file after they get decrypted
		getline(Read, un);
		getline(Read, pw);
		if (un == "" || pw == "")
		{
			break;
		}
		else
		{
			Users.insert(pair<string, string>(un, pw)); // storing the data into the Decrypted Users map
		}
	}
	encryptAccountData(); // after getting the required data encrypt the file
	ifstream ReadEncryption("Accounts.txt");
	while (ReadEncryption.good()) // go through the encrypted account data file and store the usernames and passwords in the EncryptedUsers map
	{
		getline(ReadEncryption, un);
		getline(ReadEncryption, pw);
		if (un == "" || pw == "")
		{
			break;
		}
		else
		{
			EncryptedUsers.insert(pair<string, string>(un, pw));
		}
	}
}

void AuthenticationInfo::encryptAccountData()
{
	ifstream AccountsDataEncCheck("AccountsDataEncryptionCheck.txt");
	string encryptionCheck; 
	getline(AccountsDataEncCheck, encryptionCheck);
	if (encryptionCheck == "Decrypted") //checking if the account data is decrypted
	{
		fstream ofs;
		ofs.open("Accounts.txt", ios::out | ios::trunc); //opening the account data file
		for (map<string, string>::iterator it = Users.begin(); it != Users.end(); it++) // going through the users map
		{
			uint16_t i;
			char str[100];
			string s = it->first;
			strcpy_s(str, s.c_str()); //inputting the string into the char array
			for (i = 0; (i < 100 && str[i] != '\0'); i++) //going through the char array and adding the key to each letter in the array
			{
				str[i] = str[i] + KEY;
			}
			int n = s.length();
			for (uint16_t i = 0; i < n; i++)
			{
				ofs << str[i]; // outputting the encrypted string to the account data file
			}
			ofs << endl;
			/////////////////////////////
			// the same process as the process above but for the password (second part)
			s = it->second;
			strcpy_s(str, s.c_str());
			for (i = 0; (i < 100 && str[i] != '\0'); i++)
			{
				str[i] = str[i] + KEY;
			}
			n = s.length();
			for (uint16_t i = 0; i < n; i++)
			{
				ofs << str[i];
			}
			ofs << endl;
		}
		ofs.close(); //closing file
		EncryptDecrypt ed;
		ed.writeEncrypt("AccountsDataEncryptionCheck.txt"); //updating the encryption checker file to "Encrypted" 
	}
	
}

void AuthenticationInfo::decryptAccountData()
{
	// this function will check if the account data file is encrypted and decrypt the file
	ifstream AccountsDataEncCheck("AccountsDataEncryptionCheck.txt");
	string encryptionCheck;
	getline(AccountsDataEncCheck, encryptionCheck);
	if (encryptionCheck == "Encrypted")
	{
		fstream ofs;
		ofs.open("Accounts.txt", ios::out | ios::trunc);
		for (map<string, string>::iterator it = EncryptedUsers.begin(); it != EncryptedUsers.end(); it++)
		{
			int i;
			char str[100];
			string s = it->first;
			strcpy_s(str, s.c_str());
			for (i = 0; (i < 100 && str[i] != '\0'); i++)
			{
				str[i] = str[i] - KEY;
			}
			int n = s.length();
			for (int i = 0; i < n; i++)
			{
				ofs << str[i];
			}
			ofs << endl;
			/////////////////////////////
			s = it->second;
			strcpy_s(str, s.c_str());
			for (i = 0; (i < 100 && str[i] != '\0'); i++)
			{
				str[i] = str[i] - KEY;
			}
			n = s.length();
			for (int i = 0; i < n; i++)
			{
				ofs << str[i];
			}
			ofs << endl;
		}
		ofs.close();
		EncryptDecrypt ed;
		ed.writeDecrypt("AccountsDataEncryptionCheck.txt");
	}
	
}

bool AuthenticationInfo::validateUser(string name, string password)
{
	//this will validate the inputted username and password
	bool validUser = false;
	map<string, string>::iterator it;
	it = Users.find(name);
	if (it != Users.end())
	{
		if (!(it->second.compare(password)))
		{
			validUser = true;
		}
	}
	return validUser;
}