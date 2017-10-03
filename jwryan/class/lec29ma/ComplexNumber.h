//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: ComplexNumber.h
// Description: Header file for ComplexNumber class. This class represents
//              a complex number.
//-----------------------------------------------------------------------------
#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

class ComplexNumber
{
public:
                    //-----------------------------
                    // GROUP: Data modification
                    //-----------------------------

    // sets the real part of the complex number
    void setRealPart(double real);
    // sets the imaginary part of the complex number
    void setImagPart(double imag);
    // sets real/imaginary parts by requesting them from the user
    void setRealImagPartsFromUser( );

                    //-----------------------------
                    // GROUP: Data accessors
                    //-----------------------------

    // returns the real part of the complex number
    double getRealPart( ) const;
    // returns the imaginary part of the complex number
    double getImagPart( ) const;
    // returns the magnitude of the complex number
    double getMagnitude( ) const;
    // returns the phase angle of the complex number (in radians)
    double getPhaseAngleInRadians( ) const;
    // returns the phase angle of the complex number (in degrees)
    double getPhaseAngleInDegrees( ) const;

                    //-----------------------------
                    // GROUP: Data display
                    //-----------------------------

    // prints complex number in all forms
    void printInAllForms( ) const;

    // prints complex number to standard output stream
    // in Cartesian form (i.e., a + jb)
    void printInCartesianForm( ) const;

    // prints complex number to standard output stream
    // in polar form, with the angle being in radians
    void printInPolarFormRadians( ) const;

    // prints complex number to standard output stream
    // in polar form, with the angle being in degrees
    void printInPolarFormDegrees( ) const;

                    //-----------------------------
                    // GROUP: Operations
                    //-----------------------------
    // modifies the complex number to reflect the addition of itself
    // and the given complex number
    void addComplexNumber(const ComplexNumber &number);

    // modifies the complex number to reflect the multiplication of itself
    // and the given complex number
    void multiplyComplexNumber(const ComplexNumber &number);


private:
    double m_real; // real part of complex number
    double m_imag; // imaginary part of complex number
};

#endif // COMPLEXNUMBER_H
