/*------------------------------------------------------------------------------
 * Programmer: Jason Ryan
 * Name: hw3.c
 * Description: This program simulates a package delivery robot. The robot traces
                through a given maze once then asks for the address(es) which the
                user would like to deliver to. The robot then traverses the maze
                skipping locations the user did not request to deliver to. The
                robot will continue this delivery address input and package delivery
                indefinitely.
 * Pseudo code: main
                    initialize variables/pointers
                    dynamically allocate memory and check for success
                    initialize display window

                    initialize maze/robot
                        if success
                            print maze/robot
                            learn maze
                            find possible delivery addresses
                            print turns robot made and number of deliverable addresses
                            use copAndSimplify to generate simplified list of turns

                        infinitely loop
                            get user requested addresses
                            if addresses selected
                                determine location where deliveries take place
                                perform deliveries
                            else
                                don't attempt delivery
                        close window
                        free memory

                learnTrack
                    initialize variables
                    start robot moving straight from station until it hits a junction

                    while robot has not returned to station
                        check for junction
                        check for dead end
                        follow left hand on wall strategy when at junction
                            record choice
                        uTurn when at dead end
                            record choice
                        otherwise move straight
                        check if robot at station
                    add null char to end turns string
                    return number of turns

                sort_array (from lec12ma)
                    initialize variables
                    construct array from minimum to maximum value

                getAddresses
                    initialize variables
                    while address array is not full and user is not done
                        take input for delivery addresses
                            validate input
                    sort array of addresses
                    return sorted array

                getDeliveryLocs
                    initialize variables
                    search for indexes of 'S' in array
                        when finds 'S' add index to array of sLocs
                    generate delivery locations array from sLocs

                deliver
                    initialize variables

                    initialize maze/robot
                        traverse maze and follow optimized turns array until robot returns to station
                            while traversing if optimized array position is 'S'
                                check if robot is to deliver to that address
                                    if yes, turn left and make delivery with left hand on wall strategy
                                    if no, go straight

                copyAndSimplify/simplifyTurns/initMazeAndRobotFromCLArgs provided
 -------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "useCurses.h"
#include <cstring>

#include "robotModel.h"
#include "maze.h"

const int MAX_TURNS = 300;

/* function prototype for initializing maze and robot from command line arguments */
int initMazeAndRobotFromCLArgs(int argc, char *argv[], Maze *maze, RobotModel *robot);
int copyAndSimplify(char *inturns, char *outturns, int numturns);
int simplifyTurns(char *turns, int *numTurns);

int learnTrack(Maze *maze, RobotModel *robot, char *turns);
int getAddresses(int *adds, int maxAdds);
void sort_array(int *arr, int arr_size);
void getDeliveryLocs(const char *optTurns, const int *adds, int *sLocs, int *delLocs, int maxAdds, int numTurns);
void deliver(int argc, char *argv[], Maze *maze, RobotModel *robot, const int *adds, const char *optTurns, const int *delLocs, int numAdds, int maxAdds);


int main( int argc, char *argv[] )
{

    // Maze and related variables
    Maze maze;              /* structure to store maze */
    RobotModel robot;       /* structure to model robot (current position + direction)*/
    char input;
    int numAdds, numTurns, i;
    int maxAdds = 0, done = 0, toDel = 0;

    char *turns = NULL;
    char *optTurns = NULL;
    int *adds = NULL;
    int *sLocs = NULL;
    int *delLocs = NULL;

    //Dynamically allocate memory and check for successful completion
    turns = (char*)malloc(MAX_TURNS * sizeof(char));
    optTurns = (char*)malloc(MAX_TURNS * sizeof(char));
    if(turns == NULL || optTurns == NULL)
    {
        printf("Malloc Failed\n");
        return 0;
    }

    /* initialize curses mode */
    initscr();

    printw("\n Resize screen first \n");
    printw("\n Then press s to start \n");

    do
    {
        scanw("%c", &input);
    }
    while (input != 's');

    /* print welcome message */
    printw("Welcome to the robot mail delivery system.\n");


   /* if successfully have initialized robot and maze, solve maze */
        if (initMazeAndRobotFromCLArgs(argc, argv, &maze, &robot))
        {
            /* display maze and obtain desired end point */
            clear();
            printMazePlusCurrentPos(maze, robot);

            numTurns = learnTrack(&maze, &robot, turns);

            printw("\nTurns: %s", turns);

            //The total number of deliverable addresses is equal to number of uTurns
            for(i=0; turns[i]; i++)
                maxAdds += (turns[i] == 'U');

            printw("\n# of Addresses: %d", maxAdds);

            //Dynamically allocate memory and check for successful completion
            sLocs = (int *)malloc(maxAdds * sizeof(int));
            delLocs = (int *)malloc(maxAdds * sizeof(int));
            adds = (int*) malloc(maxAdds * sizeof(int));
            if(adds == NULL || sLocs == NULL || delLocs == NULL)
            {
                printw("Malloc failed.");
                return 0;
            }

            //numTurns set to number of tuns int optTurns
            numTurns = copyAndSimplify(turns, optTurns, numTurns);

            //Continue deliveries forever
            while(!done)
            {
                numAdds = getAddresses(adds, maxAdds);
                for(i=0; i<maxAdds; i++)
                {
                    if(adds[i] != -1)
                    {
                        toDel = 1;
                        break;
                    }
                    else
                        toDel = 0;
                }

                if(toDel)
                {
                    getDeliveryLocs(optTurns, adds, sLocs, delLocs, maxAdds, numTurns);
                    deliver(argc, argv, &maze, &robot, adds, optTurns, delLocs, numAdds, maxAdds);
                    printw("\nDeleveries completed.");
                }
                else
                    printw("\nNo deliveries to be made.");

                getch();
            }

            getch();
        }

    endwin();

    free(turns);
    free(optTurns);
    free(adds);
    free(sLocs);
    free(delLocs);

    return 0;
}

/*
*Function name:  getDeliveryLocs
*Description:    Function searches optTurns for 'S' and finds indexes of 'S' where user wants to make deliveries.
*Inputs:         optTuns = const char * = pointer to character arry of the robots optimal path through the maze
*                adds = const int * = pointer to addresses the robot is able to deliver to
*                sLocs = int * = Array of indexes of 'S' in optTurns
*                delLocs = int * = Array of indexes in optTurns the user wants to deliver to
*                maxAdds = int = maximum number of user selectable addresses
*                numTurns = int = number of turns in optTurns
*Outputs:        sLocs = int * = indexes of 'S' in optTurns
*                delLocs = int * = indexes of delivery addresses in optTurns
*/

void getDeliveryLocs(const char *optTurns, const int *adds, int *sLocs, int *delLocs, int maxAdds, int numTurns)
{
    int i, j=0;

    for(i=0; i<numTurns; i++)
    {
        if(optTurns[i] == 'S')
        {
            sLocs[j] = i;
            j++;
        }
    }

    //Initialize delLocs array values to -1
    for(i=0; i<maxAdds; i++)
        delLocs[i] = -1;

    for(i=0; i<maxAdds; i++)
    {
        if(adds[i] == -1)
        {
            delLocs[i]= -1;
        }
        else
            delLocs[i] = sLocs[adds[i]];
    }

    getch();
}

/*
*Function name: deliver
*Description:   Function takes information about the robot, maze, optimal path, and delivery locations to move the robot through the maze for package deliveries.
*Inputs:        argc = int = number of command-line arguments
*               argv = array of strings = command-line arguments, with argv[1]
*                                         being the input file name
*               m = Maze * = pointer to Maze structure that should be initialized
*                            in this function (passed by simulated reference)
*               robot = RobotModel * = pointer to RobotModel that should be
*                                      initialized in this function (passed by
*                                      simulated reference)
*               adds = const int * = pointer to array of user selected addresses to deliver to
*               optTurns = const char* = pointer to character array of the robots optimal path through the maze
*
*
*Outputs:       None
*/
void deliver(int argc, char *argv[], Maze *maze, RobotModel *robot, const int *adds, const char *optTurns, const int *delLocs, int numAdds, int maxAdds)
{
    int atJunction = 0;
    int deadEnd = 0;
    int atStation = 0;
    int i = 0, j =0;
    int numS = 0;
    int delToLoc = 0;

    clear();

    printw("\nOptimized Turns: %s\n", optTurns);
    getch();

    //Reset robot
    if(initMazeAndRobotFromCLArgs(argc, argv, maze, robot))
    {

        //Have robot traverse maze
        printMazePlusCurrentPos(*maze, *robot);
        printw("Making Deliveries. Press any key to continue.");
        getch();

        moveStraight(robot);
        printMazePlusCurrentPos(*maze, *robot);
        printw("Making Deliveries. Press any key to continue.");
        getch();

        //First steps away from station.
        while(blackInFront(*maze, *robot) && atJunction != 1)
        {
            if((blackToLeft(*maze, *robot) && blackToRight(*maze, *robot)) ||
                (blackToLeft(*maze, *robot) && blackInFront(*maze, *robot)) ||
                (blackInFront(*maze, *robot) && blackToRight(*maze, *robot)) ||
                (onBlack(*maze, *robot) && blackToLeft(*maze, *robot)) ||
                (onBlack(*maze, *robot) && blackToRight(*maze, *robot)))
                atJunction = 1;

            moveStraight(robot);
            printw("Making Deliveries. Press any key to continue.");
            getch();
        }

        //Reset iterator
        i=0;

        while(atStation == 0)
        {
            //Check for special places on track where robot must make a decision
            if((blackToLeft(*maze, *robot) && blackToRight(*maze, *robot)) ||
                (blackToLeft(*maze, *robot) && blackInFront(*maze, *robot)) ||
                (blackInFront(*maze, *robot) && blackToRight(*maze, *robot)) ||
                (onBlack(*maze, *robot) && blackToLeft(*maze, *robot)) ||
                (onBlack(*maze, *robot) && blackToRight(*maze, *robot)))
                atJunction = 1;
            else
                atJunction = 0;

            if(onBlack(*maze, *robot) && !blackToLeft(*maze, *robot) && !blackInFront(*maze, *robot) && !blackToRight(*maze, *robot))
                deadEnd = 1;
            else
                deadEnd = 0;

            //When robot is at a junction use left hand on wall strategy
            if(atJunction)
            {
                if(optTurns[i] == 'L')
                {
                    turnLeft(robot);
                    printMazePlusCurrentPos(*maze, *robot);
                }
                else if(optTurns[i] == 'S')
                {

                    //Check if current address is to be delivered to
                    for(j=0; j<maxAdds; j++)
                    {
                        if(delLocs[j] == i)
                        {
                            delToLoc = 1;
                            break;
                        }
                        else
                            delToLoc = 0;
                    }

                    if(delToLoc)
                    {
                        //Turn into the delivery location
                        turnLeft(robot);
                        printMazePlusCurrentPos(*maze, *robot);

                        getch();

                        //While not at entrance to address, follow the path to make deliveries
                        while(!(blackToLeft(*maze, *robot) && blackToRight(*maze, *robot)))
                        {
                            //Check for special places on track where robot must make a decision
                            if((blackToLeft(*maze, *robot) && blackToRight(*maze, *robot)) ||
                            (blackToLeft(*maze, *robot) && blackInFront(*maze, *robot)) ||
                            (blackInFront(*maze, *robot) && blackToRight(*maze, *robot)) ||
                            (onBlack(*maze, *robot) && blackToLeft(*maze, *robot)) ||
                            (onBlack(*maze, *robot) && blackToRight(*maze, *robot)))
                                atJunction = 1;
                            else
                                atJunction = 0;

                            if(onBlack(*maze, *robot) && !blackToLeft(*maze, *robot) && !blackInFront(*maze, *robot) && !blackToRight(*maze, *robot))
                                deadEnd = 1;
                            else
                                deadEnd = 0;

                            if(atJunction)
                            {
                                if(blackToLeft(*maze, *robot))
                                {
                                    turnLeft(robot);
                                    printMazePlusCurrentPos(*maze, *robot);
                                }
                                else if(blackInFront(*maze, *robot))
                                {
                                    moveStraight(robot);
                                    printMazePlusCurrentPos(*maze, *robot);
                                }
                                else if(blackToRight(*maze, *robot))
                                {
                                    turnRight(robot);
                                    printMazePlusCurrentPos(*maze, *robot);
                                }
                            }
                            else if(deadEnd)
                            {
                                uTurn(robot);
                                printMazePlusCurrentPos(*maze, *robot);
                            }
                            else
                            {
                                if(blackInFront(*maze, *robot))
                                {
                                    moveStraight(robot);
                                    printMazePlusCurrentPos(*maze, *robot);
                                }
                            }

                            getch();
                        }

                        //Turn left upon ext to continue path around maze
                        turnLeft(robot);
                    }
                    else
                    {
                        moveStraight(robot);
                        printMazePlusCurrentPos(*maze, *robot);
                    }

                    numS++;
                }
                else if(optTurns[i] == 'R')
                {
                    turnRight(robot);
                    printMazePlusCurrentPos(*maze, *robot);
                }

                i++;
            }
            else if(deadEnd)
            {
                uTurn(robot);
                printMazePlusCurrentPos(*maze, *robot);
            }
            else
            {
                if(blackInFront(*maze, *robot))
                {
                    moveStraight(robot);
                    printMazePlusCurrentPos(*maze, *robot);
                }
            }

            printw("Making Deliveries. Press any key to continue.");
            getch();


            //Define Station to be location where robot is surrounded by black
            if(onBlack(*maze, *robot) && blackToLeft(*maze, *robot) && blackInFront(*maze, *robot) && blackToRight(*maze, *robot))
                atStation = 1;
            else
                atStation = 0;
        }
    }
}

/*
*Function name:  getAddresses
*Description:    Function which requests the user enter the address number which they wish the robot deliver to
*Inputs:         int* adds   = array for storing the delivery addresses the user requests
*                int maxAdds = maximum number of addresses the user may request the robot to deliver
*Outputs:        int numAdds = number of address the user has given the robot to deliver
*                int* adds   = array with user selected delivery addresses
*/
int getAddresses(int *adds, int maxAdds)
{
    int done = 0;
    int numAdds = 0;
    int add;
    int i;

    while(!done && numAdds<maxAdds)
    {
        printw("\nEnter address you would like to deliver to %d-%d (-1 to quit selection): ", 0, maxAdds-1);
        scanw("%d", &add);

        for(i=0; i<numAdds; i++)
        {
            while(add == adds[i])
            {
                printw("Address %d already selected. Enter new address %d-%d (-1 to quit selection): ", add, 0, maxAdds-1);
                scanw("%d", &add);
            }
        }

        if(add == -1)
        {
            done = 1;

            //Fill unused space in address input array with -1
            for(i=numAdds; i<maxAdds; i++)
                adds[i] = add;
        }
        else if(add < -1 || add >= maxAdds)
        {
            printw("Please enter valid address.");
        }
        else
        {
            adds[numAdds] = add;
            numAdds++;
        }
    }

    //Sort array of addresses from smallest to largest.
    sort_array(adds, maxAdds);

    return numAdds;
}

/*-----------------------------------------------------------------------------
 * CODE FROM LEC12MA
 *
 * Programmer:    Jason Ryan, Kyle Anderson
 * Function name: sort_array
 * Description:   This sorts the input array arr so the elements will be in
 *                ascending order (i.e., from 'smallest' to 'largest').
 *                The array is sorted using insertion sort.
 * Inputs:        arr = int * = input array
 *                arr_size = integer = number of elements in the input array
 * Outputs:       arr = int * = sorted input array
 ----------------------------------------------------------------------------*/
void sort_array(int *arr, int arr_size)
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

/*
Function name:  learnTrack
Description:    Function in which the robot learns the shape of the maze by noting
                the turns it must make from its starting point at the station until
                it returns to the station
Inputs:         *maze = pointer to Maze the robot is in
                *robot = pointer to RobotModel of the virtual robot traversing the maze
                *turns = character array for storing the sequence of turns made by the robot
Outputs:        *robot = pointer to RobotModel in its final state after traversing the maze
                *turns = char array of the turns made by the robot]
                i      = Number of turns made by robot
*/
int learnTrack(Maze *maze, RobotModel *robot, char *turns)
{
    int atJunction = 0;
    int deadEnd = 0;
    int atStation = 0;
    int i = 0;

    moveStraight(robot);
    printMazePlusCurrentPos(*maze, *robot);

    getch();

    //First steps away from station.
    while(blackInFront(*maze, *robot) && atJunction != 1)
    {
        if((blackToLeft(*maze, *robot) && blackToRight(*maze, *robot)) ||
            (blackToLeft(*maze, *robot) && blackInFront(*maze, *robot)) ||
            (blackInFront(*maze, *robot) && blackToRight(*maze, *robot)) ||
            (onBlack(*maze, *robot) && blackToLeft(*maze, *robot)) ||
            (onBlack(*maze, *robot) && blackToRight(*maze, *robot)))
            atJunction = 1;

        moveStraight(robot);
        printMazePlusCurrentPos(*maze, *robot);

        printw("Learning track. Press any key to move robot.");
        getch();

    }

    while(atStation == 0)
    {
        //Check for special places on track where robot must make a decision
        if((blackToLeft(*maze, *robot) && blackToRight(*maze, *robot)) ||
            (blackToLeft(*maze, *robot) && blackInFront(*maze, *robot)) ||
            (blackInFront(*maze, *robot) && blackToRight(*maze, *robot)) ||
            (onBlack(*maze, *robot) && blackToLeft(*maze, *robot)) ||
            (onBlack(*maze, *robot) && blackToRight(*maze, *robot)))
            atJunction = 1;
        else
            atJunction = 0;

        if(onBlack(*maze, *robot) && !blackToLeft(*maze, *robot) && !blackInFront(*maze, *robot) && !blackToRight(*maze, *robot))
            deadEnd = 1;
        else
            deadEnd = 0;

        //When robot is at a junction use left hand on wall strategy
        if(atJunction)
        {
            if(blackToLeft(*maze, *robot))
            {
                turnLeft(robot);
                strcat(turns, "L");
                printMazePlusCurrentPos(*maze, *robot);
            }
            else if(blackInFront(*maze, *robot))
            {
                moveStraight(robot);
                strcat(turns, "S");
                printMazePlusCurrentPos(*maze, *robot);
            }
            else if(blackToRight(*maze, *robot))
            {
                turnRight(robot);
                strcat(turns, "R");
                printMazePlusCurrentPos(*maze, *robot);
            }
        }
        else if(deadEnd)
        {
            uTurn(robot);
            strcat(turns,"U");
            printMazePlusCurrentPos(*maze, *robot);
        }
        else
        {
            if(blackInFront(*maze, *robot))
            {
                moveStraight(robot);
                printMazePlusCurrentPos(*maze, *robot);
            }
        }

        i++;

        printw("Learning track. Press any key to move robot.");
        getch();


        //Define Station to be location where robot is surrounded by black
        if(onBlack(*maze, *robot) && blackToLeft(*maze, *robot) && blackInFront(*maze, *robot) && blackToRight(*maze, *robot))
            atStation = 1;
        else
            atStation = 0;
    }

    turns[i] = '\0';
    return i;
}


/*-----------------------------------------------------------------------------
 * Function name: initMazeAndRobotFromCLArgs
 * Description: This function uses the specified command-line arguments to
 *              initialize the given Maze and RobotModel variables. If the
 *              incorrect number of command-line arguments is passed, an
 *              error message is displayed (and 0 is returned).
 * Inputs: argc = int = number of command-line arguments
 *         argv = array of strings = command-line arguments, with argv[1]
 *                                   being the input file name
 *         m = Maze * = pointer to Maze structure that should be initialized
 *                      in this function (passed by simulated reference)
 *         robot = RobotModel * = pointer to RobotModel that should be
 *                                initialized in this function (passed by
 *                                simulated reference)
 * Outputs: m = Maze * = pointer to initialized Maze
 *          robot = RobotModel * = pointer to initialized RobotModel
 *          int = 1 if initialization successful
 *                0 if error encountered
 ----------------------------------------------------------------------------*/
int initMazeAndRobotFromCLArgs(int argc, char *argv[], Maze *maze, RobotModel *robot)
{
    int success = 1;
    char *inputFileName;    /* input file name containing maze */
    /* obtain input filename from command line */
    if (argc >= 2) /* require at least two command-line arguments */
    {
        inputFileName = argv[1];
    }
    else
    {
        /* when incorrect number of command-line arguments are passed,
           print message indicating proper usage of program  */
        printw("Usage: %s inputFileName.txt\n", argv[0]);
        success = 0;
    }

    if (success)
    {
        success = readMaze(inputFileName, maze, robot);
    }

    return success;
}


/*-----------------------------------------------------------------------------
 * Function name: copyAndSimplify
 * Description: This function copies the inturns array with numturns entries to
 *              outturns array and simplifies it by deleting the visits to the
 *              intermediate addresses.
 * Inputs: *inturns: pointer to turn array that have to be copied & simplified
 *         *outturns: pointer to the simplified array of turns
 *         numturns: number of turns that will be copied and simplified
 * Output  optturns: length of the copied array
 ----------------------------------------------------------------------------*/
int copyAndSimplify(char *inturns, char *outturns, int numturns)
    {
        int i;
        int optturns = 0;
        for (i=0; i<numturns; i++) {
            outturns[optturns] = inturns[i];
            optturns++;
            simplifyTurns(outturns, &optturns);
        }
        return(optturns);
    }


/* note: based on code provided in maze-solve.c
 provided by 3pi */
int simplifyTurns(char *turns, int *numTurns)
{
    int done = 1;
    int n = *numTurns;
    if (n >= 3 && turns[n-2] == 'U')
    {
        int total_angle = 0;
        int i;
        for (i=1; i<=3; i++)
        {
            switch(turns[n-i])
            {
                case 'R':
                    total_angle += 90;
                    break;
                case 'L':
                    total_angle += 270;
                    break;
                case 'U':
                    total_angle += 180;
                    break;
            }
        }

        total_angle = total_angle % 360;

        switch(total_angle)
        {
            case 0:
                turns[n-3] = 'S';
                break;
            case 90:
                turns[n-3] = 'R';
                break;
            case 180:
                turns[n-3] = 'U';
                done = 0;
                break;
            case 270:
                turns[n-3] = 'L';
                break;
        }

        *numTurns = *numTurns - 2;
     }
    return(done);

}

