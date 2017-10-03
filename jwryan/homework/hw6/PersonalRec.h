//-----------------------------------------------------------------------------
// Name: PersonalRec.cpp
// Description: Header file for PersonalRec class.
//-----------------------------------------------------------------------------
#include <vector>
#include "Claim.h"

#ifndef PersonalRec_H
#define PersonalRec_H

class PersonalRec{
public:
    PersonalRec(std::string, std::string, Date, Date); //Constructor
    void print() const;
    void printName() const;
    void printClaims() const;
    void clearClaims();
    void addClaim(Claim record);

    std::vector<Claim> individualClaims; //Vector of claims
private:
    int m_age;
    bool m_isAdult;
    string m_firstName;
    string m_lastName;
    Date m_DoB;
    Date m_DateAdded;
};
#endif



