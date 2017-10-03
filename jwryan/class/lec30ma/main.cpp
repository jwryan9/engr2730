//-----------------------------------------------------------------------------
// Programmer: Jason Ryan
// Name: main.cpp
// Description: This program contains the mini-assignment associated with
//              lecture 30. It must contain a program that creates/uses objects
//              of the std::string and std::vector classes.
// Building from command line (on linux):
//              g++ main.cpp -o main.exe
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    std::string s1;
    std::string s2;
    std::string s3;
    std::string s4;

    std::vector<int> v1;
    std::vector<int> v2;

    s1 = "These are strings ";
    s2 = "concatenated together.";
    s3 = "Here is vector 1: ";
    s4 = "Here is vector 1 multiplied by 2: ";

    s1 = s1 + s2;

    std::cout<<s1<<std::endl;

    for(int i=0; i<5; i++)
        v1.push_back(i);

    for(size_t i=0; i<v1.size(); i++)
        v2.push_back(i*2);


    std::cout<<s3;

    for (size_t i=0; i<v1.size(); i++)
        std::cout<<v1.at(i)<<" ";
    std::cout<<std::endl;

    std::cout<<s4;

    for(size_t i=0; i<v2.size(); i++)
        std::cout<<v2.at(i)<<" ";
    std::cout<<std::endl;

    return 0;
}

