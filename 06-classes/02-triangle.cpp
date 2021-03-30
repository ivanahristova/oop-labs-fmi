#include <iostream>
#include <cmath>

class Triangle 
{
private:
    double a;
    double b;
    double c;

    bool validate(double a, double b, double c) const;
    double median_to_a(double a, double b, double c) const;
    double height_to_a(double a, double b, double c) const;

public:
    Triangle();
    Triangle(double a, double b, double c);
    // Triangle(double a = 1, double b = 1, double c = 1);

    double get_a() const;
    double get_b() const;
    double get_c() const;

    void set_a(double a);
    void set_b(double b);
    void set_c(double c);

    double perimeter() const;
    double area() const;
    double height(char side) const;
    double median(char side) const;
    double inradius() const;

    void print() const;
};

bool Triangle::validate(double a, double b, double c) const
{
    return a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a;
}

double Triangle::height_to_a(double a, double b, double c) const
{
    return (2 * area()) / a;
}

double Triangle::median_to_a(double a, double b, double c) const
{
    return 0.5 * sqrt(2 * (b * b) + 2 * (c * c) - a * a);
}

Triangle::Triangle()
{
    a = b = c = 1; 
}

Triangle::Triangle(double a, double b, double c) : Triangle()
{
    if (!validate(a, b, c))
    {
        return;
    }

    this->a = a;
    this->b = b;
    this->c = c;
}

double Triangle::get_a() const
{
    return a;
}

double Triangle::get_b() const
{
    return b;
}

double Triangle::get_c() const
{
    return c;
}

void Triangle::set_a(double a)
{
    if (validate(a, get_b(), get_c()))
    {
        this->a = a;
    }
}

void Triangle::set_b(double b)
{
    if (validate(get_a(), b, get_c()))
    {
        this->b = b;
    }
}

void Triangle::set_c(double c)
{
    if (validate(get_a(), get_b(), c))
    {
        this->c = c;
    }
}

double Triangle::perimeter() const
{
    return a + b + c;
}

double Triangle::area() const
{
    double p = perimeter() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::height(char side) const
{
    if (side == 'a')
    {
        return height_to_a(a, b, c);
    }
    if (side == 'b')
    {
        return height_to_a(b, a, c);
    }
    if (side == 'c')
    {
        return height_to_a(c, b, a);
    }
    return -1;
}

double Triangle::median(char side) const
{
    if (side == 'a')
    {
        return median_to_a(a, b, c);
    }
    if (side == 'b')
    {
        return median_to_a(b, a, c);
    }
    if (side == 'c')
    {
        return median_to_a(c, b, a);
    }
    return -1;
}

double Triangle::inradius() const
{
    double s = perimeter() / 2;
    return sqrt(((s - a) * (s - b) * (s - c)) / s);
}

void Triangle::print() const
{
    std::cout << "P: " << perimeter() << '\n';
    std::cout << "S: " << area() << '\n';
    std::cout << "h_a: " << height('a') << '\n';
    std::cout << "h_b: " << height('b') << '\n';
    std::cout << "h_c: " << height('c') << '\n';
    std::cout << "m_a: " << median('a') << '\n';
    std::cout << "m_b: " << median('b') << '\n';
    std::cout << "m_c: " << median('c') << '\n';
    std::cout << "r: " << inradius() << '\n';
}

int main()
{
    std::cout << "Triangle 1" << '\n';
    Triangle right_t(3, 4, 5);
    right_t.print();

    std::cout << "\nTriangle 2" << '\n';
    Triangle random_t(10, 8, 17);
    random_t.print();

    std::cout << "\nTriangle 3" << '\n';
    Triangle invalid(10, -8, 17);
    invalid.print();

    return 0;
}