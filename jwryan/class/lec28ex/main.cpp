//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: main.cpp
// Description: This program contains in-class examples associated with 
//              lecture 28 on procedural programming using C++.
// Building from command line (on linux):
//              g++ main.cpp MyFunctions.cpp -o main.exe -lm
//-----------------------------------------------------------------------------
#include <iostream> // include standard input/output library header
#include <cmath>    // include math library header

#include "MyFunctions.h" // include custom function header

// additional function prototypes (not included as part of header files):
void functionOverloadingExample();
void passByReferenceExample();
void clickerQuestion();
int clickerQuestionHelper(int a, int &b, int c=1);
void defaultArgumentExample();

int main()
{
    // print a message to the standard output stream
    std::cout << "-------------------" << std::endl;
    std::cout << "Example C++ Program" << std::endl;
    std::cout << "-------------------" << std::endl;

    // request that the user enter two numbers
    std::cout << "Please enter two floating point numbers: ";

    // read values from standard input stream
    float a, b;
    std::cin >> a >> b;

    // use standard math library function and custom function
    std::cout << "Using a math library function, ceil(" << a << ") = "
              << ceil(a) << std::endl;
    std::cout << "Using a custom function, square(" << b << ") = "<< square(b) << std::endl;

    // call function to illustrate function overloading
    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Function overloading" << std::endl;
    std::cout << "--------------------" << std::endl;
    functionOverloadingExample();

    // call function to illustrate using pass-by-reference functions
    std::cout << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "Pass-by-reference" << std::endl;
    std::cout << "-----------------" << std::endl;
    passByReferenceExample();

    // call function to illustrate using a function that has a default argument
    std::cout << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "Default arguments" << std::endl;
    std::cout << "-----------------" << std::endl;
    defaultArgumentExample();

    // call clicker question function
    std::cout << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "Clicker question" << std::endl;
    std::cout << "----------------" << std::endl;
    clickerQuestion();

    return 0; // In C++, the return is optional
}

void functionOverloadingExample()
{
    // use two different getMaximum functions
    // 1. integer version
    std::cout << "getMaximum(4, 5) = " << getMaximum(4, 5) << std::endl;
    // 2. double version
    std::cout << "getMaximum(2.3, 4.5) = " << getMaximum(2.3, 4.5) << std::endl;
}

void passByReferenceExample()
{
    int r1, arg1, arg2, arg3;
    arg1 = 5;
    arg2 = 5;
    arg3 = 5;

    // pass-by-value
    std::cout << "arg1 before pass-by-value function call: " << arg1 << std::endl;
    r1 = square(arg1);
    std::cout << "returned value from function call: " << r1 << std::endl;
    std::cout << "arg1 after pass-by-value function call: " << arg1 << std::endl;
    std::cout << std::endl;

    // pass-by-reference
    std::cout << "arg2 before pass-by-reference function call: " << arg2 << std::endl;
    squareByReference(arg2);
    std::cout << "arg2 after pass-by-reference function call: " << arg2 << std::endl;
    std::cout << std::endl;

    // pass-by-simulated reference
    std::cout << "arg3 before pass-by-simulated-reference function call: " << arg3 << std::endl;
    squareBySimulatedReference(&arg3);
    std::cout << "arg3 after pass-by-simulated-reference function call: " << arg3 << std::endl;
}

void defaultArgumentExample()
{
    // 2D case: take advantage of default argument
    std::cout << "distanceFromOrigin(1.0, 2.0) = " << distanceFromOrigin(1.0, 2.0) << std::endl;

    // 3D case: specify all parameters
    std::cout << "distanceFromOrigin(1.0, 2.0, 3.0) = " << distanceFromOrigin(1.0, 2.0, 3.0) << std::endl;
}

void clickerQuestion()
{
    int x = 2;
    int y = 2;

    int z = clickerQuestionHelper(x,y);

    //std::cout << "x = " << x << std::endl;
    //std::cout << "y = " << y << std::endl;
    //std::cout << "z = " << z << std::endl;
}

int clickerQuestionHelper(int a, int &b, int c)
{
    a = a + 1;
    b = b + 1;
    c = c + 1;
    return a + b + c;
}
