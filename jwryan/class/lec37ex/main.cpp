//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: main.cpp
// Description: This program contains in-class examples associated with
//              lecture 37 (on revisiting abstract data types)
// Building from command line (on linux):
//            g++ main.cpp ArrayADT.cpp -o main.exe
//-----------------------------------------------------------------------------
#include <iostream>
#include "ArrayADT.h"
#include <map>
#include <sstream>


// ArrayADT example
void arrayADTExample();

// std::map example
void mapExample();
void clickerQuestion();

// std::stringstream example
void stringstreamExample();
std::string showAddition(int x, int y);

int main()
{
    std::cout << "-----------------" << std::endl;
    std::cout << "arrayADTExample()" << std::endl;
    std::cout << "-----------------" << std::endl;
    arrayADTExample();

    std::cout << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << "mapExample()" << std::endl;
    std::cout << "------------" << std::endl;
    mapExample();

    std::cout << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "clickerQuestion():" << std::endl;
    std::cout << "------------------" << std::endl;
    //clickerQuestion();
    
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "stringstreamExample()" << std::endl;
    std::cout << "---------------------" << std::endl;
    stringstreamExample();

    return 0;
}

void arrayADTExample()
{
    ArrayADT myArray1(10);

    for (int i = 0; i < myArray1.getLength(); i++)
    {
        myArray1.set(i,5);
    }

    ArrayADT myArray2(myArray1);
    myArray2.set(5,30);

    std::cout << "myArray1: " << std::endl;
    myArray1.print();
    std::cout << "myArray2: " << std::endl;
    myArray2.print();
}

void mapExample()
{
    // create a map with integer keys and floating point values
    std::map< int, float > myMap;

    // "add" some items to myMap
    myMap[3] = 3.2;
    myMap[1] = 7.8;
    myMap[10] = 1.6;
    myMap[8] = 0.0;

    // iterate through items in myMap in ascending order
    std::cout << "Iterating through items in ascending order using iterator:" << std::endl;
    std::map< int, float >::iterator myIter;
    for(myIter = myMap.begin(); myIter != myMap.end(); myIter++)
    {
        int intValue = myIter->first;
        float floatValue = myIter->second;
        std::cout << intValue << " " << floatValue << std::endl;
    }

    // iterate through items in myMap in ascending order using constant iterator
    std::cout << "Iterating through items in ascending order using const iterator:" << std::endl;
    std::map< int, float >::const_iterator myCIter;
    for(myCIter = myMap.begin(); myCIter != myMap.end(); myCIter++)
    {
        int intValue = myCIter->first;
        float floatValue = myCIter->second;
        std::cout << intValue << " " << floatValue << std::endl;
    }

    // iterate through items in myMap in descending order
    std::cout << "Iterating through items in descending order using reverse iterator:" << std::endl;
    std::map< int, float >::reverse_iterator myReverseIter;
    for(myReverseIter = myMap.rbegin(); myReverseIter != myMap.rend(); myReverseIter++)
    {
        int intValue = myReverseIter->first;
        float floatValue = myReverseIter->second;
        std::cout << intValue << " " << floatValue << std::endl;
    }

    // iterate through items in constant version of myMap in descending order using constant iterator
    // create "const" version of map
    // (aside: having a const object was required to use rend() with my compiler)
    const std::map< int, float > myCMap(myMap);
    std::cout << "Iterating through items in descending order using const reverse iterator:" << std::endl;
    std::map< int, float >::const_reverse_iterator myCReverseIter;
    for(myCReverseIter = myCMap.rbegin(); myCReverseIter != myCMap.rend(); myCReverseIter++)
    {
        int intValue = myCReverseIter->first;
        float floatValue = myCReverseIter->second;
        std::cout << intValue << " " << floatValue << std::endl;
    }

    // find a particular key and modify its floating point value
    std::cout << "Finding/changing item with key of 10:" << std::endl;
    std::map< int, float >::iterator searchIter;
    searchIter = myMap.find(10);
    if (searchIter != myMap.end()) // if found
    {
        std::cout << "before: " << searchIter->first << " " << searchIter->second << std::endl;
        searchIter->second += 1.2;
        std::cout << "after: " << searchIter->first << " " << searchIter->second << std::endl;
    }

    // removing the above item from the map
    std::cout << "Erasing item with key of 10." << std::endl;
    if (searchIter != myMap.end())
    {
        myMap.erase(searchIter);
    }

    // iterate through items in myMap in descending order
    std::cout << "Iterating through items in descending order using reverse iterator:" << std::endl;
    std::map< int, float >::reverse_iterator myReverseIter2;
    for(myReverseIter2 = myMap.rbegin(); myReverseIter2 != myMap.rend(); myReverseIter2++)
    {
        int intValue = myReverseIter2->first;
        float floatValue = myReverseIter2->second;
        std::cout << intValue << " " << floatValue << std::endl;
    }

    // removing all items from the map
    myMap.clear();
}

void clickerQuestion()
{
    // create a map with integer keys and floating point values
    std::map< int, float > myMap;

    myMap[0] = 1.0;
    myMap[3] = 2.0;
    myMap[2] = 4.0;

    std::map< int, float >::iterator it;
    for(it = myMap.begin(); it != myMap.end(); it++)
    {
        if (it->second > 3.0)
        {
            it->second = 0.0;
        }
    }

    std::map< int, float >::reverse_iterator r_it;
    for (r_it = myMap.rbegin(); r_it != myMap.rend(); r_it++)
    {
        std::cout << r_it->second << std::endl;
    }
}

std::string showAddition(int x, int y)
{
    std::stringstream additionProblem;
    int result;
    
    additionProblem << x << " + " << y;
    result = x + y;
    additionProblem << " = " << result;
    return additionProblem.str();
}


void stringstreamExample()
{
    int x = 15;
    int y = 35;
    std::cout << "What is " << x << " + "
    << y << "?" << std::endl;
    std::string answer = showAddition(x,y);
    std::cout << answer << std::endl;
}



