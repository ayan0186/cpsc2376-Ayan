#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cmath> // for M_PI

// Base class
class Shape {
public:
    virtual double getArea() const = 0; // Pure virtual method
    virtual ~Shape() = default; // Virtual destructor for proper cleanup
};

// Rectangle class derived from Shape
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }
};

// Circle class derived from Shape
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return M_PI * radius * radius;
    }
};

// Function to print all areas
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream inputFile("shapes.txt");
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string shapeType;
    double dimension1, dimension2;

    while (inputFile >> shapeType) {
        if (shapeType == "rectangle") {
            inputFile >> dimension1 >> dimension2;
            shapes.push_back(std::make_unique<Rectangle>(dimension1, dimension2));
        } else if (shapeType == "circle") {
            inputFile >> dimension1;
            shapes.push_back(std::make_unique<Circle>(dimension1));
        }
    }

    printAllAreas(shapes); // Print all areas

    return 0;
}
