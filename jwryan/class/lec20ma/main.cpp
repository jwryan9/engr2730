/*-------------------------------------------------------------------------------
 * Programmer: Jason Ryan
 * Name: main.cpp
 * Description: This program contains in-class examples and the mini-assignment
 *              associated with lecture 20 on linked lists.
 *
 *              For the mini-assignment, you must complete the function to
 *              compute the sum of the reward amounts received.
 *
 *              Optional extra practice: As an additional practice problem,
 *              complete the function to return a pointer to the first
 *              AmazingRaceLocation with a reward amount less than a given key.
 -------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

/* struct amazingRaceLocation is a data type used to represent a node in a linked
   list of "amazing race" locations */
struct amazingRaceLocation {
    char *locName;         /* name of the location as a string */
    float rewardAmount;    /* reward amount at the location (in dollars) */
    struct amazingRaceLocation * nextLocation; /* pointer to the next location in list */
};

typedef struct amazingRaceLocation AmazingRaceLocation;
typedef struct amazingRaceLocation * AmazingRaceLocationPtr;

/* function prototype function to print the location names and rewards */
void printAllLocationNamesAndRewards(AmazingRaceLocationPtr startingLocationPtr);

/* function prototype for mini-assignment */
float computeTotalReward(AmazingRaceLocationPtr startingLocationPtr);

/* function prototype for optional extra practice problem */
AmazingRaceLocationPtr getFirstAmazingRaceLocationPtrWithRewardLessThanKey(AmazingRaceLocationPtr startingLocationPtr,
                                                                           float key);

int main( void )
{
    /* set up locations */
    /* Note: this is NOT the standard way linked lists are created,
       but is useful as an example. More commonly, dynamic memory
       allocation is used to create the nodes of the list */

    /* CIE classroom */
    AmazingRaceLocation cieClassroom = {"CIE Classroom", 50.00, NULL};

    /* CIE laboratory */
    AmazingRaceLocation cieLab = {"CIE Laboratory", 50.00, NULL};

    /* ECE office */
    AmazingRaceLocation eceOffice = {"ECE Office", 25.00, NULL};

    /* CEE office */
    AmazingRaceLocation ceeOffice = {"CEE Office", 25.00, NULL};

    /* CBE office */
    AmazingRaceLocation cbeOffice = {"CBE Office", 25.00, NULL};

    /* MIE office */
    AmazingRaceLocation mieOffice = {"MIE Office", 25.00, NULL};

    /* BME office */
    AmazingRaceLocation bmeOffice = {"BME Office", 25.00, NULL};

    /* Student Development Center */
    AmazingRaceLocation sdc = {"Student Development Center", 50.00, NULL};

    /* Mona Garvin office */
    AmazingRaceLocation monaGarvinOffice = {"M. Garvin Office", 5.00, NULL};

    /* Justin Garvin office */
    AmazingRaceLocation justinGarvinOffice = {"J. Garvin Office", 0.25, NULL};

    /* location pointer for future use */
    AmazingRaceLocationPtr foundLocPtr = NULL;

    /* "link" locations together */
    cieClassroom.nextLocation = &monaGarvinOffice;
    monaGarvinOffice.nextLocation = &cieLab;
    cieLab.nextLocation = &eceOffice;
    eceOffice.nextLocation = &bmeOffice;
    bmeOffice.nextLocation = &justinGarvinOffice;
    justinGarvinOffice.nextLocation = &mieOffice;
    mieOffice.nextLocation = &ceeOffice;
    ceeOffice.nextLocation = &cbeOffice;
    cbeOffice.nextLocation = &sdc;

    /* print location names and rewards */
    cout << "Amazing race location names and rewards:" << endl ;
    printAllLocationNamesAndRewards(&cieClassroom);

    /* compute and display total value */
    cout << "\n\t\t\tTotal reward value = " << fixed << "$" << setprecision(2) << setw(10) << right << computeTotalReward(&cieClassroom) << endl;

    /* display first location with a reward value less than $10 */
    foundLocPtr = getFirstAmazingRaceLocationPtrWithRewardLessThanKey(&cieClassroom, 10);
    if (foundLocPtr != NULL)
    {
        cout << "\nThe first location with reward less than $10 is " << foundLocPtr->locName << " with a reward of " << fixed << "$" << setprecision(2) << foundLocPtr->rewardAmount << endl;
    }

    return 0;
}

/*-----------------------------------------------------------------------------
 * Function name: printAllLocationNamesAndRewards
 * Description: This prints out all of the location names and reward amounts
 *              in a linked list of AmazingRaceLocations
 * Inputs: startingLocationPtr = AmazingRaceLocationPtr = pointer to first
 *                                                        node in linked list
 ----------------------------------------------------------------------------*/
void printAllLocationNamesAndRewards(AmazingRaceLocationPtr startingLocationPtr)
{
    /* option A: for loop */
    AmazingRaceLocationPtr currentPtr;
    for (currentPtr = startingLocationPtr; currentPtr != NULL; currentPtr = currentPtr->nextLocation)
    {
        cout << left << setw(36) << currentPtr->locName << "reward = " << fixed << "$" << setprecision(2) << setw(10) << right << currentPtr->rewardAmount << endl;
    }

    /* option B: equivalent while loop */
    /*
    AmazingRaceLocationPtr currentPtr = startingLocationPtr;
    while (currentPtr != NULL)
    {
        cout << left << setw(36) << currentPtr->locName << "reward = " << fixed << "$" << setprecision(2) << setw(10) << right << currentPtr->rewardAmount << endl;
        currentPtr = currentPtr->nextLocation;
    }
    */
}

/*-----------------------------------------------------------------------------
 * Function name: computeTotalReward
 * Description: This function traverses through the linked list to compute
 *              the total sum of all reward amounts of the nodes in the list.
 * Inputs: startingLocationPtr = AmazingRaceLocationPtr = pointer to first
 *                                                        node in linked list
 * Output: float = total sum of the reward amounts of the nodes in the
 *                 linked list
 ----------------------------------------------------------------------------*/
float computeTotalReward(AmazingRaceLocationPtr startingLocationPtr)
{
    float total = 0.0;
    AmazingRaceLocationPtr currentPtr = NULL;

    for(currentPtr = startingLocationPtr; currentPtr != NULL; currentPtr = currentPtr->nextLocation)
        total += currentPtr->rewardAmount;

    return total;
}

/*-----------------------------------------------------------------------------
 * Function name: getFirstAmazingRaceLocationPtrWithRewardLessThanKey
 * Description: This function traverses through the linked list to find the
 *              first node with a reward amount less than the given key.
 * Inputs: startingLocationPtr = AmazingRaceLocationPtr = pointer to first
 *                                                        node in linked list
 *         key = float = key value (we want to find the first node with a
 *                       reward amount less than this key value)
 * Output: AmazingRaceLocationPtr = pointer to the first AmazingRaceLocation
 *                                  node within the linked list with a
 *                                  a reward amount less than the given key.
 *                                  If no such node is found, NULL is returned.
 ----------------------------------------------------------------------------*/
AmazingRaceLocationPtr getFirstAmazingRaceLocationPtrWithRewardLessThanKey(AmazingRaceLocationPtr startingLocationPtr,
                                                                           float key)
{
    AmazingRaceLocationPtr currentPtr = NULL;

    for(currentPtr = startingLocationPtr; currentPtr != NULL; currentPtr = currentPtr->nextLocation)
    {
        if(currentPtr->rewardAmount < key)
            return currentPtr;
    }

    return NULL; /* return NULL if nothing found */
}
