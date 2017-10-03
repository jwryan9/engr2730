//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: RobotModel.cpp
// Description: Implementation of member functions for RobotModel class
//-----------------------------------------------------------------------------
#include "RobotModel.h"

int RobotModel::getRow( ) const
{
    return m_row;
}

int RobotModel::getCol( ) const
{
    return m_col;
}

int RobotModel::getDir( ) const
{
    return m_dir;
}

void RobotModel::setRow(int row)
{
    m_row = row;
}

void RobotModel::setCol(int col)
{
    m_col = col;
}

void RobotModel::setDir(int dir)
{
    m_dir = dir;
}

void RobotModel::moveStraight( )
{
    if (m_dir == 0)
    {
        m_col++;
    }
    else if (m_dir == 1)
    {
        m_row--;
    }
    else if (m_dir == 2)
    {
        m_col--;
    }
    else if (m_dir == 3)
    {
        m_row++;
    }
}

void RobotModel::turnLeft( )
{
    if (m_dir == 0)
    {
        m_row--;
        m_dir = 1;
    }
    else if (m_dir == 1)
    {
        m_col--;
        m_dir = 2;
    }
    else if (m_dir == 2)
    {
        m_row++;
        m_dir = 3;
    }
    else if (m_dir == 3)
    {
        m_col++;
        m_dir = 0;
    }
}

void RobotModel::turnRight( )
{
    if (m_dir == 0)
    {
        m_row++;
        m_dir = 3;
    }
    else if (m_dir == 1)
    {
        m_col++;
        m_dir = 0;
    }
    else if (m_dir == 2)
    {
        m_row--;
        m_dir = 1;
    }
    else if (m_dir == 3)
    {
        m_col--;
        m_dir = 2;
    }
}

void RobotModel::uTurn( )
{
    if (m_dir == 0)
    {
        m_col--;
        m_dir = 2;
    }
    else if (m_dir == 1)
    {
        m_row++;
        m_dir = 3;
    }
    else if (m_dir == 2)
    {
        m_col++;
        m_dir = 0;
    }
    else if (m_dir == 3)
    {
        m_row--;
        m_dir = 1;
    }
}

void RobotModel::reverse( )
{
    if (m_dir == 0)
    {
        m_col--;
    }
    else if (m_dir == 1)
    {
        m_row++;
    }
    else if (m_dir == 2)
    {
        m_col++;
    }
    else if (m_dir == 3)
    {
        m_row--;
    }
}

