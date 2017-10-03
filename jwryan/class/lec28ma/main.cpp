//-----------------------------------------------------------------------------
// Programmer: Jason Ryan
// Name: main.cpp
// Description: This program contains the mini-assignment associated with
//              lecture 28 on procedural programming using C++.
// Building from command line (on linux):
//              g++ main.cpp -o main.exe -lm
// For the mini-assignment, you must:
// 1. Write a function of your choice that uses true pass by reference.
// 2. Write a different function of your choice that has at least one parameter
//    with a default argument.
// 3. Within main(), write code to use std::cout, std::cin, and call the
//    functions you created above.
//-----------------------------------------------------------------------------
#include <iostream> // include standard input/output library header
#include <cmath>    // include math library header

// TODO: write your function prototypes here
void squareByReference(int &x);
int addInts(int x, int y=4);

using namespace std;

int main()
{
    // TODO: write your code here to use std::cout, std::cin, and
    //       to call your functions
    int x = 5;
    cout<<"x = "<<x<<", x^2 = ";
    squareByReference(x);
    cout<<x<<endl;

    cout<<"x+y = "<<addInts(x)<<endl;
    cout<<"x+7 = "<<addInts(x, 7)<<endl;


    return 0; // In C++, the return is optional
}

// TODO: write your function definitions here
void squareByReference(int &x)
{
    x = x*x;
}

int addInts(int x, int y)
{
    return x+y;
}
