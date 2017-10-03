//-----------------------------------------------------------------------------
// Programmer: TODO: Jason Ryan
// Name: main.cpp
// Description: This program contains in-class examples and the mini-assignment
//              associated with lecture 38 (on an introduction to inheritance)
// Building from command line (on linux):
//            g++ main.cpp -o main.exe
//
// Part 1 of mini-assignment: Within this comment block, provide two examples
// of a potential base class and associated derived classes (you may NOT
// provide the same examples as those used during class). For every base class,
// you must provide at least two associated derived classes. If the relationship
// is not obvious (e.g., the names you use would be known to only a limited
// number of individuals), you must provide a brief explanation of why an
// inheritance relationship would hold.
//
// Your example 1: Type of computer
// Base class name: Computer
// Derived class 1 name: Mac
// Derived class 2 name: PC
// Brief explanation (if relationship not obvious):
//
// Your example 2: Types of mammals
// Base class name: Mammal
// Derived class 1 name: Human
// Derived class 2 name: Monkey
// Brief explanation (if relationship not obvious):
//
// Part 2 of mini-assignment: Using the VideoGameWishListItem class as an
// example, create a derived class named BookWishListItem (with WishListItem
// as the base class) that represents a book on a wish list. Your
// BookWishListItem class should have a std::string data member to represent
// the format of the book (e.g., "paperback") and this data member should be
// initialized to "unknown" in the constructor. Your class should also have
// the following member functions (in addition to the constructor):
//     void setFormat(std::string format)
//     std::string getFormat() const
//     void print() const
// In your implementation of the print member function, make sure to call
// the base class's print member function first and then print out the format
// of the book. Once you have defined your class, uncomment the lines in
// main.cpp involving item3 to test your class.
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// a WishListItem object represents an item on a wish list
class WishListItem {
public:
    WishListItem() : m_name("unknown"), m_cost(0.0) {}
    void setName(std::string name) { m_name = name; }
    void setCost(double cost) { m_cost = cost; }
    std::string getName( ) const { return m_name; }
    double getCost( ) const { return m_cost; }
    void print() const;
private:
    std::string m_name; // name of item
    double m_cost;      // cost in dollars
};

void WishListItem::print() const
{
    std::cout << m_name << ": "
              <<  std::fixed << std::setprecision(2)
              << "$" << m_cost << " ";
}

// a VideoGameWishListItem represents video game on a wish list
class VideoGameWishListItem : public WishListItem {
public:
    VideoGameWishListItem() : m_gamePlatform("unknown") {}
    void setPlatform(std::string gamePlatform) { m_gamePlatform = gamePlatform; }
    std::string getPlatform() const { return m_gamePlatform; }
    void print() const;
private:
    std::string m_gamePlatform; // game platform (e.g., PS4) for game
};

void VideoGameWishListItem::print() const
{
    WishListItem::print();
    std::cout << "(for " << m_gamePlatform << ")";
}

// a BookWishListItem represents a book on a wish list
// TODO: your class definition here for BookWishListItem
class BookWishListItem : public WishListItem {
public:
    BookWishListItem() : m_bookFormat("unknown") {}
    void setFormat(std::string bookFormat) {m_bookFormat = bookFormat;}
    std::string getFormat() const {return m_bookFormat;}
    void print() const;
private:
    std::string m_bookFormat; // What form does the book come in (hardcover, paperback, ebook, etc.)
};

void BookWishListItem::print() const
{
    WishListItem::print();
    std::cout << "(in " << m_bookFormat << ")";
}

int main()
{
    std::cout << "Wish list:" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    WishListItem item1;
    item1.setName("GPS watch");
    item1.setCost(149.99);
    item1.print();
    std::cout << std::endl;

    VideoGameWishListItem item2;
    item2.setName("Just Dance 2014");
    item2.setCost(45.99);
    item2.setPlatform("PS4");
    item2.print();
    std::cout << std::endl;

    // TODO: uncomment item3 lines below
    BookWishListItem item3;
    item3.setName("C++ Templates: The Complete Guide");
    item3.setCost(56.55);
    item3.setFormat("hardcover");
    item3.print();
    std::cout << std::endl;

    // compute total cost of items
    std::vector<WishListItem> items;
    items.push_back(item1);
    items.push_back(item2);
    items.push_back(item3); // TODO: uncomment this line

    double totalCost = 0;
    std::vector<WishListItem>::iterator iter;
    for (iter = items.begin(); iter != items.end(); ++iter)
    {
        totalCost += iter->getCost();
    }

    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "Total cost: "
              << std::fixed << std::setprecision(2)
              << "$" << totalCost << std::endl;

    return 0;
}

