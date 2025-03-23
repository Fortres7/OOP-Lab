#include<iostream>
#include<cmath>
using namespace std;

class Shape {
    protected:
    string position;
    string color;
    double borderThickness;

    public:
    Shape(string pos, string col, double border) {
        position = pos;
        color = col;
        borderThickness = border;
    }

    virtual void draw() {
        cout << "Drawing a generic shape." << endl;
    }

    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};

class Circle : public Shape {
    double radius;
    string centerPosition;

    public:
    Circle(string pos, string col, double border, double rad, string center) : Shape(pos, col, border) {
        radius = rad;
        centerPosition = center;
    }

    void draw() override {
        cout << "Drawing a Circle." << endl;
    }

    double calculateArea() override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
    double width, height;
    string topLeftCorner;

    public:
    Rectangle(string pos, string col, double border, double w, double h, string corner) : Shape(pos, col, border) {
        width = w;
        height = h;
        topLeftCorner = corner;
    }

    void draw() override {
        cout << "Drawing a Rectangle." << endl;
    }

    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

int main() {
    Circle circle("Center", "Red", 2.0, 5.0, "(0,0)");
    Rectangle rectangle("Top-left", "Blue", 1.5, 4.0, 6.0, "(2,3)");
    
    circle.draw();
    cout << "Circle Area: " << circle.calculateArea() << endl;
    cout << "Circle Perimeter: " << circle.calculatePerimeter() << endl;
    
    rectangle.draw();
    cout << "Rectangle Area: " << rectangle.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << rectangle.calculatePerimeter() << endl;
    
    return 0;
}
