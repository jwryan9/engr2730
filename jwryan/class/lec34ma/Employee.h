//-----------------------------------------------------------------------------
// Name: Employee.h
// Description: Header file for Employee class. This class represents an
//              employee with a first name, last name, birth date, and hire
//              date. It is based on Fig. 18.12 on page 648 in the 6th edition
//              of the book.
//-----------------------------------------------------------------------------
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h" // include Date class definition

class Employee
{
public:
    Employee( const std::string &first, const std::string &last,
              const Date &dateOfBirth, const Date &dateOfHire );
    void print() const;
    ~Employee(); // provided to confirm destruction order
private:
    std::string firstName; // composition: member object
    std::string lastName; // composition: member object
    const Date birthDate; // composition: member object
    const Date hireDate; // composition: member object
};

#endif
