//------------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: ArrayADT.cpp
// Description: Implementation of member function of ArrayADT class
//------------------------------------------------------------------------------

#include "ArrayADT.h"
#include <iostream>

// constructor
ArrayADT::ArrayADT(int length)
{
    m_arr = NULL;
    m_length = 0;
    resize(length); // allocate memory and set length
}


// copy constructor
ArrayADT::ArrayADT(const ArrayADT &arrayToCopyFrom)
{
    m_arr = NULL;
    m_length = 0;
    resize(arrayToCopyFrom.m_length);

    // copy elements
    for (int i = 0; i < m_length; i++)
    {
        m_arr[i] = arrayToCopyFrom.m_arr[i];
    }
}

// destructor
ArrayADT::~ArrayADT()
{
    if (m_arr != NULL)
    {
        delete [] m_arr;
        m_arr = NULL;
        m_length = 0;
    }
}

// assignment operator
const ArrayADT &ArrayADT::operator=(const ArrayADT &arrayOnRight)
{
    // avoid self-assignment
    if (&arrayOnRight != this)
    {
        // resize array, if necessary
        if (arrayOnRight.m_length != m_length)
        {
            resize(arrayOnRight.m_length);
        }

        // copy elements
        for (int i = 0; i < m_length; i++)
        {
            m_arr[i] = arrayOnRight.m_arr[i];
        }
    }

    return *this; // allows a1 = a2 = a3, for example
}

// resize array to given length (does not save old values)
void ArrayADT::resize(int length)
{
    if (length != m_length)
    {
        // deallocate any existing memory
        if (m_arr != NULL)
        {
            delete [] m_arr;
            m_arr = NULL;
        }

        // allocate new memory
        if (length > 0)
        {
            m_length = length;
            m_arr = new int[length];
        }
        else
        {
            m_length = 0;
        }
    }
}

// set array value at given index to given value
void ArrayADT::set(int index, int value)
{
    if (index >= 0 && index < m_length)
    {
        m_arr[index] = value;
    }
}

// set all elements to a given value
void ArrayADT::setAll(int value)
{
    for (int i=0; i < m_length; i++)
    {
        m_arr[i] = value;
    }
}


// returns length of the array
int ArrayADT::getLength() const
{
    return m_length;
}

// returns value of element at given index
int ArrayADT::get(int index) const
{
    if (index >= 0 && index < m_length)
    {
        return m_arr[index];
    }
    else
    {
        return 0;
    }
}

// print to standard output stream
void ArrayADT::print() const
{
    for (int i = 0; i < m_length; i++)
    {
        if ((i+1)%20 == 0)
        {
            std::cout << std::endl;
        }

        std::cout << m_arr[i] << " ";
    }

    std::cout << std::endl;
}
