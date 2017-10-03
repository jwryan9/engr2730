//-----------------------------------------------------------------------------
// Programmer: TODO: Jason Ryan
// Name: Homework.cpp
// Description: Implementation of member functions for Homework class
//-----------------------------------------------------------------------------
#include <iostream>
#include "Homework.h" // Homework class definition
#include "Date.h" // Date class definition

// TODO (if not already defined in .h file): add definition of
// constructor here, making sure to use a member initializer list
// syntax to initialize the due date and the number of points
Homework::Homework(Date &due, int pts):
dueDate(due), points(pts)
{}


// TODO: add definition of print function here
void Homework::print() const
{
    std::cout<<"Due date: ";
    dueDate.print();
    std::cout<<std::endl;

    std::cout<<"Points: "<<points<<std::endl;
}
