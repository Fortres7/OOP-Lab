#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream file("data.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string searchWord, replacementWord;
    cout << "Enter search word: ";
    cin >> searchWord;
    cout << "Enter replacement word: ";
    cin >> replacementWord;

    string line;
    while (getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(searchWord, pos)) != string::npos) {
            cout << "Found at position: " << pos << endl;

            file.seekg(pos);
            file.seekp(pos);

            file << replacementWord;

            size_t paddingLength = replacementWord.size() - searchWord.size();
            if (paddingLength > 0) {
                for (size_t i = 0; i < paddingLength; ++i) {
                    file.put(' ');  
                }
            }

            pos += replacementWord.size();
        }
    }

    file.close();

    ifstream updatedFile("data.txt");
    if (!updatedFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nUpdated content of file:\n";
    string updatedLine;
    while (getline(updatedFile, updatedLine)) {
        cout << updatedLine << endl;
    }
    updatedFile.close();

    return 0;
}
