//-----------------------------------------------------------------------------
// Name: Employee.cpp
// Description: Implementation of member functions for Employee class (based on
//              Fig. 18.13 on pages 648-649 in the 6th edition of the book)
//-----------------------------------------------------------------------------
#include <iostream>
#include "Employee.h" // Employee class definition
#include "Date.h" // Date class definition

// constructor uses member initializer list to pass initializer
// values to constructors of member objects
Employee::Employee( const std::string &first, const std::string &last,
   const Date &dateOfBirth, const Date &dateOfHire )
   : firstName( first ), // initialize firstName
     lastName( last ), // initialize lastName
     birthDate( dateOfBirth ), // initialize birthDate
     hireDate( dateOfHire ) // initialize hireDate
{
   // output Employee object to show when constructor is called
   std::cout << "Employee object constructor: "
      << firstName << ' ' << lastName << std::endl;
} // end Employee constructor

// print Employee object
void Employee::print() const
{
   std::cout << lastName << ", " << firstName << "  Hired: ";
   hireDate.print();
   std::cout << "  Birthday: ";
   birthDate.print();
   std::cout << std::endl;
} // end function print

// output Employee object to show when its destructor is called
Employee::~Employee()
{
   std::cout << "Employee object destructor: "
      << lastName << ", " << firstName << std::endl;
} // end ~Employee destructor
