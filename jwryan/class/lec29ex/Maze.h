//-------------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: maze.h
// Description: This file contains a class to model a maze for a robot.
//-------------------------------------------------------------------------------
#ifndef MAZE_H
#define MAZE_H

class Maze
{
public:
            //--------------------------------------
            // GROUP: Construction/destruction/copy
            //--------------------------------------
    // default constructor
    Maze();
    // constructor to specify size
    Maze(int numRows, int numCols);
    // copy constructor
    Maze(const Maze &mazeToCopyFrom);
    // destructor
    ~Maze();
    // assignment operator
    const Maze &operator=(const Maze &mazeOnRight);


            //-----------------------------
            // GROUP: Data accessors
            //-----------------------------
    // returns number of rows of maze
    int getNumRows() const;
    // returns number of columns of maze
    int getNumCols() const;
    // returns whether maze value at (r,c) is black
    bool isBlack(int r, int c) const;

            //-----------------------------
            // GROUP: Data modification
            //-----------------------------

    // set maze value at row r and column c to black
    void setMazeValueToBlack(int r, int c);
    // set maze value at row r and column c to white
    void setMazeValueToWhite(int r, int c);
    // set all maze values to black
    void setAllToBlack( );
     // set all maze values to white
    void setAllToWhite( );

private:
    int * m_mazeArray;    // array to store maze
    int m_numRows;        // number of rows of maze
    int m_numCols;        // number of columns of maze

    // helper functions for public member functions:
    void setMazeValue(int r, int c, int val);
    void setAllMazeValues(int val);
    bool isInBounds(int r, int c) const;
};

#endif // MAZE_H
