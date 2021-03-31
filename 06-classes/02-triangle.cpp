#include <iostream>
#include <cmath>
#include <cstring>
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
    double semi_perimeter() const;
    double area() const;
    double height(char side) const;
    double median(char side) const;
    double inradius() const;
    double circumscribed_circle_radius() const;
    double angle_bisector(char side) const;
    double sin(const char* angle) const;
    double cos(const char* angle) const;

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

double Triangle::semi_perimeter() const
{
    return (a+b+c)/2;
}

double Triangle::angle_bisector(char side) const
{
    if(side == 'c')
        return sqrt(a*b-(a*b*c*c)/((a+b)*(a+b)));
    if(side == 'b')
        return sqrt(a*c-(a*b*b*c)/((a+c)*(a+c)));
    if(side == 'a')
        return sqrt((b*c-(a*a*b*c)/(b+c)*(b+c)));
    return -1;
}

double Triangle::area() const
{
    double p = semi_perimeter();
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

double Triangle::sin(const char* angle) const
{   
    double s = area();
    
    if(strcmp(angle, "alpha") == 0)
        return ((s*2)/(b*c));
    if(strcmp(angle, "beta") == 0)
        return ((s*2)/(a*c));
    if(strcmp(angle, "gamma") == 0)
        return ((s*2)/(a*b));
    return -1;
}

double Triangle::cos(const char* angle) const
{
    if(strcmp(angle, "alpha"))
        return ((b*b+c*c-a*a)/(2*b*c) == 0);
    if(strcmp(angle, "beta"))
        return ((a*a+c*c-b*b)/(2*a*c) == 0);
    if(strcmp(angle, "gamma")==1)
        return ((a*a+b*b-c*c)/(2*a*b) == 0);       
    return -1;
}
double Triangle::inradius() const
{
    double s = semi_perimeter();
    return sqrt(((s - a) * (s - b) * (s - c)) / s);
}
double Triangle::circumscribed_circle_radius() const
{
    double s = area();
    return (a*b*c/(4*s));
}
void Triangle::print() const
{
    std::cout << "P: " << perimeter() << '\n';
    std::cout << "S: " << area() << '\n';
    std::cout << "p: " << semi_perimeter() << '\n';
    std::cout << "Lc: " << angle_bisector('c') << '\n';
    std::cout << "R: " << circumscribed_circle_radius() << '\n';
    std::cout << "sin(gamma): " << sin("gamma") << '\n';
    std::cout << "cos(gamma): " << cos("gamma") << '\n';
}

int main()
{
    std::cout << "Triangle 1" << '\n';
    Triangle right_t(3, 4, 5);
    right_t.print();

    

    return 0;
}