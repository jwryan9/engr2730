//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: RobotModelMazeFunctions.cpp
// Description: Implementation of functions to modify RobotModel and Maze
//-----------------------------------------------------------------------------
#include <fstream>
#include "RobotModelMazeFunctions.h"
#include "useCurses.h"

bool readMaze(const char *fileName, Maze &m, RobotModel &robot)
{
    std::ifstream fin(fileName);
    bool success = true;

    if (fin.good())
    {
        int numRows, numCols;
        fin >> numRows >> numCols;
        Maze myMaze(numRows, numCols);
        int robotRow, robotCol, robotDir;
        fin >> robotRow >> robotCol >> robotDir;
        robot.setRow(robotRow);
        robot.setCol(robotCol);
        robot.setDir(robotDir);
        for (int r = 0; r < numRows; r++)
        {
            for (int c = 0; c < numCols; c++)
            {
                int val;
                fin >> val;
                if (val > 0)
                {
                    myMaze.setMazeValueToBlack(r,c);
                }
            }
        }

        m = myMaze; // copy maze
    }
    else
    {
        success = false;
    }

    fin.close();

    return success;
}

void printMazePlusCurrentPos(Maze m, RobotModel robot)
{
    // note: in this program, anything > 0 is considered black
    //         to mimic robot sensor values that result in larger
    //         values when placed over a dark surface.
    //         (opposite of the convention used for images)
    move(0,0);
    for (int r=0; r < m.getNumRows(); r++)
    {
        for (int c=0; c < m.getNumCols(); c++)
        {
            if (r == robot.getRow() && c == robot.getCol())
            {
                printw("* ");
            }
            else if (m.isBlack(r,c))
            {
                printw("X ");
            }
            else
            {
                printw(". ");
            }
        }
        printw("\n");
    }
}
