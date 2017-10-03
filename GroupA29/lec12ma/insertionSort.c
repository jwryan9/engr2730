#include "insertionSort.h"
/*-----------------------------------------------------------------------------
 * Programmer: Jason Ryan, Kyle Anderson
 * Function name: sort_array
 * Description: This sorts the input array arr so the elements will be in
 *              ascending order (i.e., from 'smallest' to 'largest').
 *              The array is sorted using insertion sort.
 * Inputs: arr = unsigned int * = input array
 *         arr_size = integer = number of elements in the input array
 ----------------------------------------------------------------------------*/
void sort_array(unsigned int *arr, int arr_size)
{
    int i, j, temp;

    for(i=1; i<arr_size; i++)
    {
        j=i;
        
        while(j>0 && arr[j]<arr[j-1])
        {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            
            j--;
        }
    }
}
