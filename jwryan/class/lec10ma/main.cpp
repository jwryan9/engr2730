/*---------------------------------------------------------------
 * Programmer: Jason Ryan
 * Name: main.cpp
 * Description: This file contains the implementation of the
 *              mini-assignment associated with lecture 10.
 *              The program must:
 *              - contain/call a function that uses simulated
 *                pass-by-reference to modify the value of two
 *                input integers
 *              - contain/call a function that modifies an
 *                input array, but so that the input parameter
 *                is declared using a pointer
 ---------------------------------------------------------------*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void addOneToEach(int *num1, int *num2);
void setAll(int *arr, int arrSize, int newValue);

int main( void )
{
    int num1 = 1;
    int num2 = 2;

    addOneToEach(&num1, &num2);

    int arr[] = {1, 2, 3};
    int arrSize = 3;
    int newVal = 5;

    setAll(arr, arrSize, newVal);

    return 0;
}

void addOneToEach(int *num1, int *num2)
{
    *num1 = *num1 + 1;
    *num2 = *num2 + 1;
}

void setAll(int *arr, int arrSize, int newValue)
{
    int i;

    for(i=0; i<arrSize; i++)
        arr[i] = newValue;
}
