//-------------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: RobotModel.h
// Description: This file contains a class to model a robot. A RobotModel
//              object has a current row/col position and direction. The
//              direction defines where the robot will move if the robot is to
//              move straight ahead:
//              0 = east or an increasing column direction,
//              1 = north or a decreasing row direction
//              2 = west or a decreasing column direction
//              3 = south or an increasing row direction
//              Methods are also provided to modify the current position and
//              direction of a given robot to move one unit straight, move one
//              unit to the left, move one unit to the right, and make a u-turn.
//-------------------------------------------------------------------------------
#ifndef ROBOTMODEL_H
#define ROBOTMODEL_H

class RobotModel
{
public:
            //-----------------------------
            // GROUP: Data accessors
            //-----------------------------
    // returns the current row position of the robot
    int getRow( ) const;
    // returns the current column position of the robot
    int getCol( ) const;
    // returns the current direction of the robot
    int getDir( ) const;

            //-----------------------------
            // GROUP: Data modification
            //-----------------------------
    // sets the current row position of the robot
    void setRow(int row);

    // sets the current column position of the robot
    void setCol(int col);

    // sets the current direction of the robot
    // (0=East ->, 1=North ^, 2=West <-, 3=South v)
    void setDir(int dir);

    // modifies the robot's position so that it moves
    // forward one unit
    void moveStraight( );

    // modifies the robot's position and direction so that
    // it turns left and moves one unit in this new direction
    void turnLeft( );

    // modifies the robot's position and direction so that
    // it turns right and moves one unit in this new direction
    void turnRight( );

    // modifies the robot's position and direction so that it
    // makes a 180-degree turn and moves one unit in this new direction
    void uTurn( );

    // modifies the robot's position (without changing its direction)
    // so that it moves one unit in reverse
    void reverse( );

private:
    int m_row; // current row position
    int m_col; // current column position
    int m_dir; // current direction (0=East ->, 1=North ^, 2=West <-, 3=South v)
};

#endif // ROBOTMODEL_H
