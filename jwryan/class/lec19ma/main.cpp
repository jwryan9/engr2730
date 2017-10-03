/*------------------------------------------------------------------------------
 * Programmers: Jason Ryan
 * Name: main.cpp
 * Description: This file contains an example program and corresponding
 *              mini-assignment associated with lecture 19. In particular,
 *              this program models a 'robot' moving around a maze based on
 *              key presses by the user. The maze and initial robot position
 *              are loaded from a file (with the file path specified via a
 *              command-line argument). The curses library (ncurses on linux/mac,
 *              pdcurses on windows) is used to display the maze and robot.
 *              For the mini-assignment, a function that uses simulated pass-
 *              by-reference to modify a robot needs to be written and called.
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

/* TODO: your function prototype here */
void placeRobot(RobotModel *robot, int row, int col);


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
                   new location */
                if (row >= 0 && row < maze.rows && col >= 0 && col < maze.cols)
                {
                    /* If deciding to implement the placeRobot function mentioned in class,
                       you would want to replace the following two lines with your function call */
                    placeRobot(&robot, row, col);
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

/* TODO: your function definition here */
/*
Function name:
Description:
Inputs: robot = RobotModel * = pointer to RobotModel using simulated passe by reference
Outputs: void
*/

void placeRobot(RobotModel *robot, int row, int col)
{
    robot->row = row;
    robot->col = col;
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
