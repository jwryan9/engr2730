//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: ArrayADT.h
// Description: Header file for ArrayADT class. ArrayADT represents an array
//              that knows its length.
//-----------------------------------------------------------------------------
#ifndef ARRAYADT_H
#define ARRAYADT_H

class ArrayADT {
public:
            //--------------------------------------
            // GROUP: Construction/destruction/copy
            //--------------------------------------
    // constructor and default constructor
    ArrayADT(int length = 0);

    // copy constructor
    ArrayADT(const ArrayADT &arrayToCopyFrom);

    // destructor
    ~ArrayADT();

    // assignment operator
    const ArrayADT &operator=(const ArrayADT &arrayOnRight);

            //--------------------------------------
            // GROUP: Modification
            //--------------------------------------
    // resize array to given length (does not save old values)
    void resize(int length);

    // set array value at given index to given value
    void set(int index, int value);

    // set all elements to a given value
    void setAll(int value);

            //--------------------------------------
            // GROUP: Data accessors
            //--------------------------------------
    // returns length of the array
    int getLength() const;

    // returns value of element at given index
    // (if out-of-bounds, zero is returned)
    int get(int index) const;

            //--------------------------------------
            // GROUP: Print
            //--------------------------------------
    // print to standard output stream
    void print() const;

private:
    int m_length; // length of array
    int *m_arr;   // dynamically allocated array
};

#endif // ARRAYADT_H
