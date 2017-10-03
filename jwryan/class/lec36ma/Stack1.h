//------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: Stack1.h
// Description: Header file for Stack1 class. Stack1 represents a stack
//              of integers using a std::deque<int> as the underlying data
//              representation.
//-------------------------------------------------------------------------
#ifndef STACK1_H
#define STACK1_H

#include <deque>

class Stack1 {
public:

    // default constructor, (automatic) copy constructor,
    // (automatic) assignment operator, and empty destructor
    // are okay for Stack1

    // push given value onto stack
    void push(int value);

    // if stack is not empty, removes and returns the
    // top value from stack; otherwise, returns 0
    int pop();

    // returns true if the stack is empty and false
    // otherwise
    bool empty() const;

private:
    std::deque<int> m_deque;
};

#endif // STACK1_H
