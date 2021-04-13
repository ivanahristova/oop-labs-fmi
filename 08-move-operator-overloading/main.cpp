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

    BinaryNum num1("011110x1"), num2("1010abc");  // -> "11110" and "1010"
    BinaryNum num3 = num1 & num2;

    std::cout << num3.get_str() << "\n";

    return 0;
}
