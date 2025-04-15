#include <iostream>
#include <cmath> // For mathematical functions like pi

using namespace std;

// Base class Shape

class Shape {

public:
     // Pure virtual function
    virtual double area() const = 0;
};

// Derived class Circle
class Circle : public Shape {

private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    virtual double area() const override {
        return M_PI * radius * radius;
    }
};

// Derived class Rectangle

class Rectangle : public Shape {

private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    virtual double area() const override {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    double height;
    double width;
public:
    
    Triangle(double h, double w) : height(h), width(w) {}
    
    virtual double area() const override {
        return ((height * width) / 2);
    }
};

int main() {

    Shape* shapes[3];
    shapes[0] = new Circle(5.0);        // Radius = 5.0
    shapes[1] = new Rectangle(4, 6);    // Length = 4, Width = 6^K
    shapes[2] = new Triangle(5, 3);

    for (int i = 0; i < 3; ++i) {
        cout << "Area of shape " << i + 1 << ": "
             << shapes[i]->area() << endl;
        delete shapes[i]; // Free memory allocated for each shape
    }

    return 0;
}
