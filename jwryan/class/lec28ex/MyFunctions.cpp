//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: MyFunctions.cpp
// Description: This file contains the function definitions of the function
//              prototypes in MyFunctions.h
//-----------------------------------------------------------------------------
#include <cmath>
#include "MyFunctions.h"

// function to return maximum of two input integers
int getMaximum(int a, int b)
{
    int maxValue = a;

    if (b > a)
    {
        maxValue = b;
    }

    return maxValue;
}

// function to return maximum of two input doubles
double getMaximum(double a, double b)
{
    double maxValue = a;

    if (b > a)
    {
        maxValue = b;
    }

    return maxValue;
}

// function to compute square of input float
float square(float x)
{
    return x*x;
}

// function to compute square of input integer
int square(int x)
{
    // note: using strange syntax to better allow comparison with
    // pass-by-reference functions
    x = x*x;
    return x;
}

// function to compute square of input integer by reference
void squareByReference(int &x)
{
    x = x*x;
}

// function to compute square of input integer by simulated
// reference
void squareBySimulatedReference(int *x)
{
    *x = *x * *x;
}

// function to compute distance of input point from (0,0,0)
double distanceFromOrigin(double x, double y, double z)
{
    return sqrt(x*x + y*y + z*z);
}
