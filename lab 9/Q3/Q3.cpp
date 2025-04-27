#include <iostream>
using namespace std;
#include "Q3_Book.hpp"

int main()
{
    Book book("The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842");

    cout << "Title: " << book.getTitle() << endl;
    cout << "Author: " << book.getAuthor() << endl;
    cout << "ISBN: " << book.getISBN() << endl;

    return 0;
}
