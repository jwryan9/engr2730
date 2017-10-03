//-------------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: RobotModelMazeFunnctions.h
// Description: This file contains prototypes of functions to modify RobotModel
//              and Maze objects.
//-------------------------------------------------------------------------------
#ifndef ROBOTMODELMAZEFUNCTIONS_H
#define ROBOTMODELMAZEFUNCTIONS_H

#include "RobotModel.h"
#include "Maze.h"

// function to initialize Maze object m and RobotModel robot from
// file fileName
bool readMaze(const char *fileName, Maze &m, RobotModel &robot);

// function to print the maze and its current position
void printMazePlusCurrentPos(Maze m, RobotModel robot);

#endif // ROBOTMODELMAZEFUNCTIONS_H
