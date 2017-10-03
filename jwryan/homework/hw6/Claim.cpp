//-----------------------------------------------------------------------------
// Name: Claim.cpp
// Description: Class which holds details of insurance claims, including:
//              date of occurrence, claim description, value of claim requested,
//              and value of claim approved. Provides functions for printing
//              claim information, processing claims, and returning claim info.
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

#include "Date.h"
#include "Claim.h"
/*** Global variables ***/
extern Date currentDate;

//Constructor
Claim::Claim(Date dateOfEvent, string description, double requested)
{
    m_dateOfEvent = dateOfEvent;
    m_descriptionOfEvent = description;
    m_claimRequested = requested;
}

void Claim::print() const
{
    cout<<"Date of Claim: ";
    m_dateOfEvent.print();
    cout<<endl<<"Description: "<<m_descriptionOfEvent<<endl
    <<"Claim Requested: "<<m_claimRequested<<endl
    <<"Claim Approved: "<<m_claimApproved<<endl;
}

//Function for precessing new claims; approves claims based on claim request
//and deductibleToBePaid; returns new deductibleToBePaid
double Claim::processClaim(double deductibleToBePaid, double copay)
{
    //Approve claim if yearly deductible has been met
    //If claim unapproved modify deductibleToBePaid
    if(m_claimRequested <= deductibleToBePaid)
    {
        m_claimApproved = 0;
        deductibleToBePaid -= m_claimRequested;
        return deductibleToBePaid;
    }
    else
    {
        m_claimApproved = m_claimRequested - deductibleToBePaid - copay;
        deductibleToBePaid = 0;
        return deductibleToBePaid;
    }
}

double Claim::getClaimRequested()
{
    return m_claimRequested;
}

double Claim::getClaimApproved()
{
    return m_claimApproved;
}

Date Claim::getDateOfClaim()
{
    return m_dateOfEvent;
}

