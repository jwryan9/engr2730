/*-----------------------------------------------------------------------------
 * Programmers: Jason Ryan, Kyle Anderson
 * Name: hw2.c
 * Description: .
 * To compile (using provided makefile) on linux:
 * > make
 * To load program onto robot (once usb programmer plugged in and robot on):
 * > make program
 ----------------------------------------------------------------------------*/

#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include <avr/pgmspace.h> /* allow use of program space */
#include <stdlib.h>       /* for random() functions */

const int NUM_PLAYERS = 20;


/* function prototype for battery check */
void bat_check( void );
/* function prototype for menuSelect*/
int menuSelect (void);
/* function prototype for readUserInput*/
void readUserInput (int, int, int *);
/* function prototype for getOverallBest*/
void getOverallBest(int[]);
/* function prototype for playGame */
void playGame(int[], int *, int *);
/* function prototype for getUserScore */
int getUserScore(int [], int *, int *);
/* function prototype for getUserID */
int getUserID(int *);

int main( void )
{
	/* perform battery check before starting the game */
	bat_check();

	//Initialize variables
	int *inputPtr = NULL;
	int *idPtr = NULL;
	int highScores[NUM_PLAYERS];
	int tempOne = 1;
	int tempTwo = 1;
	int i, selection;
	long seed = 0;
	
	//Set all high scores to -1
	for(i=0; i<NUM_PLAYERS; i++)
   {
       highScores[i] = -1;
   }

	inputPtr = &tempOne;
	idPtr = &tempTwo;

   while (1)
	{
		//Get user choice
		selection = menuSelect();
		
		//Act on user choice
		if(selection == 1)
		{
			clear(); // clear the LCD
      	lcd_goto_xy(0,0);
      	print("PRESS B");
      	lcd_goto_xy(0,1);
      	print("TO PLAY");
      	wait_for_button_press(BUTTON_B);
        
      	while(button_is_pressed(BUTTON_B))//While button is not released
				seed++;
			srandom(seed); //Seed random number
			
			playGame(highScores, inputPtr, idPtr);
		}		
		
		if(selection == 2)
			getUserScore(highScores, inputPtr, idPtr);
			
		if(selection == 3)
			getOverallBest(highScores);
    }
}

/*
Function name: readUserInput
Description:
Inputs: int min = lowest selection available to user
        int max = maximum selection available to user
        int *inputPtr = pointer to location where user selection is 
                        stored
Outputs: None
*/
void readUserInput (int min, int max, int *inputPtr)
{
	int delay;
	int val = *inputPtr;
	int done = 0;

   //Wait half second
   delay_ms(500);

	clear();
	lcd_goto_xy(3,0);
	print_long(val);
	lcd_goto_xy(0,1);
	print("<      >");

	while(!done)
	{
		delay = 500;
		
		//Decrease number choice
		while(button_is_pressed(BUTTON_A))
		{
			//Test if number is valid
			if(val > min)
				val--;

			clear();
			lcd_goto_xy(3,0);
			print_long(val);
			lcd_goto_xy(0,1);
			print("<      >");

			delay_ms(delay);
			delay = 50;
		}

		//Increase number choice
		while(button_is_pressed(BUTTON_C))
		{
			//Test if number is valid
			if(val < max)
				val++;

			clear();
			lcd_goto_xy(3,0);
			print_long(val);
			lcd_goto_xy(0,1);
			print("<      >");

			delay_ms(delay);
			delay = 50;
		}

		//User selected current number
		while(button_is_pressed(BUTTON_B))
		{
			wait_for_button_release(BUTTON_B);
			done = 1;
		}
	}

	//Set value
	*inputPtr = val;
}

/*
Function name: getOverallBest
Description: This function finds the overall high score and returns it.
Inputs: highScores = integer array = array of current high scores
Outputs: None
*/
void getOverallBest(int highScores[])
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

	//Print if games have been recorded
	if(highScore != -1)
	{
   	clear();
   	lcd_goto_xy(0,0);
   	print("TopScore");
   	lcd_goto_xy(3,1);
   	print_long(highScore);
   	delay_ms(2000);
	}
	else 
	{
		clear();
		lcd_goto_xy(0,0);
		print("NO GAMES");
		lcd_goto_xy(0,1);
		print("PLAYED");
		delay_ms(2000);	
	}
}

/*
Function name: menuSelect
Description: Function reads selection A,B,C and returns integer
             equivalent.
Inputs: void
Outputs: Integer
*/
int menuSelect (void)
{
	int selection = NULL;
	int done = 0;
	unsigned char button;
	
	clear();
	lcd_goto_xy(0,0);
	print("Hold");
	lcd_goto_xy(0,1);
	print("Button");
	delay_ms(1000);

	clear();
	lcd_goto_xy(3,0);
	print("For");
	lcd_goto_xy(1,1);
	print("Choice");
	delay_ms(1000);
   
   //Loop main menu until user makes a selection
   while(!done)
   {   	
		clear();
		lcd_goto_xy(0,0);
		print("A. Play");
		lcd_goto_xy(3,1);
		print("Game");
		delay_ms(1000);
		
		//Stop loop if button is pressed
		if(button_is_pressed(ANY_BUTTON))
		{
			button = button_is_pressed(ANY_BUTTON);
			wait_for_button_release(button);
			break;
		}		
		
		clear();
		lcd_goto_xy(0,0);
		print("B. User");
		lcd_goto_xy(3,1);
		print("Best");
		delay_ms(1000);
		
		//Stop loop if button is pressed
		if(button_is_pressed(ANY_BUTTON))
		{
			button = button_is_pressed(ANY_BUTTON);
			wait_for_button_release(button);
			break;
		}	
		
		clear();
		lcd_goto_xy(0,0);
		print("C. High");
		lcd_goto_xy(3,1);
		print("Score");
		delay_ms(1000);

		//Stop loop if button is pressed
		if(button_is_pressed(ANY_BUTTON))
		{
			button = button_is_pressed(ANY_BUTTON);
			wait_for_button_release(button);
			break;
		}
   }
   
   switch (button)
   {
	   case BUTTON_A:
   	   selection = 1;
         break;
      case BUTTON_B:
      	selection = 2;
         break;
      case BUTTON_C:
      	selection = 3;
         break;
    }

    return selection;
}

/*
Function name: getUserID
Description: Function prompts user to select ID number and returns that number
Input: int *idPtr = pointer to location where user id is stored
Output: User ID as integer
*/
int getUserID(int *idPtr)
{
	*idPtr = 1;	
	
	clear();
   lcd_goto_xy(0,0);
   print("Enter ID"); //Prompts player to enter ID number
	delay_ms(500);
   readUserInput(1,20,idPtr); //User enters Player ID number
	return *idPtr; // Player ID number is stored
}

/*-----------------------------------------------------------------------------
 * Function name: playGame
 * Description: This function randomizes a number and asks the user to guess what
 *              the number is until they get it correct.
 * Inputs: highScore = integer array = array of current high scores
-----------------------------------------------------------------------------*/
void playGame(int highScores[], int *inputPtr, int *idPtr)
{
   int num = 1 + random()%100; //sets num to random number
   int guess_count = 1;
   int guess = -1;
   int user;

	user = getUserID(idPtr);

   delay_ms(500);

   while (guess != num) //If guess was incorrect
   {
   	clear();
      lcd_goto_xy(0,0);
      print("Guess #"); //Prompts user to enter guess
      delay_ms(500);
      readUserInput(1,100,inputPtr); //User enters guess
      guess = *inputPtr; //Stores value entered as the guess

      if (guess < num) //Guess too low
      {
      	clear();
         lcd_goto_xy(0,0);
         print("2 low!");
         guess_count++; //Adds one to number of guesses
         delay_ms(2000);
      }
      else if (guess > num) //Guess too high
      {
      	clear();
         lcd_goto_xy(0,0);
         print("2 high!");
         guess_count++; //Adds one to number of guesses
         delay_ms(2000);
      }
      else
      {
      	if (highScores[user - 1] == -1) //Checks for previous games played
         {
         	highScores[user - 1] = guess_count; //No games played; stores number of guesses
         }
         else if (guess_count < highScores[user - 1]) //Checks if # of guesses is lower than previous best score
         {
         	highScores[user - 1] = guess_count; //Stores number of guesses as best score
         }

    	}
    }
    
	clear();
   lcd_goto_xy(0,0);
   print("Correct"); //Prints that guess was correct
   delay_ms(1000);
    
   clear();
   lcd_goto_xy(0,0);
   print_long(user);
   lcd_goto_xy(3,0);
   print("Best:");
   lcd_goto_xy(0,1);
   print_long(highScores[user - 1]); //Prints the best score for that user
   delay_ms(1000);
   return;
}

/*-----------------------------------------------------------------------------
 * Function name: getUserScore
 * Description: This function finds the best score for a specificed user.
 * Inputs: highScore = integer array = array of current high scores
           size = integer = size of highScore array
 * Outputs: score = integer = the highest score of the user
-----------------------------------------------------------------------------*/

int getUserScore(int highScores[], int *inputPtr, int *idPtr)
{
	int score, user;
	
	user = getUserID(idPtr);

	score = highScores[user - 1]; //Shows score for user entered
	
	if (score == -1)
   {
   	clear();
      lcd_goto_xy(0,0);
      print_long(user);
      lcd_goto_xy(0,1);
      print("NO GAMES");
      delay_ms(2000);
   }
   else
   {
   	clear();
      lcd_goto_xy(0,0);
      print_long(user);
      lcd_goto_xy(3,0);
      print("BEST:");
      lcd_goto_xy(0,1);
      print_long(score); //Prints score
      delay_ms(2000);
   }
   
   return score;
}

/*-----------------------------------------------------------------------------
-----------------------------------------------------------------------------
 * Function name: bat_check
 * Description: This function checks the voltage on the batteries and
 *              displays a message on the LCD until the user presses B.
 *              The message on the first line cycles between the following:
 *              Bat Chk       [-> descriptive message]
 *              xxxxmV        [-> the battery voltage]
 *              Okay/Replace  [-> whether the batteries should be replaced]
 ----------------------------------------------------------------------------*/
void bat_check( void )
{
    int firstLineType = 0; /* what should be displayed on line 1 */
                           /*  0-19: Bat Chk */
                           /* 20-39: xxxxmV  */
                           /* 40-59: Okay/Replace */
    int bat = 0;           /* last read battery voltage */

    /* wait for user to press button B */
    while(!button_is_pressed(BUTTON_B))
    {
        /* clear the lcd */
        clear();

        /* FIRST LINE */
        /* set lcd position to beginning of first line */
        lcd_goto_xy(0,0);

        /* for first line, alternate between displaying:
         Bat Check
         xxxxmV
         Okay/Replace */

        if (firstLineType < 20)
        {
            print("Bat Chk");
        }
        else if (firstLineType < 40)
        {
            bat = read_battery_millivolts();
            print_long(bat);
            print("mV");
        }
        else if (firstLineType < 60)
        {
            if (bat >= 4500)
            {
                print("Okay"); /* okay */
            }
            else
            {
                print("Replace"); /* replace */
            }
        }
        firstLineType++;
        firstLineType = firstLineType % 60;

        /* SECOND LINE */
        /* set lcd position to beginning of second line */
        lcd_goto_xy(0,1);
        print("Press B");

        /* small delay */
        delay_ms(50);
    }

    /* once pressed, wait a little bit */
    delay_ms(500);
}
