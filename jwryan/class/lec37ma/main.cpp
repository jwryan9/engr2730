//------------------------------------------------------------------
// Programmer: TODO: Jason Ryan
// Name: main.cpp
// Description: This program contains the mini-assignment for
//              lecture 37 (on abstract data types).
//
// Building from command line (on linux):
//            g++ main.cpp -o main.exe
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    //--------------------------------------------------------
    // Create a std::map<std::string, int>
    // object, add at least three std::string/int pairs to
    // the map object, and use an iterator to iterate through
    // the elements in the map to display the std::string/int
    // pair values.
    //--------------------------------------------------------

    std::map<std::string, int> myMap;

    myMap["String2"] = 9;
    myMap["String3"] = 2;
    myMap["String1"] = 18;

    map<string, int>::iterator myIter;
    for(myIter = myMap.begin(); myIter != myMap.end(); myIter++)
    {
        string strPiece = myIter->first;
        int intPiece = myIter->second;
        cout<<strPiece<<" "<<intPiece<<endl;
    }
    return 0;
}
