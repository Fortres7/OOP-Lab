#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float gpa;
};

int main() {
    Student students[5];
    
    for (int i = 0; i < 5; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> students[i].id;
        cin.ignore();
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "GPA: ";
        cin >> students[i].gpa;
        cout << endl;
    }

    ofstream outFile("students.txt", ios::out);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }
    
    for (int i = 0; i < 5; ++i) {
        outFile << students[i].id << " " << students[i].name << " " << students[i].gpa << endl;
    }
    outFile.close();

    Student newStudent;
    cout << "Enter details for 1 additional student to append:\n";
    cout << "ID: ";
    cin >> newStudent.id;
    cin.ignore();
    cout << "Name: ";
    getline(cin, newStudent.name);
    cout << "GPA: ";
    cin >> newStudent.gpa;
    cout << endl;

    ofstream appendFile("students.txt", ios::app);
    if (!appendFile) {
        cerr << "Error opening file for appending!" << endl;
        return 1;
    }
    appendFile << newStudent.id << " " << newStudent.name << " " << newStudent.gpa << endl;
    appendFile.close();

    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nAll student records:\n";
    while (inFile >> newStudent.id) {
        inFile.ignore();
        getline(inFile, newStudent.name);
        inFile >> newStudent.gpa;
        cout << "ID: " << newStudent.id << ", Name: " << newStudent.name << ", GPA: " << newStudent.gpa << endl;
    }
    inFile.close();

    return 0;
}

