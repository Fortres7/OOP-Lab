#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    int carID;
    string model;
    int year;
    bool isRented;

public:
    Car() {
        isRented = false;
    }

    Car(int id, string mod, int yr) {
        carID = id;
        model = mod;
        year = yr;
        isRented = false;
    }

    void rentCar() {
        if (!isRented) {
            isRented = true;
            cout << "Car " << model << " rented successfully.\n";
        } else {
            cout << "Car " << model << " is already rented.\n";
        }
    }

    void returnCar() {
        if (isRented) {
            isRented = false;
            cout << "Car " << model << " returned successfully.\n";
        } else {
            cout << "Car " << model << " is already available.\n";
        }
    }

    bool isVintage() {
        if (year < 2000) {
            return true;
        } else {
            return false;
        }
    }

    void displayInfo() {
        cout << "Car ID: " << carID << ", Model: " << model << ", Year: " << year;
        cout << ", Rented: ";
        if (isRented) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << endl;
    }
};

int main() {
    Car car1(1, "Toyota Corolla", 1999);
    Car car2(2, "Ford Mustang", 2022);
    Car car3(3, "Honda Civic", 2005);

    car1.displayInfo();
    car2.displayInfo();
    car3.displayInfo();

    cout << endl;

    car1.rentCar();
    car1.displayInfo();
    
    car2.rentCar();
    car2.displayInfo();
    
    car3.rentCar();
    car3.displayInfo();

    cout << endl;

    car1.returnCar();
    car1.displayInfo();

    car2.returnCar();
    car2.displayInfo();

    cout << endl;

    cout << "Is car1 vintage? ";
    if (car1.isVintage()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;

    cout << "Is car2 vintage? ";
    if (car2.isVintage()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;

    cout << "Is car3 vintage? ";
    if (car3.isVintage()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;

    return 0;
}
