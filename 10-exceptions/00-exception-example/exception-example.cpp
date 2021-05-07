#include <iostream>
#include <stdexcept>

double triangle_perimeter(double a, double b, double c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        throw std::invalid_argument("There are nonpositive sides of the triangle.");
    }

    return a + b + c;
}

int main()
{
    int a = 3, b = 4, c = 2;
    int perimeter = 0;

    try
    {
        perimeter = triangle_perimeter(a, b, c);
        std::cout << "The perimeter is: " << perimeter << '\n';
    }
    catch (std::invalid_argument &exception)
    {
        std::cout << exception.what() << '\n';
    }

    return 0;
}