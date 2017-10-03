//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: ComplexStruct.cpp
// Description: Implementation of example functions associated with using
//              complex numbers (represented as a struct complex).
//-----------------------------------------------------------------------------
#include <cmath>
#include <iostream>
#include "ComplexStruct.h"

double getMagnitudeOfComplexStruct(ComplexStruct c)
{
    return sqrt(c.real*c.real + c.imag*c.imag);
}

double getPhaseAngleOfComplexStructInRadians(ComplexStruct c)
{
     return atan2(c.imag, c.real);
}

double getPhaseAngleOfComplexStructInDegrees(ComplexStruct c)
{
    return atan2(c.imag, c.real)*45/atan(1);
}

void printComplexStructInCartesianForm(ComplexStruct c)
{
    std::cout << c.real << " + j" << c.imag << std::endl;
}

void printComplexStructInPolarFormRadians(ComplexStruct c)
{
    std::cout << "magnitude = " << getMagnitudeOfComplexStruct(c) << ", angle = "
              << getPhaseAngleOfComplexStructInRadians(c) << " radians" << std::endl;
}

void printComplexStructInPolarFormDegrees(ComplexStruct c)
{
    std::cout << "magnitude = " << getMagnitudeOfComplexStruct(c) << ", angle = "
              << getPhaseAngleOfComplexStructInDegrees(c) << " degrees" << std::endl;
}
