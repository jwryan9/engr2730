//-----------------------------------------------------------------------------
// Programmer: TODO: Jason Ryan
// Name: Homework.h
// Description: Header file for Homework class. This class represents a
//              homework assignment with a due date and the number of points
//              the homework assignment is worth.
//-----------------------------------------------------------------------------
#ifndef HOMEWORK_H
#define HOMEWORK_H

#include "Date.h" // include Date class definition

class Homework
{
public:
    // TODO: include prototype for constructor(s) here
    // you may optionally choose to define the function here as well
    // if you do, make sure to use a member initializer syntax
    // if you do not, make sure to define it within the Homework.cpp file
    Homework(Date &dueDate, int points);

    // (YOU ARE NOT REQUIRED TO DEFINE A DESTRUCTOR)

    // TODO: include prototype for print member function here
    void print() const;

    // (YOU MAY OPTIONALLY DEFINE OTHER MEMBER FUNCTIONS FOR PRACTICE)
private:
    // TODO: add data member for due date (make const)
    const Date dueDate;

    // TODO: add data member for total number of points assignment is worth
    //       (make const)
    const int points;

};

#endif
