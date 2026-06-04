#include <iostream>

class Shape
{
public:
    // Virtuell, damit bei Shape*-Zeigern die richtige Methode
    // der abgeleiteten Klasse zur Laufzeit aufgerufen wird.
    virtual double computeArea() const
    {
        return 0.0;
    }

    // Virtueller Destruktor, weil Shape eine polymorphe Basisklasse ist.
    // Dadurch ist das Löschen über Shape* sicher.
    virtual ~Shape() = default;
};

class Circle : public Shape
{
private:
    double radius;
    static constexpr double PI = 3.14;

public:
    Circle(double radius) : radius(radius) {}

    // override ist sinnvoll, weil der Compiler prüft,
    // ob wirklich eine virtuelle Funktion überschrieben wird.
    double computeArea() const override
    {
        return PI * radius * radius;
    }
};

class Rectangle : public Shape
{
private:
    double a;
    double b;

public:
    Rectangle(double a, double b) : a(a), b(b) {}

    double computeArea() const override
    {
        return a * b;
    }
};

int main()
{
    constexpr int SIZE = 4;

    Circle circle1(3.0);
    Circle circle2(4.0);
    Rectangle rectangle1(6.0, 3.0);
    Rectangle rectangle2(8.0, 2.0);

    Shape* shapes[SIZE] = {
        &circle1,
        &circle2,
        &rectangle1,
        &rectangle2
    };

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << shapes[i]->computeArea() << std::endl;
    }

    return 0;
}