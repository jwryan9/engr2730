/*-------------------------------------------------------------------------
 * Programmer: Your Name Here
 * Name: main.cpp
 * Description: this program reads a sequence of integers (entered one at a time), keeping track of the number
 * of times a 2 is entered. The program will EITHER
 *    (a) Accept enter 10 number or integers OR
 *    (b) Keep on accepting integers until the user enters a -1 (optional)
 *  Once the sequence has been entered by the user, the total number of 2's will be printed.
 -------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

int main(void)
{
    int number2s = 0;
    int userNumber = 0;

//  Continue allowing user input of integers until -1 is entered.
    while(userNumber != -1)
    {
        cout << "Please enter integer or -1: " << endl;

        cin >> userNumber;

//      Track number of 2s entered.
        if (userNumber == 2)
        {
            number2s++;
        }
    }

//  Output number of 2s the user has entered.
    cout << "Number of 2s entered: " << number2s << endl;
}
