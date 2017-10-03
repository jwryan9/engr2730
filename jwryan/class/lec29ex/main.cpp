//---------------------------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: main.cpp
// Description: This program contains a similar example program as that from
//              lectures 17-19, but with the use of classes rather than structures.
//              In particular, this program models a 'robot' moving around a
//              maze based on key presses by the user. The maze and initial
//              robot position are loaded from a file (with the file path specified
//              via a command-line argument).
// Building from command line (on linux):
//  > g++ main.cpp RobotModel.cpp RobotModelMazeFunctions.cpp Maze.cpp -o main.exe -lncurses
// To run (assuming maze.txt is located in the same diretory as main.exe):
//  > ./main.exe maze.txt
//--------------------------------------------------------------------------------------------
#include "RobotModel.h"
#include "Maze.h"
#include "RobotModelMazeFunctions.h"
#include "useCurses.h"

// function prototype for initializing maze and robot from command line arguments
bool initMazeAndRobotFromCLArgs(int argc, char *argv[], Maze &maze, RobotModel &robot);

int main( int argc, char *argv[] )
{
    // create Maze and RobotModel objects
    Maze maze;
    RobotModel robot;

    int c = ' ';

    // initialize curses mode
    initscr();

    // if successfully have initialized robot and maze, move robot around based on
    // user-entered characters
    if (initMazeAndRobotFromCLArgs(argc, argv, maze, robot))
    {
        bool done = false;           //whether we are done moving the robot around
        while (!done)
        {
            //print maze + current robot in its current position
            clear();
            printMazePlusCurrentPos(maze, robot);
            printw("%c\n", c);

            // move robot, place robot in new position, or quit
            // based on user-entered character
            c = getch();
            if (c == 's') // straight
            {
                robot.moveStraight();
            }
            else if (c == 'l') // left
            {
                robot.turnLeft();
            }
            else if (c == 'r') // right
            {
                robot.turnRight();
            }
            else if (c == 'u') // u-turn
            {
                robot.uTurn();
            }
            else if (c == 'p') // place robot in new position
            {
                int row, col;
                // 'place' the robot at a new location
                printw("\nEnter row: ");
                scanw("%d", &row);
                printw("Enter col: ");
                scanw("%d", &col);
                printw("%d %d", row, col);
                // If a valid row and column were specified, 'place' the robot at a
                //   new location. Otherwise, print an error message and wait for
                //   character to be pressed.
                if (row >= 0 && row < maze.getNumRows() && col >= 0 && col < maze.getNumCols())
                {
                    robot.setRow(row);
                    robot.setCol(col);
                }
                else
                {
                    printw("\nInvalid row and column. Press any key to continue.\n");
                    getch();
                }

            }
            else if (c == 'q') // quit
            {
                done = true;
            }
        }

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

//-----------------------------------------------------------------------------
// Function name: initMazeAndRobotFromCLArgs
// Description: This function uses the specified command-line arguments to
//              initialize the given Maze and RobotModel objects. If the
//              incorrect number of command-line arguments is passed, an
//              error message is displayed (and false is returned).
// Inputs: argc = int = number of command-line arguments
//         argv = array of strings = command-line arguments, with argv[1]
//                                   being the input file name
//         m = Maze = Maze object that should be initialized
//         robot = RobotModel = RobotModel object that should be
//                              initialized in this function
// Outputs: m = Maze = initialized Maze object
//          robot = RobotModel = pointer initialized RobotModel object
//          bool = true if initialization successful
//                 false if error encountered
//----------------------------------------------------------------------------
bool initMazeAndRobotFromCLArgs(int argc, char *argv[], Maze &maze, RobotModel &robot)
{
    int success = true;
    char *inputFileName;    // input file name containing maze

    // obtain input filename from command line
    if (argc >= 2) // require at least two command-line arguments
    {
        inputFileName = argv[1];
    }
    else
    {
        // when incorrect number of command-line arguments are passed,
        //   print message indicating proper usage of program
        printw("Usage: %s inputFileName.txt\n", argv[0]);
        success = false;
    }

    if (success)
    {
        success = readMaze(inputFileName, maze, robot);
    }

    return success;
}

