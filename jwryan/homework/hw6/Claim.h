//-----------------------------------------------------------------------------
// Name: Claim.h
// Description: Header file for Claim class.
//-----------------------------------------------------------------------------
#ifndef Claim_H
#define Claim_H

using namespace std;

class Claim{
public:
    Claim(Date, string, double); //Constructor
    void print() const;
    double processClaim(double, double); //Determine claim approval
    double getClaimRequested();
    double getClaimApproved();
    Date getDateOfClaim();
private:
    string m_descriptionOfEvent;
    Date m_dateOfEvent;
    double m_claimRequested;
    double m_claimApproved;
};
#endif



