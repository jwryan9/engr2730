/*-------------------------------------------------------------------------------
 * Programmer:  Jason Ryan, Kyle Anderson
 * Name:        turnList.c
 * Description: This program implements a turns linked list and helper functions
 *              for the mail delivery robot.
 * Pseudo Code: appendTurnToEnd
                    declare variables/malloc

                    set node values

                    if list empty
                        insert node at beginning
                    else
                        append to end

                freeAllMemoryInTurnList
                    declare variables

                    traverse linked list freeing each node

                lengthTurnList
                    declare variables

                    while loop
                        increment count
                        next pointer

                    return count

                giveAddressPointers
                    declare variables

                    count number of 'U' in list as number of addresses

                    malloc for nAddresses

                    add locations of U turns to array

                    return nAddresses

                ConcatenateTurnArrays
                    if first list not empty
                        set nextPtr of last node to first node of second list
                    if empty
                        set first list to second list

                giveOptimizedTurnList
                    declare variables

                    get number and list of addresses using giveAddressPointers

                    for number of deliveries
                        simplify and concatenate list to build optimized turns

                    simplify remaining list after deliveries have been accounted for

                    return optimized list

                copyAndSimplifyTurnList
                    declare variables

                    simplify list until second to last turn using provided simplifyTurns function

                    return simplified list

                simplifyTurns
                    given
  -------------------------------------------------------------------------------*/
#include "turnList.h"
#include <stddef.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------------
 * Function name: appendTurnToEnd
 * Description: This function creates a new node with the given value and
 *              inserts it at the end of the linked list.
 * Input: topPtr = pointer to NodePtr = pointer to the pointer of the first
 *                                        node of the list. The list is
 *                                        assumed to be in ascending order.
 *        value = char = integer value of node to be created/inserted in
 *                      sorted linked list
 * Output: topPtr = pointer to NodePtr = pointer to the pointer of the first
 *                                         node of the list. If a node
 *                                         was inserted at the beginning of
 *                                         the list, the value of *startPtr
 *                                         will have changed.
 ----------------------------------------------------------------------------*/
void appendTurnToEnd(NodePtr *topPtr, char turn)
{

    NodePtr beforeNodePtr, afterNodePtr;
    NodePtr newNodePtr = NULL;

    newNodePtr = (NodePtr) malloc(sizeof(Node));

    if(newNodePtr != NULL)
    {
        newNodePtr->turn = turn;
        newNodePtr->nextPtr = NULL;

        beforeNodePtr = NULL;
        afterNodePtr = *topPtr;

        //Loop to end of list
        while(afterNodePtr != NULL)
        {
            beforeNodePtr = afterNodePtr;
            afterNodePtr = afterNodePtr->nextPtr;
        }

        //If list is empty insert at beginning, else append to end of list
        if(beforeNodePtr == NULL)
        {
            newNodePtr->nextPtr = *topPtr;
            *topPtr = newNodePtr;
        }
        else
        {
            beforeNodePtr->nextPtr = newNodePtr;
            newNodePtr->nextPtr = afterNodePtr;
        }
    }
}

/*-----------------------------------------------------------------------------
 * Function name: freeAllMemoryInTurnArray
 * Description: This function frees all the memory in a linked list and
 *              sets the start pointer to be equal to NULL. All
 *              nodes in the linked list must have been dynamically allocated.
 * Input: topPtr = NodePtr * = pointer to pointer to the first node of linked
 *                               list
 * Output: topPtr = NodePtr * = modification of the startPtr so that it
 *                                equals NULL to indicate an empty list
 ----------------------------------------------------------------------------*/
void freeAllMemoryInTurnList(NodePtr *topPtr)
{
    NodePtr tmpPtr, currentPtr;
    currentPtr = *topPtr;

    //Traverse linked list freeing memory for each node
    while(currentPtr != NULL)
    {
        tmpPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;

        free(tmpPtr);
    }

    //Indicate the list is empty
    *topPtr = NULL;
}

/*-----------------------------------------------------------------------------
 * Function name: lengthTurnList
 * Description: This function returns the length of the turns list
 * Input: topPtr = NodePtr = pointer to the first node of linked
 *                               list
 * Output: length = int = number of elements in the linked list
 ----------------------------------------------------------------------------*/
int lengthTurnList(NodePtr topPtr)
{

    int length=0;
    NodePtr currentPtr = topPtr;

    while(currentPtr != NULL)
    {
        length++;
        currentPtr = currentPtr->nextPtr;
    }

    return length;
}

/*-----------------------------------------------------------------------------
 * Function name: giveAddressPointers
 * Description: This function returns the locations of the U turns in the array
 * Input: topPtr = NodePtr = pointer to the first node of linked
 *                               list
 *         addressLocations = NodePtr** = pointer to pointer to nodes of a linked list
 * Output: addressLocations = NodePtr** = modification of addressLocations such that
 *                                        it points to a dynamically allocated array of
 *                                        NodePtr; each entry in the array points to the
 *                                        node with U turns in the linked list. See first figure
 *                                        in description
 * Output: length = int = number of elements in the linked list

 ----------------------------------------------------------------------------*/
int giveAddressPointers(NodePtr topPtr, NodePtr **addressLocations)
{

    int nAddresses = 0, i = 0;
    *addressLocations = NULL;

    NodePtr currentPtr = topPtr;

    //Count number of addresses
    while(currentPtr != NULL)
    {
        if(currentPtr->turn == 'U')
        {
            nAddresses++;
        }
        currentPtr = currentPtr->nextPtr;
    }

    *addressLocations = (Node**)malloc(nAddresses * sizeof(NodePtr));

    //Traverse linked list, if U turn add to array of address locations
    if(*addressLocations != NULL)
    {
        currentPtr = topPtr;
        while(currentPtr != NULL)
        {
            if(currentPtr->turn == 'U')
            {
                (*(*addressLocations+i)) = currentPtr;
                i++;
            }
            currentPtr = currentPtr->nextPtr;
        }
    }

    return (nAddresses); // does not count the last U turn.

}


/*-----------------------------------------------------------------------------
 * Function name: concatenateTurnArrays
 * Description: Concatenate two turn arrays
 * Input: topPtr = pointer to the pointer of the first
 *                                         list.
 *        inTurns  = pointer to the second list.
 * Output: topPtr = pointer to the pointer of the first list; the second list is
 *                 added to the end of the first list pointed by topPtr.
 ----------------------------------------------------------------------------*/
void concatenateTurnArrays(NodePtr *topPtr, NodePtr inTurns)
{

    if(*topPtr != NULL)
    {
        NodePtr currentPtr = *topPtr;

        //Set currentPtr to point to last node of first list
        while(currentPtr->nextPtr != NULL)
            currentPtr = currentPtr->nextPtr;

        //Link second list start to first list end
        currentPtr->nextPtr = inTurns;
    }
    else
    {
        //If first list is empty, concatenated list is equal to the second list
        *topPtr = inTurns;
    }

}

/*-----------------------------------------------------------------------------
 * Function name: giveOptimizedTurnList
 * Description: This function creates a new optimal turns list to visit the delivery
 * addresses specified by deliveries. It will remove visits to stations not specified
 * in the delivery list. See the second figure in the description for the details. This
 * function should call copyAndSimplifyTurnList on segments of the turnslist and concatenates
 * the resulting arrays.
 *
 * Input:       topPtr = NodePtr = pointer to the list of turns
 *              deliveries = int* = pointer to the list of deliveries
 *              nDeliveries = int = the number of deliveries (length of deliveries
 *                                  array
 ----------------------------------------------------------------------------*/

NodePtr giveOptimizedTurnList(NodePtr topPtr, int * deliveries,int nDeliveries)
{

    NodePtr optPtr = NULL;
    NodePtr currentPtr = NULL;
    NodePtr simplifiedPtr = NULL;
    NodePtr *addressPtr = NULL;
    NodePtr endPtr = NULL;
    int nAddresses, i = 0;

    currentPtr = topPtr;

    nAddresses = giveAddressPointers(topPtr, &addressPtr);

    //Simplify turn list based on provided delivery addresses
    for(i=0; i<nDeliveries; i++)
    {
        endPtr = addressPtr[deliveries[i]];
        simplifiedPtr = copyAndSimplifyTurnList(currentPtr, endPtr);
        concatenateTurnArrays(&optPtr, simplifiedPtr);
        currentPtr = endPtr->nextPtr;
    }

    //Simplify remainder of turn list
    simplifiedPtr = copyAndSimplifyTurnList(currentPtr, addressPtr[nAddresses-1]);
    concatenateTurnArrays(&optPtr, simplifiedPtr);

    return(optPtr);

}


/*-----------------------------------------------------------------------------
 * Function name: copyAndSimplifyTurnList
 * Description: This function creates a new linked list by copying
 *              a segment of a specified linked list
 *              (from startPtr to endPtr) and simplifies it
 *              by removing the visits to the intermediate stations
 * Input:       startPtr = NodePtr = pointer to the new list
 *              endPtr = NodePtr = pointer to the last turn in the list
 * Output:      simplifiedPtr = NodePtr = pointer to the simplified list
 ----------------------------------------------------------------------------*/
NodePtr copyAndSimplifyTurnList(NodePtr startPtr, NodePtr endPtr)
{

    NodePtr simplifiedPtr = NULL;
    NodePtr currentPtr = NULL;

    currentPtr = startPtr;

    //Simplify list up to second to last turn
    while(currentPtr != endPtr->nextPtr)
    {
        appendTurnToEnd(&simplifiedPtr, currentPtr->turn);
        simplifyTurns(&simplifiedPtr);
        currentPtr = currentPtr->nextPtr;
    }

    return simplifiedPtr;

}
/*-----------------------------------------------------------------------------
 * Function name: simplifyTurns
 * Description: This function optimizes the last three nodes of the
 *              specified linked list
 *              For example, it will update the list SSLUL to SSS
 *              Note that it will not simplify the list if U is not the second last
 *              turn. For example, if called with SLULSS, the result will be SLULSS.
 * Input:       startPtr = NodePtr* = pointer to pointer the linked list of input turns
 * Output:      startPtr = NodePtr* = pointer to pointer the linked list of output turns

 * note: based on code provided in maze-solve.c provided by 3pi
 ----------------------------------------------------------------------------*/


void simplifyTurns(NodePtr *startPtr)
{
    NodePtr endPtr=*startPtr;     // pointer to the last node
    NodePtr endMinusOnePtr=NULL;  // pointer to the second last node
    NodePtr endMinusTwoPtr=NULL;  // pointer to the node before the second last node

    char character;

    int total_angle;

    if (*startPtr==NULL) {  // EMPTY LIST; do nothing
        return;
    }

    while (endPtr->nextPtr != NULL)
    {
        endMinusTwoPtr = endMinusOnePtr;
        endMinusOnePtr = endPtr;
        endPtr = endPtr->nextPtr;
    }

    // If size <3 or second last element is not U, return;

    if(endMinusTwoPtr==NULL || endMinusOnePtr->turn != 'U')
        return;
    else
    {   // logic from maze-solve.c

        total_angle = 0;
        character = endMinusTwoPtr->turn;
        total_angle += (character=='R')*90 + (character=='L')*270 + (character=='U')*180;
        character = endMinusOnePtr->turn;
        total_angle += (character=='R')*90 + (character=='L')*270 + (character=='U')*180;
        character = endPtr->turn;
        total_angle += (character=='R')*90 + (character=='L')*270 + (character=='U')*180;
        total_angle = total_angle % 360;

        switch(total_angle)
        {
            case 0:
                endMinusTwoPtr->turn = 'S';
                break;
            case 90:
                endMinusTwoPtr->turn = 'R';
                break;
            case 180:
                endMinusTwoPtr->turn = 'U';
                break;
            case 270:
                endMinusTwoPtr->turn = 'L';
                break;
        }
        free(endPtr);
        free(endMinusOnePtr);
        endMinusTwoPtr->nextPtr = NULL;
    }
}


