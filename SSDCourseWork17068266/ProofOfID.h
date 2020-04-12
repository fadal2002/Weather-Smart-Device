#ifndef PROOFOFID_AUTHENTICATION_PATTERN
#define PROOFOFID_AUTHENTICATION_PATTERN

#include <iostream>
#include <string>

using namespace std;

class ProofofID
{
private:
	string proofID;
public:
	ProofofID() {};
	ProofofID(string);
	string getproofID();
	void setproofID(string);
};

#endif // !PROOFOFID_AUTHENTICATION_PATTERN
