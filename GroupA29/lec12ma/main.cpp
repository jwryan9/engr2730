/*-----------------------------------------------------------------------------
 * Programmer: Jason Ryan, Kyle Anderson
 * Name: main.cpp
 * Description: A program to sort a number of integers
 *              and display the median value.
 *              For the mini-assignment, you must complete the implementation
 *              of the sort_array function to sort an input array using
 *              insertion sort.
 ----------------------------------------------------------------------------*/
#include <iostream>
#include <stdlib.h>
#include <string.h> /* for string functions */
#include <ctype.h>  /* for islower and toupper */

#include "insertionSort.h"

using namespace std;

int main(void)
{
 	unsigned int readings[11] = {250,210,190,220,230,85,95,115,140,200,105};
    cout << "Initial Array: " ;
    for (int i=0; i<11; i++) {
		cout << readings[i]<< " ";
	}
	cout<<endl;

	sort_array(readings, 11);
    unsigned int medianReading = readings[6];

    cout << "Sorted Array: " ;
    for (int i=0; i<11; i++) {
		cout << readings[i]<< " ";
	}
	cout<<endl;
    cout << "Median: " << medianReading << endl;

    return 0;
}

