//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: Maze.cpp
// Description: Implementation of member functions for Maze class
//-----------------------------------------------------------------------------
#include "Maze.h"
#include <cstdlib>

Maze::Maze()
{
    m_numRows = 0;
    m_numCols = 0;
    m_mazeArray = NULL;
}


Maze::Maze(int numRows, int numCols)
{
    m_numRows = numRows;
    m_numCols = numCols;
    if (m_numRows*m_numCols > 0)
    {
        m_mazeArray = new int[m_numRows*m_numCols];
        setAllToWhite( );
    }
    else
    {
        m_mazeArray = NULL;
    }
}

Maze::Maze(const Maze &mazeToCopyFrom)
{
    // copy rows/cols/pixels
    m_numRows = mazeToCopyFrom.m_numRows;
    m_numCols = mazeToCopyFrom.m_numCols;
    if (m_numRows*m_numCols > 0)
    {
        m_mazeArray = new int[m_numRows*m_numCols];

        for (int i = 0; i < m_numRows*m_numCols; i++)
        {
            m_mazeArray[i] = mazeToCopyFrom.m_mazeArray[i];
        }
    }
    else
    {
        m_mazeArray = NULL;
    }
}

Maze::~Maze()
{
    if (m_mazeArray != NULL)
    {
        delete [] m_mazeArray;
        m_numRows = 0;
        m_numCols = 0;
    }
}

const Maze &Maze::operator=(const Maze &mazeOnRight)
{
    // avoid self-assignment
    if (&mazeOnRight != this)
    {
        // if images have different sizes, delete old space and allocate new space
        if (m_numRows != mazeOnRight.m_numRows || m_numCols != mazeOnRight.m_numCols)
        {
            if (m_mazeArray != NULL)
            {
                delete [] m_mazeArray;
                m_mazeArray = NULL;
            }
            m_numRows = mazeOnRight.m_numRows;
            m_numCols = mazeOnRight.m_numCols;
            if (m_numRows*m_numCols > 0)
            {
                m_mazeArray = new int[m_numRows*m_numCols];
            }
        }

        // now copy pixels
        for (int i = 0; i < m_numRows*m_numCols; i++)
        {
            m_mazeArray[i] = mazeOnRight.m_mazeArray[i];
        }
    }

    return *this; // enables I1 = I2 = I3, for example
}

int Maze::getNumRows() const
{
    return m_numRows;
}

int Maze::getNumCols() const
{
    return m_numCols;
}

bool Maze::isBlack(int r, int c) const
{
    int val = 1;
    if (isInBounds(r,c))
    {
        val = m_mazeArray[r*m_numCols + c];
    }

    return val > 0; // using maze convention that > 0 is black and 0 is white
}

void Maze::setMazeValueToBlack(int r, int c)
{
    setMazeValue(r,c,1); // using maze convention that > 0 is black and 0 is white
}

void Maze::setMazeValueToWhite(int r, int c)
{
    setMazeValue(r,c,0); // using maze convention that > 0 is black and 0 is white
}

void Maze::setAllToBlack( )
{
    setAllMazeValues(1); // using maze convention that > 0 is black and 0 is white
}

void Maze::setAllToWhite( )
{
    setAllMazeValues(0); // using maze convention that > 0 is black and 0 is white
}

void Maze::setMazeValue(int r, int c, int val)
{
    if (isInBounds(r,c))
    {
        m_mazeArray[r*m_numCols + c] = val;
    }
}

void Maze::setAllMazeValues(int val)
{
    for (int i=0; i < m_numRows*m_numCols; i++)
    {
        m_mazeArray[i] = val;
    }
}

bool Maze::isInBounds(int r, int c) const
{
    return (r >= 0 && r < m_numRows && c >=0 && c < m_numCols);
}
