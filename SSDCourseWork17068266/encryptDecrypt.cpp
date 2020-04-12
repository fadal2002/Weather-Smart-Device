#include "EncryptDecrypt.h"

void EncryptDecrypt::writeEncrypt(string fileName)
{
	ofstream outfile;
	outfile.open(fileName);
	outfile << "Encrypted";
	outfile.close();
}

void EncryptDecrypt::writeDecrypt(string fileName)
{
	ofstream outfile;
	outfile.open(fileName);
	outfile << "Decrypted";
	outfile.close();
}

void EncryptDecrypt::logDecryptor(string fileName)
{
	//this function will decrypt a log file
	ifstream encryptedFile(fileName);
	ofstream decryptedFile;
	decryptedFile.open("temp.txt");
	string line;
	while (encryptedFile.good())
	{
		getline(encryptedFile, line);
		char key = 'A';
		string output = line;
		for (int i = 0; i < line.size(); i++)
		{
			output[i] = line[i] - key;
		}
		decryptedFile << output << endl;
	}
	encryptedFile.close();
	remove(fileName.c_str());
	decryptedFile.close();
	rename("temp.txt", fileName.c_str());
	if (fileName == "WeatherLog.txt") //this will update the apropriate encryption checks depending on what file is being decrypted
	{
		writeDecrypt("WeatherEncryptionCheck.txt");
	
	}
	else if (fileName == "AccountsLog.txt")
	{
		writeDecrypt("AccountLogEncryptionCheck.txt");
	
	}
	
}

void EncryptDecrypt::logEncryptor(string fileName)
{
	//this function will encrypt a log file
	ifstream decryptedFile(fileName);
	ofstream encryptedFile;
	encryptedFile.open("temp.txt");
	string line;
	while (decryptedFile.good())
	{
		getline(decryptedFile, line);
		char key = 'A';
		string output = line;
		for (int i = 0; i < line.size(); i++)
		{
			output[i] = line[i] + key;
		}
		encryptedFile << output << endl;
	}
	decryptedFile.close();
	remove(fileName.c_str());
	encryptedFile.close();
	rename("temp.txt", fileName.c_str());
	if (fileName == "WeatherLog.txt") // this will update the apropriate encryption checks depending on what file is being encrypted
	{
		writeEncrypt("WeatherEncryptionCheck.txt");
	}
	else if (fileName == "AccountsLog.txt")
	{
		writeEncrypt("AccountLogEncryptionCheck.txt");

	}
}