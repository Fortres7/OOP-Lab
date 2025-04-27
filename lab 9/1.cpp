#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string model;
    double rate;

public:
    Vehicle(string m, double r) : model(m), rate(r) {}
    virtual double getDailyRate() const = 0;
    virtual void displayDetails() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(string m, double r) : Vehicle(m, r) {}

    double getDailyRate() const override {
        return rate;
    }

    void displayDetails() const override {
        cout << "Car Model: " << model << ", Daily Rate: $" << rate << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string m, double r) : Vehicle(m, r) {}

    double getDailyRate() const override {
        return rate;
    }

    void displayDetails() const override {
        cout << "Bike Model: " << model << ", Daily Rate: $" << rate << endl;
    }
};

int main() {
    Vehicle* vehicles[2];

    vehicles[0] = new Car("Toyota Corolla", 70);
    vehicles[1] = new Bike("Yamaha R15", 30);

    for (int i = 0; i < 2; ++i) {
        vehicles[i]->displayDetails();
        cout << "Rental per Day: $" << vehicles[i]->getDailyRate() << endl << endl;
    }

    for (int i = 0; i < 2; ++i) {
        delete vehicles[i];
    }

    return 0;
}
