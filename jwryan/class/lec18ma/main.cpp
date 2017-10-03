/*------------------------------------------------------------------------------
 * Programmers: Jason Ryan
 * Name: main.cpp
 * Description: This file contains an example program and corresponding
 *              mini-assignment associated with lecture 18. In particular,
 *              this program models a 'robot' moving around a maze based on
 *              key presses by the user. The maze and initial robot position
 *              are loaded from a file (with the file path specified via a
 *              command-line argument). The curses library (ncurses on linux/mac,
 *              pdcurses on windows) is used to display the maze and robot.
 *              For the mini-assignment, a function that takes as input a robot
 *              and maze and returns 1 if the robot has a black unit to its left,
 *              to its right, and to its front (and returns 0 otherwise) needs
 *              to be written and called.
 * To compile on linux (if not using codeblocks):
 * > g++ -o main.exe main.cpp maze.cpp robotModel.cpp -lncurses
 * To run (assuming maze.txt is located in the same diretory as main.exe):
 * > ./main.exe maze.txt
 -------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "useCurses.h"

#include "robotModel.h"
#include "maze.h"

/*Function returns 1 if robot has black unit to its left, right, and front*/
int allBlack(Maze *maze, RobotModel *robot);


/* function prototype for initializing maze and robot from command line arguments */
int initMazeAndRobotFromCLArgs(int argc, char *argv[], Maze *maze, RobotModel *robot);

int main( int argc, char *argv[] )
{
    Maze maze;              /* strucutre to store maze */
    RobotModel robot;       /* structure to model robot (current position + direction) */
    int c = ' ';            /* last character entered by user */

    /* initialize curses mode */
    initscr();

    /* if successfully have initialized robot and maze, move robot around based on
       user-entered characters */
    if (initMazeAndRobotFromCLArgs(argc, argv, &maze, &robot))
    {
        int done = 0;           /* whether we are done moving the robot around */
        while (!done)
        {
            /* print maze + current robot in its current position */
            clear();
            printMazePlusCurrentPos(maze, robot);
            printw("%c\n", c);

            /* move robot, place robot in new position, or quit
               based on user-entered character */
            c = getch();
            if (c == 's') /* straight */
            {
                moveStraight(&robot);
            }
            else if (c == 'l') /* left */
            {
                turnLeft(&robot);
            }
            else if (c == 'r') /* right */
            {
                turnRight(&robot);
            }
            else if (c == 'u') /* u-turn */
            {
                uTurn(&robot);
            }
            else if (c == 'b')
            {
                if(allBlack(&maze, &robot))
                {
                    printw("\nBlack to front, left and right.\n");
                    getch();
                }
                else
                {
                    printw("\nNot black to front, left and right. \n");
                    getch();
                }
            }
            else if (c == 'p') /* place robot in new position */
            {
                int row, col;
                /* obtain row/column from user */
                printw("\nEnter row: ");
                scanw("%d", &row);
                printw("Enter col: ");
                scanw("%d", &col);
                printw("%d %d", row, col);
                /* If a valid row and column were specified, 'place' the robot at a
                   new location and call function to determine if robot has black to
                   the left, to the right, and in front (printing message to indicate
                   the result). Otherwise, print an error message and wait for key
                   to be pressed. */
                if (row >= 0 && row < maze.rows && col >= 0 && col < maze.cols)
                {
                    robot.row = row;
                    robot.col = col;

                    /* TODO: call function and print message here */
                    printw("\nStatus message of sensors here. Press any key to continue.\n");
                    getch();
                }
                else
                {
                    printw("\nInvalid row and column. Press any key to continue.\n");
                    getch();
                }

            }
            else if (c == 'q') /* quit */
            {
                done = 1;
            }
        }

        clearMaze(&maze);
    }
    else
    {
        printw("\nError initializing maze and robot...\n");
    }
    printw("\nDONE!\n");
    getch();
    endwin();

    return 0;
}

/*
Function name: allBlack
Description: Looks to left, right and in front of robot and returns 1 if all three positions are black
Inputs: maze = Maze * = pointer to maze the robot is in
        robot = RobotModel * = pointer to robot used in function
Output: int = 1 if all 3 positions are black, 0 if not.
*/
int allBlack(Maze *maze, RobotModel *robot)
{
    int straight = 0;
    int left = 0;
    int right = 0;

    if(blackInFront(*maze, *robot))
        straight = 1;
    if(blackToLeft(*maze, *robot))
        left = 1;
    if(blackToRight(*maze, *robot))
        right = 1;

    if(straight && left && right)
        return 1;
    else
        return 0;
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
