
//--------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: main.cpp
// Description: This program contains in-class examples and the
//              mini-assignment associated with lecture 36 (dynamic
//              memory allocation within classes)
// Building from command line (on linux):
//   g++ main.cpp Stack1.cpp Stack2.cpp StackFunctions.cpp -o main.exe
//---------------------------------------------------------------------
#include <iostream>
#include "Stack1.h"
#include "Stack2.h"
using namespace std;

int main()
{
    // to complete the mini-assignment, comment out lines
    // declaring Stack1 objects and uncomment lines
    // declaring Stack2 objects

    //Stack1 myStackA, myStackB; // use of default constructor
    Stack2 myStackA, myStackB; // use of default constructor
    myStackA.push(0);
    myStackA.push(1);
    myStackB = myStackA; // use of assignment operator
    myStackB.push(2);
    myStackB.push(3);

    //Stack1 myStackC(myStackB); // use of copy constructor
    Stack2 myStackC(myStackB); // use of copy constructor
    myStackC.push(4);

    // pop/print items from each stack:
    std::cout << "myStackA: ";
    while (! myStackA.empty())
    {
        std::cout << myStackA.pop() << " ";
    }
    std::cout << std::endl;

    std::cout << "myStackB: ";
    while (! myStackB.empty())
    {
        std::cout << myStackB.pop() << " ";
    }
    std::cout << std::endl;

    std::cout << "myStackC: ";
    while (! myStackC.empty())
    {
        std::cout << myStackC.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}
