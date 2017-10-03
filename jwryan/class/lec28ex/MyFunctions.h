//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: MyFunctions.h
// Description: Header file containing function prototypes for custom
//              functions.
//-----------------------------------------------------------------------------
#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

//-----------------------------------------------------------------------------
// Function: getMaximum
// Description: returns the maximum of two input integers
// Input: a = integer = first integer
//        b = integer = second integer
// Output: integer = maximum of a and b
//-----------------------------------------------------------------------------
int getMaximum(int a, int b);

//-----------------------------------------------------------------------------
// Function: getMaximum
// Description: returns the maximum of two input doubles
// Input: a = double = first double
//        b = double = second double
// Output: double = maximum of a and b
//-----------------------------------------------------------------------------
double getMaximum(double a, double b);

//-----------------------------------------------------------------------------
// Function: square
// Description: computes/returns square of input float
// Input: x = float = input value
// Output: float = square of input float
//-----------------------------------------------------------------------------
float square(float x);

//-----------------------------------------------------------------------------
// Function: square
// Description: computes/returns square of input integer
// Input: x = integer = input value
// Output: integer = square of input integer
//-----------------------------------------------------------------------------
int square(int x);

//-----------------------------------------------------------------------------
// Function: squareByReference
// Description: computes the square of an input integer using pass by reference
// Input: x = integer = input value
// Output: x = square of input value
//-----------------------------------------------------------------------------
void squareByReference(int &x);

//-----------------------------------------------------------------------------
// Function: squareBySimulatedReference
// Description: computes the square of an input integer using pass by simulated
//              reference
// Input: x = pointer to integer = pointer to input value
// Output: x = pointer to integer = pointer to resulting squared value
//-----------------------------------------------------------------------------
void squareBySimulatedReference(int *x);

//-----------------------------------------------------------------------------
// Function: distanceFromOrigin
// Description: computes the distance of the input point (x,y,z) from (0,0,0)
// Input: x = double = x position of point
//        y = double = y position of point (default value = 0)
//        z = double = z position of point (default value = 0)
// Output: double = computed Euclidean distance
//-----------------------------------------------------------------------------
double distanceFromOrigin(double x, double y = 0, double z = 0);

#endif // MYFUNCTIONS_H
