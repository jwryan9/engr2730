//-----------------------------------------------------------------------------
// Programmer: TODO: Jason Ryan
// Name: main.cpp
// Description: This program contains in-class examples and the mini-assignment
//              associated with lecture 34 (on composition and constant
//              data members)
// Building from the command line (on linux):
//            g++ main.cpp Date.cpp Employee.cpp Homework.cpp -o main.exe
// For the mini-assignment, you must define a Homework class that at least
// contains a due date and the total number of points as private (and constant)
// data members. You must also include a constructor that uses the member
// initializer syntax to initialize the constant data members. A member
// function to print the due date and total number of points must also be
// included.
// The class definition must be added to the Homework.h file and the member
// function definitions must be added to the Homework.cpp file.
// You must create an object of this class within the miniAssignment function
// and call the object's print member function.
//-----------------------------------------------------------------------------
#include <iostream>
#include "Date.h"
#include "Employee.h"
#include "Homework.h"
using namespace std;

void codeFromFig18_14();
void miniAssignment();

int main()
{
    std::cout << "------------------------" << std::endl;
    std::cout << "Example from Fig. 18.14:" << std::endl;
    std::cout << "------------------------" << std::endl;
    codeFromFig18_14();

    std::cout << "-----------------" << std::endl;
    std::cout << "miniAssignment():" << std::endl;
    std::cout << "-----------------" << std::endl;
    miniAssignment();

    return 0;
}

// function from main program of Fig 18.14 in 6th edition of book
void codeFromFig18_14()
{
    Date birth( 7, 24, 1949 );
    Date hire( 3, 12, 1988 );
    Employee manager( "Bob", "Blue", birth, hire );

    std::cout << std::endl;
    manager.print();

    std::cout << "\nTest Date constructor with invalid values:\n";
    Date lastDayOff( 14, 35, 1994 ); // invalid month and day

    std::cout << std::endl;
}

void miniAssignment()
{
    // create a Date object here for when homework is due
    Date dueDate(4, 21, 2016);


    // create a Homework object here, passing Date object above to constructor
    // TOOD: your code here
    Homework hw(dueDate, 50);

    // call the Homework object's print function here
    // TODO: your code here
    hw.print();

}
