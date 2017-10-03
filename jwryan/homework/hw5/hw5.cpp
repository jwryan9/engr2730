//-----------------------------------------------------------------------------
// Programmer: Jason Ryan
// Name: hw5.cpp
// Description: This computer vision application automatically counts coins to
//              determine the amount of money present in an image. The program
//              transforms an input image into a threshold image of white coins
//              on a black background. The number of pixels of each coin are
//              counted to determine the type/value of each coin. The coin image
//              is output with randomized color coding for each type of coin.
//-----------------------------------------------------------------------------
#include "Image.h"
#include <iostream>
#include <stack>

#define COIN 5          // threshold value for coins
#define DIME 4000       // minimum number of pixels of a dime
#define NICKEL 6000     // minimum number of pixels of a nickel
#define QUARTER 8000    // minimum number of pixels of a quarter
#define HALFDOLLAR 10000 //minimum number of pixels of a quarter
#define LABELNICKEL 101  // label for nickels
#define LABELDIME 175    // label for dimes
#define LABELQUARTER 220 // label for quarters
#define LABELHALF 250    // label for half dollars

#define WHITE 255 //intensity value of white pixel
#define BLACK 0 //Intensity value of black pixel


// define struct to hold pixel location
struct pixelLocation {
    int r;
    int c;
};

typedef struct pixelLocation PixelLocation;

int markConnectedComponent(Image &image, int seedRow, int seedCol, int ccLabel);
bool getSeed(const Image myImage, int intensity, int *row, int *col);

int main( int argc, char* argv[] )
{
    // get input/output image file names from command line
    if (argc != 5)
    {
        std::cout << "Usage instructions: " << std::endl;
        std::cout << "> hw5.exe inputFileName.bmp thresholdedOutputFileName.bmp coloredCoinOutputFileName.bmp whiteBackgroungOutput.bmp" << std::endl;
        return -1;
    }
    std::string inputFileName(argv[1]);
    std::string thresholdedOutputFileName(argv[2]);
    std::string coloredCoinOutputFileName(argv[3]);
    std::string whiteBackgroundFileName(argv[4]);

    // read image from input file
    std::cout << "Reading input image: " << inputFileName << std::endl;
    Image myImage;
    bool success = myImage.readFromBMPFile(inputFileName);
    if (! success)
    {
        std::cout << "Error reading input image." << std::endl;
        return -1;
    }

    //Generate threshold image
    for(int r = 0; r < myImage.getNumRows(); r++)
    {
        for(int c = 0; c < myImage.getNumCols(); c++)
        {
            int pixelValue = myImage.getPixel(r,c);
            if(pixelValue >= COIN)
            {
                myImage.setPixel(r,c,255);
            }
            else
                myImage.setPixel(r,c,0);
        }
    }

    //Write Threshold Image to file
    std::cout << "Writing threshold image: " << thresholdedOutputFileName << std::endl;
    success = myImage.writeToBMPFile(thresholdedOutputFileName);
    if(!success)
    {
        std::cout << "Error writing threshold image" << std::endl;
        return -1;
    }

    int seedRow, seedCol, pixelCount, value = 0, labelCount = 1, nickel = 0, dime = 0, quarter = 0, halfdollar = 0;
    bool seed = getSeed(myImage, WHITE, &seedRow, &seedCol);

    //While there are more unlabeled connected components label the coins
    while(seed && labelCount < 100)
    {
        pixelCount = markConnectedComponent(myImage, seedRow, seedCol, labelCount);

        if(pixelCount >= DIME && pixelCount < NICKEL)
        {
            myImage.setAllPixelsWithOldValToNewVal(labelCount, LABELDIME);
            value += 10;
            dime++;
        }
        else if(pixelCount >= NICKEL && pixelCount < QUARTER)
        {
            myImage.setAllPixelsWithOldValToNewVal(labelCount, LABELNICKEL);
            value += 5;
            nickel++;
        }
        else if(pixelCount >= QUARTER && pixelCount < HALFDOLLAR)
        {
            myImage.setAllPixelsWithOldValToNewVal(labelCount, LABELQUARTER);
            value += 25;
            quarter++;
        }
        else if(pixelCount >= HALFDOLLAR)
        {
            myImage.setAllPixelsWithOldValToNewVal(labelCount, LABELHALF);
            value += 50;
            halfdollar++;
        }

        labelCount++;
        seed = getSeed(myImage, WHITE, &seedRow, &seedCol);
    }

    //Randomly color the image and write to file
    myImage.switchToRandomColorMapping();
    std::cout << "Writing colored-coin image: " << coloredCoinOutputFileName << std::endl;
    myImage.writeToBMPFile(coloredCoinOutputFileName);

    std::cout << "Number of NICKELS: " << nickel << std::endl << "Number of DIMES: " << dime <<
    std::endl << "Number of QUARTERS: " << quarter << std::endl << "Number of HALFDOLLARS: " << halfdollar <<
    std::endl << "Total amount of money: " << value << " cents" << std::endl;

    //EXTRA CREDIT
    myImage.switchToGrayColorMapping();

    int pixelValue, r, c;

    //Set background color to white
    for(r = 0; r < myImage.getNumRows(); r++)
    {
        for(c = 0; c < myImage.getNumCols(); c++)
        {
            pixelValue = myImage.getPixel(r,c);
            if(pixelValue == 0)
                myImage.setPixel(r,c,255);
        }
    }

    //Generate outline
    for(r = 0; r < myImage.getNumRows(); r++)
    {
        for(c = 0; c < myImage.getNumCols(); c++)
        {
            if(myImage.getPixel(r,c) != 255 && (myImage.getPixel(r,c-3) == 255 || myImage.getPixel(r,c+3) == 255))
                myImage.setPixel(r,c,0);
        }
    }

    for(r = 0; r < myImage.getNumRows(); r++)
    {
        for(c = 0; c < myImage.getNumCols(); c++)
        {
            if(myImage.getPixel(r,c) != 255 && (myImage.getPixel(r-3,c) == 255 || myImage.getPixel(r+3,c) == 255))
                myImage.setPixel(r,c,0);
        }
    }

    //Write white background image to file
    std::cout << "Writing white background image: " << whiteBackgroundFileName << std::endl;
    success = myImage.writeToBMPFile(whiteBackgroundFileName);
    if(!success)
    {
        std::cout << "Error writing white background image." << std::endl;
        return -1;
    }

    return 0;
}

/*
*Function name: getSeed
*Description:   Function searches image for first pixel of a given intensity value
*Inputs:        myImage = Image = image object to search through
*               intensity = int = intensity value
*               row = int * = pointer to seed row
*               col = int * = pointer to seed column
*Outputs:       row = int * = pointer to row of first location of given intensity
*               col = int * = pointer to column of first location of given intensity
*/
bool getSeed(const Image myImage, int intensity, int *row, int *col)
{
    for(int r = 0; r < myImage.getNumRows(); r++)
    {
        for(int c = 0; c < myImage.getNumCols(); c++)
        {
            if(myImage.getPixel(r,c) == intensity)
            {
                *row = r;
                *col = c;
                return true;
            }
        }
    }
    return false;
}

/*
*Function name: markConnectedComponent
*Description:   Label all pixels of a given connected component
*Inputs:        image = Image = image object connected components is in
*               seedRow = int = row of first pixel location
*               seedCol = int = column of first pixel location
*               ccLabel = int = connected component label
*Outputs:       pixelCount = int = number of pixels in connected component
*/
int markConnectedComponent(Image &image, int seedRow, int seedCol, int ccLabel)
{
    int pixelCount = 0;
    int intensity;

    PixelLocation seedLoc;
    PixelLocation loc, left, right, up, down;
    seedLoc.r = seedRow;
    seedLoc.c = seedCol;

    //Create stack of pixel locations and push seed location into stack
    std::stack <PixelLocation> pixelLocStack;
    pixelLocStack.push(seedLoc);

    //Loop until stack is empty
    while(!pixelLocStack.empty())
    {
        //Get information about first location in stack then remove it
        loc = pixelLocStack.top();
        intensity = image.getPixel(loc.r, loc.c);
        pixelLocStack.pop();

        if(intensity == WHITE)
        {
            pixelCount++;

            //Label all pixels of intensity value with ccLabel
            image.setPixel(loc.r, loc.c, ccLabel);

            //Locate all pixels surrounding the current pixel
            left.r = loc.r;
            left.c = (loc.c) - 1;
            right.r = loc.r;
            right.c = (loc.c) + 1;
            up.r = (loc.r) - 1;
            up.c = loc.c;
            down.r = (loc.r) + 1;
            down.c = loc.c;

            //If surrounding pixels are valid push them to stack
            if(image.isInBounds(left.r, left.c))
                pixelLocStack.push(left);
            if(image.isInBounds(right.r, right.c))
                pixelLocStack.push(right);
            if(image.isInBounds(up.r, up.c))
                pixelLocStack.push(up);
            if(image.isInBounds(down.r, down.c))
                pixelLocStack.push(down);
        }
    }

    return pixelCount;
}
