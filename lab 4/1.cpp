#include <iostream>
using namespace std;

class Student
{
private:
    int studentID;
    string name;
    int age;
    char grade;

public:
    Student()
    {
        grade = 'N';
    }

    Student(string Name, int studentid, char Grade, int Age)
    {
        this->name = Name;
        this->studentID = studentid;
        this->grade = Grade;
        this->age = Age;
    }

    void promoteStudent()
    {
        if (grade == 'A')
        {
            cout << "Cannot upgrade Grade" << endl;
        }
        else if (grade == 'B')
        {
            cout << "Upgrading your Grade..." << endl;
            grade = 'A';
        }
        else if (grade == 'C')
        {
            cout << "Upgrading your Grade..." << endl;
            grade = 'B';
        }
        else if (grade == 'D')
        {
            cout << "Upgrading your Grade..."<<endl;
            grade = 'C';
        }
    }

    bool isEligibleForScholarship(){
        if (grade == 'A')
        {
            cout << "You Are Eligible for Scholarship\n";
            return true;
        }
        else{
            cout << "You are not Eligible for Scholarship\n";
            return false;
        }

    }
    void displayDetails(){
        cout << "Student ID: " << studentID <<endl;
        cout << "Student Name: " << name <<endl;
        cout << "Student Age: " << age <<endl;
        cout << "Student grade: " << grade <<endl;
    }        
};

int main()
{
    Student s1("Maarij", 1, 'A', 19);
    Student s2("Saad", 2, 'B', 20);
    Student s3("Saim", 3, 'C', 17);
    Student s4("Huzaifa", 4, 'D', 18);
    
    s1.displayDetails();
    s1.isEligibleForScholarship();
    s2.displayDetails();
    s2.isEligibleForScholarship();
    s3.displayDetails();
    s3.isEligibleForScholarship();
    s4.displayDetails();
    s4.isEligibleForScholarship();

    s1.promoteStudent();
    s2.promoteStudent();
    s3.promoteStudent();
    s4.promoteStudent();
    
    return 0;
}
