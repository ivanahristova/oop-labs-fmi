#include <iostream>
#include <fstream>
#include "binary_num.hpp"

BinaryNum generate()
{
    return BinaryNum("11000101010101");
}

int main()
{
    // BinaryNum num0 = generate();

    BinaryNum num1("101010101"), num2("1010abc");  // -> "11110" and "1010"
    // BinaryNum num3 = num1 & num2;

    // std::cout << num3.get_str() << "\n";

    std::cout << num1 << "\n";
    // std::cin >> num1;
    // std::cout << num1 << "\n";

    for (int i = 0; i < 10; i++)
    {
        num1 = num1 >> 1;
        std::cout << num1 << "\n";
    }

    return 0;
}
