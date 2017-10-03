//-----------------------------------------------------------------------------
// Programmer: Mona K. Garvin
// Name: main.cpp
// Description: This program contains in-class examples associated with
//              lecture 34 (on composition, constant member functions, and
//              constant data members)
// Building from the command line (on linux):
//            g++ main.cpp -o main.exe
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>

class TrialTimes {
public:
    TrialTimes(std::string name = "trialRunner", int num = 0) : m_name(name), m_number(num) { }
    void addTime(double time) { m_times.push_back(time); }
    double getAverageTime( ) const;
    void print() const {std::cout << m_name << " (# " << m_number << "): " << getAverageTime() << " s" << std::endl;}
private:
    const std::string m_name;
    const int m_number;
    std::vector<double> m_times;
};

double TrialTimes::getAverageTime( ) const
{
    double total = 0;
    for (size_t i = 0; i < m_times.size(); i++)
    {
        total += m_times[i];
    }
    if (m_times.size() > 0)
    {
        total /= m_times.size();
    }

    return total;
}

// original example in the notes (commented out):
//class ExampleClass {
//public:
//    ExampleClass(int a=0, int b=0) : m_a(a), m_b(b) { }
//    void setA(int a) {m_a = a;}
//    void setB(int b) {m_b = b;}
//    int getA() const {return m_a;}
//    int getB() const {return m_b;}
//private:
//    int m_a;
//    int m_b;
//};

// Example of separating the constructor definition
// (e.g., to show where to put the member initializer list)
class ExampleClass {
public:
    ExampleClass(int a=0, int b=0);
    void setA(int a) {m_a = a;}
    void setB(int b) {m_b = b;}
    int getA() const {return m_a;}
    int getB() const {return m_b;}
private:
    int m_a;
    int m_b;
};

ExampleClass::ExampleClass(int a, int b) : m_a(a), m_b(b)
{
    // nothing else to do in the constructor
}

class CQ {
public:
    CQ(char correctOption) : m_correctOption(correctOption) { m_other = 'A'; }
    bool isCorrect(char option) const;
    void switchB( ) const;
    void switchC( );
private:
    const char m_correctOption;
    char m_other;
};

//bool CQ::isCorrect(char option) const
//{
//   return m_correctOption == option;
//}

//void CQ::switchB( ) const
//{
//   m_other = m_correctOption;
//}

//void CQ::switchC( )
//{
//    m_correctOption = m_other;
//}

int main()
{
    TrialTimes runnerBob("Bob", 1134);
    runnerBob.addTime(20.0);
    runnerBob.addTime(21.6);
    runnerBob.addTime(19.6);
    runnerBob.print();

    TrialTimes runnerSue("Sue", 1532);
    runnerSue.addTime(18.2);
    runnerSue.addTime(17.6);
    runnerSue.addTime(19.5);
    runnerSue.print();

    ExampleClass a;
    std::cout << "\nExampleClass a;\nThe value of a.getA() = " << a.getA() << std::endl;

    return 0;
}
