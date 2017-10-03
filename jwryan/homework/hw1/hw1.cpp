/*------------------------------------------------------------------------------
 * Programmer: Jason Ryan
 * Date: 2/9/2016
 * Name: hw1.cpp
 * Description: This program is for Homework 1. It is a random number guessing
                game that requires to player with an ID number from 1-20 to guess
                a randomly generated number (1-100) in as few tries as possible.
                The best scores of each of the 20 players is recorded in an array.
                The game has a main menu which allows the user to start a new game,
                check the high score of an individual player, or check the overall
                high score for the game.

Pseudo Code:

main
	initialize variables

	for loop
		initialize array for player high scores to -1

	while (don't quit)
		output menu
		wait for user selection

		validate user input

		switch
			case 1
				play game
			case 2
				get personal best
			case 3
				get overall best
				if no games played
					tell user
				else
					return high score

	if quit
		exit game

void playGame(int highScores[])
	initialize variables

	ask for player number
	wait for user input

	validate user input

	seed amd generate random number

	while (incorrect guess)
		ask for guess
		wait for user guess

		validate guess

		if guess > random num
			print too high
		if guess < random num
			print too low

		score + 1

	if guess correct
		print congratulations with score

		if score < high score
			set new high score

int getPersonalBest(int highScores[])
	initialize variables
	request player number

	validate input

	return player high score

int getOverallBest(int highScores[])
	initialize variables

	for loop
		set greatest score as high score
	for loop
		set lowest score as high score if != -1

	return high score

int showLeaderboard(int highScoresp[])
    initialize variables

    set scores 1 through 3
    set players 1 through 3

    if scores 1 through 3 valid
        print leaderboard
        return true
    else
        return false

int validInput(int input, int low, int high)
	if input >= low and <= highh
		return 1
	else
		reutn false
 -------------------------------------------------------------------------------*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int NUM_PLAYERS = 20;

using namespace std;

void playGame(int highScores[]);
int getPersonalBest(int highScores[]);
int getOverallBest(int highScores[]);
int showLeaderboard(int highScores[]);
int validInput(int input, int low, int high);

int main (void)
{
    int board, highScore, highScores[NUM_PLAYERS], i, personalBest, selection;

    //Initialize the best scores array to all -1
    //NOTE: When assigning scores must subtract 1 from player id number.
    for(i=0; i<NUM_PLAYERS; i++)
    {
        highScores[i] = -1;
    }

    //Main menu
    while(selection != -1)
    {
    	//Main menu for the game.
    	cout << "\nPlease select an option from the list below.\n" << endl << "1. Play a new game." << endl
    	<< "2. Show my best score" << endl << "3. Show overall best score." << endl << "4. Show leaderboard." << endl <<  endl << "\nEnter -1 to quit" << endl;
    	cin >> selection;

    	while(!validInput(selection, 1, 4) && selection != -1)
        {
            cout << "\nPlease enter a valid selection. (1-3)" << endl;
            cin >> selection;
        }

        //Main Menu switch statement.
        switch(selection)
        {
            case 1:
                playGame(highScores);
                break;
            case 2:
                personalBest = getPersonalBest(highScores);
                if(personalBest == -1)
                    cout << "\nYou have not played any games." << endl;
                else
                    cout << "\nPersonal Best: " << personalBest << endl;
                break;
            case 3:
                highScore = getOverallBest(highScores);
                if(highScore == -1)
                    cout << "\nNo games have been played." << endl;
                else
                    cout << "\nHigh Score: " << highScore << endl;
                break;
            case 4:
                board = showLeaderboard(highScores);
                if(!board)
                    cout << "\nNot enough players have played for leaderboard." << endl;
                break;
        }
    }

	cout << "Thanks for playing! Bye bye." << endl;

    return 0;
}

/*

Function name: playGame
Description: This function runs the random number guessing game.
Inputs: highScores = integer array = array of current high scores
Outputs: None

*/
void playGame(int highScores[])
{
    int guess, playerNum, randNum;
    int score = 0;

    cout << "Enter your Player ID Number. (1-20)" << endl;
    cin >> playerNum;

    //Validate user input.
    while(!validInput(playerNum, 1, 20))
    {
        cout << "Please enter a valid Player ID Number. (1-20)" << endl;
        cin >> playerNum;
    }

    //Generate random number 1-100
    srand((unsigned)time(NULL));
    randNum = rand() % 100 + 1;

    //User guess logic
    while(guess != randNum)
    {
        cout << "\nEnter your guess (1-100): " << endl;
        cin >> guess;

        while(!validInput(guess, 1, 100))
        {
            cout << "\nEnter a valid guess (1-100): " << endl;
            cin >> guess;
        }

        if(guess > randNum)
        {
            cout << "Too high!" << endl;
        }

        if(guess < randNum)
        {
            cout << "Too low!" << endl;
        }

        score++;
    }

    if(guess == randNum)
    {
        cout << "Congratulations player # " << playerNum <<"! Your score was " << score << "!" << endl;

        //Assign score to player in highScores array
        if(highScores[playerNum-1] == -1 || highScores[playerNum-1] < score)
        {
           highScores[playerNum-1] = score;
        }
    }
}

/*

Function name: getPersonalBest
Description: This function finds a player's personal high score and returns it.
Inputs: highScores = integer array = array of current high scores
Outputs: Player's high score as integer

*/
int getPersonalBest(int highScores[])
{
    int playerNum;

    cout << "Enter your player ID number. (1-20)" << endl;
    cin >> playerNum;

    //Validate user input
    while(!validInput(playerNum, 1, 20))
    {
        cout << "Please enter a valid Player ID Number. (1-20)" << endl;
        cin >> playerNum;
    }

    return highScores[playerNum-1];
}

/*

Function name: getOverallBest
Description: This function finds the overall high score and returns it.
Inputs: highScores = integer array = array of current high scores
Outputs: Overall high score as integer

*/
int getOverallBest(int highScores[])
{
    int highScore, i;

    highScore = -1;

    //Assign high score to highest value first to avoid having -1 returned when games have been played.
    for(i = 0; i < NUM_PLAYERS; i++)
    {
        if(highScores[i] > highScore)
            highScore = highScores[i];
    }

    for(i = 0; i < NUM_PLAYERS; i++)
    {
        if(highScores[i] < highScore && highScores[i] != -1)
            highScore = highScores[i];
    }

    return highScore;
}

/*

Function name: showLeaderboard
Description: Determines the top three overall scores and prints them as a leaderboard. 
Inputs: highScores = integer array = array of current high scores
Outputs: 1 if enough scores for leaderboard, 0 of not.

*/
int showLeaderboard(int highScores[])
{
    int one = -1, two = -1, three = -1;
    int i, playerOne, playerTwo, playerThree;

    //Set top score to result of getOverallBest
    one = getOverallBest(highScores);

    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        if(highScores[i] == one)
            playerOne = i+1;
    }

    //Set top next two scores to next largest scores after score one. Use similar method to that in getOverallBest().
    for(i = 0; i < NUM_PLAYERS; i++)
    {
        if(highScores[i] > two)
            two = highScores[i];
    }

    for(i = 0; i < NUM_PLAYERS; i++)
    {
        if(highScores[i] < two && highScores[i] != -1)
        {
            if(i+1 != playerOne)
            {
                two = highScores[i];
                playerTwo = i+1;
            }
        }
    }

    for(i = 0; i < NUM_PLAYERS; i++)
    {
        if(highScores[i] > three)
            three = highScores[i];
    }

    for(i = 0; i < NUM_PLAYERS; i++)
    {
        if(highScores[i] < three && highScores[i] != -1)
        {
            if(i+1 != playerOne && i+1 != playerTwo)
            {
                three = highScores[i];
                playerThree = i+1;
            }
        }
    }

    //Check if enough games have been played to have leaderboard.
    if (one != -1 && two != -1 && three != -1)
    {
        //Output if scores are all different
        if(one != two && two != three)
        {
            cout << "Scoring Leaders" << endl << "\n1. Player: " << playerOne << " Score: " << one << endl;
            cout << "\n2. Player: " << playerTwo << " Score: " << two << endl;
            cout << "\n3. Player: " << playerThree << " Score: " << three << endl;
        }

        //Output if scores one and two are same
        else if(one == two && two != three)
        {
            cout << "Scoring Leaders" << endl << "\n1. Player: " << playerOne << " Score: " << one << endl;
            cout << "\n1. Player: " << playerTwo << " Score: " << two << endl;
            cout << "\n3. Player: " << playerThree << " Score: " << three << endl;
        }

        //Output if scores two and three are same
        else if(one != two && two == three)
        {
            cout << "Scoring Leaders" << endl << "\n1. Player: " << playerOne << " Score: " << one << endl;
            cout << "\n2. Player: " << playerTwo << " Score: " << two << endl;
            cout << "\n2. Player: " << playerThree << " Score: " << three << endl;
        }

        //Output if scores one, two and three are same
        else if(one == two && two == three)
        {
            cout << "Scoring Leaders" << endl << "\n1. Player: " << playerOne << " Score: " << one << endl;
            cout << "\n1. Player: " << playerTwo << " Score: " << two << endl;
            cout << "\n1. Player: " << playerThree << " Score: " << three << endl;
        }

        return 1;
    }

    else
        return 0;

}


/*

Function name: validInput
Description: This function determines whether an integer is between two other integers inclusive.
Inputs: input = int = number to test
        low = int = lower limit
        high = int = upper limit
Outputs: 1 if input is between low and high, 0 if it is outside that range

*/
int validInput(int input, int low, int high)
{
    if(input >= low && input <= high)
        return 1;
    else
        return 0;
}