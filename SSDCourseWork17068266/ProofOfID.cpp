#include "ProofOfID.h"

string ProofofID::getproofID()
{
	return proofID;
}

void ProofofID::setproofID(string aproofID)
{
	proofID = aproofID;
}

ProofofID::ProofofID(string aproofID)
	: proofID(aproofID) {};