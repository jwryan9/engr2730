//------------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: Image.cpp
// Description: Implementation of member functions of Image class for homework 5
//-------------------------------------------------------------------------------
#include "Image.h"
#include "EasyBMP/EasyBMP.h"
#include <cstdlib>
#include <ctime>

Image::Image()
{
    m_numRows = 0;
    m_numCols = 0;
    m_pixels = NULL;
    switchToGrayColorMapping(); // default color mapping is grayscale
}


Image::Image(int numRows, int numCols)
{
    m_numRows = numRows;
    m_numCols = numCols;
    if (m_numRows*m_numCols > 0)
    {
        m_pixels = new int[m_numRows*m_numCols];
        setAllPixels(0);
    }
    else
    {
        m_pixels = NULL;
    }
    switchToGrayColorMapping(); // default color mapping is grayscale
}



Image::~Image()
{
    if (m_pixels != NULL)
    {
        delete [] m_pixels;
        m_numRows = 0;
        m_numCols = 0;
    }
}


bool Image::readFromBMPFile(std::string inputFileName)
{
    bool success = true;

    // use BMP object to read image
    BMP inputImage;
    success = inputImage.ReadFromFile(inputFileName.c_str());
    if (success)
    {
        // allocate memory for image (deleting old, if exists)
        m_numRows = inputImage.TellHeight();
        m_numCols = inputImage.TellWidth();
        if (m_pixels != NULL) // deallocate old memory
        {
            delete [] m_pixels;
        }
        m_pixels = new int[m_numRows*m_numCols];

        // copy pixels
        for (int r = 0; r < m_numRows; r++)
        {
            for (int c = 0; c < m_numCols; c++)
            {
                RGBApixel pixelVal = inputImage.GetPixel(c, r);
                int val = (int) pixelVal.Blue + (int) pixelVal.Green + (int) pixelVal.Red;
                val = (int)(val/3.0 + 0.5);
                // clamp value to be in range 0-255
                if (val < 0)
                {
                    val = 0;
                }
                if (val > 255)
                {
                    val = 255;
                }
                m_pixels[r*m_numCols + c] = val;
            }
        }
    }

    return success;
}

bool Image::writeToBMPFile(std::string outputFileName)
{
    bool success = true;

    if (m_pixels != NULL)
    {
        // create bitmap image
        BMP outputImage;
        outputImage.SetSize(m_numCols, m_numRows);
        outputImage.SetBitDepth( 24 );
        for (int r = 0; r < m_numRows; r++)
        {
            for (int c = 0; c < m_numCols; c++)
            {
                // get pixel value and clamp between 0 and 255
                int val = m_pixels[r*m_numCols + c];
                if (val < 0)
                {
                    val = 0;
                }
                if (val > 255)
                {
                    val = 255;
                }
                // set output color based on mapping
                RGBApixel pixelVal = m_colorMapping[val];
                outputImage.SetPixel(c, r, pixelVal);
            }
        }

        // write to file
        success = outputImage.WriteToFile( outputFileName.c_str() );

    }
    else
    {
        success = false;
    }


    return success;
}


int Image::getPixel(int r, int c) const
{
    int val = 0;
    if (isInBounds(r,c))
    {
        val = m_pixels[r*m_numCols + c];
    }

    return val;
}

bool Image::isInBounds(int r, int c) const
{
    return (r >= 0 && r < m_numRows && c >=0 && c < m_numCols);
}

int Image::getNumRows() const
{
    return m_numRows;
}

int Image::getNumCols() const
{
    return m_numCols;
}

void Image::setPixel(int r, int c, int val)
{
    if (isInBounds(r,c))
    {
        m_pixels[r*m_numCols + c] = val;
    }
}

void Image::setAllPixels(int val)
{
    for (int i=0; i < m_numRows*m_numCols; i++)
    {
        m_pixels[i] = val;
    }
}


void Image::switchToGrayColorMapping()
{
    RGBApixel currPix;
    for (int i=0; i < 256; i++)
    {
        currPix.Blue = i;
        currPix.Green = i;
        currPix.Red = i;
        currPix.Alpha = 255;
        m_colorMapping[i] = currPix;
    }
}

void Image::switchToRandomColorMapping()
{
    // everything is a random color EXCEPT the first color (black)
    srand(time(NULL));
    RGBApixel currPix;
    for (int i=1; i < 256; i++)
    {
        currPix.Blue = rand() % 256;
        currPix.Green = rand() % 256;
        currPix.Red = rand() % 256;
        currPix.Alpha = 255;
        m_colorMapping[i] = currPix;
    }
}
