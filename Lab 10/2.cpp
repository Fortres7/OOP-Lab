#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name, email, summary;
    int yearsOfExperience;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your email: ";
    getline(cin, email);
    cout << "Enter your years of experience: ";
    cin >> yearsOfExperience;
    cin.ignore();
    cout << "Enter a summary: ";
    getline(cin, summary);

    ofstream outFile("resume.txt", ios::trunc);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    outFile << "Name: " << name << endl;
    outFile << "Email: " << email << endl;
    outFile << "Years of Experience: " << yearsOfExperience << endl;
    outFile << "Summary: " << summary << endl;
    outFile.close();

    ifstream inFile("resume.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nResume Content:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    return 0;
}
