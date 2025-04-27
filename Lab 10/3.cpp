#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream chapter1("chapter1.txt");
    ifstream chapter2("chapter2.txt");
    ofstream book("book.txt", ios::app);

    if (!chapter1 || !chapter2 || !book) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;

    while (getline(chapter1, line)) {
        book << line << endl;
    }
    book << endl; 

    while (getline(chapter2, line)) {
        book << line << endl;
    }

    chapter1.close();
    chapter2.close();
    book.close();

    ifstream finalBook("book.txt");
    if (!finalBook) {
        cerr << "Error opening book file!" << endl;
        return 1;
    }

    cout << "\nBook Content:\n";
    while (getline(finalBook, line)) {
        cout << line << endl;
    }
    finalBook.close();

    return 0;
}
