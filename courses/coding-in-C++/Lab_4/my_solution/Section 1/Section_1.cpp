#include <iostream>
#include <cmath>

class Vector2D
{
private:
    double x;
    double y;

public:
    Vector2D() : x(0.0), y(0.0){}

    Vector2D(double x, double y) : x(x), y(y){}

    double getX() const
    {
        return x;
    }

    double getY() const
    {
        return y;
    }

    void printCoordinates() const
    {
        std::cout << "(" << x << "|" << y << ")" << std::endl;
    }

    double getLenght() const
    {
        return sqrt((x*x) + (y*y));
    }

    double getLenght(int precision) const
    {
        double factor = std::pow(10.0, precision);
        return std::round(this->getLenght() * factor) / factor;
    }

    void operator+=(const Vector2D &vec)
    {
        this->x += vec.getX();
        this->y += vec.getY();
    }

    bool operator==(const Vector2D& vec) const;
    bool operator!=(const Vector2D& vec) const;

    void print() const
    {
        std::cout << "x: " << this->getX() << std::endl;
        std::cout << "y: " << this->getY() << std::endl;
    }
};


// free operator functions
Vector2D operator+(const Vector2D &vec_left, const Vector2D &vec_right)
{
    return Vector2D(vec_left.getX() + vec_right.getX(),
                    vec_left.getY() + vec_right.getY());
}

Vector2D operator*(const Vector2D &vec, const double scalar)
{
    return Vector2D(vec.getX() * scalar, vec.getY() * scalar);
}

Vector2D operator*(const double scalar, const Vector2D &vec)
{
    return Vector2D(vec.getX() * scalar, vec.getY() * scalar);
}


bool Vector2D::operator==(const Vector2D& vec) const
{
    const double EPSILON = 1e-9;
    return (std::fabs(x - vec.x) < EPSILON) &&
           (std::fabs(y - vec.y) < EPSILON);
}

bool Vector2D::operator!=(const Vector2D &vec) const
{
    const double EPSILON = 1e-9;
    return (std::fabs(x - vec.x) > EPSILON) ||
           (std::fabs(y - vec.y) > EPSILON);
}

int main()
{
    Vector2D vector1(4.0, 6.0);
    Vector2D vector2(5.0, 3.0);

    vector1.printCoordinates();
    std::cout << vector1.getLenght() << std::endl;
    std::cout << vector1.getLenght(3) << std::endl;

    (vector1 + vector2).print();
    (vector1 * 3).print();
    (3 * vector1).print();
    
    vector1 += vector2;
    vector1.print();

    std::cout << (vector1 == vector2) << std::endl;
    std::cout << (vector1 != vector2) << std::endl;

    return 0;
}