//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: ComplexStruct.h
// Description: This file contains a structure definition for a complex 
//              number and some function prototypes for working with
//              complex numbers.
//-----------------------------------------------------------------------------
#ifndef COMPLEXSTRUCT_H
#define COMPLEXSTRUCT_H

// struct complex represents a complex number
struct complex {
    double real; // real part
    double imag; // imaginary part
};

typedef struct complex ComplexStruct;

// returns magnitude of given complex number
double getMagnitudeOfComplexStruct(ComplexStruct c);
// returns phase angle (in radians) of given complex number
double getPhaseAngleOfComplexStructInRadians(ComplexStruct c);
// returns phase angle (in degrees) of given complex number
double getPhaseAngleOfComplexStructInDegrees(ComplexStruct c);

// prints the cartesian form of the given complex number to
// the standard output stream
void printComplexStructInCartesianForm(ComplexStruct c);
// prints the polar form of the given complex number to
// the standard output stream (angle in radians)
void printComplexStructInPolarFormRadians(ComplexStruct c);
// prints the polar form of the given complex number to
// the standard output stream (angle in degrees)
void printComplexStructInPolarFormDegrees(ComplexStruct c);

#endif // COMPLEXSTRUCT_H
