#include <iostream>
#include <cmath>

const double PI = 3.14159265358979;

class Shape {
public:
    virtual ~Shape() = default;
        virtual double area() const = 0;
            virtual double perimeter() const = 0;
            };

            class Circle : public Shape {
                double radius;
                public:
                    explicit Circle(double radius) : radius(radius) {}
                        double area() const override {
                                return PI * radius * radius;
                                    }
                                        double perimeter() const override {
                                                return 2 * PI * radius;
                                                    }
                                                    };

                                                    class Rectangle : public Shape {
                                                        double length, width;
                                                        public:
                                                            Rectangle(double length, double width)
                                                                    : length(length), width(width) {}
                                                                        double area() const override {
                                                                                return length * width;
                                                                                    }
                                                                                        double perimeter() const override {
                                                                                                return 2 * (length + width);
                                                                                                    }
                                                                                                    };

                                                                                                    class Triangle : public Shape {
                                                                                                        double a, b, c;
                                                                                                        public:
                                                                                                            Triangle(double a, double b, double c)
                                                                                                                    : a(a), b(b), c(c) {}
                                                                                                                        double area() const override {
                                                                                                                                double s = (a + b + c) / 2.0;
                                                                                                                                        return std::sqrt(s * (s - a) * (s - b) * (s - c));
                                                                                                                                            }
                                                                                                                                                double perimeter() const override {
                                                                                                                                                        return a + b + c;
                                                                                                                                                            }
                                                                                                                                                            };

                                                                                                                                                            int main() {
                                                                                                                                                                Circle circle(7.0);
                                                                                                                                                                    Rectangle rectangle(4.2, 8.0);
                                                                                                                                                                        Triangle triangle(4.0, 4.0, 3.2);

                                                                                                                                                                            std::cout << "Circle:\n"
                                                                                                                                                                                          << "  Area:      " << circle.area() << "\n"
                                                                                                                                                                                                        << "  Perimeter: " << circle.perimeter() << "\n\n";

                                                                                                                                                                                                            std::cout << "Rectangle:\n"
                                                                                                                                                                                                                          << "  Area:      " << rectangle.area() << "\n"
                                                                                                                                                                                                                                        << "  Perimeter: " << rectangle.perimeter() << "\n\n";

                                                                                                                                                                                                                                            std::cout << "Triangle:\n"
                                                                                                                                                                                                                                                          << "  Area:      " << triangle.area() << "\n"
                                                                                                                                                                                                                                                                        << "  Perimeter: " << triangle.perimeter() << "\n";

                                                                                                                                                                                                                                                                            return 0;
                                                                                                                                                                                                                                                                            }