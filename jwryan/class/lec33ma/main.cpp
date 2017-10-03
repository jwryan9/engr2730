//-----------------------------------------------------------------------------
// Programmer: TODO: Jason Ryan
// Name: main.cpp
// Description: This program contains in-class examples and the mini-assignment
//              associated with lecture 33 (more on constructors/destructors)
// Building from command line (on linux):
//            g++ main.cpp -o main.exe
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>

//---------------
// AnotherClass
//---------------
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

//---------------
// AnotherClass2
//---------------
class AnotherClass2 {
public:
    AnotherClass2(int id = 0); // constructor
    AnotherClass2(const AnotherClass2 &objToCopyFrom); // copy constructor
    ~AnotherClass2(); // destructor
private:
    int m_ID;
};

AnotherClass2::AnotherClass2(int id)
{
    m_ID = id;
    std::cout << "AnotherClass2 object with id = " << m_ID << " created. " << std::endl;
}

AnotherClass2::AnotherClass2(const AnotherClass2 &objToCopyFrom)
{
    m_ID = objToCopyFrom.m_ID;
    std::cout << "AnotherClass2 object with id = " << m_ID
              << " created using copy constructor." << std::endl;
}

AnotherClass2::~AnotherClass2()
{
    std::cout << "AnotherClass2 object with id = " << m_ID << " destroyed. " << std::endl;
}

//----------
// Point2D
//----------
class Point2D {
public:
    Point2D(int x=0, int y=0) {m_x = x; m_y = y;}
    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    int getX() const { return m_x; }
    int getY() const { return m_y; }
private:
    int m_x;
    int m_y;
};

//--------------
// ClassWithBug
//--------------
class ClassWithBug {
public:
    ClassWithBug(int data = 0) { m_data = data; } // constructor
    ClassWithBug(const ClassWithBug &objToCopyFrom) {m_data = 5;} // copy constructor WITH LOGICAL BUG
    void setData(int data) {m_data = data;}
    int getData() const { return m_data; }
private:
    int m_data;
};


// function prototypes for initial destructor examples
void destructorExample1();
void destructorExample2();
void destructor2HelperFunction(AnotherClass &obj);
void destructorExample3();
void destructor3HelperFunction(AnotherClass obj);


// function prototypes for copy constructor examples
void copyConstructorExample();
void destructorExample4();
void destructor4HelperFunction(AnotherClass2 obj);
void usingClassWithBug();
void usingClassWithBugHelper(ClassWithBug obj);

// function prototype for assignment operator example
void assignmentExample();

// function prototype for miniAssignment function
void miniAssignment();

// helper function for miniAssignment to print values of vector
void printVector(const std::vector<int> &vect);

int main()
{
    //-----------------------------
    // initial destructor examples:
    //-----------------------------

    std::cout << std::endl;
    std::cout << "destructorExample1():" << std::endl;
    destructorExample1();

    std::cout << std::endl;
    std::cout << "destructorExample2():" << std::endl;
    destructorExample2();

    std::cout << std::endl;
    std::cout << "destructorExample3():" << std::endl;
    //destructorExample3();

    //-----------------------------
    // copy constructor examples:
    //-----------------------------

    std::cout << std::endl;
    std::cout << "copyConstructorExample():" << std::endl;
    copyConstructorExample();

    std::cout << std::endl;
    std::cout << "destructorExample4():" << std::endl;
    destructorExample4();

    std::cout << std::endl;
    std::cout << "usingClassWithBug():" << std::endl;
    //usingClassWithBug();

    //------------------------------
    // assignment operator example:
    //------------------------------

    std::cout << std::endl;
    std::cout << "assignmentExample():" << std::endl;
    assignmentExample();

    //---------------------------
    // mini-assignment function:
    //---------------------------

    std::cout << std::endl;
    std::cout << "miniAssignment():" << std::endl;
    miniAssignment();

    return 0;
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

void destructorExample3()
{
    AnotherClass object(5);
    destructor3HelperFunction(object);
}

void destructor3HelperFunction(AnotherClass obj)
{
    std::cout << "In function." << std::endl;
}

void copyConstructorExample()
{
    Point2D p1(2,3); // use constructor with 2 parameters to create object p1
    Point2D p2(p1);  // use copy constructor to create object p2
    Point2D p3 = p1; // use alternate copy constructor syntax to create object p3

    std::cout << "After creating objects:" << std::endl;
    std::cout << "p1: " << p1.getX() << " " << p1.getY() << std::endl;
    std::cout << "p2: " << p2.getX() << " " << p2.getY() << std::endl;
    std::cout << "p3: " << p3.getX() << " " << p3.getY() << std::endl;

    std::cout << "After modifying p1:" << std::endl;
    p1.setX(5);
    std::cout << "p1: " << p1.getX() << " " << p1.getY() << std::endl;
    std::cout << "p2: " << p2.getX() << " " << p2.getY() << std::endl;
    std::cout << "p3: " << p3.getX() << " " << p3.getY() << std::endl;
}

void destructorExample4()
{
    AnotherClass2 object(5);
    destructor4HelperFunction(object);
}

void destructor4HelperFunction(AnotherClass2 obj)
{
    std::cout << "In function." << std::endl;
}

void usingClassWithBug()
{
    ClassWithBug obj1(1);
    ClassWithBug obj2(obj1);

    std::cout << obj1.getData() << std::endl;
    std::cout << obj2.getData() << std::endl;
    usingClassWithBugHelper(obj1);
    std::cout << obj1.getData() << std::endl;
}
void usingClassWithBugHelper(ClassWithBug obj)
{
    std::cout << obj.getData() << std::endl;
}

void assignmentExample()
{
    Point2D p1(9,10); // use constructor with 2 parameters to create object p1
    Point2D p2;       // use default constructor to create object p2

    std::cout << "After creating objects:" << std::endl;
    std::cout << "p1: " << p1.getX() << " " << p1.getY() << std::endl;
    std::cout << "p2: " << p2.getX() << " " << p2.getY() << std::endl;

    std::cout << "After using automatic assignment operator:" << std::endl;
    p2 = p1;
    std::cout << "p1: " << p1.getX() << " " << p1.getY() << std::endl;
    std::cout << "p2: " << p2.getX() << " " << p2.getY() << std::endl;
}

void miniAssignment()
{
    // Create an std::vector<int> object named vect1 using the default constructor.
    // TODO: your code here
    std::vector<int> vect1;

    // Call the push_back member function three times to have vect1 contain
    // integer values 3, 5, and 6.
    // TODO: your code here
    vect1.push_back(3);
    vect1.push_back(5);
    vect1.push_back(6);

    // Create an std::vector<int> object named vect2 using the (non-default)
    // constructor that accepts an integer (to specify the number of elements)
    // as input. Use 4 as your input so that vect2 will contain four elements.
    // TODO: your code here
    std::vector<int> vect2(4);

    // Using [] notation, modify elements of vect2 to have values of 8, 9, 10, and 11.
    // TODO: your code here
    for(int i=0; i<4; i++)
    {
        vect2[i] = 8+i;
    }

    // Create an std::vector<int> object named vect1_copy that is initialized
    // as a copy of vect1 using the copy constructor.
    // Use the ClassName newObj(oldObj) syntax.
    // TODO: your code here
    std::vector<int> vect1_copy(vect1);

    // Create an std::vector<int> object named vect2_copy that is initialized
    // as a copy of vect2 using the copy constructor.
    // Use the ClassName newObj = oldObj syntax.
    // TODO: your code here
    std::vector<int> vect2_copy = vect2;



    // Uncomment the following code to print the values of vect1, vect2,
    // vect1_copy, and vect2_copy.
    // TODO: uncomment the lines below
    std::cout << "Values of four vector objects:" << std::endl;
    std::cout << "vect1: ";
    printVector(vect1);
    std::cout << "vect2: ";
    printVector(vect2);
    std::cout << "vect1_copy: ";
    printVector(vect1_copy);
    std::cout << "vect2_copy: ";
    printVector(vect2_copy);

    // Using [] notation, modify element 0 of vect1_copy to have a value of 0.
    // Also modify element 0 of vect2_copy to have a value of 0.
    // TODO: your code here
    vect1_copy[0] = 0;
    vect2_copy[0] = 0;

    // Uncomment the following code to print the values of vect1, vect2,
    // vect1_copy, and vect2_copy.
    // TODO: uncomment the lines below
    std::cout << "After modification of vect1_copy[0] and vect2_copy[0]:" << std::endl;
    std::cout << "vect1: ";
    printVector(vect1);
    std::cout << "vect2: ";
    printVector(vect2);
    std::cout << "vect1_copy: ";
    printVector(vect1_copy);
    std::cout << "vect2_copy: ";
    printVector(vect2_copy);

    // Modify vect2 to have the same values as vect1 by using the assignment operator.
    // TODO: your code here (only one line)
    vect2 = vect1;

    // Uncomment the following code to print the values of vect1 and vect2:
    // TODO: uncomment the lines below
    std::cout << "After assignment of vect2 to vect1: " << std::endl;
    std::cout << "vect1: ";
    printVector(vect1);
    std::cout << "vect2: ";
    printVector(vect2);

    // Using [] notation, modify element 0 of vect2 to have a value of 1.
    // TODO: your code here
    vect2[0] = 1;

    // Uncomment the following code to print the values of vect1 and vect2:
    // TODO: uncomment the lines below
    std::cout << "After modification of vect2[0]: " << std::endl;
    std::cout << "vect1: ";
    printVector(vect1);
    std::cout << "vect2: ";
    printVector(vect2);
}

void printVector(const std::vector<int> &vect)
{
    for (size_t i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

