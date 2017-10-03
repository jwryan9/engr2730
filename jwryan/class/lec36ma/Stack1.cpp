//---------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: Stack1.cpp
// Description: Implementation of member functions of the Stack1 class
//----------------------------------------------------------------------

#include "Stack1.h"
#include <deque>

// push given value onto stack
void Stack1::push(int value)
{
    m_deque.push_front(value);
}

// if stack is not empty, removes and returns the
// top value from stack; otherwise, returns 0
int Stack1::pop()
{
    int topValue = 0;
    if (!m_deque.empty())
    {
        topValue = m_deque.front();
        m_deque.pop_front();
    }

    return topValue;
}

// returns true if the stack is empty and false
// otherwise
bool Stack1::empty() const
{
    return m_deque.empty();
}
