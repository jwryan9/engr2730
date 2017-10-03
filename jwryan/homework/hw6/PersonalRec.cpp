//-----------------------------------------------------------------------------
// Name: PersonalRec.cpp
// Description: Class which holds details about insurance customers including:
//              name, date of birth, date of purchase, and age. Contains methods
//              for printing customer details and claims handling.
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
#include <vector>

#include "Date.h"
#include "Claim.h"
#include "PersonalRec.h"

/*** Global variables ***/
extern Date currentDate;

//Constructor
PersonalRec::PersonalRec(string firstName, string lastName, Date DoB, Date dateAdded)
{
    m_firstName = firstName;
    m_lastName = lastName;
    m_DoB = DoB;
    m_DateAdded = dateAdded;

    m_age = DoB.getAge(DoB, currentDate);
    m_isAdult = DoB.isAdult(DoB, currentDate);
}


//Function for printing member information
void PersonalRec::print() const
{
    cout<<"Name: ";
    PersonalRec::printName();
    cout<<endl<<"   Date of Birth: ";
    m_DoB.print();
    cout<<endl<<"   Age: "<<m_age<<endl
    <<"   Is Adult: ";
    if(m_DoB.isAdult(m_DoB, currentDate))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    cout<<"   Added to the policy on: ";
    m_DateAdded.print();
}

void PersonalRec::printName() const
{
    cout<<m_firstName<<" "<<m_lastName;
}

void PersonalRec::printClaims() const
{
    cout<<"Claims of ";
    printName();
    cout<<":"<<endl<<endl;
    for(size_t i=0; i<individualClaims.size(); i++)
    {
        individualClaims[i].print();

        //Print divider between claims of individual
        if(i != individualClaims.size() - 1)
            cout<<"----------"<<endl;
    }
}

void PersonalRec::clearClaims()
{
    individualClaims.clear();
}

void PersonalRec::addClaim(Claim record)
{
    individualClaims.push_back(record);
}
