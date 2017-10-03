//-----------------------------------------------------------------------------
// Programmer: TODO: Jason Ryan
// Name: main.cpp
// Description: This program contains in-class examples and the mini-assignment
//              associated with lecture 29 (an introduction to object-
//              oriented programming).
// Building from command line (on linux):
//            g++ main.cpp ComplexNumber.cpp ComplexStruct.cpp -o main.exe -lm
// For the mini-assignment, you must complete the miniAssignment function by
// adding the appropriate line(s) of code under each comment.
//-----------------------------------------------------------------------------
#include <iostream> // include standard input/output library header
#include <cmath>    // include math library header

#include "ComplexStruct.h" // include definition of complex struct
#include "ComplexNumber.h" // include complex number class
using namespace std;

void complexExample1a();
void complexExample1b();
void complexExample2();

void miniAssignment();

int main()
{
    std::cout << "********************" << std::endl;
    std::cout << " COMPLEX EXAMPLE 1A " << std::endl;
    std::cout << "********************" << std::endl;
    complexExample1a();

    std::cout << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << " COMPLEX EXAMPLE 1B " << std::endl;
    std::cout << "********************" << std::endl;
    complexExample1b();

    std::cout << std::endl;
    std::cout << "*******************" << std::endl;
    std::cout << " COMPLEX EXAMPLE 2 " << std::endl;
    std::cout << "*******************" << std::endl;
    complexExample2();

    std::cout << std::endl;
    std::cout << "*****************" << std::endl;
    std::cout << " MINI-ASSIGNMENT " << std::endl;
    std::cout << "*****************" << std::endl;
    miniAssignment();

    return 0;
}

void complexExample1a()
{
    // create variable of type struct complex
    ComplexStruct c1;
    c1.real = 3;
    c1.imag = 4;

    // print different forms of this complex number
    printComplexStructInCartesianForm(c1);
    printComplexStructInPolarFormRadians(c1);
    printComplexStructInPolarFormDegrees(c1);
}

void complexExample1b()
{
    // create ComplexNumber object
    ComplexNumber c1;
    c1.setRealPart(3);
    c1.setImagPart(4);

    // print different forms of this complex number
    c1.printInCartesianForm();
    c1.printInPolarFormRadians();
    c1.printInPolarFormDegrees();
}

void complexExample2()
{
    // create ComplexNumber object 1
    std::cout << "---------------------------" << std::endl;
    std::cout << "Creating complex number c1:" << std::endl;
    std::cout << "---------------------------" << std::endl;
    ComplexNumber c1;
    // obtain real and imaginary parts of the first complex number from user
    c1.setRealImagPartsFromUser();
    // print in all forms
    c1.printInAllForms();

    // create ComplexNumber object 2
    std::cout << "---------------------------" << std::endl;
    std::cout << "Creating complex number c2:" << std::endl;
    std::cout << "---------------------------" << std::endl;
    ComplexNumber c2;
    // obtain real and imaginary parts of the second complex number from user
    c2.setRealImagPartsFromUser();
    // print in all forms
    c2.printInAllForms();

    // create ComplexNumber object 3
    std::cout << "---------------------------" << std::endl;
    std::cout << "Creating complex number c3:" << std::endl;
    std::cout << "---------------------------" << std::endl;
    ComplexNumber c3;
    // obtain real and imaginary parts of the second complex number from user
    c3.setRealImagPartsFromUser();
    // print in all forms
    c3.printInAllForms();

    std::cout << "-------------" << std::endl;
    std::cout << "c1 = c1 + c2:" << std::endl;
    std::cout << "-------------" << std::endl;
    c1.addComplexNumber(c2);
    c1.printInAllForms();

    std::cout << "-----------" << std::endl;
    std::cout << "c2 = c2*c3:" << std::endl;
    std::cout << "-----------" << std::endl;
    c2.multiplyComplexNumber(c3);
    c2.printInAllForms();
}

void miniAssignment()
{
    // create a ComplexNumber object named c1 representing 2 + j7
    ComplexNumber c1, c2;
    c1.setRealPart(2);
    c1.setImagPart(7);

    // print "all forms" of this complex number
    c1.printInAllForms();

    // create a ComplexNumber object named c2 representing 5 + j8
    c2.setRealPart(5);
    c2.setImagPart(8);

    // print "all forms" of this complex number
    c2.printInAllForms();

    // modify c2 so that it equals c2+c1
    c2.setRealPart(c2.getRealPart() + c1.getRealPart());
    c2.setImagPart(c2.getImagPart() + c1.getImagPart());

    // print "all forms" of the new version of c2
    c2.printInAllForms();

}
