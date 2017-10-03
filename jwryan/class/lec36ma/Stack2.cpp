//----------------------------------------------------------------------
// Programmer: Jason Ryan
// Name: Stack2.cpp
// Description: Implementation of member functions of the Stack2 class
//----------------------------------------------------------------------

#include "Stack2.h"
#include "StackFunctions.h"

// TODO: YOUR CODE HERE

Stack2::Stack2(const Stack2 &stackToCopyFrom)
{
    m_topPtr = stack_copy(stackToCopyFrom.m_topPtr);
}

Stack2::~Stack2()
{
    stack_delete_all(&m_topPtr);
}

const Stack2 & Stack2::operator=(const Stack2 &stackOnRight)
{
    if(&stackOnRight != this)
    {
        //release old memory
        stack_delete_all(&m_topPtr);

        //create copy
        m_topPtr = stack_copy(stackOnRight.m_topPtr);
    }

    return *this; //allows s1=s2=s3, for example
}

void Stack2::push(int value)
{
    stack_push(&m_topPtr, value);
}

int Stack2::pop()
{
    return stack_pop(&m_topPtr);
}

bool Stack2::empty() const
{
    return (m_topPtr == NULL);
}
