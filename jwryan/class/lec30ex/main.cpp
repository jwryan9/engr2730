//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: main.cpp
// Description: This program contains in-class examples associated with 
//              lecture 30 on standard library classes.
// Building from command line (on linux):
//            g++ main.cpp -o main.exe
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>

void stringExample1();
void stringExample2();
void stringClickerQuestion();

void vectorExample();

int main()
{
    std::cout << "******************" << std::endl;
    std::cout << " STRING EXAMPLE 1 " << std::endl;
    std::cout << "******************" << std::endl;
    stringExample1();

    std::cout << std::endl;
    std::cout << "******************" << std::endl;
    std::cout << " STRING EXAMPLE 2 " << std::endl;
    std::cout << "******************" << std::endl;
    stringExample2();

    std::cout << std::endl;
    std::cout << "*************************" << std::endl;
    std::cout << " STRING CLICKER QUESTION " << std::endl;
    std::cout << "*************************" << std::endl;
    stringClickerQuestion();

    std::cout << std::endl;
    std::cout << "****************" << std::endl;
    std::cout << " VECTOR EXAMPLE " << std::endl;
    std::cout << "****************" << std::endl;
    vectorExample();

    return 0;
}

void stringExample1()
{
    std::string s1; // empty string
    std::string s2 = "Hello";
    std::string s3("world!");

    // assignment and concatenation example
    s1 = s2;    // assign one string to another
    s1 +=  " "; // concatenation with character string
    s1 += s3;   // concatenation with another string
    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "s3 = " << s3 << std::endl;

    // another option for concatenation
    std::string s4; // empty string
    s4 = s2 + " " + s3;
    std::cout << "s4 = " << s4 << std::endl;

    // comparing strings
    if (s1 == s4)
    {
        std::cout << "s1 is equal to s4" << std::endl;
    }

    if (s2 == "Hello")
    {
        std::cout << "s2 equals \"Hello\"" << std::endl;
    }

    // reading a string (one word)
    std::string name;
    std::cout << "Please enter your first name: ";
    std::cin >> name;
    std::cout << "Hello " << name << "!" << std::endl;

    // reading a line
    std::string completeName;
    std::cout << "Please enter your first and last name: ";
    std::cin.ignore(); // throw away remaining '\n'
    std::getline(std::cin, completeName, '\n'); //read until newline is encountered
    std::cout << "Hello " << completeName << "!" << std::endl;
}

void stringExample2()
{
    std::string myString = "CIE classroom";
    std::cout << "myString = " << myString << std::endl;

    // iterate through all elements of the string: option 1
    for (size_t i = 0; i < myString.length(); i++)
    {
        std::cout << myString[i] << " ";
    }
    std::cout << std::endl;

    // iterate through all elements of the string: option 2
    for (size_t i = 0; i < myString.length(); i++)
    {
        std::cout << myString.at(i) << " ";
    }
    std::cout << std::endl;

    // iterate through all elements of the string: option 3 (don't worry about this option)
    std::string::iterator iter;
    for (iter = myString.begin(); iter != myString.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    // search/replace example
    std::string searchString = "class";
    size_t pos = myString.find(searchString);
    if (pos != std::string::npos)
    {
        std::cout << searchString << " found at " << pos << std::endl;
    }

    // replace class with fun
    size_t startPos = pos;
    size_t numberCharsToReplace = searchString.size(); // can also use size() instead of length
    std::string replacementStr = "fun";
    myString.replace(startPos, numberCharsToReplace, replacementStr);
    std::cout << "After replacement, myString = " << myString << std::endl;
}

void stringClickerQuestion()
{
    std::string myDog1 = "Teddy";
    std::string myDog2 = "JT";

    std::string generalSentence = "dog and dog are very cute.";

    generalSentence.replace(generalSentence.find("dog"), 3, myDog1);
    generalSentence.replace(generalSentence.find("dog"), 3, myDog2);

    //std::cout << generalSentence << std::endl;
}


void vectorExample()
{
    // create an empty vector of integers
    std::vector<int> myNumbers;

    // display initial size of vector
    std::cout << "initial size of int vector = " << myNumbers.size() << std::endl;

    // add some numbers to the vector (vector automatically resized)
    for (int n=0; n < 10; n++)
    {
        myNumbers.push_back(n); // add to end
    }

    // print vector: option 1
    for (size_t i=0; i < myNumbers.size(); i++)
    {
        std::cout << myNumbers[i] << " ";
    }
    std::cout << std::endl;


    // print vector: option 2
    for (size_t i=0; i < myNumbers.size(); i++)
    {
        std::cout << myNumbers.at(i) << " ";
    }
    std::cout << std::endl;

    // print vector: option 3
    std::vector<int>::iterator it;
    for (it = myNumbers.begin(); it != myNumbers.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // modify elements of vector and print result
    for (size_t i=0; i < myNumbers.size(); i+=2)
    {
        myNumbers[i] = 0;
    }
    for (size_t i=0; i < myNumbers.size(); i++)
    {
        std::cout << myNumbers[i] << " ";
    }
    std::cout << std::endl;

    // remove last element and print result
    myNumbers.pop_back();
    std::cout << "size of integer vector after calling pop_back = " << myNumbers.size() << std::endl;
    for (size_t i=0; i < myNumbers.size(); i++)
    {
        std::cout << myNumbers[i] << " ";
    }
    std::cout << std::endl;


    // create vector of strings, with initial size of 3
    std::vector< std::string > myStrings(3);
    std::cout << "initial size of string vector = " << myStrings.size() << std::endl;
    myStrings.at(0) = "zero";
    myStrings.at(1) = "one";
    myStrings.at(2) = "two";

    for (size_t i = 0; i < myStrings.size(); i++)
    {
        std::cout << myStrings[i] << " ";
    }
    std::cout << std::endl;
}
