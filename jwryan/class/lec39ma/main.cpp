//-----------------------------------------------------------------------------
// Programmer: TODO: Jason Ryan
// Name: main.cpp
// Description: This program contains in-class examples and the mini-assignment
//              associated with lecture 39 (inheritance)
// Building from command line (on linux):
//  g++ main.cpp BasePlusCommissionEmployee.cpp CommissionEmployee.cpp -o main.exe
//
// Mini-assignment: Given the provided PhonePlan class and start of a derived
// class named PhonePlanWithData in this file:
// (1) Finish the implementation of the printStatus member function for the
//     derived class named PhonePlanWithData. Your printStatus member must
//     (a) call the base class's print member function and
//     (b) also print the number of remaining amount of GB of data available
//         in the month.
// (2) Write code within your miniAssignment() function to create an object
//     of a the derived class and call ALL of its member functions at least once
//     (including those defined in the base class).
//-----------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include "BasePlusCommissionEmployee.h" // class definition for book example
using namespace std;

//----------------------------
// Inheritance syntax example
//----------------------------
class MyBaseClass {
public:
    // data modification:
    void setProtectedInt(int userInt) { m_protectedInt = userInt; }
    void setPrivateInt(int userInt) { m_privateInt = userInt; }

    // data accessors:
    int getProtectedInt() const { return m_protectedInt; }
    int getPrivateInt() const { return m_privateInt;}

    // other member functions:
    void print() const;

protected: // the base class (, friends,) and derived classes may access
    int m_protectedInt;

private: // only the base class (and friends) may access
    int m_privateInt;
};

void MyBaseClass::print() const
{
    std::cout << "The protected int equals " << m_protectedInt << "." << std::endl;
    std::cout << "The private int equals " << m_privateInt << "." << std::endl;
}

class MyDerivedClass : public MyBaseClass {
public:
    // data modification
    void setAdditionalPrivateInt(int userInt) { m_additionalPrivateInt = userInt; }

    // override base class's print function
    void print() const;

private:
    int m_additionalPrivateInt;
};

void MyDerivedClass::print() const
{
    // call base class print function
    MyBaseClass::print();

    // also print additional data member value
    std::cout << "The additional private int equals " << m_additionalPrivateInt << "." << std::endl;
}

void inheritanceExample();

//------------------
// Clicker question
//------------------
class CQBase {
public:
    void setBaseVal(int val) { m_base = val; }
    int getBaseVal() const { return m_base; }
    void print() const { std::cout << m_base << std::endl; }
protected:
    int m_base;
};

class CQDerived : public CQBase {
public:
    void setDerivedVal(int val) { m_derived = val; }
    int getDerivedVal() const { return m_derived; }
    void print() const { std::cout << m_base << " " << m_derived << std::endl; }
private:
    int m_derived;
};

void clickerQuestion();

//--------------------------
// Book inheritance example
//--------------------------
void bookInheritanceExample();

//-----------------
// Mini-assignment
//-----------------

// base class: PhonePlan
class PhonePlan {
public:
    // constructors
    PhonePlan(int remainingMinutesInMonth = 500)
    {
        setRemainingMinutesInMonth(remainingMinutesInMonth);
    }

    // data accessors
    int getRemainingMinutesInMonth() const { return m_remainingMinutesInMonth; }

    // data modification
    void setRemainingMinutesInMonth(int minutes)
    {
        m_remainingMinutesInMonth = (minutes > 0) ? minutes : 0;
    }

    void useMinutes(int minutes)
    {
        int minutesRemaining = getRemainingMinutesInMonth();
        setRemainingMinutesInMonth(minutesRemaining - minutes);
    }

    // printStatus (implementation below)
    void printStatus() const;

private:
        int m_remainingMinutesInMonth; // represents number of minutes remaining to use in a month
};

void PhonePlan::printStatus() const
{
    std::cout << "Remaining minutes in month = "
              << getRemainingMinutesInMonth() << std::endl;
}

// derived class: PhonePlanWithData
class PhonePlanWithData : public PhonePlan {
public:
    // constructors
    PhonePlanWithData(int remainingMinutesInMonth = 500, float remainingDataInMonth = 2.0)
        : PhonePlan(remainingMinutesInMonth)
    {
        setRemainingDataInMonth(remainingDataInMonth);
    }

    // data accessors
    float getRemainingDataInMonth() const { return m_remainingDataInMonth; }

    // data modification
    void setRemainingDataInMonth(float remainingDataInMonth)
    {
        m_remainingDataInMonth = (remainingDataInMonth > 0.0) ? remainingDataInMonth : 0.0;
    }

    void useData(float amountToUse)
    {
        float dataRemaining = getRemainingDataInMonth();
        setRemainingDataInMonth(dataRemaining - amountToUse);
    }

    // print
    void printStatus() const;

private:
    float m_remainingDataInMonth; // represents GB of data remaining to use in a month
};

void PhonePlanWithData::printStatus() const
{
    // TODO: call base class printStatus() function here
    PhonePlan::printStatus();


    // TODO: print message here indicating amount of data in month remaining
    std::cout << "Data Remaining: " << m_remainingDataInMonth << " GB"<<endl;

}

void miniAssignment();

int main()
{
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "inheritanceExample():" << std::endl;
    std::cout << "---------------------" << std::endl;
    inheritanceExample();

    std::cout << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "clickerQuestion():" << std::endl;
    std::cout << "------------------" << std::endl;
    //clickerQuestion();

    std::cout << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "bookInheritanceExample()" << std::endl;
    std::cout << "------------------------" << std::endl;
    bookInheritanceExample();

    std::cout << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "miniAssignment()" << std::endl;
    std::cout << "----------------" << std::endl;
    miniAssignment();

    return 0;
}

void inheritanceExample()
{
    // create an example MyBaseClass object
    MyBaseClass baseA;
    baseA.setProtectedInt(1);
    baseA.setPrivateInt(2);
    std::cout << "Printing baseA:" << std::endl;
    baseA.print();
    std::cout << std::endl;

    // create an example MyDerivedClass object
    MyDerivedClass derivedA;
    derivedA.setProtectedInt(10);
    derivedA.setPrivateInt(11);
    derivedA.setAdditionalPrivateInt(12);
    std::cout << "Printing derivedA:" << std::endl;
    derivedA.print();
    std::cout << std::endl;

    // create a MyBaseClass object from the derivedA object
    MyBaseClass baseB(derivedA); // using automatic copy constructor
    std::cout << "Printing baseB:" << std::endl;
    baseB.print();
    std::cout << std::endl;
}

void clickerQuestion()
{
    CQDerived myObj;
    myObj.setBaseVal(1);
    myObj.setDerivedVal(2);
    myObj.print();

    CQBase myObj2;
    myObj2.setBaseVal(3);
    myObj2.print();

    CQBase *myPointer = &myObj;
    myPointer->print();
}

void bookInheritanceExample()
{
   // instantiate BasePlusCommissionEmployee object
   BasePlusCommissionEmployee employee( "Bob", "Lewis", "333-33-3333", 5000, .04, 300 );

   // set floating-point output formatting
   std::cout << fixed << setprecision( 2 );

   // get commission employee data
   std::cout << "Employee information obtained by get functions: \n"
             << "\nFirst name is " << employee.getFirstName()
             << "\nLast name is " << employee.getLastName()
             << "\nSocial security number is "
             << employee.getSocialSecurityNumber()
             << "\nGross sales is " << employee.getGrossSales()
             << "\nCommission rate is " << employee.getCommissionRate()
             << "\nBase salary is " << employee.getBaseSalary() << std::endl;

   employee.setBaseSalary( 1000 ); // set base salary

   std::cout << "\nUpdated employee information output by print function: \n"
        << std::endl;

   employee.print(); // display the new employee information

   // display the employee's earnings
   std::cout << "\n\nEmployee's earnings: $" << employee.earnings() << std::endl;
}

void miniAssignment()
{
    // TODO: create PhonePlanWithData object here (you may choose any constructor you wish)
    PhonePlanWithData plan1;
    PhonePlan plan2;

    // TODO: Call ALL member functions directly available to the object here
    //       (calling each one at least once)
    //       You may call some member functions more than once, if you wish
    //       Make sure to also call the base member functions.
    plan2.setRemainingMinutesInMonth(500);
    plan2.printStatus();
    plan2.useMinutes(8);
    std::cout<<"Minutes Remaining After Use: "<<plan2.getRemainingMinutesInMonth()<<std::endl<<std::endl;

    plan1.setRemainingMinutesInMonth(750);
    plan1.printStatus();
    plan1.useMinutes(22);
    std::cout<<"Minutes Remaining After Use: "<<plan1.getRemainingMinutesInMonth()<<std::endl<<std::endl;

    plan1.setRemainingDataInMonth(4);
    plan1.printStatus();
    plan1.useData(1.27);
    std::cout<<"Data Remaining After Use: "<<plan1.getRemainingDataInMonth()<<std::endl;

}

