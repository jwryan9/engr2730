//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: Image.h
// Description: Header file for Image class for homework 5. This class
//              represents a grayscale image that can be read from a bmp file
//              and written to a bmp file in two ways (grayscale mapping and
//              randomized color mapping)
//-----------------------------------------------------------------------------

#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "EasyBMP/EasyBMP.h"

class Image
{
public:
            //--------------------------------------
            // GROUP: Construction/destruction/copy
            //--------------------------------------
    // default constructor
    Image();
    // constructor to specify size
    Image(int numRows, int numCols);
    // copy constructor
    Image(const Image &imageToCopyFrom);
    // destructor
    ~Image();
    // assignment operator
    const Image &operator=(const Image &imageOnRight);

            //-----------------------------------
            // GROUP: Image input (from file)
            //-----------------------------------
    // create image from file, given filenmame of .bmp file
    // the image is converted to grayscale
    bool readFromBMPFile(std::string inputFileName);

            //-----------------------------------
            // GROUP: Image output (to file)
            //-----------------------------------
    // write image to file, given .bmp filename
    // the mapping between intensity values and color
    // values will be based on the current color mapping
    // (see switchToGrayColorMapping() and switchToRandomColorMapping() functions)
    bool writeToBMPFile(std::string outputFileName);

    // switch color mapping to grayscale (call before writing to file)
    void switchToGrayColorMapping();
    // switch color mapping to "random colors" so that
    // each intensity value will be assigned a random color
    // (call before writing to file)
    void switchToRandomColorMapping();

            //-----------------------------
            // GROUP: Data accessors
            //-----------------------------

    // get pixel value, given input row and column
    int getPixel(int r, int c) const;

    // determine whether given pixel location (row/column) is in bounds
    bool isInBounds(int r, int c) const;

    // get number of rows
    int getNumRows() const;
    // get number of columns
    int getNumCols() const;

            //-----------------------------
            // GROUP: Data modification
            //-----------------------------

    // set pixel value at row r and column c to val
    void setPixel(int r, int c, int val);

    // set all pixel values to val
    void setAllPixels(int val);

    // set all pixel with the given oldVal to the given newVal
    void setAllPixelsWithOldValToNewVal(int oldVal, int newVal);

private:
    int m_numRows;  // number of rows
    int m_numCols;  // number of columns
    int * m_pixels; // pointer to first pixel in image
    RGBApixel m_colorMapping[256]; // color mapping for output
};

#endif // IMAGE_H
