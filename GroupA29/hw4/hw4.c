/*------------------------------------------------------------------------------
 * Programmers: Jason Ryan, Kyle Anderson
 * Name: hw4.c
 * Description: This program first sends a robot through a maze and records each
                turn that the robot makes in a linked list. It then takes input
                from the user specifying the "addresses" it needs to visit. The
                program then optimizes the linked list according to the user input
                by ignoring the addresses that the user did not enter. Finally,
                the robot traverses the maze, visiting all of the locations
                specified by the user.
 * Psuedocode:  Check battery
                Calibrate sensors
                Learn addresses in maze using function (description below)
                Find max addresses available using function
                Dynamically allocate enough memory to hold delivery addresses
                If successful in allocating memory
                    Prompt user to enter delivery addresses
                    While user is entering the addresses
                        If user enters -1
                            Exit loop
                        If address entered was already entered previously
                            Do not store and prompt for another
                        If number of addresses entered is the maximum
                            Exit loop
                        Else
                            Sort addresses numerically
                    Optimize turns list using function
                    Go to optimized turns list address using function
                    Free dynamically allocated memory
 -------------------------------------------------------------------------------*/
#include <pololu/3pi.h>         /* allow use of 3pi robot functions */
#include "hw4-utility.h"        /* extra functions for hw4 */
#include "turnList.h"           /* linked list functions */
#include <stddef.h>
#include <stdlib.h>


/* function prototypes for HW4-part2
 -------------------------------------------------------------------------------*/
void learnAddresses(NodePtr *learnedTurns);
void goToAddresses(NodePtr learnedTurns);

// Music
//-------
const char Ready[] PROGMEM = "T500>d-d-r16>d-r8r8r8";

const char welcome[] PROGMEM = ">g32>>c32";

/* main function
 -------------------------------------------------------------------------------*/
int main( void )
{
    NodePtr turnsList = NULL;
    NodePtr optTurnsList = NULL;
    NodePtr *addresses = NULL;
    int *deliveries = NULL;
    int maxTurns, input, temp, i=1, j=0, done=0;
    /* perform battery check */
    bat_check();

        /* calibrate line sensors */

    play_from_program_space(welcome);
    clear();
    print("Calibrate");
    auto_calibrate_line_sensors();

    clear();
    print("Learning"); //prints first line
    lcd_goto_xy(0,1);
    print("Track"); //prints second line
    learnAddresses(&turnsList); //sends robot throughout maze, records turns
    clear();

    while(1)
    {
        print("Delivery");
        lcd_goto_xy(0,1);
        print("Press B");
        wait_for_button(BUTTON_B);

        play_from_program_space(Ready);
        while(is_playing());

        maxTurns = giveAddressPointers(turnsList, &addresses) - 2; //finds maximum number of possible addresses
        deliveries = (int *)malloc((maxTurns + 2)*sizeof(int)); //dynamically allocates memory for delivery addresses
        if(deliveries != NULL) //memory successfully allocated
        {
            clear();
            lcd_goto_xy(0,0);
            print("Enter");
            lcd_goto_xy(0,1);
            print("Address"); //prompts user for addresses
            delay_ms(1000);
            deliveries[0] = readUserInput(-1, maxTurns, 0); //stores user input in deliveries array
            input = deliveries[0]; //stores user input in input variable
            delay_ms(1000);

            while(done == 0) //while user continues to enter addresses
            {
                clear();
                lcd_goto_xy(0,0);
                print("Enter");
                lcd_goto_xy(0,1);
                print("Address"); //prompts user for addresses
                delay_ms(1000);
                input = readUserInput(-1, maxTurns, 0); //stores user input in input variable
                if(input == -1) //if user is finished entering addresses
                {
                    done = 1; //exit loop
                }
                else
                {
                    for(j=0;j<i;j++) //check every entry
                    {
                        if(input == deliveries[j]) //if address has already been entered
                        {
                            clear();
                            lcd_goto_xy(0,0);
                            print("Already");
                            lcd_goto_xy(0,1);
                            print("Entered");
                            delay_ms(1000);
                            j = i + 1; //break loop
                        }
                    }
                    if(j == i) //address has not been entered yet
                    {
                        deliveries[i] = input; //store address
                        while(deliveries[j] < deliveries[j-1]) //sort address array
                        {
                            temp = deliveries[j];
                            deliveries[j] = deliveries[j-1];
                            deliveries[j-1] = temp;
                            j--;
                        }
                        i++; //increment i
                        if(i > maxTurns) //if no more possible entries
                        {
                            done = 1; //exit loop
                        }
                    }
                }
            }

            optTurnsList = giveOptimizedTurnList(turnsList, deliveries, i - 1); //optimize list with delivery addresses
            delay_ms(500);
            goToAddresses(optTurnsList); //visit each address
            freeAllMemoryInTurnList(&optTurnsList); //free memory
        }
    }

}

//----------------------------------------------------------------------------
// learnTrack: learn the track by going around the track and
//              adding to the linked list
// Input   learnedTurns = NodePtr*   (pointer to the linked list)
// Output  learnedTurns = NodePtr* = this list will be updated by the learned
//                        turns.
//---------------------------------------------------------------------------------

void learnAddresses(NodePtr *learnedTurns)
{

    int done = 0;

    int black_to_left;
    int black_ahead ;
    int black_to_right;
    int black_all_around;
    unsigned char volume = 50; /* volume for notes */
    // Until the packing station is reached, repeat the following
    //-----------------------------------------

    while (! done)
    {
        follow_segment(); //move straight until intersection
        get_surrounding_status(&black_to_left, &black_ahead, &black_to_right, &black_all_around); //check intersection
        if(black_all_around == 1) //if back at dispatch
        {
            appendTurnToEnd(learnedTurns, 'U'); //add U to turns list
            uTurn();
            delay_ms(250);
            stopRobot(); //stop movement
            return; //exit loop
        }
        else if(black_all_around==0) //not at dispatch
        {
            if(black_to_left == 1) //left turn available
            {
                appendTurnToEnd(learnedTurns, 'L'); //add L to turns list
                turnLeft();
            }
            else if(black_ahead==1) //no left turn, straight path
            {
                    appendTurnToEnd(learnedTurns, 'S'); //add S to turns list
                    moveStraight();
            }
            else if(black_to_right==1) //no left turn, no straight, right turn available
            {
                appendTurnToEnd(learnedTurns, 'R'); //add R to turns list
                turnRight();
            }
            else if((black_to_left+black_to_right+black_ahead) == 0) //no black on any side
            {
                appendTurnToEnd(learnedTurns, 'U'); //add U to turns list
                play_note(A(4), 50, volume); //play note at address
                uTurn();
            }
        }
    }

    return;
}

//----------------------------------------------------------------------------
// goToAddresses: go to the delivery addresses by following the optimal path
//              specified by turnList
// Input   learnedTurns = NodePtr  = pointer to the linked list
//---------------------------------------------------------------------------------

void goToAddresses(NodePtr turnList)
{

    clear();
    print("Calibrate");
    auto_calibrate_line_sensors(); //calibrate sensors

    int done = 0;
    int black_to_left;
    int black_ahead ;
    int black_to_right;
    int black_all_around;
    unsigned char volume = 50; /* volume for notes */
    NodePtr currentPtr = turnList; //sets NodePtr currentPtr to the same place as turnList

    while (! done)
    {

        clear();
        print("Deliveri");
        lcd_goto_xy(0,1);
        print("ng");

        follow_segment();
        get_surrounding_status(&black_to_left, &black_ahead, &black_to_right, &black_all_around);
        if(black_all_around == 1) //if at dispatch
        {
            uTurn();
            delay_ms(250);
            stopRobot();
            return;
        }
        else if(black_all_around == 0) //if not at dispatch
        {
            if(black_to_left || black_to_right) //if at intersection
            {
                delay_ms(250);
                if(currentPtr->nextPtr == NULL) //if turn list is empty
                {
                    uTurn();
                    delay_ms(250);
                    stopRobot();
                    return;
                }
                else //if turns list is not empty
                {
                    if(currentPtr->turn == 'L') //if next move in turns list is a left
                        turnLeft();

                    else if(currentPtr->turn == 'S') //if next move in turns list is to go straight
                        moveStraight();

                    else if(currentPtr->turn == 'R') //if next move in turns list is to go right
                        turnRight();

                    else if(currentPtr->turn == 'U') //if next move in turns list is to do a U Turn (at an address)
                    {
                        play_note(B(4), 50, volume); //play note
                        uTurn();
                    }

                    currentPtr = currentPtr->nextPtr; //traverse turns list
                }
            }
        }

        clear();
    }
}




