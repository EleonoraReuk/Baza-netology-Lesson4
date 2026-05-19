#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Figure {
protected:
    int sides_count;
    double* sides;
    double* angles;
    string name;
    bool correct;
public:
    Figure() : sides_count(0), sides(nullptr), angles(nullptr), name("Фигура"), correct(true) {}

    virtual ~Figure() {
        delete[] sides;
        delete[] angles;
    }

    virtual bool check() {
        return true;
    }

    virtual void print_info() {
        cout << name << ":" << endl;
        if (check()) {
            cout << "Правильная" << endl;
        }
        else {
            cout << "Неправильная" << endl;
        }
        cout << "Количество сторон: " << sides_count << endl;

        if (sides_count > 0 && sides != nullptr) {
            cout << "Стороны: ";
            for (int i = 0; i < sides_count; i++) {
                cout << char('a' + i) << "=" << sides[i];
                if (i < sides_count - 1) cout << " ";
            }
            cout << endl;

            cout << "Углы: ";
            for (int i = 0; i < sides_count; i++) {
                cout << char('A' + i) << "=" << angles[i];
                if (i < sides_count - 1) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};
class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double side_a, double side_b, double side_c,
        double angle_A, double angle_B, double angle_C)
        : a(side_a), b(side_b), c(side_c), A(angle_A), B(angle_B), C(angle_C) {
        sides_count = 3;
        name = "Треугольник";

        sides = new double[3] {a, b, c};
        angles = new double[3] {A, B, C};
    }

    virtual bool check() override {
        return (sides_count == 3 &&
            abs(A + B + C - 180.0) < 0.001);
    }

    virtual void print_info() override {
        cout << name << ":" << endl;
        if (check()) {
            cout << "Правильная" << endl;
        }
        else {
            cout << "Неправильная" << endl;
        }
        cout << "Количество сторон: " << sides_count << endl;
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
        cout << endl;
    }
};
class RightTriangle : public Triangle {
public:
    RightTriangle(double side_a, double side_b, double side_c,
        double angle_A, double angle_B)
        : Triangle(side_a, side_b, side_c, angle_A, angle_B, 90.0) {
        name = "Прямоугольный треугольник";
    }

    virtual bool check() override {
        return Triangle::check() && abs(C - 90.0) < 0.001;
    }
};
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double side_a, double side_b,
        double angle_A, double angle_B)
        : Triangle(side_a, side_b, side_a, angle_A, angle_B, angle_A) {
        name = "Равнобедренный треугольник";
    }

    virtual bool check() override {
        return Triangle::check() &&
            abs(a - c) < 0.001 &&
            abs(A - C) < 0.001;
    }
};
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60.0, 60.0, 60.0) {
        name = "Равносторонний треугольник";
    }

    virtual bool check() override {
        return Triangle::check() &&
            abs(a - b) < 0.001 &&
            abs(b - c) < 0.001 &&
            abs(A - 60.0) < 0.001 &&
            abs(B - 60.0) < 0.001 &&
            abs(C - 60.0) < 0.001;
    }
};
class Quadrilateral : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrilateral(double side_a, double side_b, double side_c, double side_d,
        double angle_A, double angle_B, double angle_C, double angle_D)
        : a(side_a), b(side_b), c(side_c), d(side_d),
        A(angle_A), B(angle_B), C(angle_C), D(angle_D) {
        sides_count = 4;
        name = "Четырёхугольник";

        sides = new double[4] {a, b, c, d};
        angles = new double[4] {A, B, C, D};
    }

    virtual bool check() override {
        return (sides_count == 4 &&
            abs(A + B + C + D - 360.0) < 0.001);
    }

    virtual void print_info() override {
        cout << name << ":" << endl;
        if (check()) {
            cout << "Правильная" << endl;
        }
        else {
            cout << "Неправильная" << endl;
        }
        cout << "Количество сторон: " << sides_count << endl;
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
        cout << endl;
    }
};
class Rectangle : public Quadrilateral {
public:
    Rectangle(double side_a, double side_b)
        : Quadrilateral(side_a, side_b, side_a, side_b, 90.0, 90.0, 90.0, 90.0) {
        name = "Прямоугольник";
    }

    virtual bool check() override {
        return Quadrilateral::check() &&
            abs(a - c) < 0.001 &&
            abs(b - d) < 0.001 &&
            abs(A - 90.0) < 0.001 &&
            abs(B - 90.0) < 0.001 &&
            abs(C - 90.0) < 0.001 &&
            abs(D - 90.0) < 0.001;
    }
};
class Square : public Rectangle {
public:
    Square(double side)
        : Rectangle(side, side) {
        name = "Квадрат";
    }

    virtual bool check() override {
        return Rectangle::check() &&
            abs(a - b) < 0.001;
    }
};
class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double side_a, double side_b, double angle_A, double angle_B)
        : Quadrilateral(side_a, side_b, side_a, side_b, angle_A, angle_B, angle_A, angle_B) {
        name = "Параллелограмм";
    }

    virtual bool check() override {
        return Quadrilateral::check() &&
            abs(a - c) < 0.001 &&
            abs(b - d) < 0.001 &&
            abs(A - C) < 0.001 &&
            abs(B - D) < 0.001;
    }
};
class Rhombus : public Parallelogram {
public:
    Rhombus(double side, double angle_A, double angle_B)
        : Parallelogram(side, side, angle_A, angle_B) {
        name = "Ромб";
    }

    virtual bool check() override {
        return Parallelogram::check() &&
            abs(a - b) < 0.001 &&
            abs(b - c) < 0.001 &&
            abs(c - d) < 0.001;
    }
};
int main() {
    Figure* figures[] = {
        new Figure(),
        new Triangle(10, 20, 30, 50, 60, 70),
        new RightTriangle(10, 20, 30, 50, 60),
        new RightTriangle(10, 20, 22.36, 50, 40),
        new IsoscelesTriangle(10, 20, 50, 60),
        new EquilateralTriangle(30),
        new Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80),
        new Rectangle(10, 20),
        new Square(20),
        new Parallelogram(20, 30, 30, 40),
        new Rhombus(30, 30, 40)
    };

    for (int i = 0; i < 11; i++) {
        figures[i]->print_info();
    }

    for (int i = 0; i < 11; i++) {
        delete figures[i];
    }

    return 0;
}
