#include <iostream>

struct A {
    char c1;
    double d;
    char c2;
};

struct B {
    char c1;
    char c2;
    double d;
};

int main()
{
    std::cout << sizeof(A) << '\n';
    std::cout << sizeof(B) << '\n';
}
