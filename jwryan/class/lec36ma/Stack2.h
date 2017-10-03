//------------------------------------------------------------------------
// Programmer: Jason Ryan
// Name: Stack2.h
// Description: Header file for Stack2 class. Stack2 represents a stack
//              of integers using a linked list as the underlying data
//              representation.
//-------------------------------------------------------------------------
#ifndef STACK2_H
#define STACK2_H

#include "StackFunctions.h"

// TODO: YOUR CODE HERE
class Stack2 {
public:
    Stack2(){m_topPtr = NULL;};
    Stack2(const Stack2 &stackToCopyFrom);
    ~Stack2();
    const Stack2 & operator=(const Stack2 &stackOnRight);
    void push(int value);
    int pop();
    bool empty() const;
private:
    NodePtr m_topPtr;
};

#endif // STACK2_H
