#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "NegativeNumberException - Input must be non-negative!";
    }
};
class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidTypeException - Non-numeric type detected!";
    }
};
template<typename T>
double computeSqrt(T num) {
    throw InvalidTypeException();
}
template<>
double computeSqrt<int>(int num) {
    if (num < 0)
        throw NegativeNumberException();
    return sqrt(num);
}
template<>
double computeSqrt<float>(float num) {
    if (num < 0)
        throw NegativeNumberException();
    return sqrt(num);
}
template<>
double computeSqrt<double>(double num) {
    if (num < 0)
        throw NegativeNumberException();
    return sqrt(num);
}
int main() {
    try {
        cout << computeSqrt(9) << endl;
        cout << computeSqrt(-4.0) << endl; 
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try {
        cout << computeSqrt(string("hello")) << endl; 
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
