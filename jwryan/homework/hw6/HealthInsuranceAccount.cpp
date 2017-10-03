//-----------------------------------------------------------------------------
// Name: HealthInsuranceAccount.cpp
// Description: Class which stores information about health insurance account.
//              includes all members of account, deductible per year, deductible
//              remaining in year, copay, date of renewal, and expiration date.
//              Provides functions for printing account information, adding
//              members and claims, and renewing the account.
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

#include "Date.h"
#include "PersonalRec.h"
#include "Claim.h"
#include "HealthInsuranceAccount.h"
#include <vector>

/*** Global variables ***/
extern Date currentDate;

//Constructor
HealthInsuranceAccount::HealthInsuranceAccount(PersonalRec member, double deductible, double copay)
{
    //Add member sent to constructor as primary member
    addMember(member);

    deductiblePerYear = deductible;
    m_deductibleToBePaid = deductiblePerYear;
    copayPerVisit = copay;
    m_dateRenewed = currentDate;

    //Original date of expiry for account: one year from account opening
    m_dateofExpiry = currentDate;
    m_dateofExpiry.addYears(1);
}

//Function prints list of members on account
void HealthInsuranceAccount::printMembers() const
{
    cout<<"Members:"<<endl;

    //Loop through vector for printing
    for(size_t i=0; i<members.size(); i++)
    {
        cout<<i<<". ";
        members[i].printName();
        cout<<endl;
    }
}

//Function to print claims of all members on account
void HealthInsuranceAccount::printClaims() const
{
    cout<<endl<<"======================================"<<endl
    <<"Claims:"<<endl
    <<"======================================"<<endl<<endl;

    //Loop vector
    for(size_t i=0; i<members.size(); i++)
    {
        members[i].printClaims();

        //Divide claims of different members
        if(i != members.size() - 1)
            cout<<endl<<"--------------------------------------"<<endl;
    }
    cout<<endl;
}

//Function prints all information about account
void HealthInsuranceAccount::displayAccountInformation() const
{
    cout<<endl<<"======================================"<<endl
    <<"Account Information"<<endl
    <<"======================================"<<endl
    <<"Deductible per year: "<<deductiblePerYear<<endl
    <<"Deductible to be paid: "<<m_deductibleToBePaid<<endl
    <<"Copay per visit: "<<copayPerVisit<<endl
    <<"Account started/renewed on: ";
    m_dateRenewed.print();
    cout<<endl<<"--------------------------------------";

    for(size_t i=0; i<members.size(); i++)
    {
        cout<<endl<<i<<". ";
        members[i].print();

        //Divide information of different members
        if(i != members.size() - 1)
            cout<<endl<<"--------------------------------------";
    }
    cout<<endl;
}

//Add new member to account vector
void HealthInsuranceAccount::addMember(PersonalRec new_member)
{
    members.push_back(new_member);
}

//Function for creating claim for account member
void HealthInsuranceAccount::addClaim(int memberNumber, string descriptionofEvent, double claimAmount, Date currentDate)
{
    //Generate, process, and add claim
    Claim newClaim(currentDate, descriptionofEvent, claimAmount);
    m_deductibleToBePaid = newClaim.processClaim(m_deductibleToBePaid, copayPerVisit);
    members[memberNumber].addClaim(newClaim);
}

//Function for renewing insurance upon expiration
void HealthInsuranceAccount::renewInsurance()
{
    if(currentDate>m_dateofExpiry)
    {
        //Increment expiration date and renewal date while date of expiration has passed
        while(currentDate > m_dateofExpiry)
        {
            m_dateRenewed.addYears(1);
            m_dateofExpiry.addYears(1);
        }

        //Reset deductible and claims upon renewal
        m_deductibleToBePaid = deductiblePerYear;
        for(size_t i=0; i<members.size(); i++)
        {
            members[i].clearClaims();
        }
    }

}
