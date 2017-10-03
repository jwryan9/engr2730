//-----------------------------------------------------------------------------
// Programmer: Jason Ryan
// Name: main.cpp
// Description: This program contains in-class examples and the mini-assignment
//              associated with lecture 32 (constructor/destructor basics)
// Building from command line (on linux):
//            g++ main.cpp -o main.exe
// For the mini-assignment, you must define a class of your choice that
// contains at least four different constructors and create objects of
// this class within the miniAssignment() function.
//-----------------------------------------------------------------------------
#include <iostream>

class MyClassA {
public:
    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    int getX() const { return m_x; }
    int getY() const { return m_y; }
private:
    int m_x;
    int m_y;
};

class MyClassB {
public:
    MyClassB() {m_x = 0; m_y = 0;}
    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    int getX() const { return m_x; }
    int getY() const { return m_y; }
private:
    int m_x;
    int m_y;
};

class MyClassC {
public:
    MyClassC(int x, int y) {m_x = x; m_y = y;}
    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    int getX() const { return m_x; }
    int getY() const { return m_y; }
private:
    int m_x;
    int m_y;
};

class MyClassD {
public:
    MyClassD() {m_x = 0; m_y = 0;}
    MyClassD(int x) {m_x = x; m_y = 0;}
    MyClassD(int x, int y) {m_x = x; m_y = y;}
    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    int getX() const { return m_x; }
    int getY() const { return m_y; }
private:
    int m_x;
    int m_y;
};

class MyClassE {
public:
    MyClassE(int x=0, int y=0) {m_x = x; m_y = y;}
    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    int getX() const { return m_x; }
    int getY() const { return m_y; }
private:
    int m_x;
    int m_y;
};

// prototypes for constructor examples
void constructorExampleA();
void constructorExampleB();
void constructorExampleC();
void constructorExampleD();
void constructorExampleE();

//--------------
// AnotherClass
//--------------
class AnotherClass {
public:
    AnotherClass(int id = 0); // constructor
    ~AnotherClass(); // destructor
private:
    int m_ID;
};

AnotherClass::AnotherClass(int id)
{
    m_ID = id;
    std::cout << "AnotherClass object with id = " << m_ID << " created. " << std::endl;
}

AnotherClass::~AnotherClass()
{
    std::cout << "AnotherClass object with id = " << m_ID << " destroyed. " << std::endl;
}

// function prototypes for initial destructor examples
void destructorExample1();
void destructorExample2();
void destructor2HelperFunction(AnotherClass &obj);

//-----------------------------------------------------------------------------------------
// MINI-ASSIGNMENT PART 1: CREATE CLASS OF YOUR CHOICE THAT HAS AT LEAST FOUR CONSTRUCTORS
//-----------------------------------------------------------------------------------------

class NewClass {
public:
    NewClass(int x = 0, int y = 0, int z = 0) {m_x = x; m_y = y; m_z = z;}
    void setX(int x) {m_x = x;}
    void setY(int y) {m_y = y;}
    void setZ(int z) {m_z = z;}
    int getX() {return m_x;}
    int getY() {return m_y;}
    int getZ() {return m_z;}

private:
    int m_x;
    int m_y;
    int m_z;
};

//---------------------------
// END MINI-ASSIGNMENT PART 1
//---------------------------

// prototype for mini-assignment function
void miniAssignment();

int main()
{
    //-----------------------
    // constructor examples:
    //-----------------------

    std::cout << "constructorExampleA():" << std::endl;
    constructorExampleA();

    std::cout << std::endl;
    std::cout << "constructorExampleB():" << std::endl;
    constructorExampleB();

    std::cout << std::endl;
    std::cout << "constructorExampleC():" << std::endl;
    constructorExampleC();

    std::cout << std::endl;
    std::cout << "constructorExampleD():" << std::endl;
    constructorExampleD();

    std::cout << std::endl;
    std::cout << "constructorExampleE():" << std::endl;
    constructorExampleE();

    //----------------------
    // destructor examples:
    //----------------------

    std::cout << std::endl;
    std::cout << "destructorExample1():" << std::endl;
    destructorExample1();

    std::cout << std::endl;
    std::cout << "destructorExample2():" << std::endl;
    //destructorExample2();

    //------------------
    // mini-assignment:
    //------------------

    std::cout << std::endl;
    std::cout << "miniAssignment():" << std::endl;
    miniAssignment();

    return 0;
}

void constructorExampleA()
{
    MyClassA myClassAObject;

    std::cout << myClassAObject.getX() << " " << myClassAObject.getY() << std::endl;
}

void constructorExampleB()
{
    MyClassB myClassBObject;

    std::cout << myClassBObject.getX() << " " << myClassBObject.getY() << std::endl;
}

void constructorExampleC()
{
    //MyClassC myClassCObject; // not allowed: default constructor not automatically provided since
                               // user-defined constructor defined
    MyClassC myClassCObject(1,1);

    std::cout << myClassCObject.getX() << " " << myClassCObject.getY() << std::endl;
}

void constructorExampleD()
{
    MyClassD myClassDObject1;
    MyClassD myClassDObject2(2);
    MyClassD myClassDObject3(3,3);

    std::cout << myClassDObject1.getX() << " " << myClassDObject1.getY() << std::endl;
    std::cout << myClassDObject2.getX() << " " << myClassDObject2.getY() << std::endl;
    std::cout << myClassDObject3.getX() << " " << myClassDObject3.getY() << std::endl;
}

void constructorExampleE()
{
    MyClassE myClassEObject1;
    MyClassE myClassEObject2(2);
    MyClassE myClassEObject3(3,3);

    std::cout << myClassEObject1.getX() << " " << myClassEObject1.getY() << std::endl;
    std::cout << myClassEObject2.getX() << " " << myClassEObject2.getY() << std::endl;
    std::cout << myClassEObject3.getX() << " " << myClassEObject3.getY() << std::endl;
}

void destructorExample1()
{
    AnotherClass object0;
    AnotherClass object1(1);
    AnotherClass object2(2);
}

void destructorExample2()
{
    AnotherClass object(5);
    destructor2HelperFunction(object);
}

void destructor2HelperFunction(AnotherClass &obj)
{
    std::cout << "In function." << std::endl;
}


//-----------------------------------------------------------
// MINI-ASSIGNMENT PART 2:
// WRITE CODE WITHIN THE FUNCTION BELOW TO CREATE OBJECTS OF
// THE DEFINED CLASS YOU CREATED IN PART 1. YOU MUST USE ALL
// OF THE CONSTRUCTORS YOU DEFINED.
//-----------------------------------------------------------
void miniAssignment()
{
    NewClass object1;
    NewClass object2(1);
    NewClass object3(1, 2);
    NewClass object4(1, 2, 3);

    std::cout<<"Object 1: x = "<<object1.getX()<<", y = "<<object1.getY()<<", z = "<<object1.getZ()<<std::endl;
    std::cout<<"Object 2: x = "<<object2.getX()<<", y = "<<object2.getY()<<", z = "<<object2.getZ()<<std::endl;
    std::cout<<"Object 3: x = "<<object3.getX()<<", y = "<<object3.getY()<<", z = "<<object3.getZ()<<std::endl;
    std::cout<<"Object 4: x = "<<object4.getX()<<", y = "<<object4.getY()<<", z = "<<object4.getZ()<<std::endl;
}
