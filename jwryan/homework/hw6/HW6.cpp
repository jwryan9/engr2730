//-----------------------------------------------------------------------------
// Your Name:   Jason Ryan
// Description: Application for health insurance account management. Creates
//              new account with single member and allows user to add dependent
//              members, add claims, display full account info, display claims,
//              and change date for testing of date dependent functionality.
// Pseudo Code: testFromMenu():
//                  Gather info for primary member, create account, add primary
//                  while exit not requested
//                      Present menu to user and wait for input
//                      switch
//                          add dependent
//                          add claim
//                          display account info
//                          display claims
//                          change date
//                          terminate program
//              getChoice(min, max)
//                  return integer selection within bounds
//-----------------------------------------------------------------------------
/**** Detail descriptions are provided in files "homework6.pdf"
Please read those before asking your question to TAs  *****/
#include<iostream>
#include<string>
#include<math.h>
#include <stdio.h>
using namespace std;

#include "Date.h"
#include "Claim.h"
#include "PersonalRec.h"
#include "HealthInsuranceAccount.h"


/** Global Variable **/
Date currentDate(1,1,2016);

//Function prototypes
int getChoice(int, int);
void addClaim(HealthInsuranceAccount);
void testManually();
void testFromMenu();

int main()
{
    //TESTING THE CODE MANUALLY; comment this block final testing

    //testManually();

    //DONE MANUAL FROM MENU: uncomment the code below for final testing

    testFromMenu();

    return 0;

}

// Function to test the program manually
 void testManually()
{
    double deductable = 1000;
    double copay = 20;
    string firstName, lastName;
    string claimDescription;

    PersonalRec newMember("John","Doe",Date(1,1,1970),currentDate);
    HealthInsuranceAccount newAccount(newMember,deductable,copay);

    newMember = PersonalRec("Patty","Doe",Date(1,1,1973),currentDate);
    newAccount.addMember(newMember);

    newMember = PersonalRec("Kyle","Doe",Date(1,1,2000),currentDate);
    newAccount.addMember(newMember);

    newMember = PersonalRec("Sue","Doe",Date(1,1,2004),currentDate);
    newAccount.addMember(newMember);

    newAccount.printMembers();

    newAccount.displayAccountInformation();

    currentDate = Date(5,1,2016);
    newAccount.addClaim(0,"fell down; broke bone; needed cast",3000,currentDate);

    currentDate = Date(7,5,2016);
    newAccount.addClaim(2,"high fever; tested for flu; positive",150,currentDate);

    currentDate = Date(12,5,2016);
    newAccount.addClaim(3,"high fever; tested for flu; positive",150,currentDate);

    currentDate = Date(7,10,2016);
    newAccount.addClaim(1,"Annual checkup",100,currentDate);

    currentDate = Date(7,30,2016);
    newAccount.addClaim(1,"Pain in Back; MRI",1500,currentDate);

    currentDate = Date(8,15,2016);
    newAccount.addClaim(0,"Physiotherapy",860,currentDate);

    newAccount.printClaims();
    cout << "----------------------------------------------------"<<endl;

}

//Function to test the program from menu
void testFromMenu() {

    //Declare variables
    int choice = -1;
	double deductable;
	double copay;
	string firstName;
	string lastName;
	Date DoB;

	cout<<"Enter current date ";
	currentDate.setDate();

    //Gather input to setup account
	cout<<"Starting a new policy. Give account holder info."<<endl
	<<"First name: ";
	cin>>firstName;
	cout<<"Last name: ";
	cin>>lastName;

	cout<<"Date of birth ";
	DoB.setDate();

	cout<<"Enter the deductible on the account: $";
	cin>>deductable;

	cout<<"Enter the copay per visit: $";
	cin>>copay;

    //Create primary account holder and generate new account
	PersonalRec primary(firstName, lastName, DoB, currentDate);
	HealthInsuranceAccount newAccount(primary, deductable, copay);

	while(choice != 0)
    {
        //Display menu
        cout<<endl<<"Use:"<<endl
        <<"1: Add dependent"<<endl
        <<"2: Add claim"<<endl
        <<"3: Display account information"<<endl
        <<"4: Display claims"<<endl
        <<"5: Set current date"<<endl
        <<"0: Terminate"<<endl<<endl;

        choice = getChoice(0, 5);

        //Switch statement for operation of menu system
        switch(choice)
        {
            //Add Dependent
            case 1:
                {
                    cout<<endl<<"Adding Dependent to Account"<<endl

                    //Get info about dependent
                    <<"First name: ";
                    cin>>firstName;
                    cout<<"Last name: ";
                    cin>>lastName;

                    cout<<"Date of Birth ";
                    DoB.setDate();

                    //Create new member based on dependent information and add to insurance account
                    PersonalRec dependent(firstName, lastName, DoB, currentDate);
                    newAccount.addMember(dependent);
                }
                break;
            //Add Claim
            case 2:
                {
                    //Declare variables
                    double claimRequest;
                    int memberID;
                    string claimDescription;

                    cout<<endl<<"======================================"<<endl
                    <<"Add Claim"<<endl
                    <<"======================================"<<endl;
                    newAccount.printMembers();
                    cout<<endl<<"Please select a member to add claim."<<endl;
                    memberID = getChoice(0, newAccount.members.size());

                    cout<<"Enter description of claim: ";

                    //Allows input of strings with spaces
                    getline(cin, claimDescription);
                    while(claimDescription.length() == 0)
                    {
                        getline(cin, claimDescription);
                    }

                    cout<<"Enter claim amount: ";
                    cin>>claimRequest;

                    //Add claim to account member
                    newAccount.addClaim(memberID, claimDescription, claimRequest, currentDate);
                }
                break;
            //Display Full Account Info
            case 3:
                newAccount.displayAccountInformation();
                break;
            //Display Claims
            case 4:
                newAccount.printClaims();
                break;
            //Set Date
            case 5:
                currentDate.setDate();
                //Renew insurance if new date is set after expiration
                newAccount.renewInsurance();
                break;
            //Quit Program
            case 0:
                cout<<"Goodbye."<<endl;
                break;
        }
    }
}

//Function for retrieving user menu input.
int getChoice(int minChoice, int maxChoice)
{
    int choice;
    cout<<"Enter selection: ";
    cin>>choice;

    //Ensure user input is within bounds
    while(choice < minChoice || choice > maxChoice)
    {
        cout<<"Please enter valid selection: ";
        cin>>choice;
    }

    return choice;
}
