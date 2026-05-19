/*#include <iostream>
#include <string>
using namespace std;

class Figure {
protected:
	int sides_count;
	string name;

public:
	Figure() : sides_count(0), name("Фигура") {}

	Figure(int sides, const string& figure_name)
		: sides_count(sides), name(figure_name) {}

	int get_sides_count() const {
		return sides_count;
	}

	string get_name() const {
		return name;
	}

	virtual ~Figure() {}
};

class Triangle : public Figure {
public:
	Triangle() : Figure(3, "Треугольник") {}
};

class Quadrangle : public Figure {
public:
	Quadrangle() : Figure(4, "Четырехугольник") {}
};

int main() {
	Figure figure;
	Triangle triangle;
	Quadrangle quadrangle;

	cout << "Количество сторон: " << endl;
	cout << figure.get_name() << ": " << figure.get_sides_count() << endl;
	cout << triangle.get_name() << ": " << triangle.get_sides_count() << endl;
	cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << endl;

	return 0;
}
*/