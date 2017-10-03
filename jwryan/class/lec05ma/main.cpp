/*-----------------------------------------------------------------------------
 * Programmer: Jason Ryan
 * Name: main.cpp
 * Description: This file contains the mini-assignment for lecture 5.
 *              You are required to finish the implementation
 *              of two functions (one to return the maximum of three
 *              floats and one to return the minimum of three floats):
 *              1. float obtainMax(float a, float b, float c);
 *                 -> returns the maximum of the three given floats
 *              2. float obtainMin(float a, float b, float c);
 *                 -> returns the minimum of the three given floats
 *              In addition, you may optionally choose to finish the
 *              implementation of the following function which uses
 *              simulated pass-by-reference to return the minimum
 *              and maximum of three floats:
 *              3. void obtainMinMax(float a, float b, float c,
 *                                   float *minPtr, float *maxPtr);
 *                 -> returns (using simulated pass-by-reference) the
 *                    minimum and maximum
 * MOST OF THE CODE HAS BEEN WRITTEN FOR YOU, BUT YOU NEED TO PUT YOUR
 * NAME ABOVE AND FILL IN THE PORTIONS WHERE THERE IS A COMMENT THAT
 * SAYS "YOUR CODE HERE"
 ----------------------------------------------------------------------------*/
#include <iostream>
#include <stdlib.h>
using namespace std;

/* function prototypes */
float obtainMin(float a, float b, float c);
float obtainMax(float a, float b, float c);
void obtainMinMax(float a, float b, float c, float *minPtr, float *maxPtr);

int main( void )
{
    float x, y, z;              /* input floats */
    float minByVal, maxByVal;   /* minimum and maximum values resulting from pass-by-value functions */
    float minByRef, maxByRef;   /* minimum and maximum values resulting from pass-by-simulated-reference function */

    /* obtain three floating point numbers from the user */
    cout << "Please enter three floating point numbers: ";
    cin >> x >> y >> z;

    /* obtain minimum and maximum using pass-by-value functions */
    minByVal = obtainMin(x, y, z);
    maxByVal = obtainMax(x, y, z);
    cout << "The determined minimum and maximum using pass-by-value functions:" << endl ;
    cout << "    min: " << minByVal << endl;
    cout << "    max: " << maxByVal << endl;

    /* obtain minimum and maximum using pass-by-simulated-reference function */
    obtainMinMax(x, y, z, &minByRef, &maxByRef);
    cout << "The determined minimum and maximum using the pass-by-simulated-reference function:" << endl ;
    cout << "    min: " << minByRef << endl;
    cout << "    max: " << maxByRef << endl;

    return EXIT_SUCCESS; /* like return 0; */
}

/*-----------------------------------------------------------------------------
 * Function name: obtainMin (REQUIRED FOR THIS MA)
 * Description: This function returns the minimum number from a set of three
 *              input numbers
 * Inputs: a = float = first input number
 *         b = float = second input number
 *         c = float = third input number
 * Output: the minimum of the three numbers as a float
 ----------------------------------------------------------------------------*/
float obtainMin(float a, float b, float c)
{
    float minVal = a;

    if (b < minVal)
    {
        minVal = b;
    }

    if (c < minVal)
    {
        minVal = c;
    }

    return minVal;
}

/*-----------------------------------------------------------------------------
 * Function name: obtainMax (REQUIRED FOR THIS MA)
 * Description: This function returns the maximum number from a set of three
 *              input numbers
 * Inputs: a = float = first input number
 *         b = float = second input number
 *         c = float = third input number
 * Output: the maximum of the three numbers as a float
 ----------------------------------------------------------------------------*/
float obtainMax(float a, float b, float c)
{
    float maxVal = a;

    if (b > maxVal)
    {
        maxVal = b;
    }

    if (c > maxVal)
    {
        maxVal = c;
    }

    return maxVal;
}

/*-----------------------------------------------------------------------------
 * Function name: obtainMinMax (NOT REQUIRED FOR THIS MA)
 * Description: This function uses simulated pass-by-reference to return
 *              the minimum and maximum of the three input numbers.
 * Inputs: a = float = first input number
 *         b = float = second input number
 *         c = float = third input number
 * Outputs: minPtr = pointer to float = address of the resulting minimum
 *          maxPtr = pointer to float = address of the resulting maximum
 * Hints: 1. Within this function, you may call the functions obtainMin
 *        and obtainMax as defined above (if you would like)
 *        2. Recall that since minPtr and maxPtr are declared as pointers to
 *        floats, you need to dereference the pointer when you want
 *        to set the values or use them in an expression. For example, to
 *        set the minimum value as 0, you would use the syntax:
 *        *minPtr = 0;
 *        Also see section 7.4 for further examples. We will review
 *        these concepts more later, but if you do not remember anything
 *        about pointers at this point, just think about *minVal being your
 *        'variable' to store the minimum and *maxVal being your 'variable'
 *        to store the maximum.
 ----------------------------------------------------------------------------*/
void obtainMinMax(float a, float b, float c, float *minPtr, float *maxPtr)
{
    *minPtr = obtainMin(a, b, c);
    *maxPtr = obtainMax(a, b, c);
}
