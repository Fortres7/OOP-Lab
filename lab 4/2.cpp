#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title, author;
    bool available;

    Book(int i, string t, string a, bool avail = true) {
        id = i;
        title = t;
        author = a;
        available = avail;
    }
};

class Library {
public:
    Book **books;
    int size;

    Library() {
        books = nullptr;
        size = 0;
    }

    void addbook(int id, string title, string author, bool available = true) {
        Book **newBooks = new Book*[size + 1];
        for (int i = 0; i < size; i++) {
            newBooks[i] = books[i];
        }
        newBooks[size] = new Book(id, title, author, available);
        delete[] books;
        books = newBooks;
        size++;
    }

    bool borrowbook(int id) {
        for (int i = 0; i < size; i++) {
            if (books[i]->id == id && books[i]->available) {
                books[i]->available = false;
                return true;
            }
        }
        return false;
    }

    bool returnbook(int id) {
        for (int i = 0; i < size; i++) {
            if (books[i]->id == id && !books[i]->available) {
                books[i]->available = true;
                return true;
            }
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (books[i]->available) {
                cout << "ID: " << books[i]->id << ", Title: " << books[i]->title << ", Author: " << books[i]->author << endl;
            }
        }
    }
};

int main() {
    Library lib;

    lib.addbook(1, "Book1", "Author1");
    lib.addbook(2, "Book2", "Author2", false);
    lib.addbook(3, "Book3", "Author3");

    cout << "Available books:" << endl;
    lib.display();

    lib.borrowbook(1);
    cout << "\nAfter borrowing Book 1:" << endl;
    lib.display();

    lib.returnbook(1);
    cout << "\nAfter returning Book 1:" << endl;
    lib.display();

    return 0;
}
