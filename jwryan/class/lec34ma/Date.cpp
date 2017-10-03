//-----------------------------------------------------------------------------
// Name: Date.cpp
// Description: Implementation of member functions for Date class (based on
//              Fig. 18.11 on pages 646-647 in the 6th edition of the book)
//-----------------------------------------------------------------------------

#include <iostream>
#include "Date.h" // include Date class definition

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date( int mn, int dy, int yr )
{
   if ( mn > 0 && mn <= monthsPerYear ) // validate the month
     month = mn;
   else
   {
      month = 1; // invalid month set to 1
      std::cout << "Invalid month (" << mn << ") set to 1.\n";
   } // end else

   year = yr; // could validate yr
   day = checkDay( dy ); // validate the day

   // output Date object to show when its constructor is called
   std::cout << "Date object constructor for date ";
   print();
   std::cout << std::endl;
} // end Date constructor

// print Date object in form month/day/year
void Date::print() const
{
   std::cout << month << '/' << day << '/' << year;
} // end function print

// output Date object to show when its destructor is called
Date::~Date()
{
   std::cout << "Date object destructor for date ";
   print();
   std::cout << std::endl;
} // end ~Date destructor

// utility function to confirm proper day value based on
// month and year; handles leap years, too
int Date::checkDay( int testDay ) const
{
   static const int daysPerMonth[ monthsPerYear + 1 ] =
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   // determine whether testDay is valid for specified month
   if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
      return testDay;

   // February 29 check for leap year
   if ( month == 2 && testDay == 29 && ( year % 400 == 0 ||
      ( year % 4 == 0 && year % 100 != 0 ) ) )
      return testDay;

   std::cout << "Invalid day (" << testDay << ") set to 1.\n";

   return 1; // leave object in consistent state if bad value
} // end function checkDay

