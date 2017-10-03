//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: main.cpp
// Description: This program contains in-class examples associated with
//              lecture 35 (dynamic memory allocation and pointers in C++)
// Building from command line (on linux):
//            g++ main.cpp ComplexNumber.cpp ComplexStruct.cpp -o main.exe
//-----------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "ComplexStruct.h"
#include "ComplexNumber.h"

// classes for initial clicker question
class Point2DA {
public:
    Point2DA(float x=0, float y=0) : m_x(x), m_y(y) {}

    void setX(float x) {m_x = x;}
    void setY(float y) {m_y = y;}

    float getX() {return m_x;}
    float getY() {return m_y;}
private:
    float m_x;
    float m_y;
};

class Point2DB {
public:
    Point2DB(float x=0, float y=0) : m_x(x), m_y(y) { }
    Point2DB(const Point2DB &p) { }
    ~Point2DB() {}
    const Point2DB &operator=(const Point2DB &p) { return *this; }

    void setX(float x) {m_x = x;}
    void setY(float y) {m_y = y;}

    float getX() {return m_x;}
    float getY() {return m_y;}
private:
    float m_x;
    float m_y;
};

class Point2DC {
public:
    Point2DC(float x=0, float y=0) : m_x(x), m_y(y) {}
    Point2DC(const Point2DC &p) { m_x = p.m_x; m_y = p.m_y; }
    ~Point2DC() {}
    const Point2DC &operator=(const Point2DC &p) {m_x = p.m_x; m_y = p.m_y; return *this;}

    void setX(float x) {m_x = x;}
    void setY(float y) {m_y = y;}

    float getX() {return m_x;}
    float getY() {return m_y;}
private:
    float m_x;
    float m_y;
};

void exampleWithClickerQuestion1();


// prototypes for dynamic array examples
void dynamicArrayExampleCStyle();
void dynamicArrayExampleCPlusPlusStyle();

// prototypes for complex number examples
void complexStructCStyle();
void complexNumberClassCPlusPlusStyle();

// prototype for second clicker question
void clickerQuestion2();

// simple class to illustrate use of `this' pointer
class SimpleClass {
public:
    SimpleClass(int x=0) { m_x = x; }
    void setX1(int x) { m_x = x; }
    void setX2(int x) { this->m_x = x; }
    void setX3(int x) { (*this).m_x = x; }
    int getX() const { return m_x; }
private:
    int m_x;
};

void simpleClassExample();

// simple class that enables cascading member function calls
class CanCascade {
public:
    CanCascade(int x=0, int y=0, int z=0) { m_x = x; m_y = y; m_z = z; }
    CanCascade & setX(int x) { m_x = x;
                               std::cout << "setX" << std::endl;
                               return *this; }
    CanCascade & setY(int y) { m_y = y;
                               std::cout << "setY" << std::endl;
                               return *this; }
    CanCascade & setZ(int z) { m_z = z;
                               std::cout << "setZ" << std::endl;
                               return *this; }
    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getZ() const { return m_z; }
private:
    int m_x;
    int m_y;
    int m_z;
};

void cascadeExample();


int main()
{
    std::cout << "-----------------------------" << std::endl;
    std::cout << "exampleWithClickerQuestion1()" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    //exampleWithClickerQuestion1();

    std::cout << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "dynamicArrayExampleCStyle()" << std::endl;
    std::cout << "---------------------------" << std::endl;
    dynamicArrayExampleCStyle();

    std::cout << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "dynamicArrayExampleCPlusPlusStyle()" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    dynamicArrayExampleCPlusPlusStyle();

    std::cout << "---------------------" << std::endl;
    std::cout << "complexStructCStyle()" << std::endl;
    std::cout << "---------------------" << std::endl;
    complexStructCStyle();

    std::cout << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "complexNumberClassCPlusPlusStyle()" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    complexNumberClassCPlusPlusStyle();

    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "simpleClassExample()" << std::endl;
    std::cout << "--------------------" << std::endl;
    simpleClassExample();

    std::cout << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "cascadeExample()" << std::endl;
    std::cout << "----------------" << std::endl;
    //cascadeExample();

    return 0;
}

void exampleWithClickerQuestion1()
{
    // using Point2DA
    Point2DA a1(1,2);
    Point2DA a2(a1);   // use copy constructor
    Point2DA a3;
    a3 = a1;           // use assignment operator

    std::cout << "a1=(" << a1.getX() << "," << a1.getY() << ")" << std::endl;
    std::cout << "a2=(" << a2.getX() << "," << a2.getY() << ")" << std::endl;
    std::cout << "a3=(" << a3.getX() << "," << a3.getY() << ")" << std::endl;

    // using Point2DB
    Point2DB b1(1,2);
    Point2DB b2(b1);   // use copy constructor
    Point2DB b3;
    b3 = b1;           // use assignment operator

    std::cout << "b1=(" << b1.getX() << "," << b1.getY() << ")" << std::endl;
    std::cout << "b2=(" << b2.getX() << "," << b2.getY() << ")" << std::endl;
    std::cout << "b3=(" << b3.getX() << "," << b3.getY() << ")" << std::endl;

    // using Point2DC
    Point2DC c1(1,2);
    Point2DC c2(c1);   // use copy constructor
    Point2DC c3;
    c3 = c1;           // use assignment operator

    std::cout << "c1=(" << c1.getX() << "," << c1.getY() << ")" << std::endl;
    std::cout << "c2=(" << c2.getX() << "," << c2.getY() << ")" << std::endl;
    std::cout << "c3=(" << c3.getX() << "," << c3.getY() << ")" << std::endl;
}

void dynamicArrayExampleCStyle()
{
    int *myDynamicArray = NULL;
    int n = 10;
    int i;

    myDynamicArray = (int *) malloc(n*sizeof(int));

    for (i=0; i < n; i++)
    {
        myDynamicArray[i] = i;
        printf("myDynamicArray[%d] = %d\n", i, myDynamicArray[i]);
    }

    free(myDynamicArray);
}

void dynamicArrayExampleCPlusPlusStyle()
{
    int *myDynamicArray = NULL;
    int n = 10;

    myDynamicArray = new int[n];

    for (int i=0; i < n; i++)
    {
        myDynamicArray[i] = i;
        std::cout << "myDynamicArray[" << i << "] = " << myDynamicArray[i] << std::endl;
    }

    delete [] myDynamicArray;
}

void complexStructCStyle()
{
    ComplexStruct *myComplexStructPtr;

    myComplexStructPtr = (ComplexStruct *) malloc(sizeof(ComplexStruct));
    myComplexStructPtr->real = 5;
    myComplexStructPtr->imag = 2;

    printComplexStructInCartesianForm(*myComplexStructPtr);
    myComplexStructPtr->real = 10;
    printComplexStructInCartesianForm(*myComplexStructPtr);

    free(myComplexStructPtr);
}

void complexNumberClassCPlusPlusStyle()
{
    ComplexNumber *myComplexNumberPtr;

    myComplexNumberPtr = new ComplexNumber(5,2);

    myComplexNumberPtr->printInCartesianForm( );
    myComplexNumberPtr->setRealPart(10);
    myComplexNumberPtr->printInCartesianForm( );

    delete myComplexNumberPtr;
}

void clickerQuestion2()
{
    int n = 10; // array size
    ComplexNumber *myArray = NULL;

    // create an array of complex numbers
    // OPTION A:
    //myArray = new ComplexNumber[n];
    //for (int i=0; i < n; i++)
    //{
    //    myArray[i].setRealPart(2);
    //    myArray[i].setImagPart(2);
    //}

    // OPTION B:
    //myArray = new ComplexNumber[n];
    //for (int i=0; i < n; i++)
    //{
    //    myArray[i]->setRealPart(2);
    //    myArray[i]->setImagPart(2);
    //}

    // OPTION C:
    //myArray = new ComplexNumber(2,2)[n];
}

void simpleClassExample()
{
    SimpleClass a;
    a.setX1(1);
    std::cout << a.getX() << std::endl;
    a.setX2(2);
    std::cout << a.getX() << std::endl;
    a.setX3(3);
    std::cout << a.getX() << std::endl;
}

void cascadeExample()
{
    CanCascade myObject;
    myObject.setX(1).setY(2).setZ(3);
}
