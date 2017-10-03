//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: main.cpp
// Description: This program contains in-class examples associated with 
//              lecture 31 on standard library classes and the use of classes
//              needed for homework 5.
// Building from command line (on linux):
//  > g++ main.cpp Image.cpp EasyBMP/EasyBMP.cpp -o main.exe
// To run (assuming testImage.bmp is located in the same diretory as main.exe):
//  > ./main.exe testImage.bmp invertedOutput.bmp randomColorOutput.bmp
//-----------------------------------------------------------------------------
#include "Image.h"
#include <iostream>
#include <vector>
#include <stack>


// function prototypes for stack-based clicker questions
void stackExample1();
void stackExample2();

// define struct to hold pixel location
struct pixelLocation {
    int r; // row of pixel
    int c; // column of pixel
};
typedef struct pixelLocation PixelLocation;

int main( int argc, char* argv[] )
{
    //--------------------------------------------
    // initial clicker questions/examples stacks:
    //--------------------------------------------

    std::cout << "stackExample1():" << std::endl;
    //stackExample1();

    std::cout << "stackExample2():" << std::endl;
    //stackExample2();

    //-----------------------------
    // example use of Image class:
    //-----------------------------
    // get input/output image file names from command line
    if (argc != 4)
    {
        std::cout << "Usage instructions: " << std::endl;
        std::cout << "> main.exe inputFileName.bmp invertedOutputFileName.bmp randomColorOutputFileName.bmp" << std::endl;
        return -1;
    }
    std::string inputFileName(argv[1]);
    std::string invertedOutputFileName(argv[2]);
    std::string randomColorOutputFileName(argv[3]);

    // read image from input file
    std::cout << "Reading input image: " << inputFileName << std::endl;
    Image myImage;
    bool success = myImage.readFromBMPFile(inputFileName);
    if (! success)
    {
        std::cout << "Error reading input image." << std::endl;
        return -1;
    }

    // invert image (example of how to iterate through pixels of
    // of image and modify the image values)
    for (int r = 0; r < myImage.getNumRows(); r++)
    {
        for (int c = 0; c < myImage.getNumCols(); c++)
        {
            int oldPixelValue = myImage.getPixel(r,c);
            int newPixelValue = 255 - oldPixelValue;
            myImage.setPixel(r,c,newPixelValue);
        }
    }

    // write modified version of image to file (in grayscale)
    std::cout << "Writing inverted output image: " << invertedOutputFileName << std::endl;
    success = myImage.writeToBMPFile(invertedOutputFileName);
    if (! success)
    {
        std::cout << "Error writing output image." << std::endl;
        return -1;
    }

    // write modified version of image to file (using randomized colors)
    std::cout << "Writing randomized color output image: " << randomColorOutputFileName << std::endl;
    myImage.switchToRandomColorMapping();
    success = myImage.writeToBMPFile(randomColorOutputFileName);
    if (! success)
    {
        std::cout << "Error writing output image." << std::endl;
        return -1;
    }


    return 0;
}

void stackExample1()
{
    std::stack< int > myStack;

    myStack.push(4);
    int count = 1; // count the total number of pushes onto stack
    while(! myStack.empty() )
    {
        int val = myStack.top(); // obtain top value
        myStack.pop(); // remove top value from stack

        if (val > 0)
        {
            myStack.push(val-1);
            count++;
        }
    }

    std::cout << count << std::endl;
}

void stackExample2()
{
    std::stack< PixelLocation > locStack;
    PixelLocation loc;

    loc.r = 1;
    loc.c = 1;
    locStack.push(loc);
    loc.r = 2;
    loc.c = 2;
    locStack.push(loc);
    loc.r = 3;
    loc.c = 3;
    locStack.push(loc);

    bool done = false;
    while (! done)
    {
        PixelLocation topLoc = locStack.top();
        locStack.pop();
        std::cout << topLoc.r << " " << topLoc.c << std::endl;
        if (topLoc.r <= 2)
        {
            done = true;
        }
    }
}
