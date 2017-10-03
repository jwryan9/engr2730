//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: main.cpp
// Description: This program contains in-class examples associated with 
//              lecture 40 (constructors and destructors in derived classes)
// Building from command line (on linux):
//            g++ main.cpp -o main.exe
//-----------------------------------------------------------------------------
#include <iostream>

class MyBase {
public:
    // constructor
    MyBase(int val = 5)
    {
        m_val = val;
        std::cout << "In base constructor." << std::endl;
    }
    // destructor
    ~MyBase()
    {
        std::cout << "In base destructor." << std::endl;
    }
    // set value
    void setVal(int val) { m_val = val; }
    // get value
    int getVal() const { return m_val; }
private:
    int m_val;
};

class MyDerived1 : public MyBase {
public:
    // constructor
    MyDerived1(std::string name = "Hello")
    {
        m_name = name;
        std::cout << "In derived constructor." << std::endl;
    }
    // destructor
    ~MyDerived1()
    {
        std::cout << "In derived destructor." << std::endl;
    }
    // set name
    void setName(std::string name) { m_name = name; }
    // get name
    std::string getName() const { return m_name; }
private:
    std::string m_name;
};

void example1();

class MyDerived2 : public MyBase {
public:
    // constructor
    MyDerived2(std::string name = "Hello", int val = 7) : MyBase(val)
    {
        m_name = name;
        std::cout << "In derived constructor." << std::endl;
    }
    // destructor
    ~MyDerived2()
    {
        std::cout << "In derived destructor." << std::endl;
    }
    // set name
    void setName(std::string name) { m_name = name; }
    // get name
    std::string getName() const { return m_name; }
private:
    std::string m_name;
};

void example2();

void example3();

int main()
{
    std::cout << "----------" << std::endl;
    std::cout << "example1()" << std::endl;
    std::cout << "----------" << std::endl;
    //example1();

    std::cout << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << "example2()" << std::endl;
    std::cout << "----------" << std::endl;
    //example2();

    std::cout << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << "example3()" << std::endl;
    std::cout << "----------" << std::endl;
    //example3();

    return 0;
}

void example1()
{
    MyDerived1 d1("Test");
    std::cout << d1.getName() << " " << d1.getVal() << " " << std::endl;
}

void example2()
{
    MyDerived2 d2;
    std::cout << d2.getName() << " " << d2.getVal() << " " << std::endl;
}

void example3()
{
    MyDerived2 d1, d2;
    std::cout << "do something" << std::endl;
}
