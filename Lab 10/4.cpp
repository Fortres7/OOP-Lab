#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("info.txt", ios::out);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }
    outFile << "C++ is a powerful programming language.";
    outFile.close();

    fstream file("info.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    cout << "Initial get pointer position: " << file.tellg() << endl;
    cout << "Initial put pointer position: " << file.tellp() << endl;

    file.seekg(6);
    string word;
    file >> word;
    cout << "Read word from position 6: " << word << endl;

    file.seekp(6);
    file << "dynamic";  

    cout << "New get pointer position: " << file.tellg() << endl;
    cout << "New put pointer position: " << file.tellp() << endl;

    file.close();

    ifstream updatedFile("info.txt");
    if (!updatedFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    string updatedContent;
    getline(updatedFile, updatedContent);
    cout << "Updated content: " << updatedContent << endl;

    updatedFile.close();

    return 0;
}
