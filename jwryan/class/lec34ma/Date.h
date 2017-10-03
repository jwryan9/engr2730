//-----------------------------------------------------------------------------
// Name: Date.h
// Description: Header file for Date class. This class represents a date
//              (day, month, year). It is based on Fig. 18.10 on page 646 in
//              the 6th edition of the book.
//-----------------------------------------------------------------------------
#ifndef DATE_H
#define DATE_H

class Date
{
public:
    static const int monthsPerYear = 12; // number of months in a year
    Date (int mn = 1, int dy = 1, int yr = 1900); // constructors
    void print() const; // print date in month/day/year format
    ~Date(); // destructor provided to confirm destruction order
private:
    int month; // 1-12 (January-December)
    int day; // 1-31 based on month
    int year; // any year

    // utility function to check if day is proper for month and year
    int checkDay( int testDay ) const;
};

#endif
