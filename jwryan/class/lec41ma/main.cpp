//-----------------------------------------------------------------------------
// Programmer: TODO: Jason Ryan
// Name: main.cpp
// Description: This file contains examples and the mini-assignment associated
//              with lecture 41 (on templates)
// Building from command line (on linux):
//            g++ main.cpp -o main.exe
//
// Mini-assignment
//
// Part 1:
// 1. Examine the function "maximumInt" and the example use of this function in
//    "useOfMaximumIntFunction." This function does NOT use templates and so it
//    only works with integers.
// 2. Examine a similar function "maximum" that DOES use templates and its usage
//    in "useOfMaximumFunction." Because of the use of templates, different versions
//    of the function are created automatically, as needed, by the compiler.
// 3. Examine the function "minimumInt" and the example use of this function in
//    "useOfMinimumIntFunction." This function does NOT use templates and so it
//     only works with integers.
// 4. CREATE A TEMPLATED VERSION OF THIS FUNCTION NAMED "minimum"
// 5. ILLUSTRATE USING YOUR TEMPLATED MINIMUM FUNCTION WITH AT LEAST TWO DIFFERENT
//    TYPES IN THE FUNCTION "miniAssignmentPart1"
//
// Part 2:
// 1. Examine the class named IntItem and the example use of this class in the
//    "useIntItemClass" function. This class does NOT use templates and thus you
//    may only create objects that contain an integer value.
// 2. Examine a similar class named Item and the example use of this class in the
//    "useItemClass" function. Because of the use of templates, different versions
//    of the class are created automatically, as needed, by the compiler.
// 3. Examine the class named StudentFloat and the example use of this class in the
//    "useStudentFloatClass" function.
// 4. CREATE A TEMPLATED VERSION OF THIS CLASS NAMED Student (SO THAT THE
//    TYPE OF m_dataItem ASSOCIATED WITH THE STUDENT MAY VARY)
// 5. ILLUSTRATE USING THIS CLASS WITH AT LEAST TWO DIFFERENT TYPES IN THE
//    FUNCTION "miniAssignmentPart2"
//-----------------------------------------------------------------------------
#include <iostream>
using namespace std;
//----------------------------
// PART 1 FUNCTION PROTOTYPES
//----------------------------

// non-templated maximum function prototype for integers
int maximumInt(int a, int b, int c);

// test function to call the above function
void useOfMaximumIntFunction();

// templated maximum function prototype
template < typename T >
T maximum(T a, T b, T c);

// test function to call the above function
void useOfMaximumFunction();

// non-templated minimum function prototype
int minimumInt(int a, int b, int c);

// test function to call above function
void useOfMinimumIntFunction();

// templated minimum function prototype
// TOOD: your function prototype here
template <typename T>
T minimum(T a, T b, T c);


// test function to call your function above
void miniAssignmentPart1();

//----------------------------------------
// PART 2 CLASSES AND FUNCTION PROTOTYPES
//----------------------------------------

// example class to represent an integer item with an associated name
class IntItem {
public:
    // constructor
    IntItem(std::string name = "", int val = 0) {  m_name = name; m_itemValue = val; }

    // data modification
    void setItemName(std::string name) { m_name = name; }
    void setItemValue(int val) { m_itemValue = val; }

    // data accessors
    std::string getItemName() const { return m_name; }
    int getItemValue() const { return m_itemValue; }

    // print
    void print() const;

private:
    std::string m_name;
    int m_itemValue;
};

// implementation of print member function for IntItem class
void IntItem::print() const
{
    std::cout << "IntItem:" << std::endl;
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Value: " << m_itemValue << std::endl;
}

// function prototype for function to use class above
void useIntItemClass();

// example templated class to represent an item with an associated name
template< typename T >
class Item {
public:
    // constructor
    Item(std::string name = "", T val = 0) {  m_name = name; m_itemValue = val; }

    // data modification
    void setItemName(std::string name) { m_name = name; }
    void setItemValue(T val) { m_itemValue = val; }

    // data accessors
    std::string getItemName() const { return m_name; }
    T getItemValue() const { return m_itemValue; }

    // print
    void print() const;

private:
    std::string m_name;
    T m_itemValue;
};

// implementation of print member function for Item class
template< typename T >
void Item< T >::print() const
{
    std::cout << "Item:" << std::endl;
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Value: " << m_itemValue << std::endl;
}

// function prototype for function to use Item class above
void useItemClass();

// example class to represent student with a first name, last name,
// and associated data item
class StudentFloat {
public:
    // constructor
    StudentFloat(std::string first = "",
                 std::string last = "",
                 float dataItem = 0.0) {  m_firstName = first;
                                          m_lastName = last;
                                          m_dataItem = dataItem; }

    // data modification
    void setFirstName(std::string first) { m_firstName = first; }
    void setLastName(std::string last) { m_lastName = last; }
    void setDataItem(float dataItem) { m_dataItem = dataItem; }

    // data accessors
    std::string getFirstName() const { return m_firstName; }
    std::string getLastName() const { return m_lastName; }
    float getDataItem() const { return m_dataItem; }

    // print
    void print() const;

private:
    std::string m_firstName;
    std::string m_lastName;
    float m_dataItem;
};

// implementation of print function
void StudentFloat::print() const
{
    std::cout << "Student:" << std::endl;
    std::cout << "First name: " << m_firstName << std::endl;
    std::cout << "Last name: " << m_lastName << std::endl;
    std::cout << "Associated data item: " << m_dataItem << std::endl;
}

// function prototype for function to use StudentFloatClass above
void useStudentFloatClass();

// TODO: create templated Student class below:
template <typename T>
class Student {
public:
    // constructor
    Student(std::string first = "",
                 std::string last = "",
                 T dataItem = 0.0) {  m_firstName = first;
                                          m_lastName = last;
                                          m_dataItem = dataItem; }

    // data modification
    void setFirstName(std::string first) { m_firstName = first; }
    void setLastName(std::string last) { m_lastName = last; }
    void setDataItem(T dataItem) { m_dataItem = dataItem; }

    // data accessors
    std::string getFirstName() const { return m_firstName; }
    std::string getLastName() const { return m_lastName; }
    T getDataItem() const { return m_dataItem; }

    // print
    void print() const;

private:
    std::string m_firstName;
    std::string m_lastName;
    T m_dataItem;
};

template <typename T>
void Student<T>::print() const
{
    std::cout<<"Item:" <<std::endl;
    std::cout<<"Name: "<<m_firstName<<" "<<m_lastName<<std::endl;
    std::cout<<"Value: "<<m_dataItem<<std::endl;
}

// test function to test your templated Student class
void miniAssignmentPart2();

//------
// MAIN
//------
int main()
{
    std::cout << "-------------------------" << std::endl;
    std::cout << "useOfMaximumIntFunction()" << std::endl;
    std::cout << "-------------------------" << std::endl;
    useOfMaximumIntFunction();

    std::cout << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "useOfMaximumFunction()" << std::endl;
    std::cout << "----------------------" << std::endl;
    useOfMaximumFunction();

    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "miniAssignmentPart1()" << std::endl;
    std::cout << "---------------------" << std::endl;
    miniAssignmentPart1();

    std::cout << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "useIntItemCLass()" << std::endl;
    std::cout << "-----------------" << std::endl;
    useIntItemClass();

    std::cout << std::endl;
    std::cout << "--------------" << std::endl;
    std::cout << "useItemCLass()" << std::endl;
    std::cout << "--------------" << std::endl;
    useItemClass();

    std::cout << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "useStudentFloatCLass()" << std::endl;
    std::cout << "----------------------" << std::endl;
    useStudentFloatClass();

    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "miniAssignmentPart2()" << std::endl;
    std::cout << "---------------------" << std::endl;
    miniAssignmentPart2();

    return 0;
}

// returns maximum of integers a, b, and c
int maximumInt(int a, int b, int c)
{
    int maximumVal = a;

    if (b > maximumVal)
    {
        maximumVal = b;
    }

    if (c > maximumVal)
    {
        maximumVal = c;
    }

    return maximumVal;
}

void useOfMaximumIntFunction()
{
    int a, b, c;
    std::cout << "Please enter three integers: ";
    std::cin >> a >> b >> c;
    std::cout << "The maximum integer entered was " << maximumInt(a,b,c) << std::endl;
}

// returns maximum of a, b, and c
template < typename T >
T maximum(T a, T b, T c)
{
    T maximumVal = a;

    if (b > maximumVal)
    {
        maximumVal = b;
    }

    if (c > maximumVal)
    {
        maximumVal = c;
    }

    return maximumVal;
}

// calls function above
void useOfMaximumFunction()
{
    float f1, f2, f3;
    std::cout << "Please enter three floats: ";
    std::cin >> f1 >> f2 >> f3;
    std::cout << "The maximum float entered was " << maximum(f1,f2,f3) << "." << std::endl;

    int i1, i2, i3;
    std::cout << "Please enter three integers: ";
    std::cin >> i1 >> i2 >> i3;
    std::cout << "The maximum integer entered was " << maximum(i1,i2,i3) << "." << std::endl;
}

// returns minimum of integers a, b, and c
int minimumInt(int a, int b, int c)
{
    int minimumVal = a;

    if (b < minimumVal)
    {
        minimumVal = b;
    }

    if (c < minimumVal)
    {
        minimumVal = c;
    }

    return minimumVal;
}

// calls function above
void useOfMinimumIntFunction()
{
    int a, b, c;
    std::cout << "Please enter three integers: ";
    std::cin >> a >> b >> c;
    std::cout << "The minimum integer entered was " << minimumInt(a,b,c) << "." << std::endl;
}

// TODO: your templated minimum function to go here
template <typename T>
T minimum(T a, T b, T c)
{
    T minimumVal = a;

        if (b < minimumVal)
    {
        minimumVal = b;
    }

    if (c < minimumVal)
    {
        minimumVal = c;
    }

    return minimumVal;
}

// calls your templated function above
void miniAssignmentPart1()
{
    // TODO: call your templated minimum function at least twice (using two different types)

    std::cout << "Minimum 1, 2, 3: " << minimum(1, 2, 3) << std::endl;
    std::cout << "Minimum 7.5, 9.4, 84.2:" << minimum(7.5, 9.4, 84.2)<<std::endl;
}

//--------
// PART 2
//--------

// function to use IntItem class
void useIntItemClass()
{
    IntItem myItem1("January", 31);
    IntItem myItem2("February", 28);

    myItem1.print();
    myItem2.print();
}

// function to use templated Item class
void useItemClass()
{
    Item< int > myItem1("Course", 57017);
    Item< float > myItem2("pi", 3.14);
    Item< std::string > myItem3("Favorite class", "CIE");

    myItem1.print();
    myItem2.print();
    myItem3.print();
}

// function to use StudentFloat class
void useStudentFloatClass()
{
    StudentFloat dog1("Teddy", "Garvin", 90.5);
    StudentFloat dog2("JT", "Garvin", 78.2);
    dog1.print();
    dog2.print();
}

// function to use templated Student class
void miniAssignmentPart2()
{
    // TODO: create at least two objects of your templated Studunt class,
    // each with a different data item type
    // Then call the print member function for each object.

    Student <int> tempStudent1 ("Teddy", "Garvin", 90);
    Student <float> tempStudent2 ("JT", "Garvin", 78.2);
    tempStudent1.print();
    std::cout<<std::endl;
    tempStudent2.print();
}
