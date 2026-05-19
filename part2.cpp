#include <iostream>
#include <string>
using namespace std;


class Figure {
public:
    virtual string get_name() const = 0;
    virtual ~Figure() = default;
};
class Triangle : public Figure {
protected:
    double a, b, c; 
    double A, B, C;  

public:
    Triangle(double side_a, double side_b, double side_c, double angle_A, double angle_B, double angle_C)
        : a(side_a), b(side_b), c(side_c), A(angle_A), B(angle_B), C(angle_C) {
    }

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }

    string get_name() const override { return "Треугольник"; }
};


class RightTriangle : public Triangle {
public:
    RightTriangle(double side_a, double side_b, double side_c, double angle_A, double angle_B)
        : Triangle(side_a, side_b, side_c, angle_A, angle_B, 90) {
    }

    string get_name() const override { return "Прямоугольный треугольник"; }
};


class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double side_a, double side_b, double angle_A, double angle_B)
        : Triangle(side_a, side_b, side_a, angle_A, angle_B, angle_A) {
    }

    string get_name() const override { return "Равнобедренный треугольник"; }
};


class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {
    }

    string get_name() const override { return "Равносторонний треугольник"; }
};


class Quadrilateral : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrilateral(double side_a, double side_b, double side_c, double side_d, double angle_A, double angle_B, double angle_C, double angle_D)
        : a(side_a), b(side_b), c(side_c), d(side_d), A(angle_A), B(angle_B), C(angle_C), D(angle_D) {
    }

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_d() const { return d; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
    double get_D() const { return D; }

    string get_name() const override { return "Четырёхугольник"; }
};


class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double side_a, double side_b, double angle_A, double angle_B)
        : Quadrilateral(side_a, side_b, side_a, side_b, angle_A, angle_B, angle_A, angle_B) {
    }

    string get_name() const override { return "Параллелограмм"; }
};


class Rectangle : public Parallelogram {
public:
    Rectangle(double side_a, double side_b)
        : Parallelogram(side_a, side_b, 90, 90) {
    }

    string get_name() const override { return "Прямоугольник"; }
};


class Rhombus : public Parallelogram {
public:
    Rhombus(double side, double angle_A, double angle_B)
        : Parallelogram(side, side, angle_A, angle_B) {
    }

    string get_name() const override { return "Ромб"; }
};


class Square : public Rectangle {
public:
    Square(double side)
        : Rectangle(side, side) {
    }

    string get_name() const override { return "Квадрат"; }
};


void print_info(const Figure* figure) {
    cout << figure->get_name() << ":\n";


    if (const Triangle* triangle = dynamic_cast<const Triangle*>(figure)) {
        cout << "Стороны: a=" << triangle->get_a()
            << " b=" << triangle->get_b()
            << " c=" << triangle->get_c() << endl;
        cout << "Углы: A=" << triangle->get_A()
            << " B=" << triangle->get_B()
            << " C=" << triangle->get_C() << endl;
    }

    else if (const Quadrilateral* quad = dynamic_cast<const Quadrilateral*>(figure)) {
        cout << "Стороны: a=" << quad->get_a()
            << " b=" << quad->get_b()
            << " c=" << quad->get_c()
            << " d=" << quad->get_d() << endl;
        cout << "Углы: A=" << quad->get_A()
            << " B=" << quad->get_B()
            << " C=" << quad->get_C()
            << " D=" << quad->get_D() << endl;
    }
    cout << endl;
}


int main() {
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    EquilateralTriangle equilateralTriangle(30);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_info(&triangle);
    print_info(&rightTriangle);
    print_info(&isoscelesTriangle);
    print_info(&equilateralTriangle);
    print_info(&quadrilateral);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return 0;
}
