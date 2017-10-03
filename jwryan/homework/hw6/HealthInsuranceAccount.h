//-----------------------------------------------------------------------------
// Name: HealthInsuranceAccount.h
// Description: Header file for HealthInsuranceAccount class.
//-----------------------------------------------------------------------------
#include <vector>

#ifndef INSURANCE_H
#define INSURANCE_H

class HealthInsuranceAccount{
public:
    HealthInsuranceAccount(PersonalRec, double, double); //Constructor
    void printMembers() const;
    void printClaims() const;
    void displayAccountInformation() const; //Print full account information
    void addMember(PersonalRec);
    void addClaim(int, string, double, Date); //Add claim for member
    void renewInsurance();

    std::vector<PersonalRec> members; //Vector of PersonalRec objects for storing account members
    double deductiblePerYear;
    double copayPerVisit;

private:
    Date m_dateRenewed;
    Date m_dateofExpiry;
    double m_deductibleToBePaid;
};
#endif



