//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: ComplexNumber.cpp
// Description: Implementation of member functions for ComplexNumber class
//-----------------------------------------------------------------------------
#include <cmath>
#include <iostream>
#include "ComplexNumber.h"

void ComplexNumber::setRealPart(double real)
{
    m_real = real;
}

void ComplexNumber::setImagPart(double imag)
{
    m_imag = imag;
}

void ComplexNumber::setRealImagPartsFromUser( )
{
    std::cout << "Please enter the real part of a complex number: ";
    std::cin >> m_real;
    std::cout << "Please enter the imaginary part of a complex number: ";
    std::cin >> m_imag;
}


double ComplexNumber::getRealPart( ) const
{
    return m_real;
}

double ComplexNumber::getImagPart( ) const
{
    return m_imag;
}

double ComplexNumber::getMagnitude( ) const
{
    return sqrt(m_real*m_real + m_imag*m_imag);
}

double ComplexNumber::getPhaseAngleInRadians( ) const
{
    return atan2(m_imag, m_real);
}

double ComplexNumber::getPhaseAngleInDegrees( ) const
{
    return atan2(m_imag, m_real)*45/atan(1);
}

void ComplexNumber::printInAllForms( ) const
{
    printInCartesianForm();
    printInPolarFormRadians();
    printInPolarFormDegrees();
}

void ComplexNumber::printInCartesianForm( ) const
{
    std::cout << m_real << " + j" << m_imag << std::endl;
}

void ComplexNumber::printInPolarFormRadians( ) const
{
    std::cout << "magnitude = " << getMagnitude() << ", angle = "
              << getPhaseAngleInRadians() << " radians" << std::endl;
}

void ComplexNumber::printInPolarFormDegrees( ) const
{
    std::cout << "magnitude = " << getMagnitude() << ", angle = "
              << getPhaseAngleInDegrees() << " degrees" << std::endl;
}

void ComplexNumber::addComplexNumber(const ComplexNumber &number)
{
    m_real += number.getRealPart();
    m_imag += number.getImagPart();
}

void ComplexNumber::multiplyComplexNumber(const ComplexNumber &number)
{
    double newMagnitude = getMagnitude()*number.getMagnitude();
    double newAngle = getPhaseAngleInRadians() + number.getPhaseAngleInRadians();

    setRealPart(newMagnitude*cos(newAngle));
    setImagPart(newMagnitude*sin(newAngle));
}
